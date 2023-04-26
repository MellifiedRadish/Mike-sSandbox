// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "RaidV01/Weapon/Weapon.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraSystem.h"
#include "NiagaraComponent.h"
#include "RaidCharacter.generated.h"

UCLASS()

class RAIDV01_API ARaidCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ARaidCharacter();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	virtual float TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;
	virtual void SetRagdoll();
	UFUNCTION(BlueprintCallable, Category = "Weapon")
	void EquipWeapon(AWeapon* Weapon);
	AWeapon* GetWeapon() const;
	bool IsAiming();
	//virtual void PostInitilizeComponents() override;

protected:
	virtual void BeginPlay() override;

	void MoveForward(float Value);
	void MoveRight(float Value);
	void Turn(float Value);
	void LookUp(float Value);
	void EquipButtonPressed();
	void EndGamePressed();
	void OnFireDown();
	void OnFireUp();
	void StartBurst();
	void ExecuteBurst();
	void EndBurst();
	void RequestFire();
	void ShootRay();
	void AimButtonPressed();
	void AimButtonReleased();

private: 
	UPROPERTY(VisibleAnywhere, Category = Camera)
	class USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, Category = Camera)
	class UCameraComponent* FollowCamera;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Asset References", meta = (AllowPrivateAccess = "true"))
	UNiagaraSystem* HitParticles;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Asset References", meta = (AllowPrivateAccess = "true"))
	USoundBase* ShootSounds;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Asset References", meta = (AllowPrivateAccess = "true"))
	USoundBase* ShootSkeletonSounds;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Asset References", meta = (AllowPrivateAccess = "true"))
	USoundBase* ShootHurtSounds;

	//UPROPERTY(VisibleAnywhere)
	//class UCombatComponent* Combat;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = General, meta = (AllowPrivateAccess = "true"))
	int32 Health;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = General, meta = (AllowPrivateAccess = "true"))
	int32 MaxHealth;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = General, meta = (AllowPrivateAccess = "true"))
	bool bAiming;

	UPROPERTY(VisibleAnywhere, Category = "Weapon")
	bool bFireIsDown;

	UPROPERTY(VisibleAnywhere, Category = "Weapon")
	bool bWasFiringLastFrame;

	UPROPERTY(VisibleAnywhere, Category = "Weapon")
	AWeapon* EquippedWeapon;

	bool bIsBursting;
	int RoundsFiredThisBurst;

public:	
	

};
