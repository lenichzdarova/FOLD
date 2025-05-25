// Fill out your copyright notice in the Description page of Project Settings.


#include "Attributes/HealthAttributeSet.h"
#include "GameplayEffectExtension.h"
#include "Net/UnrealNetwork.h"

void UHealthAttributeSet::OnRep_CurrentHealth(const FGameplayAttributeData& OldData)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UHealthAttributeSet, CurrentHealth, OldData);
}

float UHealthAttributeSet::GetCurrentHealth() const
{
	return CurrentHealth.GetCurrentValue();
}

void UHealthAttributeSet::SetCurrentHealth(float NewValue)
{
	NewValue = FMath::Max(NewValue, 0.0f);
	UAbilitySystemComponent* AbilitySystemComponent = GetOwningAbilitySystemComponent();
	if (ensure(AbilitySystemComponent))
	{
		AbilitySystemComponent->SetNumericAttributeBase(GetCurrentHealthAttribute(), NewValue);
	}	
}

void UHealthAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldData)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UHealthAttributeSet, MaxHealth, OldData);
}

float UHealthAttributeSet::GetMaxHealth() const
{
	return MaxHealth.GetCurrentValue();
}

void UHealthAttributeSet::SetMaxHealth(float NewValue)
{
	float delta = NewValue - MaxHealth.GetBaseValue();
	UAbilitySystemComponent* AbilitySystemComponent = GetOwningAbilitySystemComponent();
	if (ensure(AbilitySystemComponent))
	{
		AbilitySystemComponent->SetNumericAttributeBase(GetMaxHealthAttribute(), NewValue);		
	}
	SetCurrentHealth(CurrentHealth.GetBaseValue() + delta);
}

float UHealthAttributeSet::GetMaxHealthBase() const
{
	return MaxHealth.GetBaseValue();
}

void UHealthAttributeSet::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION_NOTIFY(UHealthAttributeSet, CurrentHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UHealthAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always )
}

void UHealthAttributeSet::PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	if (Data.EvaluatedData.Attribute == GetCurrentHealthAttribute())
	{
		SetCurrentHealth(GetCurrentHealth());		
	}
	if (Data.EvaluatedData.Attribute == GetMaxHealthAttribute())
	{
		SetMaxHealth(GetMaxHealth());
	}
}
