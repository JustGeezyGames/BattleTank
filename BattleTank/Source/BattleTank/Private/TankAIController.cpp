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

	if (!ensure(PlayerTank && ControlledAI)) { return; }
	
	//Move towards the player
	MoveToActor(PlayerTank, AcceptanceRadius);


	//Aim towards the player
	UTankAimingComponent* AimingComponent = ControlledAI->FindComponentByClass<UTankAimingComponent>();
	AimingComponent->AimAt(PlayerTank->GetActorLocation());

	//Fire
	AimingComponent->Fire();
}