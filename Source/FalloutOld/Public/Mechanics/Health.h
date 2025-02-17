// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Health.generated.h"

/**
 * 
 */

DECLARE_DYNAMIC_DELEGATE_OneParam(FHealthChanged, int, modifiedValue);


UCLASS(BlueprintType)
class FALLOUTOLD_API UHealth: public UObject
{
	GENERATED_BODY()

private:
	UPROPERTY()
	int MaxHealth;
	UPROPERTY()
	int CurrentHealth;
	
public:
	UFUNCTION()
	int GetMaxHealth() const {return MaxHealth;}
	UFUNCTION()
	void SetMaxHealth(int Value);
	UFUNCTION()
	void AddMaxHealth(int Value);
	UFUNCTION()
	void RemoveMaxHealth(int Value);
	
	UFUNCTION()
	int GetCurrentHealth() const {return CurrentHealth;}
	UFUNCTION()
	void SetCurrentHealth(int Value);
	UFUNCTION()
	void AddCurrentHealth(int Value);
	UFUNCTION()
	void RemoveCurrentHealth(int Value);
	
	//Delegates

	UPROPERTY()
	FHealthChanged OnHealthChanged;
	UPROPERTY()
	FHealthChanged OnMaxHealthChanged;
	
};
