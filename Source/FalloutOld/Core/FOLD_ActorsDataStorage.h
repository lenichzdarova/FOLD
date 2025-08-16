// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FOLDGameplayActorData.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "FOLD_ActorsDataStorage.generated.h"

/**
 * 
 */
UCLASS()
class FALLOUTOLD_API UFOLD_ActorsDataStorage : public UGameInstanceSubsystem
{
	GENERATED_BODY()

	TMap<FGuid, FFOLDGameplayActorData> ActorsSerializedData;

	public:
	void StoreActor(AActor* InActor);
	void RestoreActor(AActor* InActor);
	AActor* SpawnActorAndRestore(FGuid ID);
	bool ContainsActorData(FGuid ID) const;
	FFOLDGameplayActorData GetActorData(FGuid ID) const;
};
