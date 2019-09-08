// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Button.h"
#include "Components/VerticalBox.h"
#include "LeaderboardMenu.generated.h"

/**
 * 
 */
UCLASS()
class VEHICLE_API ULeaderboardMenu : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UUserWidget> MainMenuReference;

protected:
	virtual void NativeConstruct() override;
	virtual void SynchronizeProperties() override;

	UFUNCTION()
	void OnBackButtonClicked();

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* BackButton = nullptr;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UVerticalBox* ScoresVerticalBox = nullptr;

private:
	void FillOutLeaderboard();
};

