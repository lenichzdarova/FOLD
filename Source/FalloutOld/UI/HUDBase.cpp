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

void AHUDBase::Initialize(TScriptInterface<IInputProvider> inputResult, TScriptInterface<IInputReceiver> playerInputs, APawnBase* character, UWorldTravelHandler* WorldTravelHandler)
{
	InputProvider = inputResult;
	InputReceiver = playerInputs;
	PlayerCharacter = character;
	TravelHandler = WorldTravelHandler;	
}

void AHUDBase::SetCinematicState_Implementation()
{
	UHUDStateCinematic* cinematic = NewObject<UHUDStateCinematic>(this);
	cinematic->Initialize(this);
	Execute_SetState(this,cinematic);
	
}
void AHUDBase::SetDialogState_Implementation()
{
	UHUDStateDialog* dialog = NewObject<UHUDStateDialog>(this);
	dialog->Initialize(Dialog, DownPanel, this);
	Execute_SetState(this,dialog);
}
void AHUDBase::SetGameplayState_Implementation()
{
	UHUDStateGameplay* gameplay = NewObject<UHUDStateGameplay>(this);
	gameplay->Initialize(DownPanel,InputReceiver, InputProvider, this);
	Execute_SetState(this,gameplay);
}
void AHUDBase::SetInventoryState_Implementation()
{	
	UHUDStateInventory* inventory = NewObject<UHUDStateInventory>(this);
	inventory->Initialize(DownPanel, Inventory, this);
	Execute_SetState(this,inventory);
}
void AHUDBase::SetOptionsState_Implementation()
{
	UHUDStateOptions* options = NewObject<UHUDStateOptions>(this);
	options->Initialize(DownPanel,Options, this);
	Execute_SetState(this,options);
}
void AHUDBase::SetPipBoyState_Implementation()
{
	UHUDStatePipBoy* pipboy = NewObject<UHUDStatePipBoy>(this);
	pipboy->Initialize(PipBoy,DownPanel, this);
	Execute_SetState(this,pipboy);
}
void AHUDBase::SetCharacterSheetState_Implementation()
{
	UHUDStateCharacterSheet* charSheet = NewObject<UHUDStateCharacterSheet>(this);	
	charSheet->Initialize(CharacterSheet,DownPanel, this);
	Execute_SetState(this, charSheet);
}
void AHUDBase::SetIngameCinematicState_Implementation()
{
	UHUDStateIngameCinematic* ingameCinematic = NewObject<UHUDStateIngameCinematic>(this);
	ingameCinematic->Initialize(DownPanel, this);
	Execute_SetState(this,ingameCinematic);
}
void AHUDBase::SetLocalMapState_Implementation()
{
	UHUDStateLocalMap* localMap = NewObject<UHUDStateLocalMap>(this);
	localMap->Initialize(DownPanel,LocalMap, this);
	Execute_SetState(this,localMap);
}
void AHUDBase::SetMainMenuState_Implementation()
{
	UHUDStateMainMenu* mainMenu = NewObject<UHUDStateMainMenu>(this);
	mainMenu->Initialize(MainMenu, this);	
	Execute_SetState(this,mainMenu);
}
void AHUDBase::SetWorldMapState_Implementation()
{
	UHUDStateTravel* travel = NewObject<UHUDStateTravel>(this);
	auto widget = CreateWidget(GetOwningPlayerController(), Travel);
	UWidgetWorldTravel* widgetTravel = Cast<UWidgetWorldTravel>(widget);
	travel->Initialize(widgetTravel, this, TravelHandler);
	Execute_SetState(this,travel);
}
void AHUDBase::SetState_Implementation(UHUDStateBase* state)
{
	if(CurrentHUDState)
	{
		CurrentHUDState->Stop();
	}
	CurrentHUDState = state;
	CurrentHUDState->Start();
}


















