// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingObstacle.h"

AMovingObstacle::AMovingObstacle()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AMovingObstacle::BeginPlay()
{
	Super::BeginPlay();
	
	StartLocation = StartPoint->GetComponentLocation();
	EndLocation = EndPoint->GetComponentLocation();
	StartRotation = Platform->GetComponentRotation();
	EndRotation = EndPoint->GetComponentRotation();
	PlatformMove->SetPlayRate(PlayRate);


}

void AMovingObstacle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

