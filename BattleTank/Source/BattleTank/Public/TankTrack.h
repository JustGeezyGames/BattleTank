// Copyright Just Geezy Games

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	//Sets default values for tank track
	UTankTrack();

	//Sets a throttle between -1 and +1.
	UFUNCTION(BlueprintCallable, category ="Input")
	void SetThrottle(float Throttle);

	void DriveTrack();
	
	// Max force per track, in Newtons
	UPROPERTY(EditDefaultsOnly)
	float TrackMaxDrivingForce = 40000000.f; //Assumes 40 ton tank

protected:
	virtual void BeginPlay() override;

private:
	void ApplySidewaysForce();

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);

	float CurrentThrottle = 0.f;
};
