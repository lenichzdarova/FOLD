// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerControllerBase.h"

#include "GameInstanceBase.h"
#include "FalloutOld/InputContextDefault.h"
#include "Kismet/GameplayStatics.h"
#include "Runtime/AIModule/Classes/AIController.h"
//#include "UI/HUDBase.h"

/*
void APlayerControllerBase::Initialize(TSubclassOf<UInputMapper> Input)
{
	auto playerView = GetWorld()->SpawnActor<APlayerView>(FVector::Zero(), FRotator::ZeroRotator);
	PlayerView = playerView;
	SetViewTarget(PlayerView);	

	//WorldTravelHandler = NewObject<UWorldTravelHandler>(this);	

	//InputMapper = NewObject<UInputMapper>(this, Input.Get());
	//InputMapper->Initialize(GetEnhancedInputSubsystem());
	
	//AHUDBase* HUD = Cast<AHUDBase>(GetHUD());
	//HUD->Initialize(this,this, FocusedEntity, WorldTravelHandler);

	//HUDInputBridging(HUD, InputMapper);

	auto widget = CreateWidget(this, CursorWidgetType);
	CursorWidget = Cast<UWidgetCursor>(widget);
	bShowMouseCursor = true;	
	
	SetMouseCursorWidget(EMouseCursor::Default, CursorWidget);
	SetInputContextDefault();
	
	//focus game window
	FInputModeGameOnly mode;
	mode.SetConsumeCaptureMouseDown(false);
	SetInputMode(mode);	
}*/

void APlayerControllerBase::Initialize() 
{
	//spawn and setup playerView instance
	auto playerView = GetWorld()->SpawnActor<APlayerView>(FVector::Zero(), FRotator::ZeroRotator);
	PlayerView = playerView;
	SetViewTarget(PlayerView);

	//setup cursor
	auto widget = CreateWidget(this, CursorWidgetType);
	CursorWidget = Cast<UWidgetCursor>(widget);
	bShowMouseCursor = true;
	SetMouseCursorWidget(EMouseCursor::Default, CursorWidget);
	
	//focus game window
	FInputModeGameOnly mode;
	mode.SetConsumeCaptureMouseDown(false);
	SetInputMode(mode);
	
	//for not reset camera after possess character
	bAutoManageActiveCameraTarget = false;

	//set party
	UGameInstanceBase* gameInstance = Cast<UGameInstanceBase>(GetGameInstance());
	party = gameInstance->Party;
	selector = gameInstance->characterSelector;
	selector->FocusedCharacterChanged.AddDynamic(this, &APlayerControllerBase::OnFocusedCharacterChanged);	
}

void APlayerControllerBase::Tick(float DeltaSeconds)
{
	if(inputContext)
	{		
		FHitResult hit;
		FVector location, direction;
		DeprojectMousePositionToWorld(location,direction);
		FCollisionQueryParams params;
		params.AddIgnoredActor(selector->GetFocusedCharacter());
		GetWorld()->LineTraceSingleByChannel(hit, location, location + direction*10000.f, ECC_Visibility,params);		
		inputContext->SetCursorData(hit);
	}	
}


#pragma region InputReceiver
void APlayerControllerBase::OnActionInput_Implementation()
{
	/*
	FHitResult hit;
	GetHitResultUnderCursorByChannel(UEngineTypes::ConvertToTraceType(ECC_Visibility), false,hit);*/
	if(selector->GetFocusedCharacter())
	{
		FHitResult hit;
		FVector location, direction;
		DeprojectMousePositionToWorld(location,direction);
		FCollisionQueryParams params;
		params.AddIgnoredActor(selector->GetFocusedCharacter());
		GetWorld()->LineTraceSingleByChannel(hit, location, location + direction*10000.f, ECC_Visibility,params);
		//ActionInput.Broadcast(hit);
		inputContext->OnLeftMouseButton(hit);
	}	
}

void APlayerControllerBase::OnCameraMoveInput_Implementation(FVector2D value)
{
	FVector moveOffset(0,0,0);
	moveOffset.X = value.X;
	moveOffset.Y = value.Y;
	GEngine->AddOnScreenDebugMessage(INDEX_NONE,10, FColor::Red, moveOffset.ToString());
	PlayerView->Move(moveOffset);
	CameraMoveInput.Broadcast(value);
}

void APlayerControllerBase::OnCameraRotateInput_Implementation(float value)
{		
	PlayerView->SetRotation(value);
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

/*
UWorldTravelHandler* APlayerControllerBase::GetTravelHandler()
{
	return WorldTravelHandler;
}*/

void APlayerControllerBase::SetInputContext(UInputContextBase* context)
{	
	inputContext = context;	
}

void APlayerControllerBase::SetInputContextDefault()
{
	auto context =  NewObject<UInputContextDefault>();
	context->Initialize(this, selector->GetFocusedCharacter(),CursorWidget, GetWorld());	
	SetInputContext(context);
}

void APlayerControllerBase::OnFocusedCharacterChanged()
{
	//Possess(selector->GetFocusedCharacter());
	SetInputContextDefault();
}

void APlayerControllerBase::CycleCharacters()
{
	selector->SetNext();
}






























