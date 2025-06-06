// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "../../../Source/FBXMeshImporter/Public/MeshImporter.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMeshImporter() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMesh_NoRegister();
	FBXMESHIMPORTER_API UClass* Z_Construct_UClass_UMeshImporter();
	FBXMESHIMPORTER_API UClass* Z_Construct_UClass_UMeshImporter_NoRegister();
	UPackage* Z_Construct_UPackage__Script_FBXMeshImporter();
// End Cross Module References
	DEFINE_FUNCTION(UMeshImporter::execLoadStaticMeshFromFile)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_FilePath);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UStaticMesh**)Z_Param__Result=UMeshImporter::LoadStaticMeshFromFile(Z_Param_FilePath);
		P_NATIVE_END;
	}
	void UMeshImporter::StaticRegisterNativesUMeshImporter()
	{
		UClass* Class = UMeshImporter::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "LoadStaticMeshFromFile", &UMeshImporter::execLoadStaticMeshFromFile },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UMeshImporter_LoadStaticMeshFromFile_Statics
	{
		struct MeshImporter_eventLoadStaticMeshFromFile_Parms
		{
			FString FilePath;
			UStaticMesh* ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FilePath_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_FilePath;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMeshImporter_LoadStaticMeshFromFile_Statics::NewProp_FilePath_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UMeshImporter_LoadStaticMeshFromFile_Statics::NewProp_FilePath = { "FilePath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MeshImporter_eventLoadStaticMeshFromFile_Parms, FilePath), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMeshImporter_LoadStaticMeshFromFile_Statics::NewProp_FilePath_MetaData), Z_Construct_UFunction_UMeshImporter_LoadStaticMeshFromFile_Statics::NewProp_FilePath_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UMeshImporter_LoadStaticMeshFromFile_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MeshImporter_eventLoadStaticMeshFromFile_Parms, ReturnValue), Z_Construct_UClass_UStaticMesh_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMeshImporter_LoadStaticMeshFromFile_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshImporter_LoadStaticMeshFromFile_Statics::NewProp_FilePath,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMeshImporter_LoadStaticMeshFromFile_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMeshImporter_LoadStaticMeshFromFile_Statics::Function_MetaDataParams[] = {
		{ "Category", "Mesh Import" },
		{ "ModuleRelativePath", "Public/MeshImporter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMeshImporter_LoadStaticMeshFromFile_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMeshImporter, nullptr, "LoadStaticMeshFromFile", nullptr, nullptr, Z_Construct_UFunction_UMeshImporter_LoadStaticMeshFromFile_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMeshImporter_LoadStaticMeshFromFile_Statics::PropPointers), sizeof(Z_Construct_UFunction_UMeshImporter_LoadStaticMeshFromFile_Statics::MeshImporter_eventLoadStaticMeshFromFile_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMeshImporter_LoadStaticMeshFromFile_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMeshImporter_LoadStaticMeshFromFile_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UMeshImporter_LoadStaticMeshFromFile_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UMeshImporter_LoadStaticMeshFromFile_Statics::MeshImporter_eventLoadStaticMeshFromFile_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UMeshImporter_LoadStaticMeshFromFile()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMeshImporter_LoadStaticMeshFromFile_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UMeshImporter);
	UClass* Z_Construct_UClass_UMeshImporter_NoRegister()
	{
		return UMeshImporter::StaticClass();
	}
	struct Z_Construct_UClass_UMeshImporter_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UMeshImporter_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_FBXMeshImporter,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMeshImporter_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UMeshImporter_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UMeshImporter_LoadStaticMeshFromFile, "LoadStaticMeshFromFile" }, // 482528009
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMeshImporter_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMeshImporter_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "MeshImporter.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/MeshImporter.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UMeshImporter_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMeshImporter>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UMeshImporter_Statics::ClassParams = {
		&UMeshImporter::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x001000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMeshImporter_Statics::Class_MetaDataParams), Z_Construct_UClass_UMeshImporter_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UMeshImporter()
	{
		if (!Z_Registration_Info_UClass_UMeshImporter.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMeshImporter.OuterSingleton, Z_Construct_UClass_UMeshImporter_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UMeshImporter.OuterSingleton;
	}
	template<> FBXMESHIMPORTER_API UClass* StaticClass<UMeshImporter>()
	{
		return UMeshImporter::StaticClass();
	}
	UMeshImporter::UMeshImporter(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UMeshImporter);
	UMeshImporter::~UMeshImporter() {}
	struct Z_CompiledInDeferFile_FID_HostProject_Plugins_FBXMeshImporter_Source_FBXMeshImporter_Public_MeshImporter_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_FBXMeshImporter_Source_FBXMeshImporter_Public_MeshImporter_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UMeshImporter, UMeshImporter::StaticClass, TEXT("UMeshImporter"), &Z_Registration_Info_UClass_UMeshImporter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMeshImporter), 318685951U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_FBXMeshImporter_Source_FBXMeshImporter_Public_MeshImporter_h_2617400751(TEXT("/Script/FBXMeshImporter"),
		Z_CompiledInDeferFile_FID_HostProject_Plugins_FBXMeshImporter_Source_FBXMeshImporter_Public_MeshImporter_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_FBXMeshImporter_Source_FBXMeshImporter_Public_MeshImporter_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
