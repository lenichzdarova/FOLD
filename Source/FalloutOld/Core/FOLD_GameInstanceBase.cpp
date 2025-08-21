// Fill out your copyright notice in the Description page of Project Settings.


#include "FOLD_GameInstanceBase.h"
#include "Misc/PlayerParty.h"

void UFOLD_GameInstanceBase::Init()
{
	Super::Init();
	PlayerParty = NewObject<UPlayerParty>();
}
