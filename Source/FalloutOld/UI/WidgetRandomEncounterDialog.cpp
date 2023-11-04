// Fill out your copyright notice in the Description page of Project Settings.


#include "WidgetRandomEncounterDialog.h"

void UWidgetRandomEncounterDialog::Initialize(RandomEncounterData* EncounterData)
{
	SetEncounterDescription();
	ChooseAccept.AddUObject(this, &UWidgetRandomEncounterDialog::OnAcceptButtonClick);
	ChooseDecline.AddUObject(this, &UWidgetRandomEncounterDialog::OnDeclineButtonClick);
}
void UWidgetRandomEncounterDialog::SetEncounterDescription()
{
	ChooseAccept.Broadcast();
}
void UWidgetRandomEncounterDialog::OnAcceptButtonClick()
{
	ChooseAccept.Broadcast();
}
void UWidgetRandomEncounterDialog::OnDeclineButtonClick()
{
	ChooseDecline.Broadcast();
}





