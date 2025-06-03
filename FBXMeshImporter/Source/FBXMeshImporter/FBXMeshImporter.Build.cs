/*
using UnrealBuildTool;
using System.IO;

public class FBXMeshImporter : ModuleRules
{
    public FBXMeshImporter(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] {
            "Core",
            "CoreUObject",
            "Engine",
            "RenderCore",
            "RHI",
            "MeshDescription",        
            "StaticMeshDescription",   
            "PhysicsCore"
        });

        PrivateDependencyModuleNames.AddRange(new string[]
        {
            "CoreUObject",
            "Slate",
            "SlateCore"
        });

        string ThirdPartyPath = Path.Combine(ModuleDirectory, "../../ThirdParty/");

        // Попытка загрузить Assimp в проекте
        if (!LoadAssimp(Target, ThirdPartyPath))
        {
            // Если не найдено, пытаемся загрузить из директории движка
            string EngineThirdPartyPath = Path.Combine(Target.RelativeEnginePath, "Source/ThirdParty/");
            LoadAssimp(Target, EngineThirdPartyPath);
        }
    }

    private bool LoadAssimp(ReadOnlyTargetRules Target, string ThirdPartyPath)
    {
        // Путь к Assimp
        string AssimpPath = Path.Combine(ThirdPartyPath, "Assimp");
        string IncludePath = Path.Combine(AssimpPath, "include");

        // Проверка наличия файла в include директории
        if (!Directory.Exists(IncludePath))
        {
            return false; // Не найдено, вернем false, чтобы попробовать другой путь
        }

        PublicIncludePaths.Add(IncludePath);

        if (Target.Platform == UnrealTargetPlatform.Win64)
        {
            string LibraryPath = Path.Combine(AssimpPath, "lib", "Win64");
            string BinaryPath = Path.Combine(AssimpPath, "bin", "Win64");

            // Проверка наличия библиотек
            if (!File.Exists(Path.Combine(LibraryPath, "assimp-vc143-mt.lib")))
            {
                return false; // Не найдено, выходим
            }

            PublicAdditionalLibraries.Add(Path.Combine(LibraryPath, "assimp-vc143-mt.lib"));

            // PublicDelayLoadDLLs указывает, что мы будем загружать DLL вручную
            PublicDelayLoadDLLs.Add("assimp-vc143-mt.dll");

            // Указываем правильный путь для RuntimeDependencies, чтобы DLL копировалась в Binaries/Win64
            string PluginBinariesDir = Path.Combine(ModuleDirectory, "../../Binaries/Win64/");
            RuntimeDependencies.Add(Path.Combine(PluginBinariesDir, "assimp-vc143-mt.dll"), Path.Combine(BinaryPath, "assimp-vc143-mt.dll"));
        }

        return true; // Все успешно загружено
    }
}
*/

using UnrealBuildTool;
using System.IO;

public class FBXMeshImporter : ModuleRules
{
    public FBXMeshImporter(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] {
            "Core",
            "CoreUObject",
            "Engine",
            "RenderCore",
            "RHI",
            "MeshDescription",        
            "StaticMeshDescription",   
            "PhysicsCore"
        });

        PrivateDependencyModuleNames.AddRange(new string[]
        {
            "CoreUObject",
            "Slate",
            "SlateCore"
        });

        string ThirdPartyPath = Path.Combine(ModuleDirectory, "../../ThirdParty/");

        // Попытка загрузить Assimp в проекте
        if (!LoadAssimp(Target, ThirdPartyPath))
        {
            // Если не найдено, пытаемся загрузить из директории движка
            string EngineThirdPartyPath = Path.Combine(Target.RelativeEnginePath, "Source/ThirdParty/");
            LoadAssimp(Target, EngineThirdPartyPath);
        }
    }

    private bool LoadAssimp(ReadOnlyTargetRules Target, string ThirdPartyPath)
    {
        // Путь к Assimp
        string AssimpPath = Path.Combine(ThirdPartyPath, "Assimp");
        string IncludePath = Path.Combine(AssimpPath, "include");

        // Проверка наличия файла в include директории
        if (!Directory.Exists(IncludePath))
        {
            return false; // Не найдено, вернем false, чтобы попробовать другой путь
        }

        PublicIncludePaths.Add(IncludePath);

        if (Target.Platform == UnrealTargetPlatform.Win64)
        {
            string LibraryPath = Path.Combine(AssimpPath, "lib", "Win64");
            string BinaryPath = Path.Combine(AssimpPath, "bin", "Win64");

            // Проверка наличия библиотек
            string AssimpLib = Path.Combine(LibraryPath, "assimp-vc143-mt.lib");
            string AssimpDll = Path.Combine(BinaryPath, "assimp-vc143-mt.dll");

            if (!File.Exists(AssimpLib) || !File.Exists(AssimpDll))
            {
                System.Console.WriteLine("Assimp files not found: " + AssimpLib + " or " + AssimpDll);
                return false; // Не найдено, выходим
            }

            // Статическая библиотека для компиляции
            PublicAdditionalLibraries.Add(AssimpLib);

            // Указываем, что будем загружать DLL вручную
            PublicDelayLoadDLLs.Add("assimp-vc143-mt.dll");

            // Копирование DLL в корневую папку Binaries/Win64 проекта или билда
            string ProjectBinariesDir = Path.Combine(Path.GetDirectoryName(Target.ProjectFile.FullName), "Binaries", "Win64");
            string TargetDllPath = Path.Combine(ProjectBinariesDir, "assimp-vc143-mt.dll");

            // Добавляем зависимость для копирования DLL в Binaries/Win64 при сборке и упаковке
            RuntimeDependencies.Add(TargetDllPath, AssimpDll, StagedFileType.NonUFS);
        }

        return true; // Все успешно загружено
    }
}
