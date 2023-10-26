// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FalloutOld/InputReceiver.h"
#include "FalloutOld/CharacterEntity.h"
#include "Blueprint/UserWidget.h"
#include "WidgetDownPanel.generated.h"

/**
 * 
 */
UCLASS(Blueprintable,BlueprintType)
class FALLOUTOLD_API UWidgetDownPanel : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void Initialize(TScriptInterface<IInputReceiver> inputReceiver, ACharacterEntity* playerCharacter);


	DECLARE_MULTICAST_DELEGATE(FMulticastDelegate)
	FMulticastDelegate InventoryButtonClicked;
	FMulticastDelegate CharacterButtonClicked;
	FMulticastDelegate OptionsButtonClicked;
	FMulticastDelegate PipboyButtonClicked;
	FMulticastDelegate MapButtonClicked;
};
