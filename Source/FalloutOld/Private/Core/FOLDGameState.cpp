// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/FOLDGameState.h"

void AFOLDGameState::AddPlayerState(APlayerState* PlayerState)
{
	Super::AddPlayerState(PlayerState);
	OnPlayersCountChange.Broadcast();
	UE_LOG(LogTemp, Display, TEXT("Player state added"));
}

void AFOLDGameState::RemovePlayerState(APlayerState* PlayerState)
{
	Super::RemovePlayerState(PlayerState);
	OnPlayersCountChange.Broadcast();
	UE_LOG(LogTemp, Display, TEXT("Player state removed"));
}

