// Fill out your copyright notice in the Description page of Project Settings.

#include "OpponentAIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"

void AOpponentAIController::BeginPlay()
{
	Super::BeginPlay();

	UBlackboardComponent* blackboardComponent;
	UseBlackboard(OpponentBlackboardAsset, blackboardComponent);
	RunBehaviorTree(OpponentBehaviorTree);

}
