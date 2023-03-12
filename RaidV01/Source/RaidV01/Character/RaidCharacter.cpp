// Fill out your copyright notice in the Description page of Project Settings.


#include "RaidCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"	
#include "GameFramework/CharacterMovementComponent.h"
#include "RaidV01/RaidComponents/CombatComponent.h"
#include "Kismet/GameplayStatics.h"
#include "EnemyCharacterBase.h"

// Sets default values
ARaidCharacter::ARaidCharacter() : Health(75), MaxHealth(100)
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(GetMesh());
	CameraBoom->TargetArmLength = 600.f;
	CameraBoom->bUsePawnControlRotation = true;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;

	bUseControllerRotationYaw = false;
	GetCharacterMovement()->bOrientRotationToMovement = true;

	//Combat = CreateDefaultSubobject<UCombatComponent>(TEXT("CombatComponent"));
	//Combat->SetIsReplicated(true);
}

// Called when the game starts or when spawned
void ARaidCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called to bind functionality to input
void ARaidCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);

	PlayerInputComponent->BindAxis("MoveForward", this, &ARaidCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ARaidCharacter::MoveRight);
	PlayerInputComponent->BindAxis("Turn", this, &ARaidCharacter::Turn);
	PlayerInputComponent->BindAxis("LookUp", this, &ARaidCharacter::LookUp);

	PlayerInputComponent->BindAction("Equip", IE_Pressed, this, &ARaidCharacter::EquipButtonPressed);
	PlayerInputComponent->BindAction("ShootKey", IE_Pressed, this, &ARaidCharacter::ShootRay);
}

//void ARaidCharacter::PostInitilizeComponents()
//{
	//Super::PostInitializeComponents();
	//if (Combat) {
	//	Combat->Character = this;
	//}
//}

void ARaidCharacter::MoveForward(float Value)
{
	if (Controller != nullptr && Value != 0.f) {
		const FRotator YawRotation(0.f, Controller->GetControlRotation().Yaw, 0.f);
		const FVector Direction(FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X));
		AddMovementInput(Direction, Value);
	}
}

void ARaidCharacter::MoveRight(float Value)
{
	if (Controller != nullptr && Value != 0.f) {
		const FRotator YawRotation(0.f, Controller->GetControlRotation().Yaw, 0.f);
		const FVector Direction(FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y));
		AddMovementInput(Direction, Value);
	}
}

void ARaidCharacter::Turn(float Value)
{
	AddControllerYawInput(Value);
}

void ARaidCharacter::LookUp(float Value)
{
	AddControllerPitchInput(Value);
}

void ARaidCharacter::EquipButtonPressed()
{
	//if (Combat) {
		//revisit weapon again Combat->EquipWeapon(OverlappingWeapon);
	//}
}

void ARaidCharacter::ShootRay()
{
	// *** now we want to fire from the center of the screen and see what it hits. This is the end position of the ray 
	
	// find the location of the character's gun
	USkeletalMeshComponent* ourMesh = GetMesh();
	const FVector CharacterGunPosition = ourMesh->GetComponentLocation() + FVector(0, 0, 120);

	// find location of cross hairs
	FVector2D ViewportSize;
	if (GEngine && GEngine->GameViewport)
	{
		GEngine->GameViewport->GetViewportSize(ViewportSize);
	}
	FVector2D CrosshairLocation(ViewportSize.X / 2.f, ViewportSize.Y / 2.f);

	FVector CrosshairWorldPosition;
	FVector CrosshairWorldDirection;
	bool bScreenToWorld = UGameplayStatics::DeprojectScreenToWorld(
		UGameplayStatics::GetPlayerController(this, 0), 
		CrosshairLocation,
		CrosshairWorldPosition,
		CrosshairWorldDirection);

	if (bScreenToWorld) // was deprojection successful?
	{
		const FVector Start = CrosshairWorldPosition;
		// actually fire our shot from camera 
		FHitResult ScreenTraceHit;
		//const FVector Start = CrosshairWorldPosition;
		const FVector End = CrosshairWorldPosition + CrosshairWorldDirection * 50'0000;

		FVector ScreenBeamEndPoint = End;
		GetWorld()->LineTraceSingleByChannel(ScreenTraceHit, Start, End, ECollisionChannel::ECC_Visibility);
		if (ScreenTraceHit.bBlockingHit)
		{
			ScreenBeamEndPoint = ScreenTraceHit.Location;
			
			AEnemyCharacterBase* enemy = Cast<AEnemyCharacterBase>(ScreenTraceHit.GetActor());
			if (enemy) 
			{
				UE_LOG(LogTemp, Warning, TEXT("hit enemy"));
				FDamageEvent event = FDamageEvent();
				enemy->TakeDamage(50, event, GetController(), this);
			}

			//DrawDebugLine(GetWorld(), Start, End, FColor::Red, false, 2.f);
			//DrawDebugSphere(GetWorld(), ScreenTraceHit.ImpactPoint, 20.0f, 1, FColor::Blue, true, 2.0f);
			//UE_LOG(LogTemp, Warning, TEXT("Screen hit"));

			// Now make another screen trace from the character to the point this hit (for visual purposes)
			FHitResult CharacterTraceHit;
			const FVector CharacterBeamEndPoint = ScreenTraceHit.ImpactPoint;
			GetWorld()->LineTraceSingleByChannel(CharacterTraceHit, CharacterGunPosition, CharacterBeamEndPoint, ECollisionChannel::ECC_Visibility);
			DrawDebugLine(GetWorld(), CharacterGunPosition, CharacterBeamEndPoint, FColor::Blue, false, 2.f);
			DrawDebugSphere(GetWorld(), CharacterTraceHit.ImpactPoint, 30.0f, 1, FColor::Blue, true, 2.0f);
		
		}
	}

}

// Called every frame
void ARaidCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


