// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "../../../Source/FBXMeshImporter/Public/LoadedStaticMesh.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLoadedStaticMesh() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_UStaticMesh();
	ENGINE_API UClass* Z_Construct_UClass_UWorld_NoRegister();
	FBXMESHIMPORTER_API UClass* Z_Construct_UClass_ULoadedStaticMesh();
	FBXMESHIMPORTER_API UClass* Z_Construct_UClass_ULoadedStaticMesh_NoRegister();
	UPackage* Z_Construct_UPackage__Script_FBXMeshImporter();
// End Cross Module References
	void ULoadedStaticMesh::StaticRegisterNativesULoadedStaticMesh()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ULoadedStaticMesh);
	UClass* Z_Construct_UClass_ULoadedStaticMesh_NoRegister()
	{
		return ULoadedStaticMesh::StaticClass();
	}
	struct Z_Construct_UClass_ULoadedStaticMesh_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_World_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_World;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ULoadedStaticMesh_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UStaticMesh,
		(UObject* (*)())Z_Construct_UPackage__Script_FBXMeshImporter,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ULoadedStaticMesh_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULoadedStaticMesh_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Object" },
		{ "IncludePath", "LoadedStaticMesh.h" },
		{ "ModuleRelativePath", "Public/LoadedStaticMesh.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULoadedStaticMesh_Statics::NewProp_World_MetaData[] = {
		{ "ModuleRelativePath", "Public/LoadedStaticMesh.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ULoadedStaticMesh_Statics::NewProp_World = { "World", nullptr, (EPropertyFlags)0x0040000000002000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULoadedStaticMesh, World), Z_Construct_UClass_UWorld_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ULoadedStaticMesh_Statics::NewProp_World_MetaData), Z_Construct_UClass_ULoadedStaticMesh_Statics::NewProp_World_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ULoadedStaticMesh_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULoadedStaticMesh_Statics::NewProp_World,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ULoadedStaticMesh_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ULoadedStaticMesh>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ULoadedStaticMesh_Statics::ClassParams = {
		&ULoadedStaticMesh::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ULoadedStaticMesh_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ULoadedStaticMesh_Statics::PropPointers),
		0,
		0x009000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ULoadedStaticMesh_Statics::Class_MetaDataParams), Z_Construct_UClass_ULoadedStaticMesh_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ULoadedStaticMesh_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_ULoadedStaticMesh()
	{
		if (!Z_Registration_Info_UClass_ULoadedStaticMesh.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ULoadedStaticMesh.OuterSingleton, Z_Construct_UClass_ULoadedStaticMesh_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ULoadedStaticMesh.OuterSingleton;
	}
	template<> FBXMESHIMPORTER_API UClass* StaticClass<ULoadedStaticMesh>()
	{
		return ULoadedStaticMesh::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ULoadedStaticMesh);
	ULoadedStaticMesh::~ULoadedStaticMesh() {}
	struct Z_CompiledInDeferFile_FID_HostProject_Plugins_FBXMeshImporter_Source_FBXMeshImporter_Public_LoadedStaticMesh_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_FBXMeshImporter_Source_FBXMeshImporter_Public_LoadedStaticMesh_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ULoadedStaticMesh, ULoadedStaticMesh::StaticClass, TEXT("ULoadedStaticMesh"), &Z_Registration_Info_UClass_ULoadedStaticMesh, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ULoadedStaticMesh), 1775335712U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_FBXMeshImporter_Source_FBXMeshImporter_Public_LoadedStaticMesh_h_186381686(TEXT("/Script/FBXMeshImporter"),
		Z_CompiledInDeferFile_FID_HostProject_Plugins_FBXMeshImporter_Source_FBXMeshImporter_Public_LoadedStaticMesh_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_FBXMeshImporter_Source_FBXMeshImporter_Public_LoadedStaticMesh_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
