// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Button.h"
#include "EditableText.h"
#include "MainMenu.generated.h"

/**
 * 
 */
UCLASS()
class VEHICLE_API UMainMenu : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UUserWidget> LeaderboardMenuReference;

protected:
	virtual void NativeConstruct() override;
	
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UEditableText* EnterNameEditableText = nullptr;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* StartGameButton = nullptr;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* LeaderboardButton = nullptr;

private:
	UFUNCTION()
	void OnStartGameButtonClicked();
	UFUNCTION()
	void OnLeaderboardButtonClicked();
};
