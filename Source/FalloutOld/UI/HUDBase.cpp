// Fill out your copyright notice in the Description page of Project Settings.


#include "HUDBase.h"
#include "HUDStateCharacterSheet.h"
#include "HUDStateCinematic.h"
#include "HUDStateDialog.h"
#include "HUDStateGameplay.h"
#include "HUDStateIngameCinematic.h"
#include "HUDStateOptions.h"
#include "HUDStateInventory.h"
#include "HUDStateLocalMap.h"
#include "HUDStateMainMenu.h"
#include "HUDStatePipBoy.h"
#include "HUDStateTravel.h"

void AHUDBase::Initialize(TScriptInterface<IInputProvider> inputResult, TScriptInterface<IInputReceiver> playerInputs, ACharacterEntity* character, UWorldTravelHandler* WorldTravelHandler)
{
	InputProvider = inputResult;
	InputReceiver = playerInputs;
	PlayerCharacter = character;
	TravelHandler = WorldTravelHandler;
	SetupStates();
}

void AHUDBase::SetupStates()
{
	UHUDStateCharacterSheet* charSheet = NewObject<UHUDStateCharacterSheet>(this);	
	charSheet->Initialize(CharacterSheet,DownPanel, this);
	AllHUDStates.Add(charSheet);

	UHUDStateCinematic* cinematic = NewObject<UHUDStateCinematic>(this);
	cinematic->Initialize(this);
	AllHUDStates.Add(cinematic);

	UHUDStateDialog* dialog = NewObject<UHUDStateDialog>(this);
	dialog->Initialize(Dialog, DownPanel, this);
	AllHUDStates.Add(dialog);

	UHUDStateGameplay* gameplay = NewObject<UHUDStateGameplay>(this);
	gameplay->Initialize(DownPanel,InputReceiver, InputProvider, this);
	AllHUDStates.Add(gameplay);

	UHUDStateIngameCinematic* ingameCinematic = NewObject<UHUDStateIngameCinematic>(this);
	ingameCinematic->Initialize(DownPanel, this);
	AllHUDStates.Add(ingameCinematic);

	UHUDStateInventory* inventory = NewObject<UHUDStateInventory>(this);
	inventory->Initialize(DownPanel, Inventory, this);
	AllHUDStates.Add(inventory);

	UHUDStateLocalMap* localMap = NewObject<UHUDStateLocalMap>(this);
	localMap->Initialize(DownPanel,LocalMap, this);
	AllHUDStates.Add(localMap);

	UHUDStateMainMenu* mainMenu = NewObject<UHUDStateMainMenu>(this);
	mainMenu->Initialize(MainMenu, this);
	AllHUDStates.Add(mainMenu);

	UHUDStateOptions* options = NewObject<UHUDStateOptions>(this);
	options->Initialize(DownPanel,Options, this);
	AllHUDStates.Add(options);

	UHUDStatePipBoy* pipboy = NewObject<UHUDStatePipBoy>(this);
	pipboy->Initialize(PipBoy,DownPanel, this);
	AllHUDStates.Add(pipboy);

	UHUDStateTravel* travel = NewObject<UHUDStateTravel>(this);
	travel->Initialize(Travel, this, TravelHandler);
	AllHUDStates.Add(travel);
}

void AHUDBase::SetState_Implementation(TSubclassOf<UHUDStateBase> type)
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
void AHUDBase::SetCinematicState_Implementation()
{
	Execute_SetState(this,UHUDStateCinematic::StaticClass());
}
void AHUDBase::SetDialogState_Implementation()
{
	Execute_SetState(this,UHUDStateDialog::StaticClass());
}
void AHUDBase::SetGameplayState_Implementation()
{
	Execute_SetState(this,UHUDStateGameplay::StaticClass());
}
void AHUDBase::SetInventoryState_Implementation()
{
	Execute_SetState(this,UHUDStateInventory::StaticClass());
}
void AHUDBase::SetOptionsState_Implementation()
{
	Execute_SetState(this,UHUDStateOptions::StaticClass());
}
void AHUDBase::SetPipBoyState_Implementation()
{
	Execute_SetState(this,UHUDStatePipBoy::StaticClass());
}
void AHUDBase::SetCharacterSheetState_Implementation()
{
	Execute_SetState(this,UHUDStateCharacterSheet::StaticClass());
}
void AHUDBase::SetIngameCinematicState_Implementation()
{
	Execute_SetState(this,UHUDStateIngameCinematic::StaticClass());
}
void AHUDBase::SetLocalMapState_Implementation()
{
	Execute_SetState(this,UHUDStateLocalMap::StaticClass());
}
void AHUDBase::SetMainMenuState_Implementation()
{
	Execute_SetState(this,UHUDStateMainMenu::StaticClass());
}
void AHUDBase::SetWorldMapState_Implementation()
{
	Execute_SetState(this,UHUDStateTravel::StaticClass());
}

















