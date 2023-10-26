// Fill out your copyright notice in the Description page of Project Settings.


#include "HUDInputBridge.h"

#include "EnhancedInputComponent.h"

void UHUDInputBridge::Initialize(AHUDBase* hud, UPlayerInputData* inputData, UEnhancedInputLocalPlayerSubsystem* inputSubsystem)
{
	HUD = hud;
	InputData = inputData;	
	InputData->Initialize(inputSubsystem);
	BindEvents();	
}

void UHUDInputBridge::BindEvents()
{
	
}

void UHUDInputBridge::OnInventoryState()
{
	
}
void UHUDInputBridge::OnMapState()
{
	
}
void UHUDInputBridge::OnOptionState()
{
	
}
void UHUDInputBridge::OnPipboyState()
{
	
}
void UHUDInputBridge::OnCharacterSheetState()
{
	
}















