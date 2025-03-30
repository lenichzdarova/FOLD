// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/PartyPanel.h"
#include "Components/VerticalBoxSlot.h"
#include "Core/FOLDGameState.h"
#include "Kismet/GameplayStatics.h"

void UPartyPanel::NativeConstruct()
{
	Super::NativeConstruct();

	AFOLDGameState* GameState = Cast<AFOLDGameState>(UGameplayStatics::GetGameState(this));
	UPlayerParty* PlayerParty = GameState->PlayerParty;
	TArray<FString>PartyMembersID = PlayerParty->GetParty();
	for (auto CharacterID : PartyMembersID)
	{
		UCharacterPortrait* Portrait = ConstructPortraitWidget(CharacterID);
		Portraits.Add(Portrait);
	}
	PlayerParty->Changed.AddUObject(this, &ThisClass::OnPartyChanged);
}

void UPartyPanel::OnPartyChanged(const TArray<FString>& CharactersID)
{	
	for (int i = 0; i < CharactersID.Num(); i++)
	{
		UCharacterPortrait* widget = nullptr;		
		FString CharacterID = CharactersID[i];
		if (!Portraits.IsValidIndex(i))
		{
			widget = ConstructPortraitWidget(CharacterID);
			Portraits.Add(widget);			
		}
		else
		{
			widget = Portraits[i];
			if (widget->GetCharacterID() != CharacterID)
			{
				widget->SetCharacterID(CharacterID);	
			}					
		}		
	}
	while (Portraits.Num() - CharactersID.Num() != 0)
	{
		UCharacterPortrait* widget = Portraits.Pop(EAllowShrinking::Yes);
		widget->RemoveFromParent();
	}	
}

UCharacterPortrait* UPartyPanel::ConstructPortraitWidget(FString ID)
{	
	UCharacterPortrait* Portrait = CreateWidget<UCharacterPortrait>(this, PortraitClass);
	Portrait->SetCharacterID(ID);
	UVerticalBoxSlot* VerticalBoxSlot = Cast<UVerticalBoxSlot>(VerticalBox->AddChild(Portrait));
	VerticalBoxSlot->SetHorizontalAlignment(HAlign_Center);
	VerticalBoxSlot->SetVerticalAlignment(VAlign_Center);
	return Portrait;
}
