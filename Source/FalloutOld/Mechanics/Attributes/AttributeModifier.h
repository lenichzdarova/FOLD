// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AttributeModifier.generated.h"

/**
 * 
 */
UCLASS()
class FALLOUTOLD_API UAttributeModifier : public UObject
{
	GENERATED_BODY()

	private:
	int Value;
	
	public:
	UFUNCTION()
	void SetValue(int InValue) {Value = InValue;};
	UFUNCTION()
	int GetValue() const {return Value;};
};
