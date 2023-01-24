// Fill out your copyright notice in the Description page of Project Settings.


#include "RaidAnimInstance.h"
#include "RaidCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

void URaidAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	RaidCharacter = Cast<ARaidCharacter>(TryGetPawnOwner());
}
void URaidAnimInstance::NativeUpdateAnimation(float DeltaTime)
{
	Super::NativeUpdateAnimation(DeltaTime);

	if (RaidCharacter == nullptr) {
		RaidCharacter = Cast<ARaidCharacter>(TryGetPawnOwner());
	}

	if (RaidCharacter == nullptr) {
		return;
	}

	FVector Velocity = RaidCharacter->GetVelocity();
	Velocity.Z = 0.f;
	Speed = Velocity.Size();

	bIsInAir = RaidCharacter->GetCharacterMovement()->IsFalling();

	bIsAccelerating = RaidCharacter->GetCharacterMovement()->GetCurrentAcceleration().Size() > 0.f ? true : false; //Ternary Expression if greater than 0 its true else set to false.
}
