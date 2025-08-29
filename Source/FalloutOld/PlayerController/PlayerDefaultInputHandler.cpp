#include "PlayerDefaultInputHandler.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "CursorContextComponent.h"
#include "EnhancedInputComponent.h"
#include "FOLD_ActorRefSubsystem.h"
#include "InteractableActorComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Misc/FOLD_Statics.h"
#include "Targeting/FOLDTargetTypes.h"
#include "Misc/PlayerView.h"


void UPlayerDefaultInputHandler::BindInputEvents()
{
	Super::BindInputEvents();

	Action = GetInputActionFromConfig(FGameplayTag::RequestGameplayTag("Input.CursorAction"));
	RequestContext = GetInputActionFromConfig(FGameplayTag::RequestGameplayTag("Input.CursorContext"));
	Cancel = GetInputActionFromConfig(FGameplayTag::RequestGameplayTag("Input.Cancel"));
	CameraMove = GetInputActionFromConfig(FGameplayTag::RequestGameplayTag("Input.CameraMove"));
	CameraRotate = GetInputActionFromConfig(FGameplayTag::RequestGameplayTag("Input.CameraRotate"));

	InputComponent->BindAction(Action, ETriggerEvent::Triggered, this, &UPlayerDefaultInputHandler::OnCursorAction);
	InputComponent->BindAction(RequestContext, ETriggerEvent::Triggered, this, &UPlayerDefaultInputHandler::OnCursorContext);
	InputComponent->BindAction(Cancel, ETriggerEvent::Triggered, this, &UPlayerDefaultInputHandler::OnCancel);
	InputComponent->BindAction(CameraMove,ETriggerEvent::Triggered, this, &UPlayerDefaultInputHandler::OnCameraMove);
	InputComponent->BindAction(CameraRotate, ETriggerEvent::Triggered, this, &UPlayerDefaultInputHandler::OnCameraRotate);	
}

void UPlayerDefaultInputHandler::OnCursorAction(const FInputActionValue& InputValue)
{	
	const FHitResult HitResult = GetHitResult();
	if (!HitResult.bBlockingHit) return;
	
	if (AActor* ControlledActor = GetControlledActor())
	{		
		IAbilitySystemInterface* AbilityInterface = Cast<IAbilitySystemInterface>(ControlledActor);
		if (!AbilityInterface) return;
		UAbilitySystemComponent* AbilityComponent = AbilityInterface->GetAbilitySystemComponent();
		FGameplayTag AbilityTag;
	
		if(HitResult.GetActor()->GetComponentByClass<UInteractableActorComponent>())
		{		
			AbilityTag = FGameplayTag::RequestGameplayTag("GameplayAbilities.Ability.Interact");
		}		
		else
		{		
			AbilityTag = FGameplayTag::RequestGameplayTag("GameplayAbilities.Ability.MoveToLocation");	
		}	
		
		FGameplayEventData EventData;		
		EventData.Instigator = ControlledActor;
		EventData.Target = HitResult.GetActor();			
		EventData.TargetData.Add(new FGameplayAbilityTargetData_SingleTargetHit(HitResult));
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
	if (InputValue.GetValueType() == EInputActionValueType::Axis1D)
	{
		float Value = InputValue.Get<float>();
		APlayerCameraManager* CameraManager = UGameplayStatics::GetPlayerCameraManager(GetWorld(), 0);
		AActor* ViewTarget = CameraManager->GetViewTarget();
		if (APlayerView* PlayerView = Cast<APlayerView>(ViewTarget))
		{
			PlayerView->SetRotation(Value);
		}
	}
}

const FHitResult& UPlayerDefaultInputHandler::GetHitResult() const
{
	APlayerController* Controller = Cast<APlayerController>(GetOuter());
	UCursorContextComponent* CursorContextComponent = Controller->GetComponentByClass<UCursorContextComponent>();
	return  CursorContextComponent->GetHitResult();
}

AActor* UPlayerDefaultInputHandler::GetControlledActor() const
{
	UWorld* World = GetWorld();		
	return UFOLD_Statics::GetPlayerCharacter(GetWorld());
}

