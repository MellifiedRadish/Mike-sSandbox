// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "RaidV01/RaidComponents/CombatComponents.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCombatComponents() {}
// Cross Module References
	RAIDV01_API UClass* Z_Construct_UClass_UCombatComponents_NoRegister();
	RAIDV01_API UClass* Z_Construct_UClass_UCombatComponents();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	UPackage* Z_Construct_UPackage__Script_RaidV01();
// End Cross Module References
	void UCombatComponents::StaticRegisterNativesUCombatComponents()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UCombatComponents);
	UClass* Z_Construct_UClass_UCombatComponents_NoRegister()
	{
		return UCombatComponents::StaticClass();
	}
	struct Z_Construct_UClass_UCombatComponents_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UCombatComponents_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_RaidV01,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCombatComponents_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "RaidComponents/CombatComponents.h" },
		{ "ModuleRelativePath", "RaidComponents/CombatComponents.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UCombatComponents_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCombatComponents>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UCombatComponents_Statics::ClassParams = {
		&UCombatComponents::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x00B000A4u,
		METADATA_PARAMS(Z_Construct_UClass_UCombatComponents_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UCombatComponents_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UCombatComponents()
	{
		if (!Z_Registration_Info_UClass_UCombatComponents.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCombatComponents.OuterSingleton, Z_Construct_UClass_UCombatComponents_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UCombatComponents.OuterSingleton;
	}
	template<> RAIDV01_API UClass* StaticClass<UCombatComponents>()
	{
		return UCombatComponents::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UCombatComponents);
	struct Z_CompiledInDeferFile_FID_RaidV01_Source_RaidV01_RaidComponents_CombatComponents_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_RaidV01_Source_RaidV01_RaidComponents_CombatComponents_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UCombatComponents, UCombatComponents::StaticClass, TEXT("UCombatComponents"), &Z_Registration_Info_UClass_UCombatComponents, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCombatComponents), 3350293622U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_RaidV01_Source_RaidV01_RaidComponents_CombatComponents_h_2146842123(TEXT("/Script/RaidV01"),
		Z_CompiledInDeferFile_FID_RaidV01_Source_RaidV01_RaidComponents_CombatComponents_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_RaidV01_Source_RaidV01_RaidComponents_CombatComponents_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
