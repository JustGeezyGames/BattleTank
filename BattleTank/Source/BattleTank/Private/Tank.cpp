// Copyright Just Geezy Games

#include "BattleTank.h"
#include "TankAimingComponent.h"
#include "TankMovementComponent.h"
#include "TankBarrel.h"
#include "Projectile.h"
//#include "ProjectileMovementComponent.h"
#include "Tank.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	UE_LOG(LogTemp, Warning, TEXT("ATANK"))
}

void ATank::BeginPlay()
{
	//Need to call Super for BP begin play to run
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("ATANK-BeginPlay"))
}

void ATank::AimAt(FVector HitLocation)
{
	if (!TankAimingComponent) { return; }
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}

void ATank::Fire()
{
	bool isReloaded = FPlatformTime::Seconds() - LastFireTime > ReloadTimeInSeconds;

	if (Barrel && isReloaded)
	{
		//Spawn a projectile at the socket location on the barrel
		FVector POO = Barrel->GetSocketLocation(FName("Projectile"));
		FRotator Rotation = Barrel->GetSocketRotation(FName("Projectile"));
		AProjectile* Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint, POO, Rotation);

		Projectile->LaunchProjectile(LaunchSpeed);
		LastFireTime = FPlatformTime::Seconds();
	}
}
