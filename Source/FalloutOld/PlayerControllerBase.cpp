// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerControllerBase.h"
#include "UI/HUDBase.h"

void APlayerControllerBase::Initialize(TSubclassOf<UInputMapper> Input)
{
	auto playerView = GetWorld()->SpawnActor<APlayerView>(FVector::Zero(), FRotator::ZeroRotator);
	PlayerView = playerView;
	SetViewTarget(PlayerView);
	
	auto playerCharacter = GetWorld()->SpawnActor<ACharacterEntity>(FVector::Zero(), FRotator::ZeroRotator);
	PlayerCharacter = playerCharacter;

	WorldTravelHandler = NewObject<UWorldTravelHandler>(this);	

	InputMapper = NewObject<UInputMapper>(this, Input.Get());
	InputMapper->Initialize(GetEnhancedInputSubsystem());
	
	AHUDBase* HUD = Cast<AHUDBase>(GetHUD());
	HUD->Initialize(this,this, PlayerCharacter, WorldTravelHandler);

	HUDInputBridging(HUD, InputMapper);
	
	bShowMouseCursor = true;	
}

void APlayerControllerBase::Tick(float DeltaSeconds)
{
	WorldTravelHandler->Update(DeltaSeconds);
}

void APlayerControllerBase::HUDInputBridging(TScriptInterface<IHUDStateSwitcher> HUDStateSwitcher, UInputMapper* inputMapper)
{
	HUDStateSwitcher->CinematicState.AddUObject(inputMapper, &UInputMapper::SetCinematicContext);
	HUDStateSwitcher->DialogState.AddUObject(inputMapper, &UInputMapper::SetDialogContext);
	HUDStateSwitcher->GameplayState.AddUObject(inputMapper, &UInputMapper::SetGameplayContext);
	HUDStateSwitcher->InventoryState.AddUObject(inputMapper, &UInputMapper::SetInventoryContext);
	HUDStateSwitcher->OptionsState.AddUObject(inputMapper, &UInputMapper::SetOptionContext);
	HUDStateSwitcher->PipBoyState.AddUObject(inputMapper, &UInputMapper::SetPipBoyContext);
	HUDStateSwitcher->CharacterSheetState.AddUObject(inputMapper, &UInputMapper::SetCharacterSheetContext);
	HUDStateSwitcher->IngameCinematicState.AddUObject(inputMapper, &UInputMapper::SetCinematicContext);
	HUDStateSwitcher->LocalMapState.AddUObject(inputMapper, &UInputMapper::SetLocalMapContext);
	HUDStateSwitcher->MainMenuState.AddUObject(inputMapper, &UInputMapper::SetMainMenuContext);
	HUDStateSwitcher->WorldMapState.AddUObject(inputMapper, &UInputMapper::SetWorldMapContext);
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

























