// Fill out your copyright notice in the Description page of Project Settings.


#include "HUDStateGameplay.h"

void UHUDStateGameplay::Initialize(UWidgetDownPanel* downPanel, TScriptInterface<IInputReceiver> InputReceiver, TScriptInterface<IInputProvider> InputProvider)
{
	DownPanel = downPanel;
	PlayerInputReceiver = InputReceiver;
	PlayerInputProvider = InputProvider;
}

void UHUDStateGameplay::BindEvents()
{	
	DownPanel->InventoryButtonClicked.AddUObject(this, &UHUDStateGameplay::OnInventoryButtonClick);
	DownPanel->CharacterButtonClicked.AddUObject(this, &UHUDStateGameplay::OnCharacterButtonClicked);
	DownPanel->OptionsButtonClicked.AddUObject(this, &UHUDStateGameplay::OnOptionsButtonClicked);
	DownPanel->PipboyButtonClicked.AddUObject(this, &UHUDStateGameplay::OnPipboyButtonClicked);
	DownPanel->MapButtonClicked.AddUObject(this, &UHUDStateGameplay::OnMapButtonClicked);
}

void UHUDStateGameplay::UnbindEvents()
{
	DownPanel->InventoryButtonClicked.RemoveAll(this);
	DownPanel->CharacterButtonClicked.RemoveAll(this);
	DownPanel->OptionsButtonClicked.RemoveAll(this);
	DownPanel->PipboyButtonClicked.RemoveAll(this);
	DownPanel->MapButtonClicked.RemoveAll(this);
}

void UHUDStateGameplay::Start()
{
	DownPanel->AddToViewport();
	BindEvents();
}

void UHUDStateGameplay::Stop()
{
	DownPanel->RemoveFromParent();
	UnbindEvents();
}

void UHUDStateGameplay::OnInventoryButtonClick()
{
	PlayerInputReceiver->Execute_OnOpenInventoryInput(PlayerInputReceiver.GetObject());
}

void UHUDStateGameplay::OnCharacterButtonClicked()
{
	PlayerInputReceiver->Execute_OnOpenCharacterSheetInput(PlayerInputReceiver.GetObject());
}

void UHUDStateGameplay::OnMapButtonClicked()
{
	//not implemented yet
}

void UHUDStateGameplay::OnOptionsButtonClicked()
{
	PlayerInputReceiver->Execute_OnCancelInput(PlayerInputReceiver.GetObject());
}
void UHUDStateGameplay::OnPipboyButtonClicked()
{
	//not implemented yet
}





