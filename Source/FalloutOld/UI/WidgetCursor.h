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
	void SetInteract();
	UFUNCTION()
	void SetDialog();
	
protected:
	UPROPERTY(meta=(BindWidget), BlueprintReadWrite)
	UImage* cursorImage;
	UPROPERTY(BlueprintReadWrite)
	UTexture2D* defaultTexture;
	UPROPERTY(BlueprintReadWrite)
	UTexture2D* dialogTexture;
	UPROPERTY(BlueprintReadWrite)
	UTexture2D* interactTexture;
	
	
};
