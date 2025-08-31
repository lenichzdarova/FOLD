// Fill out your copyright notice in the Description page of Project Settings.


#include "Abilities/GameplayAbility_MoveToLocation.h"

#include "AbilitySystemInterface.h"
#include "AIController.h"
#include "GameplayTagsManager.h"
#include "Abilities/Tasks/AbilityTask_MoveToLocation.h"
#include "Tasks/GameplayTask_MoveToLocation.h"

UGameplayAbility_MoveToLocation::UGameplayAbility_MoveToLocation()
{
	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;
	bRetriggerInstancedAbility = true;	
	FAbilityTriggerData Trigger;
	Trigger.TriggerTag = UGameplayTagsManager::Get().RequestGameplayTag("GameplayAbilities.Ability.MoveToLocation", true);	
	AbilityTriggers.Add(Trigger);
}

void UGameplayAbility_MoveToLocation::ExecuteAbility()
{
	Super::ExecuteAbility();

	auto MoveTask = UGameplayTask::NewTask<UGameplayTask_MoveToLocation>(this);
	MoveTask->OnTaskEnd.AddDynamic(this, &UGameplayAbility_MoveToLocation::OnMoveTaskEnd);

	auto TargetData = CurrentEventData.TargetData.Get(0);
	FVector MoveDestination = TargetData->GetHitResult()->Location;
	
	MoveTask->SetDestination(MoveDestination);
	MoveTask->ReadyForActivation();
}

void UGameplayAbility_MoveToLocation::OnMoveTaskEnd()
{	
	EndAbility(GetCurrentAbilitySpecHandle(), GetCurrentActorInfo(), GetCurrentActivationInfo(), false, false);
}
