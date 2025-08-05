// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "FOLD_IDGeneratorSubsystem.generated.h"

USTRUCT()
struct FGameplayID
{
	GENERATED_BODY()

	UPROPERTY()
	FString Prefix;

	UPROPERTY()
	int SerialNumber;
};

/**
 * 
 */
UCLASS()
class FALLOUTOLD_API UFOLD_IDGeneratorSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

	private:	
	TMap<FString, int32> IDs;	//string is id prefix describing object type like NPC_Raider_ID
	TMap<FString, TSharedPtr<TSet<int>>> UnregisteredIDPool;
	public:
	UFUNCTION()
	void RegisterID(FGameplayID ID);
	UFUNCTION()
	void UnregisterID(FGameplayID ID);
	UFUNCTION()
	FGameplayID GenerateID(FString Prefix);	
};
