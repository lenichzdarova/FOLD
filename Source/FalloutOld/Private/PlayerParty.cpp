// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerParty.h"

#include "Net/UnrealNetwork.h"

void UPlayerParty::AddID(FString CharID)
{	
	PartyMembersID.Add(CharID);
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 100, FColor::Red, "Add character");
	Changed.Broadcast();
}

void UPlayerParty::RemoveID(FString CharID)
{
	if (ContainsID(CharID))
	{
		PartyMembersID.Remove(CharID);
		Changed.Broadcast();		
	}
}

void UPlayerParty::Swap(FString First, FString Second)
{
	if (ContainsID(First) && ContainsID(Second))
	{
		size_t FirstIndex = PartyMembersID.Find(First);
		size_t SecondIndex = PartyMembersID.Find(Second);
		if (FirstIndex && SecondIndex)
		{
			PartyMembersID.Swap(FirstIndex, SecondIndex);	
		}
		Changed.Broadcast();
	}	
}

bool UPlayerParty::ContainsID(FString CharID) const
{
	return PartyMembersID.Contains(CharID);
}

TArray<FString> UPlayerParty::GetPartyMembersID() const
{
	return PartyMembersID;
}

void UPlayerParty::SetPartyMembersID(TArray<FString> CharIDs)
{
	PartyMembersID = CharIDs;
	Changed.Broadcast();
}

void UPlayerParty::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	UObject::GetLifetimeReplicatedProps(OutLifetimeProps);
	
	DOREPLIFETIME(UPlayerParty, PartyMembersID);
}

void UPlayerParty::OnRep_CharactersID()
{
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 100, FColor::Red, "Add character OnRep_CharactersID");
	Changed.Broadcast();
}







