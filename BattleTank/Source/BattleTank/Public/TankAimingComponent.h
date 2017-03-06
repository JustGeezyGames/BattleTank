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
	Locked,
	OutOfAmmo
};

//Forward declaration
class UTankBarrel;
class UTankTurret;
class AProjectile;

//Hold barrel's properties
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	//Sets default values for this component's properties
	UTankAimingComponent();

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void InitializeComponents(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);

	UFUNCTION(BlueprintCallable)
	void AimAt(FVector HitLocation);

	//Barrel Reference is set in Blueprint
	UFUNCTION(BlueprintCallable)
	void Fire();

	EFiringStatus GetFiringState() const;

	UFUNCTION(BlueprintCallable)
	int32 GetAmmoRemaining() const;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringStatus FiringState = EFiringStatus::Reloading;

private:
	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;

	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

	bool IsBarrelMoving();

	FVector AimDirection;

	void MoveBarrelTowards();

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed = 4000.f;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float ReloadTimeInSeconds = 3.f;

	double LastFireTime = 0;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	int32 Ammo = 3;
};
