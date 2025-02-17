// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Image.h"
#include "WidgetWorldMapImage.generated.h"

/**
 * 
 */
UCLASS()
class FALLOUTOLD_API UWidgetWorldMapImage : public UUserWidget
{
	GENERATED_BODY()
protected:
	UPROPERTY(meta=(BindWidget),BlueprintReadWrite)
	UImage* Map;		

public:
	
	FVector2D GetMapSize();
	void SetPointerClickEventOn();
	void SetPointerClickEventOff();
	
	DECLARE_MULTICAST_DELEGATE_OneParam(FMulticastDelegate, FVector2D)
	FMulticastDelegate PointerEvent;

protected:		
	virtual FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
};
