// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "FalloutOld/Interfaces/InputReceiver.h"
#include "FalloutOld/CharacterBase.h"
#include "WidgetInventory.generated.h"

/**
 * 
 */
UCLASS(Blueprintable,BlueprintType)
class FALLOUTOLD_API UWidgetInventory : public UUserWidget
{
	GENERATED_BODY()
protected:
	UPROPERTY(meta=(BindWidget),BlueprintReadOnly)
	UButton* CancelButton;	
public:
	UFUNCTION()
	void Initialize(TScriptInterface<IInputReceiver> inputReceiver, ACharacterBase* playerCharacter);	
};
