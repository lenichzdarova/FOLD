// Fill out your copyright notice in the Description page of Project Settings.


#include "Party.h"

const TArray<ACharacterBase*>& UParty::GetParty()
{
	return party;
}

void UParty::RemoveByIndex(int index)
{
	if(party.IsValidIndex(index))
	{
		party.RemoveAt(index);
	}
}

void UParty::AddCharacter(ACharacterBase* pointer)
{
	party.Add(pointer);
}
void UParty::RemoveByValue(ACharacterBase* pointer)
{
	party.RemoveSingle(pointer);
}



