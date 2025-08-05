// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "FOLDGameMode.generated.h"

/**
 * 
 */
UCLASS()
class FALLOUTOLD_API AFOLDGameMode : public AGameModeBase
{
	GENERATED_BODY()

	AFOLDGameMode();
	
	virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;
	virtual void PostSeamlessTravel() override;
	void ConfigureLevelAfterLoad();
	void SpawnPlayerGroup();	
};

