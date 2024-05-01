// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CharacterBase.h"

#include "Party.generated.h"

/**
 * 
 */
UCLASS()
class FALLOUTOLD_API UParty : public UObject
{
	GENERATED_BODY()

	UPROPERTY()
	TArray<ACharacterBase*> party;

public:
	UFUNCTION()
	void AddCharacter(ACharacterBase* pointer);
	UFUNCTION()
	void RemoveByIndex(int index);
	UFUNCTION()
	void RemoveByValue(ACharacterBase* pointer);
	UFUNCTION()
	const TArray<ACharacterBase*>& GetParty();
};
