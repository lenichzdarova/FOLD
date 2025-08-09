// Fill out your copyright notice in the Description page of Project Settings.

#include "FOLDPlayerControllerBase.h"

#include "FOLDActorRefSubsystem.h"
#include "FOLDGameInstanceBase.h"
#include "FalloutOld/Unsorted/InputContextDefault.h"
#include "Kismet/GameplayStatics.h"

void AFOLDPlayerControllerBase::Initialize()
{
	// spawn and setup playerView instance
	if (IsLocalController())
	{		
		// setup cursor
		auto widget = CreateWidget(this, CursorWidgetType);
		CursorWidget = Cast<UWidgetCursor>(widget);
		bShowMouseCursor = true;
		SetMouseCursorWidget(EMouseCursor::Default, CursorWidget);
		
		// focus game window
		FInputModeGameOnly mode;
		mode.SetConsumeCaptureMouseDown(false);
		SetInputMode(mode);
		
		//inputcontext
		SetInputContextDefault();
		UFOLDActorRefSubsystem* ActorRefSubsystem = GetWorld()->GetSubsystem<UFOLDActorRefSubsystem>();
		if (!ActorRefSubsystem) return;
		if(AActor* PlayerActor = ActorRefSubsystem->GetActorByTag(FGameplayTag::RequestGameplayTag("Actors.Player")))
		{
			ACharacterBase* PlayerCharacter = Cast<ACharacterBase>(PlayerActor);
			inputContext->Initialize(this, PlayerCharacter, nullptr, nullptr);
			//SetupCamera
			FTransform CameraInitTransform = PlayerCharacter->GetTransform();
			auto playerView = GetWorld()->SpawnActor<APlayerView>(CameraInitTransform.GetLocation(), CameraInitTransform.Rotator());
			PlayerView = playerView;
			SetViewTarget(PlayerView);
		}		
	}

	// for not reset camera after possess character
	bAutoManageActiveCameraTarget = false;
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "FOLDPlayerControllerBase::Initialize");
}

void AFOLDPlayerControllerBase::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	if (inputContext)
	{
		FHitResult hit;
		FVector location, direction;
		FCollisionQueryParams params;
		params.AddIgnoredActor(GetPawn());
		DeprojectMousePositionToWorld(location, direction);
		GetWorld()->LineTraceSingleByChannel(
			hit, location, location + direction * 10000.f, ECC_Visibility, params);
		inputContext->SetCursorData(hit);
	}
}

#pragma region InputReceiver
void AFOLDPlayerControllerBase::OnActionInput_Implementation()
{
	if (inputContext)
	{
		FHitResult Hit;
		if (GetHitResultUnderCursor(ECC_Visibility, true, Hit))
		{
			inputContext->OnLeftMouseButton(Hit);
		}
	}
}

void AFOLDPlayerControllerBase::OnCameraMoveInput_Implementation(
	FVector2D value)
{
	if (PlayerView)
	{
		FVector moveOffset(0, 0, 0);
		moveOffset.X = value.X;
		moveOffset.Y = value.Y;
		PlayerView->Move(moveOffset);
		CameraMoveInput.Broadcast(value);
	}
}

void AFOLDPlayerControllerBase::OnCameraRotateInput_Implementation(
	float value)
{
	if (PlayerView)
	{
		PlayerView->SetRotation(value);
	}
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

UEnhancedInputLocalPlayerSubsystem*
AFOLDPlayerControllerBase::GetEnhancedInputSubsystem()
{
	return ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(
		GetLocalPlayer());
}

void AFOLDPlayerControllerBase::SetInputContext(UInputContextBase* context)
{
	inputContext = context;
}

void AFOLDPlayerControllerBase::SetInputContextDefault()
{
	auto context = NewObject<UInputContextDefault>();
	SetInputContext(context);
}
