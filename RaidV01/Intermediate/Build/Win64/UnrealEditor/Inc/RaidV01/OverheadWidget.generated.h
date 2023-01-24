// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class APawn;
#ifdef RAIDV01_OverheadWidget_generated_h
#error "OverheadWidget.generated.h already included, missing '#pragma once' in OverheadWidget.h"
#endif
#define RAIDV01_OverheadWidget_generated_h

#define FID_RaidV01_Source_RaidV01_HUD_OverheadWidget_h_15_SPARSE_DATA
#define FID_RaidV01_Source_RaidV01_HUD_OverheadWidget_h_15_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execShowPlayerNetRole);


#define FID_RaidV01_Source_RaidV01_HUD_OverheadWidget_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execShowPlayerNetRole);


#define FID_RaidV01_Source_RaidV01_HUD_OverheadWidget_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUOverheadWidget(); \
	friend struct Z_Construct_UClass_UOverheadWidget_Statics; \
public: \
	DECLARE_CLASS(UOverheadWidget, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/RaidV01"), NO_API) \
	DECLARE_SERIALIZER(UOverheadWidget)


#define FID_RaidV01_Source_RaidV01_HUD_OverheadWidget_h_15_INCLASS \
private: \
	static void StaticRegisterNativesUOverheadWidget(); \
	friend struct Z_Construct_UClass_UOverheadWidget_Statics; \
public: \
	DECLARE_CLASS(UOverheadWidget, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/RaidV01"), NO_API) \
	DECLARE_SERIALIZER(UOverheadWidget)


#define FID_RaidV01_Source_RaidV01_HUD_OverheadWidget_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UOverheadWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UOverheadWidget) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UOverheadWidget); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UOverheadWidget); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UOverheadWidget(UOverheadWidget&&); \
	NO_API UOverheadWidget(const UOverheadWidget&); \
public:


#define FID_RaidV01_Source_RaidV01_HUD_OverheadWidget_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UOverheadWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UOverheadWidget(UOverheadWidget&&); \
	NO_API UOverheadWidget(const UOverheadWidget&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UOverheadWidget); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UOverheadWidget); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UOverheadWidget)


#define FID_RaidV01_Source_RaidV01_HUD_OverheadWidget_h_12_PROLOG
#define FID_RaidV01_Source_RaidV01_HUD_OverheadWidget_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_RaidV01_Source_RaidV01_HUD_OverheadWidget_h_15_SPARSE_DATA \
	FID_RaidV01_Source_RaidV01_HUD_OverheadWidget_h_15_RPC_WRAPPERS \
	FID_RaidV01_Source_RaidV01_HUD_OverheadWidget_h_15_INCLASS \
	FID_RaidV01_Source_RaidV01_HUD_OverheadWidget_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_RaidV01_Source_RaidV01_HUD_OverheadWidget_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_RaidV01_Source_RaidV01_HUD_OverheadWidget_h_15_SPARSE_DATA \
	FID_RaidV01_Source_RaidV01_HUD_OverheadWidget_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_RaidV01_Source_RaidV01_HUD_OverheadWidget_h_15_INCLASS_NO_PURE_DECLS \
	FID_RaidV01_Source_RaidV01_HUD_OverheadWidget_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> RAIDV01_API UClass* StaticClass<class UOverheadWidget>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_RaidV01_Source_RaidV01_HUD_OverheadWidget_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
