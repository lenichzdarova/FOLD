// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Image.h"
#include "WidgetMap.generated.h"

/**
 * 
 */
UCLASS()
class FALLOUTOLD_API UWidgetMap : public UUserWidget
{
	GENERATED_BODY()
protected:
	UPROPERTY(meta=(BindWidget),BlueprintReadWrite)
	UImage* Map;
	UPROPERTY(meta=(BindWidget),BlueprintReadWrite)
	UImage* DestinationMark;
	UPROPERTY(meta=(BindWidget),BlueprintReadWrite)
	UImage* PlayerMark;
	UPROPERTY(BlueprintReadWrite)
	UTexture2D* PlayerMarkStaying;
	UPROPERTY(BlueprintReadWrite)
	UTexture2D* PlayerMarkMoving;
	UPROPERTY(BlueprintReadWrite)
	UTexture2D* PlayerMarkEncounter;	

public:
	
	void Initialize(FVector2D);
	/*
	//destination mark functions	
	UFUNCTION()
	void SetDestinationMarkPosition(FVector2D);
	UFUNCTION()
	FVector2D GetDestinationMarkPosition();	*/
	
	//player mark functions
	UFUNCTION()
	void SetPlayerMarkPosition(FVector2D value);
	UFUNCTION()
	void SetDestinationMarkPosition(FVector2D value);	

protected:
	UFUNCTION()
	void ShowDestinationMark();
	UFUNCTION()
	void HideDestinationMark();	
};
