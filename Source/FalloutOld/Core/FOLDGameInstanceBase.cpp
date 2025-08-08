// Fill out your copyright notice in the Description page of Project Settings.


#include "FOLDGameInstanceBase.h"
#include "Unsorted/PlayerParty.h"

void UFOLDGameInstanceBase::Init()
{
	Super::Init();
	PlayerParty = MakeShared<UPlayerParty>();
}
