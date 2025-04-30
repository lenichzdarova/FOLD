// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/FOLDPlayerControllerBase.h"
#include "Core/FOLDGameInstanceBase.h"
#include "InputContextDefault.h"
#include "Core/FOLDGameState.h"


void AFOLDPlayerControllerBase::Initialize() 
{
	//spawn and setup playerView instance
	if (IsLocalController())
	{
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
	}
	
	//for not reset camera after possess character
	bAutoManageActiveCameraTarget = false;

	//set party
	
	AFOLDGameState* GameState = Cast<AFOLDGameState>(GetWorld()->GetGameState());
	if (GameState)
	{
		
	}	
}

void AFOLDPlayerControllerBase::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	if(inputContext)
	{		
		FHitResult hit;
		FVector location, direction;
		FCollisionQueryParams params;
		params.AddIgnoredActor(selector->GetFocusedCharacter());		
		DeprojectMousePositionToWorld(location,direction);
		GetWorld()->LineTraceSingleByChannel(hit, location, location + direction*10000.f, ECC_Visibility,params);		
		inputContext->SetCursorData(hit);		
	}	
}


#pragma region InputReceiver
void AFOLDPlayerControllerBase::OnActionInput_Implementation()
{
	if(inputContext)
	{
		inputContext->OnLeftMouseButton();
	}		
}

void AFOLDPlayerControllerBase::OnCameraMoveInput_Implementation(FVector2D value)
{
	if (PlayerView)
	{
		FVector moveOffset(0,0,0);
		moveOffset.X = value.X;
		moveOffset.Y = value.Y;	
		PlayerView->Move(moveOffset);
		CameraMoveInput.Broadcast(value);
	}	
}

void AFOLDPlayerControllerBase::OnCameraRotateInput_Implementation(float value)
{
	if (PlayerView)
	PlayerView->SetRotation(value);
	CameraRotateInput.Broadcast(value);
}

void AFOLDPlayerControllerBase::OnBattleInput_Implementation()
{
	EndBattleInput.Broadcast();
}
void AFOLDPlayerControllerBase::OnCancelInput_Implementation()
{
	CancelInput.Broadcast();
}
void AFOLDPlayerControllerBase::OnEndTurnInput_Implementation()
{
	EndTurnInput.Broadcast();
}
void AFOLDPlayerControllerBase::OnOpenInventoryInput_Implementation()
{
	OpenInventoryInput.Broadcast();
}
void AFOLDPlayerControllerBase::OnOpenCharacterSheetInput_Implementation()
{
	OpenCharacterSheetInput.Broadcast();
}
void AFOLDPlayerControllerBase::OnCursorContextInput_Implementation()
{
	CursorContextInput.Broadcast();
}
void AFOLDPlayerControllerBase::OnOpenMapInput_Implementation()
{
	OpenMapInput.Broadcast();
}
void AFOLDPlayerControllerBase::OnOpenPipBoyInput_Implementation()
{
	OpenPipBoyInput.Broadcast();
}
#pragma endregion InputReceiver


UEnhancedInputLocalPlayerSubsystem* AFOLDPlayerControllerBase::GetEnhancedInputSubsystem()
{
	return ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
}

/*
UWorldTravelHandler* APlayerControllerBase::GetTravelHandler()
{
	return WorldTravelHandler;
}*/

void AFOLDPlayerControllerBase::SetInputContext(UInputContextBase* context)
{	
	inputContext = context;	
}

void AFOLDPlayerControllerBase::SetInputContextDefault()
{
	auto context =  NewObject<UInputContextDefault>();
	context->Initialize(this, selector->GetFocusedCharacter(),CursorWidget, GetWorld(), ActionHandler);	
	SetInputContext(context);
}

void AFOLDPlayerControllerBase::OnFocusedCharacterChanged()
{
	//Possess(selector->GetFocusedCharacter());
	SetInputContextDefault();	
}

void AFOLDPlayerControllerBase::CycleCharacters()
{
	if (selector)
	selector->SetNext();
}





























