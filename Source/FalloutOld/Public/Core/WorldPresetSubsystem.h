// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SaveGame/WorldPreset.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "WorldPresetSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class FALLOUTOLD_API UWorldPresetSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

	private:
	UPROPERTY()
	TMap<FString, UWorldPreset*> Presets;
public:
	void InitializeWorld(UWorld* World);
	void ApplyPresetToWorld(UWorld* World, const UWorldPreset* Preset) const;
	UWorldPreset* MakeWorldPreset(UWorld* World);
};
