// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerControllerBase.h"
#include "PlayerControllerStateGameplay.h"
#include "PlayerControllerStateUI.h"

APlayerControllerBase::APlayerControllerBase()
{		
	ActionHandler = CreateDefaultSubobject<UActionHandler>("Action handler");	
}

void APlayerControllerBase::OnActionInput_Implementation()
{	
	Execute_OnActionInput(CurrentState);
}

void APlayerControllerBase::OnCameraMoveInput_Implementation(FVector2D value)
{
	Execute_OnCameraMoveInput(CurrentState,value);	
}

void APlayerControllerBase::OnCameraRotateInput_Implementation(float value)
{	
	Execute_OnCameraRotateInput(CurrentState, value);	
}

void APlayerControllerBase::OnBattleInput_Implementation()
{
	Execute_OnBattleInput(CurrentState);
}
void APlayerControllerBase::OnCancelInput_Implementation()
{
	Execute_OnCancelInput(CurrentState);
}
void APlayerControllerBase::OnEndTurnInput_Implementation()
{
	Execute_OnEndTurnInput(CurrentState);
}
void APlayerControllerBase::OnOpenInventoryInput_Implementation()
{
	Execute_OnOpenInventoryInput(CurrentState);
}
void APlayerControllerBase::OnOpenCharacterSheetInput_Implementation()
{
	Execute_OnOpenCharacterSheetInput(CurrentState);
}
void APlayerControllerBase::OnToggleMouseContextInput_Implementation()
{
	Execute_OnToggleMouseContextInput(CurrentState);
}

void APlayerControllerBase::SetInputState(TSubclassOf<UPlayerControllerStateBase> type)
{
	if(CurrentState)
	{
		CurrentState->Stop();
	}	
	for (auto state : AllStates)
	{
		if( state->IsA(type))
		{
			CurrentState = state;
		}
	}
	CurrentState->Start();
}

void APlayerControllerBase::SetupStates()
{
	UPlayerControllerStateGameplay* gameplayState = NewObject<UPlayerControllerStateGameplay>(this);	
	AllStates.Add(gameplayState);	
	UPlayerControllerStateUI* uiState = NewObject<UPlayerControllerStateUI>(this);
	AllStates.Add(uiState);
	for (auto state : AllStates)
	{
		state->Initialize(HUD, PlayerCharacter, CursorController);
	}
	SetInputState(UPlayerControllerStateGameplay::StaticClass());	
}























