// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerControllerStateGameplay.h"

void UPlayerControllerStateGameplay::OnActionInput_Implementation()
{	
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 10, FColor::Red, "srenk");
	/*
	FHitResult hit;
	if(GetHitResultUnderCursor(ECC_Visibility, true, hit))
	{
		auto actor = hit.GetActor();
		if(auto grid = Cast<AGridActor>(actor) )
		{						
			auto action = NewObject<UActionMoveToPoint>(this);
			action->SetupAction(PlayerCharacter, grid, hit.Location);
			ActionHandler->AddAction(action);			
		}
	}	*/
}


void UPlayerControllerStateGameplay::OnBattleInput_Implementation()
{
	
}

void UPlayerControllerStateGameplay::OnCancelInput_Implementation()
{
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 10, FColor::Red, "Pook");
}

void UPlayerControllerStateGameplay::OnCameraRotateInput_Implementation(float value)
{
	
}

void UPlayerControllerStateGameplay::OnEndTurnInput_Implementation()
{
	
}

void UPlayerControllerStateGameplay::OnOpenInventoryInput_Implementation()
{
	
}

void UPlayerControllerStateGameplay::OnOpenCharacterSheetInput_Implementation()
{
	
}

void UPlayerControllerStateGameplay::OnToggleMouseContextInput_Implementation()
{
	
}

void UPlayerControllerStateGameplay::OnCameraMoveInput_Implementation(FVector2D value)
{
	/*value.Normalize();	
	FVector moveVector{value.X,value.Y,0};
	PlayerView->Move(moveVector);*/
}

void UPlayerControllerStateGameplay::Start()
{
	
}

void UPlayerControllerStateGameplay::Stop()
{
	
}

void UPlayerControllerStateGameplay::BindEvents()
{
	
}








