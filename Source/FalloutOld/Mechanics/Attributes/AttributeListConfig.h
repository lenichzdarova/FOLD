// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "AttributeListConfig.generated.h"

/**
 * 
 */
UCLASS()
class FALLOUTOLD_API UAttributeListConfig : public UPrimaryDataAsset
{
	GENERATED_BODY()

	public:
	UPROPERTY(EditAnywhere)
	TMap<FGameplayTag, int > Attributes{
	{FGameplayTag::RequestGameplayTag("Character.Attributes.Strength"), 0},
	{FGameplayTag::RequestGameplayTag("Character.Attributes.Perception"), 0},
	{FGameplayTag::RequestGameplayTag("Character.Attributes.Endurance"), 0},
	{FGameplayTag::RequestGameplayTag("Character.Attributes.Charisma"), 0},
	{FGameplayTag::RequestGameplayTag("Character.Attributes.Intelligence"), 0},
	{FGameplayTag::RequestGameplayTag("Character.Attributes.Agility"), 0},
	{FGameplayTag::RequestGameplayTag("Character.Attributes.Luck"), 0},
	};
};
