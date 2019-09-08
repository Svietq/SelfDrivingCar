// Fill out your copyright notice in the Description page of Project Settings.

#include "EndPointTriggerBox.h"
#include "UI/MainMenu.h"
#include "Kismet/GameplayStatics.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "UI/TopScoresSave.h"

void AEndPointTriggerBox::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	APlayerController* playerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);

	UMainMenu* mainMenu = CreateWidget<UMainMenu>(playerController, MainMenuReference);
	mainMenu->AddToViewport();

	playerController->bShowMouseCursor = true;
	UWidgetBlueprintLibrary::SetInputMode_UIOnlyEx(playerController, nullptr, EMouseLockMode::DoNotLock);

	const FString& SlotName = FString{ TEXT("Leaderboard") };
	UTopScoresSave* topScoresSave = Cast<UTopScoresSave>(UGameplayStatics::LoadGameFromSlot(SlotName, 0));
	topScoresSave->TopScores.Add(topScoresSave->CurrentPlayerName, FDateTime::UtcNow() - topScoresSave->CurrentPlayerStartingTime);
	UGameplayStatics::SaveGameToSlot(topScoresSave, SlotName, 0);
}
