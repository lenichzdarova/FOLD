// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HUDStateSwitcher.h"
#include "HUDStateBase.generated.h"

class IHUDStateSwitcher;
/**
 * 
 */
UCLASS(Abstract)
class FALLOUTOLD_API UHUDStateBase : public UObject
{
	GENERATED_BODY()

protected:
	virtual void BindEvents(){};
	virtual void UnbindEvents(){};	

public:
	virtual void Start();
	virtual void Stop();
};
