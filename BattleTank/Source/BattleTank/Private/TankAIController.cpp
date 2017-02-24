// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	ATank* ControlledAI = GetControlledAI();
	if (!ControlledAI)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI possessing a tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI controller possessing %s"), *(ControlledAI->GetName()));
	}

	ATank* PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI can't find player"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("%s targetting player tank (%s)"), *(ControlledAI->GetName()), *PlayerTank->GetName());
	}
}

// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayerTank())
	{
		GetControlledAI()->AimAt(GetPlayerTank()->GetActorLocation());
	}
}

ATank* ATankAIController::GetControlledAI() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());	
}