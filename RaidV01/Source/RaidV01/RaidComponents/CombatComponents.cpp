// Fill out your copyright notice in the Description page of Project Settings.


#include "CombatComponents.h"


UCombatComponents::UCombatComponents()
{
	
	PrimaryComponentTick.bCanEverTick = false;

	
}



void UCombatComponents::BeginPlay()
{
	Super::BeginPlay();

	
	
}



void UCombatComponents::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	
}

