// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "Waypoint.h"
#include "OpponentCar.h"
#include "MoveToWaypoint.generated.h"

/**
 * 
 */
UCLASS()
class VEHICLE_API UMoveToWaypoint : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void NativeReceiveExecute(AActor* OwnerActor);
	
	UFUNCTION(BlueprintImplementableEvent)
	void MoveCompletedEvent();

	UPROPERTY(BlueprintReadWrite)
	FBlackboardKeySelector Route;

private:
	AWaypoint* FindClosestWaypoint(AOpponentCar* opponentCar);

};
