// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "EndPointTriggerBox.generated.h"

/**
 * 
 */
UCLASS()
class VEHICLE_API AEndPointTriggerBox : public ATriggerBox
{
	GENERATED_BODY()

protected:
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UUserWidget> MainMenuReference;
	
};
