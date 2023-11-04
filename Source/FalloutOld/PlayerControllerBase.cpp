// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerControllerBase.h"
#include "HUDInputBridge.h"
#include "UI/HUDBase.h"

void APlayerControllerBase::Initialize(APlayerView* CameraActor, ACharacterEntity* PlayerActor)
{
	PlayerView = CameraActor;
	SetViewTarget(PlayerView);
	bShowMouseCursor = true;
	PlayerCharacter = PlayerActor;
	WorldTravelHandler = NewObject<UWorldTravelHandler>(this);
	WorldTravelHandler->Initialize(Cast<UGameInstanceBase>(GetGameInstance()));
}

void APlayerControllerBase::Tick(float DeltaSeconds)
{
	WorldTravelHandler->Update(DeltaSeconds);
}



#pragma region InputReceiver
void APlayerControllerBase::OnActionInput_Implementation()
{	
	ActionInput.Broadcast();
}

void APlayerControllerBase::OnCameraMoveInput_Implementation(FVector2D value)
{
	CameraMoveInput.Broadcast(value);
}

void APlayerControllerBase::OnCameraRotateInput_Implementation(float value)
{	
	CameraRotateInput.Broadcast(value);
}

void APlayerControllerBase::OnBattleInput_Implementation()
{
	EndBattleInput.Broadcast();
}
void APlayerControllerBase::OnCancelInput_Implementation()
{
	CancelInput.Broadcast();
}
void APlayerControllerBase::OnEndTurnInput_Implementation()
{
	EndTurnInput.Broadcast();
}
void APlayerControllerBase::OnOpenInventoryInput_Implementation()
{
	OpenInventoryInput.Broadcast();
}
void APlayerControllerBase::OnOpenCharacterSheetInput_Implementation()
{
	OpenCharacterSheetInput.Broadcast();
}
void APlayerControllerBase::OnCursorContextInput_Implementation()
{
	CursorContextInput.Broadcast();
}
void APlayerControllerBase::OnOpenMapInput_Implementation()
{
	OpenMapInput.Broadcast();
}
void APlayerControllerBase::OnOpenPipBoyInput_Implementation()
{
	OpenPipBoyInput.Broadcast();
}
#pragma endregion InputReceiver


UEnhancedInputLocalPlayerSubsystem* APlayerControllerBase::GetEnhancedInputSubsystem()
{
	return ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
}

UWorldTravelHandler* APlayerControllerBase::GetTravelHandler()
{
	return WorldTravelHandler;
}

























