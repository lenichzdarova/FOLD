// Fill out your copyright notice in the Description page of Project Settings.


#include "Abilities/FOLD_GameplayAbility.h"

#include "Abilities/Tasks/AbilityTask_WaitCancel.h"
#include "Abilities/Tasks/AbilityTask_WaitConfirm.h"

void UFOLD_GameplayAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle,
                                            const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
                                            const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
		
	if (bool bIsTurnbased = false)
	{
		if (bool bIsPlayerControlled = true)
		{
			ShowAbilityUI();
		}
		UAbilityTask_WaitConfirm* WaitConfirmTask = UAbilityTask_WaitConfirm::WaitConfirm(this);
		WaitConfirmTask->OnConfirm.AddDynamic(this,&UFOLD_GameplayAbility::OnConfirmationSucceed);			
		UAbilityTask_WaitCancel* WaitCancelTask = UAbilityTask_WaitCancel::WaitCancel(this);
		WaitCancelTask->OnCancel.AddDynamic(this, &UFOLD_GameplayAbility::OnConfirmationCancelled);		
	}
	else
	{
		TryExecuteAbility();
	}
}

void UFOLD_GameplayAbility::ShowAbilityUI()
{
}

void UFOLD_GameplayAbility::OnConfirmationSucceed()
{
	TryExecuteAbility();
}

void UFOLD_GameplayAbility::OnConfirmationCancelled()
{
	EndAbility(GetCurrentAbilitySpecHandle(), GetCurrentActorInfo(), GetCurrentActivationInfo(), false, true);
}

void UFOLD_GameplayAbility::TryExecuteAbility()
{
	bool bIsCommited = CommitAbility(CurrentSpecHandle, GetCurrentActorInfo(), GetCurrentActivationInfo());
	if (bIsCommited)
	{
		ExecuteAbility();
	}
	else
	{
		EndAbility(GetCurrentAbilitySpecHandle(), GetCurrentActorInfo(), GetCurrentActivationInfo(), false, true);
	}	
}

void UFOLD_GameplayAbility::ExecuteAbility()
{
}

void UFOLD_GameplayAbility::OnAbilityTaskEnd()
{
	
}
