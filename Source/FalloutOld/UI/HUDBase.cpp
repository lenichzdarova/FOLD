// Fill out your copyright notice in the Description page of Project Settings.


#include "HUDBase.h"

#include "HUDStateCharacterSheet.h"
#include "HUDStateDialog.h"
#include "HUDStateGameplay.h"
#include "HUDStateInventory.h"
#include "HUDStateOptions.h"

void AHUDBase::Initialize(TScriptInterface<IInputProvider> inputProvider, TScriptInterface<IInputReceiver> inputReceiver, ACharacterEntity* playerCharacter)
{
	
}

void AHUDBase::SetupStates()
{
	//here create and iniatialize all states.
}

void AHUDBase::SetState(TSubclassOf<UHUDStateBase> type)
{
	if(CurrentHUDState)
	{
		CurrentHUDState->Stop();
	}	
	for (auto state : AllHUDStates)
	{
		if( state->IsA(type))
		{
			CurrentHUDState = state;
		}
	}
	CurrentHUDState->Start();
}


void AHUDBase::SetDialogState()
{
	SetState(UHUDStateDialog::StaticClass());
}
void AHUDBase::SetGameplayState()
{
	SetState(UHUDStateGameplay::StaticClass());
}
void AHUDBase::SetCharacterSheetState()
{
	SetState(UHUDStateCharacterSheet::StaticClass());
}
void AHUDBase::SetOptionsState()
{
	SetState(UHUDStateOptions::StaticClass());
}

void AHUDBase::SetInventoryState()
{
	SetState(UHUDStateInventory::StaticClass());
}
void AHUDBase::SetPipboyState()
{
	
}

void AHUDBase::SetLocalMapState()
{
	
}

void AHUDBase::SetMainMenuState()
{
	
}
void AHUDBase::SetWorldMapState()
{
	
}



