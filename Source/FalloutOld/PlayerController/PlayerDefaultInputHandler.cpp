#include "PlayerDefaultInputHandler.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "EnhancedInputComponent.h"
#include "FOLD_ActorRefSubsystem.h"
#include "Kismet/GameplayStatics.h"
#include "Misc/FOLD_Statics.h"
#include "Targeting/FOLDTargetTypes.h"
#include "Misc/PlayerView.h"


void UPlayerDefaultInputHandler::BindInputEvents()
{
	Super::BindInputEvents();

	CursorAction = GetInputActionFromConfig(FGameplayTag::RequestGameplayTag("Input.CursorAction"));
	CursorContext = GetInputActionFromConfig(FGameplayTag::RequestGameplayTag("Input.CursorContext"));
	Cancel = GetInputActionFromConfig(FGameplayTag::RequestGameplayTag("Input.Cancel"));
	CameraMove = GetInputActionFromConfig(FGameplayTag::RequestGameplayTag("Input.CameraMove"));
	CameraRotate = GetInputActionFromConfig(FGameplayTag::RequestGameplayTag("Input.CameraRotate"));

	InputComponent->BindAction(CursorAction, ETriggerEvent::Triggered, this, &UPlayerDefaultInputHandler::OnCursorAction);
	InputComponent->BindAction(CursorContext, ETriggerEvent::Triggered, this, &UPlayerDefaultInputHandler::OnCursorContext);
	InputComponent->BindAction(Cancel, ETriggerEvent::Triggered, this, &UPlayerDefaultInputHandler::OnCancel);
	InputComponent->BindAction(CameraMove,ETriggerEvent::Triggered, this, &UPlayerDefaultInputHandler::OnCameraMove);
	InputComponent->BindAction(CameraRotate, ETriggerEvent::Triggered, this, &UPlayerDefaultInputHandler::OnCameraRotate);	
}

void UPlayerDefaultInputHandler::OnCursorAction(const FInputActionValue& InputValue)
{
	
	FHitResult HitResult = GetHitResult();
	if (!HitResult.bBlockingHit) return;
	
	if (AActor* ControlledActor = GetControlledActor())
	{		
		IAbilitySystemInterface* AbilityInterface = Cast<IAbilitySystemInterface>(ControlledActor);
		if (!AbilityInterface) return;
		UAbilitySystemComponent* AbilityComponent = AbilityInterface->GetAbilitySystemComponent();
		FGameplayTag AbilityTag;
	
		if(HitResult.GetActor()->Implements<UAbilitySystemInterface>())
		{		
			GEngine->AddOnScreenDebugMessage(222, 1, FColor::Red, "request interact");
		}		
		else
		{		
			AbilityTag = FGameplayTag::RequestGameplayTag("GameplayAbilities.Ability.Move");	
		}	
	
		FGameplayEventData EventData;
		EventData.Instigator = ControlledActor;
		EventData.Target = HitResult.GetActor();		
		FFOLDTargetData* TargetData = new FFOLDTargetData();
		TargetData->HitResult = HitResult;		
		EventData.TargetData.Add(TargetData);
		AbilityComponent->HandleGameplayEvent(AbilityTag, &EventData);
	}	
}

void UPlayerDefaultInputHandler::OnCursorContext(const FInputActionValue& InputValue)
{
}

void UPlayerDefaultInputHandler::OnCancel(const FInputActionValue& InputValue)
{
}

void UPlayerDefaultInputHandler::OnCameraMove(const FInputActionValue& InputValue)
{	
	if (InputValue.GetValueType() == EInputActionValueType::Axis2D)
	{
		FVector2D Value = InputValue.Get<FVector2D>();
		APlayerCameraManager* CameraManager = UGameplayStatics::GetPlayerCameraManager(GetWorld(), 0);
		AActor* ViewTarget = CameraManager->GetViewTarget();
		if (APlayerView* PlayerView = Cast<APlayerView>(ViewTarget))
		{
			PlayerView->Move(Value);
		}
	}
}

void UPlayerDefaultInputHandler::OnCameraRotate(const FInputActionValue& InputValue)
{
	
}

FHitResult UPlayerDefaultInputHandler::GetHitResult() const
{
	FHitResult hit;
	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	ETraceTypeQuery Query{ECC_Visibility};	
	PlayerController->GetHitResultUnderCursorByChannel(Query,true, hit);	
	return hit;
}

AActor* UPlayerDefaultInputHandler::GetControlledActor() const
{
	UWorld* World = GetWorld();		
	return UFOLD_Statics::GetPlayerCharacter(GetWorld());
}

