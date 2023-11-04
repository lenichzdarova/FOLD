// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HUDStateBase.h"
#include "HUDStateCinematic.generated.h"

/**
 * 
 */
UCLASS()
class FALLOUTOLD_API UHUDStateCinematic : public UHUDStateBase
{
	GENERATED_BODY()

	UPROPERTY()
	TScriptInterface<IHUDStateSwitcher> StateSwitcher;
	
public:
	virtual void Initialize(TScriptInterface<IHUDStateSwitcher>);	

protected:
	virtual void BindEvents() override;
	virtual void UnbindEvents() override;
	

	virtual void OnCancelInput();
};
