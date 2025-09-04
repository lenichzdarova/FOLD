// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeModifier.h"
#include "GameplayTagContainer.h"
#include "UObject/Object.h"
#include "Attribute.generated.h"

/**
 * 
 */
UCLASS()
class FALLOUTOLD_API UAttribute : public UObject
{
	GENERATED_BODY()

	UPROPERTY(SaveGame)
	int Value;	
	UPROPERTY()
	TSet<const UAttributeModifier*> Modifiers;
	
public:
	UFUNCTION()
	int GetBaseValue(FGameplayTag Tag) const { return Value;}
	UFUNCTION()
	int GetValue() const;
	UFUNCTION()
	void SetAttribute(const int InValue) { Value = InValue; } 
	UFUNCTION()
	int GetAttributeBonus(FGameplayTag Tag) const;
	UFUNCTION()
	void AddModifier(UAttributeModifier* Modifier) {Modifiers.Add(Modifier);};
};
