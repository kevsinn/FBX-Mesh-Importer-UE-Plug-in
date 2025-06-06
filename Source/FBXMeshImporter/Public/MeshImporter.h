#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MeshImporter.generated.h"

UCLASS(Blueprintable)
class FBXMESHIMPORTER_API UMeshImporter : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Mesh Import")
	static UStaticMesh* LoadStaticMeshFromFile(const FString& FilePath);
};