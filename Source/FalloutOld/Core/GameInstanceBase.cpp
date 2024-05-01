// Fill out your copyright notice in the Description page of Project Settings.


#include "GameInstanceBase.h"

UGameInstanceBase::UGameInstanceBase(const FObjectInitializer& ObjectInitializer)
{
	Party = ObjectInitializer.CreateDefaultSubobject<UParty>(this, "Party");
}
