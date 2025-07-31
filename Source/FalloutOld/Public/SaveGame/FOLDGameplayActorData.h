#pragma once

#include "CoreMinimal.h"
#include "FOLDGameplayComponentData.h"
#include "FOLDGameplayActorData.generated.h"


/** Сериализованные данные актора */
USTRUCT(BlueprintType)
struct FALLOUTOLD_API FFOLDGameplayActorData
{
	GENERATED_BODY()

	UPROPERTY(SaveGame)
	TSubclassOf<AActor> ActorSubtype;
	UPROPERTY(SaveGame)
	FTransform Transform;
	UPROPERTY(SaveGame)
	FRotator ControlRotator;
	UPROPERTY(SaveGame)
	TArray<uint8> SerializedData;
	UPROPERTY(SaveGame)
	TArray<FFOLDGameplayComponentData> Components;	
};