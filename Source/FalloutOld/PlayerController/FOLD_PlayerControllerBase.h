// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerControllerConfig.h"
#include "Misc/PlayerView.h"
#include "WidgetCursor.h"
#include "FalloutOld/GameplayActors/CharacterBase.h"
#include "PlayerController/CursorController.h"
#include "Misc/PlayerParty.h"
#include "GameFramework/PlayerController.h"
#include "PlayerController/InputConfig.h"
#include "FOLD_PlayerControllerBase.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, Abstract)
class FALLOUTOLD_API AFOLD_PlayerControllerBase : public APlayerController
											 
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;
	UPROPERTY(BlueprintReadWrite)
	APlayerView* PlayerView = nullptr;	

protected:

	virtual void Tick(float DeltaSeconds) override;
	
private:
	UPROPERTY(EditAnywhere)
	TObjectPtr<UPlayerControllerConfig> PlayerControllerConfig;	
protected:		
	
	UFUNCTION(BlueprintCallable)
	void Initialize(UPlayerControllerConfig* InConfig);	
};
