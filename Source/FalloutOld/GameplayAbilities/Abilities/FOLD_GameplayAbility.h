// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "FOLD_GameplayAbility.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class FALLOUTOLD_API UFOLD_GameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()	
	
protected:

	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override final;	
	
	
	virtual void ShowAbilityUI();
	UFUNCTION()
	void OnConfirmationSucceed();
	UFUNCTION()
	void OnConfirmationCancelled();	
	void TryExecuteAbility();
	//место входа для имплементации логики абилки
	virtual void ExecuteAbility();
	//вызывается по окончанию основной логики абилки, которая поидее должна быть инкапсулирована в таск
	virtual void OnAbilityTaskEnd();		
};

