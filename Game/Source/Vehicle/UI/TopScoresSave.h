// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "TopScoresSave.generated.h"

/**
 * 
 */
UCLASS()
class VEHICLE_API UTopScoresSave : public USaveGame
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadWrite)
	TMap<FString, FTimespan> TopScores;

	UPROPERTY(BlueprintReadWrite)
	FDateTime CurrentPlayerStartingTime;

	UPROPERTY(BlueprintReadWrite)
	FString CurrentPlayerName;
};