// Copyright Just Geezy Games

#pragma once

#include "AIController.h"
#include "TankAIController.generated.h"


/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

	//How close the AI tank can get to the player
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	float AcceptanceRadius = 8000.f;

private:

	UFUNCTION()
	void OnPossessedTankDeath();

	virtual void SetPawn(APawn* InPawn) override;
};
