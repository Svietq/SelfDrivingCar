// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/TimelineComponent.h"
#include "Components/BoxComponent.h"
#include "MovingObstacle.generated.h"

UCLASS()
class VEHICLE_API AMovingObstacle : public AActor
{
	GENERATED_BODY()
	
public:	
	AMovingObstacle();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintReadWrite)
	FVector StartLocation;
	UPROPERTY(BlueprintReadWrite)
	FVector EndLocation;
	UPROPERTY(BlueprintReadWrite)
	FRotator StartRotation;
	UPROPERTY(BlueprintReadWrite)
	FRotator EndRotation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float PlayRate = 1.0;

	UPROPERTY(BlueprintReadWrite)
	UStaticMeshComponent* Platform;
	UPROPERTY(BlueprintReadWrite)
	UBoxComponent* StartPoint;
	UPROPERTY(BlueprintReadWrite)
	UBoxComponent* EndPoint;

	UPROPERTY(BlueprintReadWrite)
	UTimelineComponent* PlatformMove;

};
