// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "WidgetLocalMap.generated.h"

/**
 * 
 */
UCLASS()
class FALLOUTOLD_API UWidgetLocalMap : public UUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(meta=(BindWidget),BlueprintReadOnly)
	UButton* CancelButton;	
};
