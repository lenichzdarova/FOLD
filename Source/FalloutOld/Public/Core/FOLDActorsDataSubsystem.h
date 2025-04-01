// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "concepts"
#include "FOLDActorsDataSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class FALLOUTOLD_API UFOLDActorsDataSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

	UPROPERTY()
	TMap<FString, UObject*> ActorsGameplayData;

public:
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

	template <typename T> requires std::derived_from<T, UObject>
	inline T* GetEmptyDataObject(FString ID)
	{
		T* Object = NewObject<T>(this);
		AddActorGameplayData(ID, Object);
		return Object;
	};
};

