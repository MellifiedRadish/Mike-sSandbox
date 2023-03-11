// Fill out your copyright notice in the Description page of Project Settings.


#include "RaidAnimInstance.h"
#include "RaidCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"

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
	bAiming = RaidCharacter->IsAiming();

	FRotator AimRotation = RaidCharacter->GetBaseAimRotation();
	FRotator MovementRotation = UKismetMathLibrary::MakeRotFromX(RaidCharacter->GetVelocity());
	FRotator DeltaRot = UKismetMathLibrary::NormalizedDeltaRotator(MovementRotation, AimRotation);
	DeltaRotation = FMath::RInterpTo(DeltaRotation, DeltaRot, DeltaTime, 6.f);
	YawOffset = DeltaRotation.Yaw;
	//YawOffset = UKismetMathLibrary::NormalizedDeltaRotator(MovementRotation, AimRotation).Yaw;
}
