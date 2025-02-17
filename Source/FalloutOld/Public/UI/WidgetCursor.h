// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Image.h"
#include "WidgetCursor.generated.h"

/**
 * 
 */
UCLASS()
class FALLOUTOLD_API UWidgetCursor : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void SetDefault();
	UFUNCTION()
	void SetUse();
	UFUNCTION()
	void SetDialog();
	UFUNCTION()
	void SetTake();
	
protected:
	UPROPERTY(meta=(BindWidget), BlueprintReadWrite)
	UImage* cursorImage;
	UPROPERTY(BlueprintReadWrite)
	UTexture2D* Default;
	UPROPERTY(BlueprintReadWrite)
	UTexture2D* Dialog;
	UPROPERTY(BlueprintReadWrite)
	UTexture2D* Use;
	UPROPERTY(BlueprintReadWrite)
	UTexture2D* Take;
	
	
};
