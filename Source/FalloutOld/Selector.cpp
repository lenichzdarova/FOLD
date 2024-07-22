// Fill out your copyright notice in the Description page of Project Settings.


#include "Selector.h"

APawnBase* USelector::GetFocusedCharacter() const
{
	return focused;
}

void USelector::SetFocusedByIndex(int index)
{	
	if(partyMembers.IsValidIndex(index))
	{
		APawnBase* selected = partyMembers[index];
		if(focused != selected)
		{
			SetFocusedByValue(selected);
		}		
	}
}

void USelector::SetPartyMembers(const TArray<APawnBase*> characters)
{
	partyMembers = characters;
	if(!characters.IsEmpty())
	{
		if(focused)
		{
			if(!partyMembers.Contains(focused))
			{
				SetFocusedByIndex(0);
			}		
		}
		else
		{
			SetFocusedByIndex(0);
		}
	}
	else
	{
		SetFocusedByValue(nullptr);
	}
}

void USelector::SetFocusedByValue(APawnBase* character)
{	
	if(partyMembers.Contains(character))
	{		
		if(focused != character)
		{
			focused = character;
			FocusedCharacterChanged.Broadcast();
			FString debugMessage = focused?focused.GetName(): "Nullptr";
			GEngine->AddOnScreenDebugMessage(INDEX_NONE,5, FColor::Red, debugMessage);
		}		
	}
}

void USelector::SetNext()
{
	if(!partyMembers.IsEmpty())
	{
		auto index = partyMembers.Find(focused);
		index = index == (partyMembers.Num() - 1)? 0 : ++index;
		SetFocusedByIndex(index);		
	}
}





