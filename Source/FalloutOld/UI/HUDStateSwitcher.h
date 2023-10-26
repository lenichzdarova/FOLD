// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Runtime/CoreUObject/Public/UObject/Interface.h"
#include "HUDStateSwitcher.generated.h"

// This class does not need to be modified.
UINTERFACE()
class UHUDStateSwitcher : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class FALLOUTOLD_API IHUDStateSwitcher
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void SetInventoryState(){};
	virtual void SetCharacterSheetState(){};
	virtual void SetDialogState(){};
	virtual void SetOptionsState(){};
	virtual void SetGameplayState(){};
	virtual void SetMainMenuState(){};
	virtual void SetWorldMapState(){};
	virtual void SetLocalMapState(){};
	virtual void SetPipboyState(){};
};
