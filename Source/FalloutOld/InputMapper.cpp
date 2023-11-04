// Fill out your copyright notice in the Description page of Project Settings.


#include "InputMapper.h"

void UInputMapper::Initialize(UEnhancedInputLocalPlayerSubsystem* subsystem)
{
	InputSubsystem = subsystem;
	subsystem->AddMappingContext(Default,0);
}

void UInputMapper::SetMappingContext(UInputMappingContext* context)
{
	InputSubsystem->ClearAllMappings();
	InputSubsystem->AddMappingContext(context,0);
}

void UInputMapper::SetDefaultContext()
{
	SetMappingContext(Default);
}
void UInputMapper::SetInventoryContext()
{
	SetMappingContext(Inventory);
}

void UInputMapper::SetCharacterSheetContext()
{
	UE_LOG(LogTemp, Warning, TEXT("Not implemented"));
}
void UInputMapper::SetOptionContext()
{
	UE_LOG(LogTemp, Warning, TEXT("Not implemented"));
}
void UInputMapper::SetPipBoyContext()
{
	UE_LOG(LogTemp, Warning, TEXT("Not implemented"));
}
void UInputMapper::SetLocalMapContext()
{
	UE_LOG(LogTemp, Warning, TEXT("Not implemented"));
}
void UInputMapper::SetWorldMapContext()
{
	UE_LOG(LogTemp, Warning, TEXT("Not implemented"));
}
void UInputMapper::SetCinematicContext()
{
	UE_LOG(LogTemp, Warning, TEXT("Not implemented"));
}
void UInputMapper::SetDialogContext()
{
	UE_LOG(LogTemp, Warning, TEXT("Not implemented"));
}
void UInputMapper::SetGameplayContext()
{
	UE_LOG(LogTemp, Warning, TEXT("Not implemented"));
}
void UInputMapper::SetIngameCinematicContext()
{
	UE_LOG(LogTemp, Warning, TEXT("Not implemented"));
}
void UInputMapper::SetMainMenuContext()
{
	UE_LOG(LogTemp, Warning, TEXT("Not implemented"));
}



