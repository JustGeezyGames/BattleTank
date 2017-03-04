// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAimingComponent.h"
#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto ControlledAI = GetPawn();
	UTankAimingComponent* AimingComponent = ControlledAI->FindComponentByClass<UTankAimingComponent>();
	
	if (!ensure (PlayerTank && ControlledAI)) { return; }

	MoveToActor(PlayerTank, AcceptanceRadius);

	//Aim towards the player
	AimingComponent->AimAt(PlayerTank->GetActorLocation());

	//Fire
	//ControlledAI->Fire();
}

/*ATank* ATankAIController::GetControlledAI() const
{
	return Cast<ATank>(GetPawn());	
}*/