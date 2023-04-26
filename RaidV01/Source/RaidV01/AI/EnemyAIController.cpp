// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAIController.h"

#include "RaidV01/Character/RaidCharacter.h"

AEnemyAIController::AEnemyAIController() {
}

void AEnemyAIController::BeginPlay() {
	Super::BeginPlay();

	RunBehaviorTree(BehaviorTree);
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
