// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "FalloutOld/PawnBase.h"
#include "FalloutOld/InputReceiver.h"
#include "WidgetCharacterSheet.generated.h"

/**
 * 
 */
UCLASS(Blueprintable,BlueprintType)
class FALLOUTOLD_API UWidgetCharacterSheet : public UUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(meta=(BindWidget),BlueprintReadOnly)
	UButton* CancelButton;	
};
