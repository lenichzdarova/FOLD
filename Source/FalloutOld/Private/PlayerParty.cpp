// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerParty.h"

void UPlayerParty::AddID(FString CharID)
{
	CharactersID.Add(CharID);
	IDAdded.Broadcast(CharID);
}

void UPlayerParty::RemoveID(FString CharID)
{
	if (ContainsID(CharID))
	{
		CharactersID.Remove(CharID);
		IDRemoved.Broadcast(CharID);
	}
}

bool UPlayerParty::ContainsID(FString CharID) const
{
	return CharactersID.Contains(CharID);
}

TArray<FString> UPlayerParty::GetParty() const
{
	return CharactersID;
}

void UPlayerParty::SetParty(TArray<FString> CharIDs)
{
	CharactersID = CharIDs;
}







