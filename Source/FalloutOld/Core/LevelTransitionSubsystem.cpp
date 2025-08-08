// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelTransitionSubsystem.h"

#include "WorldPresetSubsystem.h"
#include "Kismet/GameplayStatics.h"

void ULevelTransitionSubsystem::RequestTransitionToGameLevel(const TSoftObjectPtr<UWorld> TargetLevelAsset, bool bAbsolute,
	FString Options)
{
	UWorld* World = GetWorld();
	UGameInstance* GameInstance = UGameplayStatics::GetGameInstance(World);
	UWorldPresetSubsystem* WorldPresetSubsystem = GameInstance->GetSubsystem<UWorldPresetSubsystem>();
	WorldPresetSubsystem->CollectPresetFromWorld(World);
	UGameplayStatics::OpenLevelBySoftObjectPtr(World, TargetLevelAsset, bAbsolute, Options);
}
