// Copyright Just Geezy Games

#include "BattleTank.h"
#include "TankTrack.h"
#include "TankMovementComponent.h"



void UTankMovementComponent::InitializeComponent(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}

void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
	//No need to call Super since we're replacing the functionality
	FVector TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	FVector AIForwardIntention = MoveVelocity.GetSafeNormal();
	//UE_LOG(LogTemp, Warning, TEXT("%s moving to %s"), *TankName, *MoveVelocityString)

	float ForwardThrow = FVector::DotProduct(TankForward, AIForwardIntention);
	IntendMoveForward(ForwardThrow);

	FVector RotationThrow = FVector::CrossProduct(TankForward, AIForwardIntention);
	IntendRotate(RotationThrow.Z);
}


void UTankMovementComponent::IntendMoveForward(float Throw)
{
	if (!LeftTrack || !RightTrack)
	{
		UE_LOG(LogTemp, Warning, TEXT("Tracks not set"))
		return;
	}
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
}

//Positive moves right, negative moves left
void UTankMovementComponent::IntendRotate(float Throw)
{
	if (!LeftTrack || !RightTrack)
	{
		UE_LOG(LogTemp, Warning, TEXT("Tracks not set"))
		return;
	}	
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);
}