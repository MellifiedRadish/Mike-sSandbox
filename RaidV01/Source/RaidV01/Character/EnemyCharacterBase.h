// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnemyCharacterBase.generated.h"

class USoundCue;

UCLASS(Abstract)
class RAIDV01_API AEnemyCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemyCharacterBase();

	UFUNCTION(BlueprintCallable, Category = "PlayerCondition")
	bool IsAlive() const;

	UFUNCTION()
	void OnSeePawn(APawn* PlayerPawn);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, class AActor* DamageCauser) override;

	virtual bool CanDie(float KillingDamage, FDamageEvent const& DamageEvent, AController* Killer, AActor* DamageCauser) const;

	virtual bool Die(float KillingDamage, FDamageEvent const& DamageEvent, AController* Killer, AActor* DamageCauser);

	virtual void OnDeath(float KillingDamage, FDamageEvent const& DamageEvent, APawn* PawnInstigator, AActor* DamageCauser);

	UFUNCTION(BlueprintCallable, Category = "Attacking")
	virtual void PerformAttack(AActor* HitActor);

	virtual void PlaySound(float DamageTaken, struct FDamageEvent const& DamageEvent, APawn* PawnInstigator, AActor* DamageCauser, bool isKilled);

	virtual void SetRagdoll();

private:

	bool IsDying;

	bool SensedTarget;

	float LastSeenTime;

	float LastAttackTime;

public:

	UPROPERTY(EditDefaultsOnly, Category = "AI")
	int32 Health;

	UPROPERTY(EditDefaultsOnly, Category = "AI")
	int32 MaxHealth;

	UPROPERTY(EditDefaultsOnly, Category = "AI")
	float SenseTimeout;

	UPROPERTY(EditDefaultsOnly, Category = "Attacking")
	float AttackTimeout;

	UPROPERTY(EditDefaultsOnly, Category = "Attacking")
	float MeleeDamage;

	UPROPERTY(EditDefaultsOnly, Category = "Attacking")
	UAnimMontage* AnimMontage;

	UPROPERTY(EditDefaultsOnly, Category = "Sound")
	USoundCue* SoundHurt;

	UPROPERTY(EditDefaultsOnly, Category = "Sound")
	USoundCue* SoundDeath;

	UPROPERTY(EditAnywhere)
	class UPawnSensingComponent* PawnSensingComponent;

};
