// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerInputData.h"

UPlayerInputData::UPlayerInputData()
{

}

void UPlayerInputData::Initialize(UEnhancedInputLocalPlayerSubsystem* subsystem)
{
	InputSubsystem = subsystem;
	subsystem->AddMappingContext(Default,0);
}

void UPlayerInputData::SetMappingContext(UInputMappingContext* context)
{
	InputSubsystem->ClearAllMappings();
	InputSubsystem->AddMappingContext(context,0);
}

void UPlayerInputData::SetDefaultContext()
{
	SetMappingContext(Default);
}
void UPlayerInputData::SetInventoryContext()
{
	SetMappingContext(Inventory);
}

void UPlayerInputData::SetMenuContext()
{
	SetMappingContext(Menu);
}



