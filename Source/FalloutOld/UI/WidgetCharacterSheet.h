// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FalloutOld/CharacterEntity.h"
#include "FalloutOld/InputReceiver.h"
#include "WidgetCharacterSheet.generated.h"

/**
 * 
 */
UCLASS(Blueprintable,BlueprintType)
class FALLOUTOLD_API UWidgetCharacterSheet : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void Initialize(TScriptInterface<IInputReceiver> inputReceiver, ACharacterEntity* playerCharacter);
	
};
