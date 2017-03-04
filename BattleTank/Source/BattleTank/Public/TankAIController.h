// Copyright Just Geezy Games

#pragma once

#include "AIController.h"
#include "TankAIController.generated.h"

class ATank;
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

private:

	ATank* PlayerTank = nullptr;
	ATank* ControlledAI = nullptr;

	//How close the AI tank can get to the player
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	float AcceptanceRadius = 300.f;
	
};
