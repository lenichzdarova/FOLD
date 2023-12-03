// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Image.h"
#include "WidgetWorldMapPlayerMark.generated.h"

/**
 * 
 */
UCLASS()
class FALLOUTOLD_API UWidgetWorldMapPlayerMark : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(meta=(BindWidget),BlueprintReadWrite)
	UImage* PlayerMark;	
	UPROPERTY(BlueprintReadWrite)
	UTexture2D* PlayerMarkStaying;
	UPROPERTY(BlueprintReadWrite)
	UTexture2D* PlayerMarkMoving;
	UPROPERTY(BlueprintReadWrite)
	UTexture2D* PlayerMarkEncounter;

public:
	UFUNCTION()
	void SetMoveMode();
	UFUNCTION()
	void SetStopMode();
	UFUNCTION()
	void SetEncounterMode();

	DECLARE_MULTICAST_DELEGATE(FMulticastDelegate)
	FMulticastDelegate PointerEvent;

protected:
	virtual FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
};
