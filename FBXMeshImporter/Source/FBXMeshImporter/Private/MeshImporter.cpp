#include "MeshImporter.h"
#include "LoadedStaticMesh.h"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include "Misc/Paths.h"
#include "MeshDescription.h"
#include "StaticMeshAttributes.h"
#include "PhysicsEngine/BodySetup.h"
#include "Engine/World.h"
#include "Engine/Engine.h"

#if PLATFORM_WINDOWS
    #include "Windows/WindowsPlatformProcess.h"
#endif

// Структура для хранения ключа вершины с позицией, нормалью и основным UV-каналом
struct FVertexKey
{
    FVector3f Position;
    FVector3f Normal;
    FVector2f UV;

    bool operator==(const FVertexKey& Other) const
    {
        return Position.Equals(Other.Position, 0.001f) &&
               Normal.Equals(Other.Normal, 0.001f) &&
               UV.Equals(Other.UV, 0.001f);
    }

    friend uint32 GetTypeHash(const FVertexKey& Key)
    {
        return HashCombine(HashCombine(GetTypeHash(Key.Position), GetTypeHash(Key.Normal)), GetTypeHash(Key.UV));
    }
};

// Функция для загрузки статического меша из файла
UStaticMesh* UMeshImporter::LoadStaticMeshFromFile(const FString& FilePath)
{
    // Проверка существования файла
    if (!FPaths::FileExists(FilePath))
    {
        UE_LOG(LogTemp, Error, TEXT("Файл не найден: %s"), *FilePath);
        return nullptr;
    }

    // Пути для поиска библиотеки Assimp
    TArray<FString> PossiblePaths = {
        FPaths::Combine(FPaths::ProjectDir(), TEXT("Binaries/Win64/assimp-vc143-mt.dll")),
        FPaths::Combine(FPaths::ProjectPluginsDir(), TEXT("FBXMeshImporter/Binaries/Win64/assimp-vc143-mt.dll")),
        FPaths::Combine(FPaths::EnginePluginsDir(), TEXT("FBXMeshImporter/Binaries/Win64/assimp-vc143-mt.dll")),
        FPaths::Combine(FPaths::EnginePluginsDir(), TEXT("Marketplace/FBXMeshImporter/Binaries/Win64/assimp-vc143-mt.dll"))
    };

    // Загрузка DLL Assimp
    void* AssimpDLLHandle = nullptr;
    for (const FString& Path : PossiblePaths)
    {
        UE_LOG(LogTemp, Log, TEXT("Пробуем загрузить Assimp DLL: %s"), *Path);
        AssimpDLLHandle = FPlatformProcess::GetDllHandle(*Path);
        if (AssimpDLLHandle)
        {
            UE_LOG(LogTemp, Log, TEXT("Assimp DLL загружен: %s"), *Path);
            break;
        }
    }

    if (!AssimpDLLHandle)
    {
        UE_LOG(LogTemp, Error, TEXT("Не удалось загрузить Assimp DLL!"));
        return nullptr;
    }

    // Чтение файла с использованием Assimp
    FString AbsoluteFilePath = FPaths::ConvertRelativePathToFull(FilePath);
    std::string FilePathStr(TCHAR_TO_UTF8(*AbsoluteFilePath));

    Assimp::Importer Importer;
    const aiScene* Scene = Importer.ReadFile(FilePathStr,
        aiProcess_Triangulate |
        aiProcess_CalcTangentSpace |
        aiProcess_GenUVCoords |         // Генерация UV, если их нет
        aiProcess_PreTransformVertices  // Сохраняем корректный масштаб
    );

    if (!Scene || !Scene->HasMeshes())
    {
        UE_LOG(LogTemp, Error, TEXT("Ошибка загрузки меша: %s"), *FilePath);
        return nullptr;
    }

    aiMesh* Mesh = Scene->mMeshes[0];

    // Создание нового статического меша с использованием подкласса
    ULoadedStaticMesh* StaticMesh = NewObject<ULoadedStaticMesh>((UObject*)GetTransientPackage(), ULoadedStaticMesh::StaticClass(), FName(*FPaths::GetBaseFilename(FilePath)), RF_Public | RF_Standalone);
    if (!StaticMesh)
    {
        UE_LOG(LogTemp, Error, TEXT("Не удалось создать объект ULoadedStaticMesh."));
        return nullptr;
    }

    // Устанавливаем текущий мир
    if (UWorld* CurrentWorld = GEngine ? GEngine->GetCurrentPlayWorld() : nullptr)
    {
        StaticMesh->SetWorld(CurrentWorld);
    }

    // Инициализация описания меша
    FMeshDescription MeshDescription;
    FStaticMeshAttributes Attributes(MeshDescription);
    Attributes.Register();

    // Определение количества доступных UV-каналов
    uint32 MaxUVChannels = 0;
    for (uint32 Channel = 0; Channel < 10 && Mesh->HasTextureCoords(Channel); ++Channel)
    {
        MaxUVChannels = Channel + 1;
    }

    // Мапы для хранения ключей вершин и их идентификаторов
    TMap<FVertexKey, FVertexID> VertexKeyToID;
    TMap<uint32, FVertexInstanceID> VertexIndexToInstanceID;

    // Обработка вершин
    for (uint32 VertexIndex = 0; VertexIndex < Mesh->mNumVertices; ++VertexIndex)
    {
        aiVector3D Vertex = Mesh->mVertices[VertexIndex];
        FVector3f Position(Vertex.x, Vertex.z, Vertex.y);

        FVector3f Normal(0, 0, 0);
        if (Mesh->HasNormals())
        {
            const aiVector3D& N = Mesh->mNormals[VertexIndex];
            Normal = FVector3f(N.x, N.y, N.z);
        }

        // Обработка всех доступных UV-каналов
        TArray<FVector2f> UVs;
        for (uint32 Channel = 0; Channel < MaxUVChannels; ++Channel)
        {
            if (Mesh->mTextureCoords[Channel])
            {
                const aiVector3D& TexCoord = Mesh->mTextureCoords[Channel][VertexIndex];
                FVector2f UV(
                    FMath::Fmod(TexCoord.x, 1.0f), // Нормализация X через модуль
                    FMath::Fmod(1.0f - TexCoord.y, 1.0f) // Нормализация и инверсия Y через модуль
                );
                // Убедимся, что значения в пределах [0, 1]
                UV.X = FMath::Clamp(UV.X, 0.0f, 1.0f);
                UV.Y = FMath::Clamp(UV.Y, 0.0f, 1.0f);
                UVs.Add(UV);
            }
        }

        // Используем первый UV-канал для ключа вершины
        FVector2f PrimaryUV(0, 0);
        if (UVs.Num() > 0)
        {
            PrimaryUV = UVs[0]; // Используем UV Channel 0
        }

        FVertexKey Key{ Position, Normal, PrimaryUV };
        FVertexID* VertexIDPtr = VertexKeyToID.Find(Key);

        FVertexID VertexID;
        if (VertexIDPtr)
        {
            VertexID = *VertexIDPtr;
        }
        else
        {
            VertexID = MeshDescription.CreateVertex();
            MeshDescription.GetVertexPositions()[VertexID] = Position;
            VertexKeyToID.Add(Key, VertexID);
        }

        FVertexInstanceID VertexInstanceID = MeshDescription.CreateVertexInstance(VertexID);
        VertexIndexToInstanceID.Add(VertexIndex, VertexInstanceID);

        Attributes.GetVertexInstanceNormals()[VertexInstanceID] = Normal;

        // Установка всех UV-каналов
        for (uint32 Channel = 0; Channel < static_cast<uint32>(UVs.Num()); ++Channel)
        {
            Attributes.GetVertexInstanceUVs().Set(VertexInstanceID, Channel, UVs[Channel]);
        }

        // Обработка тангентов и бинормалей, если они есть
        if (Mesh->HasTangentsAndBitangents())
        {
            const aiVector3D& Tangent = Mesh->mTangents[VertexIndex];
            FVector3f TangentVec(Tangent.x, Tangent.z, Tangent.y);
            Attributes.GetVertexInstanceTangents()[VertexInstanceID] = TangentVec;

            const aiVector3D& Bitangent = Mesh->mBitangents[VertexIndex];
            FVector3f BitangentVec(Bitangent.x, Bitangent.z, Bitangent.y);
            float W = FVector3f::DotProduct(FVector3f::CrossProduct(Normal, TangentVec), BitangentVec) < 0.0f ? -1.0f : 1.0f;
            Attributes.GetVertexInstanceBinormalSigns()[VertexInstanceID] = W;
        }
    }

    // Создание группы полигонов
    FPolygonGroupID PolygonGroupID = MeshDescription.CreatePolygonGroup();

    // Обработка полигонов (треугольников)
    for (uint32 FaceIndex = 0; FaceIndex < Mesh->mNumFaces; ++FaceIndex)
    {
        const aiFace& Face = Mesh->mFaces[FaceIndex];
        if (Face.mNumIndices != 3) continue; // Пропускаем не треугольные полигоны

        TArray<FVertexInstanceID> VertexInstanceIDs;
        for (uint32 VertexIdx = 0; VertexIdx < 3; ++VertexIdx)
        {
            uint32 Index = Face.mIndices[VertexIdx];
            VertexInstanceIDs.Add(VertexIndexToInstanceID[Index]);
        }

        MeshDescription.CreatePolygon(PolygonGroupID, VertexInstanceIDs);
    }

    // Построение меша
    TArray<const FMeshDescription*> MeshDescriptionPtrs;
    MeshDescriptionPtrs.Add(&MeshDescription);

    UStaticMesh::FBuildMeshDescriptionsParams BuildParams;
    BuildParams.bBuildSimpleCollision = true; // Создаём простую коллизию
    BuildParams.bAllowCpuAccess = true;       // Сохраняем данные для сложной коллизии

#if UE_BUILD_DEBUG || UE_BUILD_DEVELOPMENT
    BuildParams.bFastBuild = true; // Ускоренная сборка для Debug/Development
#endif

    StaticMesh->BuildFromMeshDescriptions(MeshDescriptionPtrs, BuildParams);

    // Настройка коллизии
    StaticMesh->CreateBodySetup();
    if (UBodySetup* BodySetup = StaticMesh->GetBodySetup())
    {
        BodySetup->CollisionTraceFlag = ECollisionTraceFlag::CTF_UseComplexAsSimple; // Используем сложную коллизию
    }

    // Логирование размеров меша
    FBoxSphereBounds Bounds = StaticMesh->GetBounds();
    UE_LOG(LogTemp, Log, TEXT("Размер меша: %s"), *Bounds.BoxExtent.ToString());

    return StaticMesh;
}