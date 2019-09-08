// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TargetPoint.h"
#include "Waypoint.generated.h"

/**
 * 
 */
UCLASS()
class VEHICLE_API AWaypoint : public ATargetPoint
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite)
	float Radius = 1000.0;
	
};
