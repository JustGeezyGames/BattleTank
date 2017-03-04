// Copyright Just Geezy Games

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h" //New classes above

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

protected:
	virtual void BeginPlay() override;
	
private:

};
