// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "RaidCharacter.generated.h"

UCLASS()

class RAIDV01_API ARaidCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ARaidCharacter();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	//virtual void PostInitilizeComponents() override;

protected:
	virtual void BeginPlay() override;

	void MoveForward(float Value);
	void MoveRight(float Value);
	void Turn(float Value);
	void LookUp(float Value);
	void EquipButtonPressed();
	void ShootRay();

private: 
	UPROPERTY(VisibleAnywhere, Category = Camera)
	class USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, Category = Camera)
	class UCameraComponent* FollowCamera;

	//UPROPERTY(VisibleAnywhere)
	//class UCombatComponent* Combat;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = General, meta = (AllowPrivateAccess = "true"))
	int32 Health;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = General, meta = (AllowPrivateAccess = "true"))
	int32 MaxHealth;

public:	
	

};
