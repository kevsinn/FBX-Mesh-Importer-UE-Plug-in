#pragma once
#include "CoreMinimal.h"
#include "Engine/StaticMesh.h"
#include "LoadedStaticMesh.generated.h"

UCLASS()
class FBXMESHIMPORTER_API ULoadedStaticMesh : public UStaticMesh
{
	GENERATED_BODY()

public:
	ULoadedStaticMesh(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
	virtual UWorld* GetWorld() const override;
	void SetWorld(UWorld* InWorld);

private:
	UPROPERTY(Transient)
	UWorld* World = nullptr;
};