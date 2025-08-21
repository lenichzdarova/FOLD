// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Image.h"
#include "WidgetCursor.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class FALLOUTOLD_API UWidgetCursor : public UUserWidget
{
	GENERATED_BODY()

public:
	
	
protected:
	UPROPERTY(meta=(BindWidget), BlueprintReadWrite)
	UImage* cursorImage;
public:
	void SetCursorAppearance(UTexture2D* CursorAppearance);
};
