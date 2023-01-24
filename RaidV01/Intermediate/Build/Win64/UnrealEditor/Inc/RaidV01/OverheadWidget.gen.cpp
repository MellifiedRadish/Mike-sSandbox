// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "RaidV01/HUD/OverheadWidget.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOverheadWidget() {}
// Cross Module References
	RAIDV01_API UClass* Z_Construct_UClass_UOverheadWidget_NoRegister();
	RAIDV01_API UClass* Z_Construct_UClass_UOverheadWidget();
	UMG_API UClass* Z_Construct_UClass_UUserWidget();
	UPackage* Z_Construct_UPackage__Script_RaidV01();
	ENGINE_API UClass* Z_Construct_UClass_APawn_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UTextBlock_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(UOverheadWidget::execShowPlayerNetRole)
	{
		P_GET_OBJECT(APawn,Z_Param_InPawn);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ShowPlayerNetRole(Z_Param_InPawn);
		P_NATIVE_END;
	}
	void UOverheadWidget::StaticRegisterNativesUOverheadWidget()
	{
		UClass* Class = UOverheadWidget::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "ShowPlayerNetRole", &UOverheadWidget::execShowPlayerNetRole },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UOverheadWidget_ShowPlayerNetRole_Statics
	{
		struct OverheadWidget_eventShowPlayerNetRole_Parms
		{
			APawn* InPawn;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_InPawn;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOverheadWidget_ShowPlayerNetRole_Statics::NewProp_InPawn = { "InPawn", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OverheadWidget_eventShowPlayerNetRole_Parms, InPawn), Z_Construct_UClass_APawn_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOverheadWidget_ShowPlayerNetRole_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOverheadWidget_ShowPlayerNetRole_Statics::NewProp_InPawn,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOverheadWidget_ShowPlayerNetRole_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "HUD/OverheadWidget.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOverheadWidget_ShowPlayerNetRole_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOverheadWidget, nullptr, "ShowPlayerNetRole", nullptr, nullptr, sizeof(Z_Construct_UFunction_UOverheadWidget_ShowPlayerNetRole_Statics::OverheadWidget_eventShowPlayerNetRole_Parms), Z_Construct_UFunction_UOverheadWidget_ShowPlayerNetRole_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOverheadWidget_ShowPlayerNetRole_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UOverheadWidget_ShowPlayerNetRole_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UOverheadWidget_ShowPlayerNetRole_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UOverheadWidget_ShowPlayerNetRole()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOverheadWidget_ShowPlayerNetRole_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UOverheadWidget);
	UClass* Z_Construct_UClass_UOverheadWidget_NoRegister()
	{
		return UOverheadWidget::StaticClass();
	}
	struct Z_Construct_UClass_UOverheadWidget_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DisplayText_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_DisplayText;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UOverheadWidget_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UUserWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_RaidV01,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UOverheadWidget_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UOverheadWidget_ShowPlayerNetRole, "ShowPlayerNetRole" }, // 4287308565
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOverheadWidget_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n *\n */" },
		{ "IncludePath", "HUD/OverheadWidget.h" },
		{ "ModuleRelativePath", "HUD/OverheadWidget.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOverheadWidget_Statics::NewProp_DisplayText_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "HUD/OverheadWidget.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UOverheadWidget_Statics::NewProp_DisplayText = { "DisplayText", nullptr, (EPropertyFlags)0x0010000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UOverheadWidget, DisplayText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UOverheadWidget_Statics::NewProp_DisplayText_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UOverheadWidget_Statics::NewProp_DisplayText_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UOverheadWidget_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOverheadWidget_Statics::NewProp_DisplayText,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UOverheadWidget_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UOverheadWidget>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UOverheadWidget_Statics::ClassParams = {
		&UOverheadWidget::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UOverheadWidget_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UOverheadWidget_Statics::PropPointers),
		0,
		0x00B010A0u,
		METADATA_PARAMS(Z_Construct_UClass_UOverheadWidget_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UOverheadWidget_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UOverheadWidget()
	{
		if (!Z_Registration_Info_UClass_UOverheadWidget.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UOverheadWidget.OuterSingleton, Z_Construct_UClass_UOverheadWidget_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UOverheadWidget.OuterSingleton;
	}
	template<> RAIDV01_API UClass* StaticClass<UOverheadWidget>()
	{
		return UOverheadWidget::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UOverheadWidget);
	struct Z_CompiledInDeferFile_FID_RaidV01_Source_RaidV01_HUD_OverheadWidget_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_RaidV01_Source_RaidV01_HUD_OverheadWidget_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UOverheadWidget, UOverheadWidget::StaticClass, TEXT("UOverheadWidget"), &Z_Registration_Info_UClass_UOverheadWidget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UOverheadWidget), 2621156809U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_RaidV01_Source_RaidV01_HUD_OverheadWidget_h_984279459(TEXT("/Script/RaidV01"),
		Z_CompiledInDeferFile_FID_RaidV01_Source_RaidV01_HUD_OverheadWidget_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_RaidV01_Source_RaidV01_HUD_OverheadWidget_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
