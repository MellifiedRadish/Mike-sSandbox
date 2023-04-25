// Fill out your copyright notice in the Description page of Project Settings.


#include "RaidCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"	
#include "GameFramework/CharacterMovementComponent.h"
#include "RaidV01/RaidComponents/CombatComponent.h"
#include "Kismet/GameplayStatics.h"
#include "EnemyCharacterBase.h"

// Sets default values
// TODO: Might be safer to have some "None" weapon instead of directly using nullptr?
ARaidCharacter::ARaidCharacter() : Health(100), MaxHealth(100), EquippedWeapon(nullptr)
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
	GetCharacterMovement()->bOrientRotationToMovement = false;//was true
	bUseControllerRotationYaw = true;

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
	PlayerInputComponent->BindAction("ShootKey", IE_Pressed, this, &ARaidCharacter::OnFireDown);
	PlayerInputComponent->BindAction("ShootKey", IE_Released, this, &ARaidCharacter::OnFireUp);
	PlayerInputComponent->BindAction("Aim", IE_Pressed, this, &ARaidCharacter::AimButtonPressed);
	PlayerInputComponent->BindAction("Aim", IE_Released, this, &ARaidCharacter::AimButtonReleased);
}

bool ARaidCharacter::IsAiming()
{
	return bAiming;
}

float ARaidCharacter::TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator,
	AActor* DamageCauser) {
	if (Health <= 0) {
		return 0.f;
	}

	// might have different values by gamemode/difficulty?
	const float ScaledDamage = Super::TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);

	if (ScaledDamage > 0.f) {
		Health -= ScaledDamage;

		if (Health <= 0) {
			// might want to check damage types (if we have any)

			SetRagdoll();
			//Die(ScaledDamage, DamageEvent, EventInstigator, DamageCauser);
		} else {
			//APawn* pawn = EventInstigator ? EventInstigator->GetPawn() : nullptr;
			//PlaySound(ScaledDamage, DamageEvent, pawn, DamageCauser, false);
		}
	}

	return ScaledDamage;
}

void ARaidCharacter::SetRagdoll() {
	bool inRagdoll = false;
	USkeletalMeshComponent* Mesh3P = GetMesh();

	if (IsValid(this)) {
		inRagdoll = false;
	} else if (!Mesh3P || !Mesh3P->GetPhysicsAsset()) {
		inRagdoll = false;
	} else {
		Mesh3P->SetAllBodiesSimulatePhysics(true);
		Mesh3P->SetSimulatePhysics(true);
		Mesh3P->WakeAllRigidBodies();
		Mesh3P->bBlendPhysics = true;

		inRagdoll = true;
	}

	UCharacterMovementComponent* CharacterComp = Cast<UCharacterMovementComponent>(GetMovementComponent());
	if (CharacterComp)
	{
		CharacterComp->StopMovementImmediately();
		CharacterComp->DisableMovement();
		CharacterComp->SetComponentTickEnabled(false);
	}
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

void ARaidCharacter::OnFireDown()
{
	bFireIsDown = true;
}

void ARaidCharacter::OnFireUp()
{
	bFireIsDown = false;
}

void ARaidCharacter::StartBurst()
{
	bIsBursting = true;
	RoundsFiredThisBurst = 0;
	if (GetWeapon()) GetWeapon()->SetTimeLastBursted(GetWorld()->TimeSeconds);
}

// Runs every frame while the gun is firing its burst.
void ARaidCharacter::ExecuteBurst()
{
	if (!GetWeapon() || !GetWeapon()->ReadyToFire()) return;
	ShootRay();
	if (GetWeapon())
	{
		GetWeapon()->SetTimeLastFired(GetWorld()->TimeSeconds);
		RoundsFiredThisBurst++;
		if (RoundsFiredThisBurst >= GetWeapon()->GetRoundsPerBurst()) EndBurst();
	} else
	{
		EndBurst();
	}
}

void ARaidCharacter::EndBurst()
{
	bIsBursting = false;
}

void ARaidCharacter::EquipWeapon(AWeapon* Weapon)
{
	EquippedWeapon = Weapon;
}

AWeapon* ARaidCharacter::GetWeapon() const
{
	return EquippedWeapon;
}

void ARaidCharacter::RequestFire()
{
	if (!GetWeapon()) return;
	switch (GetWeapon()->GetFiringMode()) {
		case EWeaponFiringMode::Semi:
			// Do not fire if the fire button was held last frame, or if the gun's RPM is too slow.
			if (bWasFiringLastFrame || !GetWeapon()->ReadyToFire()) return;
			ShootRay();
			if (GetWeapon()) GetWeapon()->SetTimeLastFired(GetWorld()->TimeSeconds);
			break;
		case EWeaponFiringMode::Auto:
			if (!GetWeapon()->ReadyToFire()) return;
			ShootRay();
			if (GetWeapon()) GetWeapon()->SetTimeLastFired(GetWorld()->TimeSeconds);
			break;
		case EWeaponFiringMode::Burst:
			if (bWasFiringLastFrame || !GetWeapon()->ReadyToFire() || !GetWeapon()->ReadyToStartBurst() || bIsBursting) return;
			StartBurst();
			break;
		default: ;
	}

}

void ARaidCharacter::ShootRay()
{
	// *** now we want to fire from the center of the screen and see what it hits. This is the end position of the ray
	// find the location of the character's gun
	// TODO(ben): replace this with a GetWeapon().GetBarrel() call
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

			UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), HitParticles, ScreenTraceHit.ImpactPoint);
			
			AEnemyCharacterBase* enemy = Cast<AEnemyCharacterBase>(ScreenTraceHit.GetActor());
			if (enemy) 
			{
				UE_LOG(LogTemp, Warning, TEXT("hit enemy"));

				float DamageAmount = 50.f;
				FPointDamageEvent DamageEvent;
				DamageEvent.Damage = DamageAmount;
				enemy->TakeDamage(DamageAmount, DamageEvent, GetController(), this);
			}

			//DrawDebugLine(GetWorld(), Start, End, FColor::Red, false, 2.f);
			//DrawDebugSphere(GetWorld(), ScreenTraceHit.ImpactPoint, 20.0f, 1, FColor::Blue, true, 2.0f);
			//UE_LOG(LogTemp, Warning, TEXT("Screen hit"));

			// Now make another screen trace from the character to the point this hit (for visual purposes)
			FHitResult CharacterTraceHit;
			const FVector CharacterBeamEndPoint = ScreenTraceHit.ImpactPoint;
			GetWorld()->LineTraceSingleByChannel(CharacterTraceHit, CharacterGunPosition, CharacterBeamEndPoint, ECollisionChannel::ECC_Visibility);
			//DrawDebugLine(GetWorld(), CharacterGunPosition, CharacterBeamEndPoint, FColor::Blue, false, 2.f);
			//DrawDebugSphere(GetWorld(), CharacterTraceHit.ImpactPoint, 30.0f, 1, FColor::Red, true, 2.0f);
		}
	}

}

void ARaidCharacter::AimButtonPressed()
{
	bAiming = true;
}

void ARaidCharacter::AimButtonReleased()
{
	bAiming = false;
}

// Called every frame
void ARaidCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (bFireIsDown) RequestFire();
	if (bIsBursting) ExecuteBurst();
	
	bWasFiringLastFrame = bFireIsDown;
}


