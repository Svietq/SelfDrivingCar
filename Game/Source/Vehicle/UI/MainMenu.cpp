// Fill out your copyright notice in the Description page of Project Settings.

#include "MainMenu.h"
#include "Kismet/GameplayStatics.h"
#include "LeaderboardMenu.h"
#include "TopScoresSave.h"

void UMainMenu::NativeConstruct()
{
	Super::NativeConstruct();

	if (StartGameButton)
	{
		StartGameButton->OnClicked.AddDynamic(this, &UMainMenu::OnStartGameButtonClicked);
	}

	if (LeaderboardButton)
	{
		LeaderboardButton->OnClicked.AddDynamic(this, &UMainMenu::OnLeaderboardButtonClicked);
	}

}

void UMainMenu::OnStartGameButtonClicked()
{
	UGameplayStatics::OpenLevel(GetWorld(), TEXT("VehicleMap"));
	const FString& SlotName = FString{ TEXT("Leaderboard") };
	UTopScoresSave* topScoresSave = Cast<UTopScoresSave>(UGameplayStatics::LoadGameFromSlot(SlotName, 0));
	topScoresSave->CurrentPlayerStartingTime = FDateTime::UtcNow();
	topScoresSave->CurrentPlayerName = EnterNameEditableText->GetText().ToString();
	UGameplayStatics::SaveGameToSlot(topScoresSave, SlotName, 0);

}

void UMainMenu::OnLeaderboardButtonClicked()
{
	RemoveFromParent();
	ULeaderboardMenu* leaderboardMenu = CreateWidget<ULeaderboardMenu>(UGameplayStatics::GetPlayerController(GetWorld(), 0), LeaderboardMenuReference);
	leaderboardMenu->AddToViewport();
}
