// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FOLDSaveGame.h"
#include "Core/FOLDActorsDataSubsystem.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "PersistentDataSubsystem.generated.h"

/**
 * система сохранения и загрузки
 */
UCLASS()
class FALLOUTOLD_API UPersistentDataSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
public:
	void SaveGame (FString Name, UFOLDActorsDataSubsystem* DataStorage);
	
	UFOLDActorsDataSubsystem* LoadGame (FString Name);	
};

