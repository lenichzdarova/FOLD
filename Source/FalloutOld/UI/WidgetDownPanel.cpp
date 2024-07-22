// Fill out your copyright notice in the Description page of Project Settings.


#include "WidgetDownPanel.h"
void UWidgetDownPanel::Initialize(APawnBase* playerCharacter)
{
	BindEvents();
}

void UWidgetDownPanel::OnCharacterButtonClick()
{
	CharacterButtonClicked.Broadcast();
}
void UWidgetDownPanel::OnInventoryButtonClick()
{
	InventoryButtonClicked.Broadcast();
}
void UWidgetDownPanel::OnMapButtonClick()
{
	MapButtonClicked.Broadcast();
}
void UWidgetDownPanel::OnOptionsButtonClick()
{
	OptionsButtonClicked.Broadcast();
}
void UWidgetDownPanel::OnPipBoyButtonClick()
{
	PipBoyButtonClicked.Broadcast();
}
void UWidgetDownPanel::BindEvents()
{
	InventoryButton->OnClicked.AddDynamic(this, &UWidgetDownPanel::OnInventoryButtonClick);
	CharacterButton->OnClicked.AddDynamic(this, &UWidgetDownPanel::OnCharacterButtonClick);
	MapButton->OnClicked.AddDynamic(this, &UWidgetDownPanel::OnMapButtonClick);
	OptionsButton->OnClicked.AddDynamic(this, &UWidgetDownPanel::OnOptionsButtonClick);
	PipBoyButton->OnClicked.AddDynamic(this, &UWidgetDownPanel::OnPipBoyButtonClick);
}










