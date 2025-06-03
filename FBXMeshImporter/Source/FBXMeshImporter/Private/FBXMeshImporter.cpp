// Copyright Epic Games, Inc. All Rights Reserved.

#include "FBXMeshImporter.h"
#include "Engine/StaticMesh.h"
#include "UObject/UObjectGlobals.h"

#define LOCTEXT_NAMESPACE "FFBXMeshImporterModule"

void FFBXMeshImporterModule::StartupModule()
{
}

void FFBXMeshImporterModule::ShutdownModule()
{
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FFBXMeshImporterModule, FBXMeshImporter)