// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerParty.h"

#include "Net/UnrealNetwork.h"

void UPlayerParty::AddID(FString CharID)
{	
	CharactersID.Add(CharID);
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 100, FColor::Red, "Add character");
	Changed.Broadcast(CharactersID);
}

void UPlayerParty::RemoveID(FString CharID)
{
	if (ContainsID(CharID))
	{
		CharactersID.Remove(CharID);
		Changed.Broadcast(CharactersID);		
	}
}

void UPlayerParty::Swap(FString First, FString Second)
{
	if (ContainsID(First) && ContainsID(Second))
	{
		size_t FirstIndex = CharactersID.Find(First);
		size_t SecondIndex = CharactersID.Find(Second);
		if (FirstIndex && SecondIndex)
		{
			CharactersID.Swap(FirstIndex, SecondIndex);	
		}
		Changed.Broadcast(CharactersID);
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
	Changed.Broadcast(CharactersID);
}

void UPlayerParty::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	UObject::GetLifetimeReplicatedProps(OutLifetimeProps);
	
	DOREPLIFETIME(UPlayerParty, CharactersID);
}

void UPlayerParty::OnRep_CharactersID()
{
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 100, FColor::Red, "Add character OnRep_CharactersID");
	Changed.Broadcast(CharactersID);
}







