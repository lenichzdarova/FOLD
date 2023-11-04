// Fill out your copyright notice in the Description page of Project Settings.


#include "HUDInputBridge.h"

#include "EnhancedInputComponent.h"

void UHUDInputBridge::Initialize(TScriptInterface<IHUDStateSwitcher> StateSwitcher, UInputMapper* mapper)
{
	HUDStateSwitcher = StateSwitcher;
	InputMapper = mapper;	
	BindEvents();	
}

void UHUDInputBridge::BindEvents()
{
	HUDStateSwitcher->CinematicState.AddUObject(this, &UHUDInputBridge::OnCinematicState);
	HUDStateSwitcher->DialogState.AddUObject(this, &UHUDInputBridge::OnDialogState);
	HUDStateSwitcher->GameplayState.AddUObject(this, &UHUDInputBridge::OnGameplayState);
	HUDStateSwitcher->InventoryState.AddUObject(this, &UHUDInputBridge::OnInventoryState);
	HUDStateSwitcher->OptionsState.AddUObject(this, &UHUDInputBridge::OnOptionState);
	HUDStateSwitcher->PipBoyState.AddUObject(this, &UHUDInputBridge::OnPipboyState);
	HUDStateSwitcher->CharacterSheetState.AddUObject(this, &UHUDInputBridge::OnCharacterSheetState);
	HUDStateSwitcher->IngameCinematicState.AddUObject(this, &UHUDInputBridge::OnIngameCinematicState);
	HUDStateSwitcher->LocalMapState.AddUObject(this, &UHUDInputBridge::OnLocalMapState);
	HUDStateSwitcher->MainMenuState.AddUObject(this, &UHUDInputBridge::OnMainMenuState);
	HUDStateSwitcher->WorldMapState.AddUObject(this, &UHUDInputBridge::OnWorldMapState);
}

void UHUDInputBridge::OnInventoryState()
{
	InputMapper->SetInventoryContext();
}
void UHUDInputBridge::OnLocalMapState()
{
	InputMapper->SetLocalMapContext();
}
void UHUDInputBridge::OnOptionState()
{
	InputMapper->SetOptionContext();
}
void UHUDInputBridge::OnPipboyState()
{
	InputMapper->SetPipBoyContext();
}
void UHUDInputBridge::OnCharacterSheetState()
{
	InputMapper->SetCharacterSheetContext();
}
void UHUDInputBridge::OnCinematicState()
{
	InputMapper->SetCinematicContext();
}
void UHUDInputBridge::OnDialogState()
{
	InputMapper->SetDialogContext();
}
void UHUDInputBridge::OnGameplayState()
{
	InputMapper->SetGameplayContext();
}
void UHUDInputBridge::OnWorldMapState()
{
	InputMapper->SetWorldMapContext();
}
void UHUDInputBridge::OnIngameCinematicState()
{
	InputMapper->SetIngameCinematicContext();
}
void UHUDInputBridge::OnMainMenuState()
{
	InputMapper->SetMainMenuContext();
}



















