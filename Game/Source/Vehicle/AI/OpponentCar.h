// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "VehiclePawn.h"
#include "OpponentCar.generated.h"

/**
 * 
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FMoveCompletedDelegate);

UCLASS()
class VEHICLE_API AOpponentCar : public AVehiclePawn
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintImplementableEvent)
	void MoveToLocation(const FVector& Location, float Radius);

	UPROPERTY(BlueprintReadWrite)
	FVector Destination;
	UPROPERTY(BlueprintReadWrite)
	float Distance;
	UPROPERTY(BlueprintReadWrite)
	float Started;
	UPROPERTY(BlueprintReadWrite)
	float WaypointRadius = 1000.0; 

	UPROPERTY(BlueprintReadWrite)
	FMoveCompletedDelegate MoveCompleted;

};
