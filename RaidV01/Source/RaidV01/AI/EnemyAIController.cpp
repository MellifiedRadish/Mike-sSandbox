// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAIController.h"

#include "RaidV01/Character/RaidCharacter.h"

AEnemyAIController::AEnemyAIController() {
	PawnSensingComponent = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("PawnSensingComponent"));
}

void AEnemyAIController::BeginPlay() {
	Super::BeginPlay();

	// bind our OnSeePawn function to the function of the PawnSensing component
	PawnSensingComponent->OnSeePawn.AddDynamic(this, &AEnemyAIController::OnSeePawn);

	RunBehaviorTree(BehaviorTree);
}

void AEnemyAIController::OnSeePawn(APawn* PlayerPawn) {
	ARaidCharacter* Player = Cast<ARaidCharacter>(PlayerPawn);

	if (Player) {
		SetHasPlayerLOS(true, Player);
		RunRetriggerableTimer();
	}
}

void AEnemyAIController::SetHasPlayerLOS(bool SeePlayer, UObject* Player) {
	if (SeePlayer) {
		GetBlackboardComponent()->SetValueAsBool(FName("HasPlayerLOS"), SeePlayer);
		GetBlackboardComponent()->SetValueAsObject(FName("EnemyActor"), Player);
	} else {
		GetBlackboardComponent()->SetValueAsBool(FName("HasPlayerLOS"), SeePlayer);

		ACharacter* EnemyChar = Cast<ACharacter>(GetPawn());
		EnemyChar->GetMesh()->GetAnimInstance()->StopAllMontages(0);
	}
}

void AEnemyAIController::RunRetriggerableTimer() {
	GetWorld()->GetTimerManager().ClearTimer(RetriggerableTimerHandle);

	FunctionDelegate.BindUFunction(this, FName("SetHasPlayerLOS"), false, GetPawn());

	GetWorld()->GetTimerManager().SetTimer(RetriggerableTimerHandle, FunctionDelegate, PawnSensingComponent->SensingInterval * 20.f, false);
}
