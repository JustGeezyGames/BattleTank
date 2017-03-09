// Copyright Just Geezy Games

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h" //New classes above

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTankDelegate);

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

	//Called by the engine when actor damage is dealt
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const & DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

	//Returns current health as a percentage of starting health, between 0 and 1.
	UFUNCTION(BlueprintPure)
	float GetHealthPercent() const;

	FTankDelegate OnDeath;

protected:

	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	int32 StartingHealth = 100;

private:
	UPROPERTY(VisibleAnywhere, Category = "Health")
	int32 CurrentHealth;
};
