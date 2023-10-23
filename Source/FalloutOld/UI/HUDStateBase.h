// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HUDStateBase.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class FALLOUTOLD_API UHUDStateBase : public UObject
{
	GENERATED_BODY()

public:
	virtual void Start(){};
	virtual void Stop(){};
};
