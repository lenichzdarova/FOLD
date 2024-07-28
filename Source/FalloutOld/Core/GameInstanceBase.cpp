// Fill out your copyright notice in the Description page of Project Settings.


#include "GameInstanceBase.h"

UGameInstanceBase::UGameInstanceBase(const FObjectInitializer& ObjectInitializer)
{
	Party = ObjectInitializer.CreateDefaultSubobject<UParty>(this, "Party");
	characterSelector = ObjectInitializer.CreateDefaultSubobject<USelector>(this, "Selector");
	Party->PartyChanged.AddDynamic(this, &UGameInstanceBase::OnPartyChanged);
	WorldActions = ObjectInitializer.CreateDefaultSubobject<UActionHandler>(this, "Action handler");
}

void UGameInstanceBase::OnPartyChanged()
{
	characterSelector->SetPartyMembers(Party->GetParty());
}

