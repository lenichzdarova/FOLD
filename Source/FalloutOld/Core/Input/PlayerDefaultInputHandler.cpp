#include "PlayerDefaultInputHandler.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "EnhancedInputComponent.h"
#include "Abilities/GameplayAbility_MoveToLocation.h"

/*
void UInputContextDefault::OnLeftMouseButton(FHitResult InHit)
{	
	if (!InHit.bBlockingHit || !ActiveCharacter ) return;	
	IAbilitySystemInterface* AbilityInterface = Cast<IAbilitySystemInterface>(ActiveCharacter);
	if (!AbilityInterface) return;
	UAbilitySystemComponent* AbilityComponent = AbilityInterface->GetAbilitySystemComponent();
	FGameplayTag AbilityTag;
	
	if(InHit.GetActor()->Implements<UAbilitySystemInterface>())
	{		
		GEngine->AddOnScreenDebugMessage(222, 1, FColor::Red, "request interact");
	}		
	else
	{		
		AbilityTag = FGameplayTag::RequestGameplayTag("GameplayAbilities.Ability.Move");	
	}	
	
	FGameplayEventData EventData;
	EventData.Instigator = ActiveCharacter;
	EventData.Target = InHit.GetActor();	
	AbilityComponent->HandleGameplayEvent(AbilityTag, &EventData);		
}*/

/*
void UInputContextDefault::SetCursorData(FHitResult hit)
{
	
	if(hit.bBlockingHit)
	{		
		AActor* actor = hit.GetActor();		
		if(actor && actor->Implements<UAbilitySystemInterface>())
		{
			//сдесь мы запрашиваем дефолтное действие у актора и меняем курсор под него
			//CursorWidget->SetDialog();	синтаксис обращения к курсору
		}		
		else
		{			
			CursorWidget->SetDefault();			
		}		
	}
	else
	{
		CursorWidget->SetDefault();
	}
}*/


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
	}
}

void UPlayerDefaultInputHandler::OnCameraRotate(const FInputActionValue& InputValue)
{
	
}
