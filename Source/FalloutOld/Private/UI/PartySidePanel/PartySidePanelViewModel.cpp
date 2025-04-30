// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/PartySidePanel/PartySidePanelViewModel.h"

#include "PlayerParty.h"
#include "Core/FOLDGameState.h"
#include "Core/FOLDPlayerStateBase.h"
#include "GameFramework/GameStateBase.h"

void UPartySidePanelViewModel::Initialize()
{
	GameState = Cast<AFOLDGameState>(GetWorld()->GetGameState());
	OnChangedDelegateHandle = GameState->OnPlayersCountChange.AddUObject(this,&UPartySidePanelViewModel::OnPlayersCountUpdated);
	FindPlayersPartyData();		
}

void UPartySidePanelViewModel::BeginDestroy()
{
	UObject::BeginDestroy();
	if (GameState.IsValid())
	{
		GameState->OnPlayersCountChange.Remove(OnChangedDelegateHandle);
	}		
}

void UPartySidePanelViewModel::FindPlayersPartyData()
{
	PlayersPartyData.Empty();	
	auto Players = GameState->PlayerArray;	
	for (const auto& Player : Players)
	{		
		AFOLDPlayerStateBase* FOLDPlayerState = Cast<AFOLDPlayerStateBase>(Player);
		UPlayerParty* Party = FOLDPlayerState->PlayerParty;
		PlayersPartyData.Add(Party);		
	}
	OnChanged.Broadcast();
} 

void UPartySidePanelViewModel::OnPlayersCountUpdated()
{
	FindPlayersPartyData();
}
