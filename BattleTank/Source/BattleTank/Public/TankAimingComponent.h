// Copyright Just Geezy Games

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

// ENUMS
UENUM()
enum class EFiringStatus : uint8
{
	Aiming,
	Reloading,
	Locked
};

//Forward declaration
class UTankBarrel;
class UTankTurret;

//Hold barrel's properties
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	//UTankAimingComponent();

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void InitializeComponents(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);

	UFUNCTION(BlueprintCallable)
	void AimAt(FVector WorldSpaceAim, float LaunchSpeed);

protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringStatus FiringState = EFiringStatus::Aiming;


private:
	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;

	void MoveBarrelTowards(FVector AimDirection);
};
