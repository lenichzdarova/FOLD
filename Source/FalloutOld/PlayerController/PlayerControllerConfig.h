// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CursorContextComponent.h"
#include "CursorController.h"
#include "PlayerInputHandlerComponentBase.h"
#include "Engine/DataAsset.h"
#include "PlayerControllerConfig.generated.h"

/**
 * 
 */
UCLASS()
class FALLOUTOLD_API UPlayerControllerConfig : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	TSubclassOf<UPlayerInputHandlerComponentBase> InputHandlerClass;
	UPROPERTY(EditAnywhere)
	TObjectPtr<UInputConfig> InputConfig;
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<UCursorContextComponent> CursorContextClass;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UCursorController> CursorController;
	UPROPERTY(EditAnywhere)
	TSubclassOf<UWidgetCursor> CursorWidget;
	UPROPERTY(EditAnywhere)
	TMap<FGameplayTag, UTexture2D*> CursorIcons;
};
