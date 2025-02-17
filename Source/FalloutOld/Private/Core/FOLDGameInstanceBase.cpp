// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/FOLDGameInstanceBase.h"

UFOLDGameInstanceBase::UFOLDGameInstanceBase(const FObjectInitializer& ObjectInitializer)
{
	Party = ObjectInitializer.CreateDefaultSubobject<UParty>(this, "Party");
	characterSelector = ObjectInitializer.CreateDefaultSubobject<USelector>(this, "Selector");
	Party->PartyChanged.AddDynamic(this, &UFOLDGameInstanceBase::OnPartyChanged);
	WorldActions = ObjectInitializer.CreateDefaultSubobject<UActionHandler>(this, "Action handler");
}

void UFOLDGameInstanceBase::OnPartyChanged()
{
	characterSelector->SetPartyMembers(Party->GetParty());
}

