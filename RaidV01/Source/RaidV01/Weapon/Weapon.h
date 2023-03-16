// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Weapon.generated.h"


UENUM(BlueprintType)
enum class EWeaponState : uint8
{
	EWS_Initial UMETA(DisplayName = "Initial State"),
	EWS_Equipped UMETA(DisplayName = "Equipped"),
	EWS_Dropped UMETA(DisplayName = "Dropped"),

	EWS_MAX UMETA(DisplayName = "DefaultMAX")
};

UENUM(BlueprintType)
enum class EWeaponFiringMode : uint8
{
	Semi UMETA(DisplayName = "Semi-Auto"),
	Auto UMETA(DisplayName = "Automatic"),
	Burst UMETA(DisplayName = "Burst")
};

UCLASS()
class RAIDV01_API AWeapon : public AActor
{
	GENERATED_BODY()

public:
	AWeapon();
	virtual void Tick(float DeltaTime) override;
	EWeaponFiringMode GetFiringMode() const;
	int GetRoundsPerMinute() const;
	int GetRoundsPerBurst() const;
	void SetTimeLastFired(float Time);
	float GetTimeLastFired() const;
	bool ReadyToFire() const;
	bool ReadyToStartBurst() const;
	void SetTimeLastBursted(float Time);
protected:
	virtual void BeginPlay() override;
	UFUNCTION()
		virtual void OnSphereOverlap(
			UPrimitiveComponent* OverlappedComponent,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex,
			bool bFromSweep,
			const FHitResult& SweepResult
		);

	UFUNCTION()
		void OnSphereEndOverLap(
			UPrimitiveComponent* OverlappedComponent,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex
		);

private:
	UPROPERTY(VisibleAnywhere, Category = "Weapon Properties")
		USkeletalMeshComponent* WeaponMesh;

	UPROPERTY(VisibleAnywhere, Category = "Weapon Properties")
		class USphereComponent* AreaSphere;

	UPROPERTY(VisibleAnywhere, Category = "Weapon Properties")
		EWeaponState WeaponState;

	UPROPERTY(VisibleAnywhere, Category = "Weapon Properties")
		class UWidgetComponent* PickupWidget;

	UPROPERTY(EditAnywhere, Category = "Weapon Properties")
		EWeaponFiringMode FiringMode;

	// The rounds per minute the weapon can fire. Auto and burst will fire at this rate. Semi cannot exceed this rate.
	UPROPERTY(EditAnywhere, Category = "Weapon Properties")
	int RoundsPerMinute;
	UPROPERTY(EditAnywhere, Category = "Weapon Properties")
	int RoundsPerBurst;
	UPROPERTY(EditAnywhere, Category = "Weapon Properties")
	float SecondsBetweenBursts;
	
	float TimeLastFired;
	float TimeLastBursted;
	
public:

	FORCEINLINE void SetWeaponState(EWeaponState State) { WeaponState = State; }

};