// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyCharacterBase.h"

#include "RaidCharacter.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundCue.h"
#include "RaidV01/RaidV01GameModeBase.h"
#include "RaidV01/AI/EnemyAIController.h"

// Sets default values
AEnemyCharacterBase::AEnemyCharacterBase(): Health(100), MaxHealth(100), SenseTimeout(2.f), AttackTimeout(1.f), MeleeDamage(10.f)
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PawnSensingComponent = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("PawnSensingComponent"));

	// Don't collide with camera checks to keep 3rd person camera at position when zombies or other players are standing behind us
	GetMesh()->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore);
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore);
}

bool AEnemyCharacterBase::IsAlive() const {
	return Health > 0;
}

void AEnemyCharacterBase::OnSeePawn(APawn* PlayerPawn) {
	SensedTarget = true;
	LastSeenTime = GetWorld()->GetTimeSeconds();

	AEnemyAIController* AIController = Cast<AEnemyAIController>(GetController());
	ARaidCharacter* Player = Cast<ARaidCharacter>(PlayerPawn);

	if (AIController && Player) {
		AIController->SetHasPlayerLOS(true, Player);
	}
}

// Called when the game starts or when spawned
void AEnemyCharacterBase::BeginPlay()
{
	Super::BeginPlay();

	// bind our OnSeePawn function to the function of the PawnSensing component
	PawnSensingComponent->OnSeePawn.AddDynamic(this, &AEnemyCharacterBase::OnSeePawn);
}

// Called every frame
void AEnemyCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (SensedTarget && GetWorld()->TimeSeconds - LastSeenTime > SenseTimeout) {
		AEnemyAIController* AIController = Cast<AEnemyAIController>(GetController());

		if (AIController) {
			SensedTarget = false;
			AIController->SetHasPlayerLOS(false, nullptr);
		}
	}
}

float AEnemyCharacterBase::TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator,
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

			Die(ScaledDamage, DamageEvent, EventInstigator, DamageCauser);
		} else {
			APawn* pawn = EventInstigator ? EventInstigator->GetPawn() : nullptr;
			PlaySound(ScaledDamage, DamageEvent, pawn, DamageCauser, false);
		}
	}

	return ScaledDamage;
}

bool AEnemyCharacterBase::CanDie(float KillingDamage, FDamageEvent const& DamageEvent, AController* Killer,
	AActor* DamageCauser) const {

	// check if character is already dying, destroyed or if we have authority
	if (IsDying ||
		IsValid(this) ||
		!HasAuthority() ||	// network check (probably irrelevant for Raid)
		GetWorld()->GetAuthGameMode() == NULL)
	{
		return false;
	}

	return true;
}

bool AEnemyCharacterBase::Die(float KillingDamage, FDamageEvent const& DamageEvent, AController* Killer,
	AActor* DamageCauser) {

	if (!CanDie(KillingDamage, DamageEvent, Killer, DamageCauser))
	{
		return false;
	}

	Health = FMath::Min(0.0f, Health);

	// Fallback to default DamageType if none is specified
	UDamageType const* const DamageType = DamageEvent.DamageTypeClass ? DamageEvent.DamageTypeClass->GetDefaultObject<UDamageType>() : GetDefault<UDamageType>();
	Killer = GetDamageInstigator(Killer, *DamageType);

	// Unused: Notify the gamemode we got killed for scoring and game over state */
	// AController* KilledPlayer = Controller ? Controller : Cast<AController>(GetOwner());
	// GetWorld()->GetAuthGameMode<ARaidV01GameModeBase>()->Killed(Killer, KilledPlayer, this, DamageType);

	OnDeath(KillingDamage, DamageEvent, Killer ? Killer->GetPawn() : nullptr, DamageCauser);
	return true;
}

void AEnemyCharacterBase::OnDeath(float KillingDamage, FDamageEvent const& DamageEvent, APawn* PawnInstigator,
	AActor* DamageCauser) {

	if (IsDying) {
		return;
	}

	SetReplicateMovement(true);
	TearOff();
	IsDying = true;

	PlaySound(KillingDamage, DamageEvent, PawnInstigator, DamageCauser, true);

	DetachFromControllerPendingDestroy();

	// Disable all collision on capsule
	UCapsuleComponent* CapsuleComp = GetCapsuleComponent();
	CapsuleComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	CapsuleComp->SetCollisionResponseToAllChannels(ECR_Ignore);

	USkeletalMeshComponent* Mesh3P = GetMesh();
	if (Mesh3P) {
		Mesh3P->SetCollisionProfileName(TEXT("Ragdoll"));
	}
	SetActorEnableCollision(true);

	SetRagdoll();

	// Apply physics impulse on the bone of the enemy skeleton mesh we hit (ray-trace damage only)
	if (DamageEvent.IsOfType(FPointDamageEvent::ClassID)) {
		FPointDamageEvent PointDmg = *((FPointDamageEvent*)(&DamageEvent));
		{
			// FTODO: Use DamageTypeClass->DamageImpulse
			Mesh3P->AddImpulseAtLocation(PointDmg.ShotDirection * 12000, PointDmg.HitInfo.ImpactPoint, PointDmg.HitInfo.BoneName);
		}
	}

	if (DamageEvent.IsOfType(FRadialDamageEvent::ClassID)) {
		FRadialDamageEvent RadialDmg = *((FRadialDamageEvent const*)(&DamageEvent));
		{
			Mesh3P->AddRadialImpulse(RadialDmg.Origin, RadialDmg.Params.GetMaxRadius(), 100000 /*RadialDmg.DamageTypeClass->DamageImpulse*/, ERadialImpulseFalloff::RIF_Linear);
		}
	}
}

void AEnemyCharacterBase::PerformAttack(AActor* HitActor) {
	if (HitActor) {
		ARaidCharacter* Player = Cast<ARaidCharacter>(HitActor);

		if (Player && GetWorld()->TimeSeconds - LastAttackTime > AttackTimeout) {
			LastAttackTime = GetWorld()->GetTimeSeconds();
			PlayAnimMontage(AnimMontage);

			FPointDamageEvent DamageEvent;
			DamageEvent.Damage = MeleeDamage;
			Player->TakeDamage(DamageEvent.Damage, DamageEvent, GetController(), this);
		}
	}
}

void AEnemyCharacterBase::PlaySound(float DamageTaken, FDamageEvent const& DamageEvent, APawn* PawnInstigator,
                                    AActor* DamageCauser, bool isKilled) {

	if (isKilled && SoundDeath) {
		UGameplayStatics::SpawnSoundAttached(SoundDeath, RootComponent, NAME_None, FVector::ZeroVector, EAttachLocation::SnapToTarget, true);
	} else if (SoundHurt) {
		UGameplayStatics::SpawnSoundAttached(SoundHurt, RootComponent, NAME_None, FVector::ZeroVector, EAttachLocation::SnapToTarget, true);
	}
}

void AEnemyCharacterBase::SetRagdoll() {
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

	if (!inRagdoll)
	{
		// Immediately hide the pawn
		TurnOff();
		SetActorHiddenInGame(true);
		SetLifeSpan(1.0f);
	}
	else
	{
		SetLifeSpan(10.0f);
	}
}
