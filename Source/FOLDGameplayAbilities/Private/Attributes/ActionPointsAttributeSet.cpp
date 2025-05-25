// Fill out your copyright notice in the Description page of Project Settings.

#include "Attributes/ActionPointsAttributeSet.h"
#include "AbilitySystemComponent.h"
#include "GameplayEffectExtension.h"
#include "Net/UnrealNetwork.h"

void UActionPointsAttributeSet::OnRep_CurrentPoints(const FGameplayAttributeData& OldData)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UActionPointsAttributeSet, CurrentPoints, OldData);
}

float UActionPointsAttributeSet::GetCurrentPoints() const
{
	return CurrentPoints.GetCurrentValue();
}

void UActionPointsAttributeSet::SetCurrentPoints(float NewValue)
{
	NewValue = FMath::Max(NewValue, 0.0f);
	UAbilitySystemComponent* AbilitySystemComponent = GetOwningAbilitySystemComponent();
	if (ensure(AbilitySystemComponent))
	{
		AbilitySystemComponent->SetNumericAttributeBase(GetCurrentPointsAttribute(), NewValue);
	}	
}

void UActionPointsAttributeSet::OnRep_MaxPoints(const FGameplayAttributeData& OldData)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UActionPointsAttributeSet, MaxPoints, OldData);
}

float UActionPointsAttributeSet::GetMaxPoints() const
{
	return MaxPoints.GetCurrentValue();
}

void UActionPointsAttributeSet::SetMaxPoints(float NewValue)
{
	float delta = NewValue - MaxPoints.GetBaseValue();
	UAbilitySystemComponent* AbilitySystemComponent = GetOwningAbilitySystemComponent();
	if (ensure(AbilitySystemComponent))
	{
		AbilitySystemComponent->SetNumericAttributeBase(GetMaxPointsAttribute(), NewValue);		
	}	
}

float UActionPointsAttributeSet::GetMaxPointsBase() const
{
	return MaxPoints.GetBaseValue();
}

void UActionPointsAttributeSet::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION_NOTIFY(UActionPointsAttributeSet, CurrentPoints, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UActionPointsAttributeSet, MaxPoints, COND_None, REPNOTIFY_Always )
}

void UActionPointsAttributeSet::PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	if (Data.EvaluatedData.Attribute == GetCurrentPointsAttribute())
	{
		SetCurrentPoints(GetCurrentPoints());		
	}
	if (Data.EvaluatedData.Attribute == GetMaxPointsAttribute())
	{
		SetMaxPoints(GetMaxPoints());		
	}
}
