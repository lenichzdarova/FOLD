// Fill out your copyright notice in the Description page of Project Settings.


#include "HUDStateGameplay.h"

void UHUDStateGameplay::Initialize(TSubclassOf<UWidgetDownPanel> downPanel, TScriptInterface<IInputReceiver> InputReceiver,
									TScriptInterface<IInputProvider> InputProvider, TScriptInterface<IHUDStateSwitcher> stateSwitcher)
{
	DownPanel = downPanel;
	PlayerInputReceiver = InputReceiver;
	PlayerInputProvider = InputProvider;
	StateSwitcher = stateSwitcher;
}

void UHUDStateGameplay::BindEvents()
{	/*
	DownPanel->InventoryButtonClicked.AddUObject(this, &UHUDStateGameplay::OnInventoryButtonClicked);
	DownPanel->CharacterButtonClicked.AddUObject(this, &UHUDStateGameplay::OnCharacterButtonClicked);
	DownPanel->OptionsButtonClicked.AddUObject(this, &UHUDStateGameplay::OnOptionsButtonClicked);
	DownPanel->PipBoyButtonClicked.AddUObject(this, &UHUDStateGameplay::OnPipBoyButtonClicked);
	DownPanel->MapButtonClicked.AddUObject(this, &UHUDStateGameplay::OnMapButtonClicked);

	PlayerInputProvider->OpenMapInput.AddUObject(this, &UHUDStateGameplay::OnOpenMapInput);
	PlayerInputProvider->OpenCharacterSheetInput.AddUObject(this, &UHUDStateGameplay::OnOpenCharacterInput);
	PlayerInputProvider->OpenInventoryInput.AddUObject(this, &UHUDStateGameplay::OnOpenInventoryInput);
	PlayerInputProvider->CancelInput.AddUObject(this, &UHUDStateGameplay::OnCancelInput);
	PlayerInputProvider->OpenPipBoyInput.AddUObject(this, &UHUDStateGameplay::OnOpenPipBoyInput);*/
}

void UHUDStateGameplay::UnbindEvents()
{/*
	DownPanel->InventoryButtonClicked.RemoveAll(this);
	DownPanel->CharacterButtonClicked.RemoveAll(this);
	DownPanel->OptionsButtonClicked.RemoveAll(this);
	DownPanel->PipBoyButtonClicked.RemoveAll(this);
	DownPanel->MapButtonClicked.RemoveAll(this);

	PlayerInputProvider->OpenMapInput.RemoveAll(this);
	PlayerInputProvider->OpenCharacterSheetInput.RemoveAll(this);
	PlayerInputProvider->OpenInventoryInput.RemoveAll(this);
	PlayerInputProvider->CancelInput.RemoveAll(this);
	PlayerInputProvider->OpenPipBoyInput.RemoveAll(this);*/
}

//buttons events
void UHUDStateGameplay::OnInventoryButtonClicked()
{
	PlayerInputReceiver->Execute_OnOpenInventoryInput(PlayerInputReceiver.GetObject());
}

void UHUDStateGameplay::OnCharacterButtonClicked()
{
	OnOpenCharacterInput();
}

void UHUDStateGameplay::OnMapButtonClicked()
{
	OnOpenMapInput();
}

void UHUDStateGameplay::OnOptionsButtonClicked()
{
	OnCancelInput();
}
void UHUDStateGameplay::OnPipBoyButtonClicked()
{
	OnOpenPipBoyInput();
}

//player input
void UHUDStateGameplay::OnOpenCharacterInput()
{
	StateSwitcher->Execute_SetCharacterSheetState(StateSwitcher.GetObject());
}
void UHUDStateGameplay::OnOpenInventoryInput()
{
	StateSwitcher->Execute_SetInventoryState(StateSwitcher.GetObject());
}
void UHUDStateGameplay::OnOpenMapInput()
{
	StateSwitcher->Execute_SetLocalMapState(StateSwitcher.GetObject());
}
void UHUDStateGameplay::OnCancelInput()
{
	StateSwitcher->Execute_SetOptionsState(StateSwitcher.GetObject());
}
void UHUDStateGameplay::OnOpenPipBoyInput()
{
	StateSwitcher->Execute_SetPipBoyState(StateSwitcher.GetObject());
}











