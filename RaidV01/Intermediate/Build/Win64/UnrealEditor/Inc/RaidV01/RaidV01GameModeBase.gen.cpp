// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "RaidV01/RaidV01GameModeBase.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRaidV01GameModeBase() {}
// Cross Module References
	RAIDV01_API UClass* Z_Construct_UClass_ARaidV01GameModeBase_NoRegister();
	RAIDV01_API UClass* Z_Construct_UClass_ARaidV01GameModeBase();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_RaidV01();
// End Cross Module References
	void ARaidV01GameModeBase::StaticRegisterNativesARaidV01GameModeBase()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ARaidV01GameModeBase);
	UClass* Z_Construct_UClass_ARaidV01GameModeBase_NoRegister()
	{
		return ARaidV01GameModeBase::StaticClass();
	}
	struct Z_Construct_UClass_ARaidV01GameModeBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ARaidV01GameModeBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_RaidV01,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ARaidV01GameModeBase_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "RaidV01GameModeBase.h" },
		{ "ModuleRelativePath", "RaidV01GameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ARaidV01GameModeBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ARaidV01GameModeBase>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ARaidV01GameModeBase_Statics::ClassParams = {
		&ARaidV01GameModeBase::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009002ACu,
		METADATA_PARAMS(Z_Construct_UClass_ARaidV01GameModeBase_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ARaidV01GameModeBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ARaidV01GameModeBase()
	{
		if (!Z_Registration_Info_UClass_ARaidV01GameModeBase.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ARaidV01GameModeBase.OuterSingleton, Z_Construct_UClass_ARaidV01GameModeBase_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ARaidV01GameModeBase.OuterSingleton;
	}
	template<> RAIDV01_API UClass* StaticClass<ARaidV01GameModeBase>()
	{
		return ARaidV01GameModeBase::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ARaidV01GameModeBase);
	struct Z_CompiledInDeferFile_FID_RaidV01_Source_RaidV01_RaidV01GameModeBase_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_RaidV01_Source_RaidV01_RaidV01GameModeBase_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ARaidV01GameModeBase, ARaidV01GameModeBase::StaticClass, TEXT("ARaidV01GameModeBase"), &Z_Registration_Info_UClass_ARaidV01GameModeBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ARaidV01GameModeBase), 1140509569U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_RaidV01_Source_RaidV01_RaidV01GameModeBase_h_441409164(TEXT("/Script/RaidV01"),
		Z_CompiledInDeferFile_FID_RaidV01_Source_RaidV01_RaidV01GameModeBase_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_RaidV01_Source_RaidV01_RaidV01GameModeBase_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
