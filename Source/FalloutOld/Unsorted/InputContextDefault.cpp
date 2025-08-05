#include "InputContextDefault.h"
#include "AbilitySystemBlueprintLibrary.h"

void UInputContextDefault::Initialize(IInputProvider* inputProvider, APawnBase* activeCharacter, UWidgetCursor* cursorWidget, UWorld* world)	
{
	Super::Initialize(inputProvider, activeCharacter, cursorWidget, world);
	BindInputEvents(inputProvider);	
}

void UInputContextDefault::BindInputEvents(IInputProvider* value)
{	
	
}

void UInputContextDefault::OnLeftMouseButton(FHitResult InHit)
{
	if (!InHit.bBlockingHit || !ActiveCharacter ) return;	
	IAbilitySystemInterface* AbilityInterface = Cast<IAbilitySystemInterface>(ActiveCharacter);
	if (!AbilityInterface) return;
	UAbilitySystemComponent* AbilityComponent = AbilityInterface->GetAbilitySystemComponent();
	FGameplayTag AbilityTag;
	if(InHit.GetActor()->Implements<UAbilitySystemInterface>())
	{
		AbilityTag = FGameplayTag::RequestGameplayTag("GameplayAbility.Ability.Interact");
	}		
	else
	{			
		AbilityTag = FGameplayTag::RequestGameplayTag("GameplayAbility.Ability.Move");	
	}		
	
	FGameplayEventData EventData;
	EventData.Instigator = ActiveCharacter;
	EventData.Target = InHit.GetActor();	
	AbilityComponent->HandleGameplayEvent(AbilityTag, &EventData);
}

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
}




