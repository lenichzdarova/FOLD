// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ActorsGameplayData.generated.h"

/**
 * 
 */
UCLASS()
class FALLOUTOLD_API UActorsGameplayData : public UObject
{
	GENERATED_BODY()

	UPROPERTY()
	TMap<FString, UObject*> ActorsGameplayData;

	UFUNCTION()
	void AddActorGameplayData(FString ID, UObject* Value);
	UFUNCTION()
	UObject* GetActorGameplayData(FString ID) const;
	UFUNCTION()
	void RemoveActorGameplayData(FString ID);

	UFUNCTION()
	void Clear();
	UFUNCTION()
	TMap<FString, UObject*> GetGameplayData() const;
	UFUNCTION()
	void SetGameplayData(TMap<FString, UObject*> Value);	
};
