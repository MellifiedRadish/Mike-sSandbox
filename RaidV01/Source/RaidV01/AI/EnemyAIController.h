// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "Perception/PawnSensingComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/Character.h"
#include "EnemyAIController.generated.h"

/**
 * 
 */
UCLASS()
class RAIDV01_API AEnemyAIController : public AAIController
{
	GENERATED_BODY()

public:

	AEnemyAIController();

	void BeginPlay() override;

	UFUNCTION()
	void OnSeePawn(APawn* PlayerPawn);

	UFUNCTION()
	void SetHasPlayerLOS(bool SeePlayer, class UObject* Player);

	void RunRetriggerableTimer();

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UBehaviorTree* BehaviorTree;

	UPROPERTY(EditAnywhere)
	class UPawnSensingComponent* PawnSensingComponent;

	FTimerHandle RetriggerableTimerHandle;
	FTimerDelegate FunctionDelegate;	
};
