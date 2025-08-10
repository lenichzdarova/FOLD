// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FalloutOld/Unsorted/PlayerView.h"
#include "WidgetCursor.h"
#include "FalloutOld/GameplayActors/CharacterBase.h"
#include "FalloutOld/Unsorted/CursorController.h"
#include "FalloutOld/Unsorted/PlayerParty.h"
#include "GameFramework/PlayerController.h"
#include "Input/InputConfig.h"
#include "FOLDPlayerControllerBase.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, Abstract)
class FALLOUTOLD_API AFOLDPlayerControllerBase : public APlayerController
											 
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(BlueprintReadWrite)
	APlayerView* PlayerView = nullptr;	

	UPROPERTY()
	UCursorController* CursorController = nullptr;	
	UPROPERTY(BlueprintReadWrite)
	TSubclassOf<UWidgetCursor> CursorWidgetType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UInputConfig> DefaultInputConfig;
	
	UPROPERTY(BlueprintReadWrite)
	UWidgetCursor* CursorWidget;	

protected:

	virtual void Tick(float DeltaSeconds) override;
	

protected:		
	
	UFUNCTION(BlueprintCallable)
	void Initialize();	
};
