// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "concepts"
#include "Character/GameplayDataObjectBase.h"
#include "FOLDActorsDataSubsystem.generated.h"

/**
 * Подсистема хранит данные игровых сущностей.
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

	/*
	 * Если в хранилище нет данных актора с указанным ID, вернет nullptr
	*/
	template <class T>
	T* GetActorGameplayData(FString ID) const
	{
		if (!ActorsGameplayData.Contains(ID)) return nullptr;
		auto GameplayDataUObject = *ActorsGameplayData.Find(ID);		
		return Cast<T>(GameplayDataUObject);
	}

	/*
	 * Функция создает объект для хранения данных игровой сущьности
	 * Подсистема является Outer объекта, чтобы его жизненный цикл не зависел
	 * от игрового актора и объект не был уничтожен, например, при переходе на другой уровень.
	*/
	template <typename T> requires std::derived_from<T, UGameplayDataObjectBase>
	T* GetEmptyDataObject(FString ID)
	{
		T* Object = NewObject<T>(this);
		AddActorGameplayData(ID, Object);
		return Object;
	};
};

