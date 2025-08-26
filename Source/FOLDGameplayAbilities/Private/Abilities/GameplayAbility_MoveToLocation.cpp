// Fill out your copyright notice in the Description page of Project Settings.


#include "Abilities/GameplayAbility_MoveToLocation.h"

#include "AbilitySystemInterface.h"
#include "AIController.h"
#include "GameplayTagsManager.h"
#include "Abilities/Tasks/AbilityTask_MoveToLocation.h"
#include "Tasks/GameplayTask_Move.h"

UGameplayAbility_MoveToLocation::UGameplayAbility_MoveToLocation()
{
	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;
	bRetriggerInstancedAbility = true;	
	FAbilityTriggerData Trigger;
	Trigger.TriggerTag = UGameplayTagsManager::Get().RequestGameplayTag("GameplayAbilities.Ability.Move", true);	
	AbilityTriggers.Add(Trigger);
}

void UGameplayAbility_MoveToLocation::ActivateAbility(const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
	const FGameplayEventData* TriggerEventData)
{	
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);	
	
	if (!CommitAbility(Handle, ActorInfo, ActivationInfo))
	{			
		constexpr bool bReplicateEndAbility = false;
		constexpr bool bWasCancelled = true;
		EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);
		return;
	}
	
	if (!IsValid(TriggerEventData->Target))
	{			
		return;
	}
	auto MoveTask = UGameplayTask::NewTask<UGameplayTask_Move>(this);
	MoveTask->OnTaskEnd.AddDynamic(this, &UGameplayAbility_MoveToLocation::OnMoveTaskEnd);

	auto TargetData = TriggerEventData->TargetData.Get(0);
	FVector MoveDestination = TargetData->GetHitResult()->Location;
	
	MoveTask->SetDestination(MoveDestination);
	MoveTask->ReadyForActivation();	
}

void UGameplayAbility_MoveToLocation::OnMoveTaskEnd()
{	
	EndAbility(GetCurrentAbilitySpecHandle(), GetCurrentActorInfo(), GetCurrentActivationInfo(), false, false);
}
