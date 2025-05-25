// Fill out your copyright notice in the Description page of Project Settings.


#include "Abilities/GameplayAbility_MoveToLocation.h"

#include "AbilitySystemInterface.h"
#include "AIController.h"
#include "GameplayTagsManager.h"
#include "Abilities/Tasks/AbilityTask_MoveToLocation.h"

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
		constexpr bool bReplicateEndAbility = true;
		constexpr bool bWasCancelled = true;
		EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);
		return;
	}

	
	if (!IsValid(TriggerEventData->Target))
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "no valid target");	
		return;
	}
	
	
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, ActorInfo->AvatarActor.Get()->GetName());	
}

void UGameplayAbility_MoveToLocation::EndAbility(const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
	bool bReplicateEndAbility, bool bWasCancelled)
{
	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);
}
