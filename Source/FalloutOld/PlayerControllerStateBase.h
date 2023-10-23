// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CursorController.h"
#include "InputReceiver.h"
#include "UI/HUDBase.h"
#include "CharacterEntity.h"
#include "PlayerControllerStateBase.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class FALLOUTOLD_API UPlayerControllerStateBase : public UObject, public IInputReceiver
{
	GENERATED_BODY()
	
public:
	virtual void Initialize(AHUDBase* hud, ACharacterEntity*  playerCharacter, UCursorController* cursorController){};
	virtual void Start(){};
	virtual void Stop(){};
	virtual void BindEvents(){};
};
