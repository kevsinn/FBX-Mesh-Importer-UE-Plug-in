#include "LoadedStaticMesh.h"

ULoadedStaticMesh::ULoadedStaticMesh(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	bAllowCPUAccess = true;
}

UWorld* ULoadedStaticMesh::GetWorld() const
{
	return World ? World : Super::GetWorld();
}

void ULoadedStaticMesh::SetWorld(UWorld* InWorld)
{
	World = InWorld;
}