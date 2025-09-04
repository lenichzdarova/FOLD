// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Attribute.h"
#include "AttributeListConfig.h"
#include "GameplayTagContainer.h"
#include "UObject/Object.h"
#include "AttributesListComponent.generated.h"
/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class FALLOUTOLD_API UAttributesListComponent : public UActorComponent
{
	GENERATED_BODY()

	UAttributesListComponent();

	UPROPERTY()
	TMap<FGameplayTag, UAttribute*> Attributes;
	UPROPERTY(EditAnywhere)
	TObjectPtr<UAttributeListConfig> Config;

	public:
	UFUNCTION()
	UAttribute* GetAttribute(FGameplayTag Tag);
	UFUNCTION()
	void SetAttribute(FGameplayTag Tag, UAttribute* Attribute);	
};
