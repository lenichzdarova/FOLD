// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Attribute.h"
#include "UObject/Object.h"
#include "AttributesList.generated.h"
/**
 * 
 */
UCLASS()
class FALLOUTOLD_API UAttributesList : public UObject
{
	GENERATED_BODY()

	UAttributesList();

	UPROPERTY()
	TMap<TEnumAsByte<EAttribute>, UAttribute*> Attributes;

	UFUNCTION()
	UAttribute* GetAttribute(EAttribute ID);
	UFUNCTION()
	int GetAttributeBonus(EAttribute ID) const;
};
