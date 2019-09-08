// Fill out your copyright notice in the Description page of Project Settings.

#include "MoveToWaypoint.h"
#include "BehaviorTree/BTFunctionLibrary.h"
#include "OpponentAIController.h"
#include "Kismet/GameplayStatics.h"
#include "Actions/PawnActionsComponent.h"

void UMoveToWaypoint::NativeReceiveExecute(AActor* OwnerActor)
{
	AOpponentAIController* aiController = Cast<AOpponentAIController>(OwnerActor);

	if (aiController)
	{
		APawn* controlledPawn = aiController->GetActionsComp()->GetControlledPawn();
		AOpponentCar* opponentCar = Cast<AOpponentCar>(controlledPawn);
		AWaypoint* waypoint = Cast<AWaypoint>(UBTFunctionLibrary::GetBlackboardValueAsObject(this, Route));

		if (!waypoint)
		{
			waypoint = FindClosestWaypoint(opponentCar);
			UBTFunctionLibrary::SetBlackboardValueAsObject(this, Route, waypoint);
		}

		opponentCar->MoveToLocation(waypoint->GetActorLocation(), waypoint->Radius);
		opponentCar->MoveCompleted.AddDynamic(this, &UMoveToWaypoint::MoveCompletedEvent);

	}
}

AWaypoint* UMoveToWaypoint::FindClosestWaypoint(AOpponentCar* opponentCar)
{
	TArray<AActor*> waypoints;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AWaypoint::StaticClass(), waypoints);
	if (waypoints.Num() == 0)
	{
		return nullptr;
	}

	waypoints.Sort([opponentCar](const AActor& waypointA, const AActor& waypointB)
	{
		const float waypointADistance = (opponentCar->GetActorLocation() - waypointA.GetActorLocation()).Size();
		const float waypointBDistance = (opponentCar->GetActorLocation() - waypointB.GetActorLocation()).Size();

		return waypointADistance < waypointBDistance;
	});

	return Cast<AWaypoint>(waypoints[0]);
}

