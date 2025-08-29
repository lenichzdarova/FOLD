// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTask.h"
#include "TaskCostInterface.h"
#include "FOLDTaskBase.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class FOLDGAMEPLAYABILITIES_API UFOLDTaskBase : public UGameplayTask, public ITaskCostInterface
{
	GENERATED_BODY()

private:
	bool bShouldApplyCost = false;	
public:
	virtual void ShouldApplyCost_Implementation(bool bShouldApply) override;	
};
