// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/FOLDGameInstanceBase.h"

UFOLDGameInstanceBase::UFOLDGameInstanceBase(const FObjectInitializer& ObjectInitializer)
{
	Party = ObjectInitializer.CreateDefaultSubobject<UPlayerParty>(this, "Party");
	characterSelector = ObjectInitializer.CreateDefaultSubobject<USelector>(this, "Selector");	
}

void UFOLDGameInstanceBase::OnPartyChanged()
{
	
}

