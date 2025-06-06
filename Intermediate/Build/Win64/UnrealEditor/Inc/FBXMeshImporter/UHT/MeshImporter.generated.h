// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "MeshImporter.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UStaticMesh;
#ifdef FBXMESHIMPORTER_MeshImporter_generated_h
#error "MeshImporter.generated.h already included, missing '#pragma once' in MeshImporter.h"
#endif
#define FBXMESHIMPORTER_MeshImporter_generated_h

#define FID_HostProject_Plugins_FBXMeshImporter_Source_FBXMeshImporter_Public_MeshImporter_h_10_SPARSE_DATA
#define FID_HostProject_Plugins_FBXMeshImporter_Source_FBXMeshImporter_Public_MeshImporter_h_10_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_HostProject_Plugins_FBXMeshImporter_Source_FBXMeshImporter_Public_MeshImporter_h_10_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_HostProject_Plugins_FBXMeshImporter_Source_FBXMeshImporter_Public_MeshImporter_h_10_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execLoadStaticMeshFromFile);


#define FID_HostProject_Plugins_FBXMeshImporter_Source_FBXMeshImporter_Public_MeshImporter_h_10_ACCESSORS
#define FID_HostProject_Plugins_FBXMeshImporter_Source_FBXMeshImporter_Public_MeshImporter_h_10_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUMeshImporter(); \
	friend struct Z_Construct_UClass_UMeshImporter_Statics; \
public: \
	DECLARE_CLASS(UMeshImporter, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/FBXMeshImporter"), NO_API) \
	DECLARE_SERIALIZER(UMeshImporter)


#define FID_HostProject_Plugins_FBXMeshImporter_Source_FBXMeshImporter_Public_MeshImporter_h_10_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UMeshImporter(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UMeshImporter(UMeshImporter&&); \
	NO_API UMeshImporter(const UMeshImporter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMeshImporter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMeshImporter); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UMeshImporter) \
	NO_API virtual ~UMeshImporter();


#define FID_HostProject_Plugins_FBXMeshImporter_Source_FBXMeshImporter_Public_MeshImporter_h_7_PROLOG
#define FID_HostProject_Plugins_FBXMeshImporter_Source_FBXMeshImporter_Public_MeshImporter_h_10_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_HostProject_Plugins_FBXMeshImporter_Source_FBXMeshImporter_Public_MeshImporter_h_10_SPARSE_DATA \
	FID_HostProject_Plugins_FBXMeshImporter_Source_FBXMeshImporter_Public_MeshImporter_h_10_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_HostProject_Plugins_FBXMeshImporter_Source_FBXMeshImporter_Public_MeshImporter_h_10_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_HostProject_Plugins_FBXMeshImporter_Source_FBXMeshImporter_Public_MeshImporter_h_10_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_HostProject_Plugins_FBXMeshImporter_Source_FBXMeshImporter_Public_MeshImporter_h_10_ACCESSORS \
	FID_HostProject_Plugins_FBXMeshImporter_Source_FBXMeshImporter_Public_MeshImporter_h_10_INCLASS_NO_PURE_DECLS \
	FID_HostProject_Plugins_FBXMeshImporter_Source_FBXMeshImporter_Public_MeshImporter_h_10_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> FBXMESHIMPORTER_API UClass* StaticClass<class UMeshImporter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_HostProject_Plugins_FBXMeshImporter_Source_FBXMeshImporter_Public_MeshImporter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
