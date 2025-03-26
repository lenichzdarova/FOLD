// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FOLDSaveGame.h"
#include "ActorsGameplayData.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "PersistentDataSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class FALLOUTOLD_API UPersistentDataSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
public:
	void SaveGame (FString Name, UActorsGameplayData* DataStorage);
	
	UActorsGameplayData* LoadGame (FString Name);	
};

