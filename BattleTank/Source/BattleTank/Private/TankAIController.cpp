// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Tank.h"
#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	ControlledAI = Cast<ATank>(GetPawn());
	if (!ensure (ControlledAI))
	{
		UE_LOG(LogTemp, Warning, TEXT("AI not possessing a tank"));
		return;
	}
	if (ensure (PlayerTank))
	{
		MoveToActor(PlayerTank, AcceptanceRadius);

		//Aim towards the player
		ControlledAI->AimAt(PlayerTank->GetActorLocation());

		//Fire
		ControlledAI->Fire();
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI can't find player"));
	}
}

/*ATank* ATankAIController::GetControlledAI() const
{
	return Cast<ATank>(GetPawn());	
}*/