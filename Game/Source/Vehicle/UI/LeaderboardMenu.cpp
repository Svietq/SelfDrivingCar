// Fill out your copyright notice in the Description page of Project Settings.

#include "LeaderboardMenu.h"
#include "Kismet/GameplayStatics.h"
#include "Components/TextBlock.h"
#include "TopScoresSave.h"
#include "WidgetTree.h"
#include "MainMenu.h"

void ULeaderboardMenu::NativeConstruct()
{
	Super::NativeConstruct();

	if (BackButton)
	{
		BackButton->OnClicked.AddDynamic(this, &ULeaderboardMenu::OnBackButtonClicked);
	}
}

void ULeaderboardMenu::SynchronizeProperties()
{
	Super::SynchronizeProperties();

	FillOutLeaderboard();
}

void ULeaderboardMenu::OnBackButtonClicked()
{
	RemoveFromParent();
	UMainMenu* mainMenu = CreateWidget<UMainMenu>(UGameplayStatics::GetPlayerController(GetWorld(), 0), MainMenuReference);
	mainMenu->AddToViewport();
}

void ULeaderboardMenu::FillOutLeaderboard()
{
#if WITH_EDITOR
	if (!ScoresVerticalBox)
	{
		return;
	}
#endif
	FString SlotName = FString{ TEXT("Leaderboard") };
	TMap<FString, FTimespan>& TopScores = Cast<UTopScoresSave>(UGameplayStatics::LoadGameFromSlot(SlotName, 0))->TopScores;	
	TopScores.ValueSort([](const FTimespan& firstTimeValue, const FTimespan& secondTimeValue) { return firstTimeValue < secondTimeValue; });
	for (const TPair<FString, FTimespan>& topScore : TopScores)
	{
		UTextBlock* newScoreText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass());
		FTextBuilder TextBuilder;
		TextBuilder.AppendLineFormat(FTextFormat::FromString("{0} : {1}s"), 
									 FText::FromString(topScore.Key),
									 FText::FromString(FString::SanitizeFloat(TopScores.Find(topScore.Key)->GetTotalSeconds())));
		newScoreText->SetText(TextBuilder.ToText());

		ScoresVerticalBox->AddChildToVerticalBox(newScoreText);
	}

}

