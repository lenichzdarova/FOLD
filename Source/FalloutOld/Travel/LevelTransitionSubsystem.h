// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "LevelTransitionSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class FALLOUTOLD_API ULevelTransitionSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

private:
	UPROPERTY()
	FGameplayTag PlayerSpawnTag;
public:
	void RequestTransitionToGameLevel(const TSoftObjectPtr<UWorld> TargetLevelAsset, 
	const FGameplayTag& InPlayerSpawnTag, bool bAbsolute = true, FString Options = FString(L""));
	FGameplayTag GetSpawnTag() const {return PlayerSpawnTag;}
};
