// Fill out your copyright notice in the Description page of Project Settings.


#include "Abilities/GameplayAbility_Interaction.h"

#include "GameplayTagsManager.h"
#include "Interaction/InteractableActorComponent.h"
#include "Tasks/GameplayTask_MoveToActor.h"

UGameplayAbility_Interaction::UGameplayAbility_Interaction()
{
	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;
	bRetriggerInstancedAbility = true;	
	FAbilityTriggerData Trigger;
	Trigger.TriggerTag = UGameplayTagsManager::Get().RequestGameplayTag("GameplayAbilities.Ability.Interact", true);	
	AbilityTriggers.Add(Trigger);
}

void UGameplayAbility_Interaction::ExecuteAbility()
{
	Super::ExecuteAbility();

	auto MoveTask = UGameplayTask::NewTask<UGameplayTask_MoveToActor>(this);
	MoveTask->OnTaskEnd.AddDynamic(this, &UGameplayAbility_Interaction::OnMoveTaskEnd);

	auto TargetData = CurrentEventData.TargetData.Get(0);
	AActor* TargetActor = TargetData->GetHitResult()->GetActor();
	
	MoveTask->SetTargetActor(TargetActor);
	MoveTask->ReadyForActivation();
}

void UGameplayAbility_Interaction::OnMoveTaskEnd()
{
	const AActor* TargetActor = CurrentEventData.Target.Get();
	UInteractableActorComponent* InteractComponent = TargetActor->GetComponentByClass<UInteractableActorComponent>();
	if (!InteractComponent) return;
	InteractComponent->Interact(GetAvatarActorFromActorInfo());
}
