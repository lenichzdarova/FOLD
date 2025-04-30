// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/PartySidePanel/PartyViewModel.h"

void UPartyViewModel::SetPlayerParty(UPlayerParty* PlayerParty)
{
	if (!IsValid(PlayerParty)) return;
	Party = PlayerParty;	
	DelegateHandle = Party->Changed.AddUObject(this, &UPartyViewModel::OnPlayerPartyUpdate);
	OnPlayerPartyUpdate();	
}

void UPartyViewModel::BeginDestroy()
{
	UObject::BeginDestroy();
	if (DelegateHandle.IsValid())
	{
		if (Party.IsValid())
		{
			Party->Changed.Remove(DelegateHandle);	
		}		
	}	
}

void UPartyViewModel::OnPlayerPartyUpdate()
{
	CharactersID = Party.Get()->GetPartyMembersID();
	OnPlayerPartyUpdated.Broadcast();
}
