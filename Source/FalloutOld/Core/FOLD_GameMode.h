// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "PlayerControllerConfig.h"
#include "GameFramework/GameModeBase.h"
#include "FOLD_GameMode.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class FALLOUTOLD_API AFOLD_GameMode : public AGameModeBase
{
	GENERATED_BODY()

	AFOLD_GameMode();
	
	virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;	
	void ConfigureLevelAfterLoad();
	void HandlePlayerPartySpawn();
	const FGameplayTag GetPlayerSpawnTag() const;	
};

