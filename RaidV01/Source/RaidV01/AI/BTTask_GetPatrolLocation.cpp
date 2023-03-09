// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_GetPatrolLocation.h"

#include "EnemyAIController.h"

EBTNodeResult::Type UBTTask_GetPatrolLocation::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) {
	AEnemyAIController* ThisController = Cast<AEnemyAIController>(OwnerComp.GetAIOwner());
	if (ThisController == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	UNavigationSystemV1* NavArea = UNavigationSystemV1::GetNavigationSystem(ThisController);
	FVector RandomLocation{0, 0, 0};

	if (NavArea) {
		NavArea->K2_GetRandomReachablePointInRadius(GetWorld(),
			GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation(),
			RandomLocation, 15000.f);	// random location within 15000 units of player
	} else {
		return EBTNodeResult::Failed;
	}

	OwnerComp.GetBlackboardComponent()->SetValueAsVector(FName("PatrolLocation"), RandomLocation);

	return EBTNodeResult::Succeeded;
}
