// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon.h"
#include "Components/SphereComponent.h"
#include "Components/WidgetComponent.h"
#include "RAIDV01/Character/RaidCharacter.h"
// Sets default values
AWeapon::AWeapon()
{
	PrimaryActorTick.bCanEverTick = false;
	//bReplicates = true;

	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("WeaponMesh"));
	SetRootComponent(WeaponMesh);

	WeaponMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
	WeaponMesh->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Ignore);
	WeaponMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	AreaSphere = CreateDefaultSubobject<USphereComponent>(TEXT("AreaSphere"));
	AreaSphere->SetupAttachment(RootComponent);
	AreaSphere->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	AreaSphere->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	PickupWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("PickupWidget"));
	PickupWidget->SetupAttachment(RootComponent);

	TimeLastFired = 0.0;
}

void AWeapon::BeginPlay()
{
	Super::BeginPlay();

	
	AreaSphere->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	AreaSphere->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);
	AreaSphere->OnComponentBeginOverlap.AddDynamic(this, &AWeapon::OnSphereOverlap);
	AreaSphere->OnComponentEndOverlap.AddDynamic(this, &AWeapon::OnSphereEndOverLap);
	if (PickupWidget)
	{
		PickupWidget->SetVisibility(false);
	}
}

void AWeapon::OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ARaidCharacter* RaidCharacter = Cast<ARaidCharacter>(OtherActor);
	if (RaidCharacter && PickupWidget) {
		PickupWidget->SetVisibility(true);
	}
}

EWeaponFiringMode AWeapon::GetFiringMode() const
{
	return FiringMode;
}

int AWeapon::GetRoundsPerMinute() const
{
	return RoundsPerMinute;
}

int AWeapon::GetRoundsPerBurst() const
{
	return  RoundsPerBurst;
}

float AWeapon::GetTimeLastFired() const
{
	return TimeLastFired;
}

void AWeapon::SetTimeLastFired(float Time)
{
	TimeLastFired = Time;
}

bool AWeapon::ReadyToFire() const
{
	return GetWorld()->TimeSeconds - TimeLastFired > 60.0 / RoundsPerMinute;
}

bool AWeapon::ReadyToStartBurst() const
{
	return  GetWorld()->TimeSeconds - TimeLastBursted > SecondsBetweenBursts;
}

void AWeapon::SetTimeLastBursted(float Time)
{
	TimeLastBursted = Time;
}

void AWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AWeapon::OnSphereEndOverLap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
	ARaidCharacter* RaidCharacter = Cast<ARaidCharacter>(OtherActor);
	if (RaidCharacter && PickupWidget) {
		PickupWidget->SetVisibility(false);
	}
}
