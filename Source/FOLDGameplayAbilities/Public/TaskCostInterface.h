// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffect.h"
#include "UObject/Interface.h"
#include "TaskCostInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI, BlueprintType)
class UTaskCostInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class FOLDGAMEPLAYABILITIES_API ITaskCostInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.	
	
public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	float GetCost();
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void ShouldApplyCost(bool bShouldApply);
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	bool ApplyCost();
};
