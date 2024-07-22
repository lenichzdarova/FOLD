// Fill out your copyright notice in the Description page of Project Settings.


#include "Party.h"

const TArray<APawnBase*> UParty::GetParty() const
{
	return partyMembers;
}

void UParty::RemoveByIndex(int index)
{
	if(partyMembers.IsValidIndex(index))
	{
		partyMembers.RemoveAt(index);
	}
	PartyChanged.Broadcast();
}

void UParty::AddCharacter(APawnBase* pointer)
{	
	partyMembers.Add(pointer);
	PartyChanged.Broadcast();	
}
void UParty::RemoveByValue(APawnBase* pointer)
{
	partyMembers.RemoveSingle(pointer);
	PartyChanged.Broadcast();
}





