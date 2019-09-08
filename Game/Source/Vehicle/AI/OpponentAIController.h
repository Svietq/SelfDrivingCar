// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "OpponentAIController.generated.h"

/**
 * 
 */
UCLASS()
class VEHICLE_API AOpponentAIController : public AAIController
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite)
	UBlackboardData* OpponentBlackboardAsset;

	UPROPERTY(BlueprintReadWrite)
	UBehaviorTree* OpponentBehaviorTree;

	UPROPERTY(BlueprintReadWrite)
	FName PlayerKey;
	
protected:
	virtual void BeginPlay() override;

};
