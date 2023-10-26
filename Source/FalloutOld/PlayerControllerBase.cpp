// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerControllerBase.h"

APlayerControllerBase::APlayerControllerBase()
{		
	ActionHandler = CreateDefaultSubobject<UActionHandler>("Action handler");	
}

void APlayerControllerBase::OnActionInput_Implementation()
{	
	
}

void APlayerControllerBase::OnCameraMoveInput_Implementation(FVector2D value)
{
		
}

void APlayerControllerBase::OnCameraRotateInput_Implementation(float value)
{	
	
}

void APlayerControllerBase::OnBattleInput_Implementation()
{
	
}
void APlayerControllerBase::OnCancelInput_Implementation()
{
	
}
void APlayerControllerBase::OnEndTurnInput_Implementation()
{
	
}
void APlayerControllerBase::OnOpenInventoryInput_Implementation()
{
	
}
void APlayerControllerBase::OnOpenCharacterSheetInput_Implementation()
{
	
}
void APlayerControllerBase::OnToggleMouseContextInput_Implementation()
{
	
}


UEnhancedInputLocalPlayerSubsystem* APlayerControllerBase::GetEnhancedInputSubsystem()
{
	return ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
}
























