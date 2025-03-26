// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SaveGame/WorldPreset.h"
#include "SaveGame/FOLDGameplayActorData.h"
#include "FOLDGameMode.generated.h"

/**
 * 
 */
UCLASS()
class FALLOUTOLD_API AFOLDGameMode : public AGameModeBase
{
	GENERATED_BODY()

	virtual void PostLogin(APlayerController* NewPlayer) override;
	virtual void StartPlay() override;
	virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;
	
	void SpawnPlayerGroup();	
};

