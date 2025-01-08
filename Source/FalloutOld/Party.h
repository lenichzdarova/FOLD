// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Core/CharacterBase.h"

#include "Party.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class FALLOUTOLD_API UParty : public UObject
{
	GENERATED_BODY()

	UPROPERTY()
	TArray<ACharacterBase*> partyMembers;	

public:
	UFUNCTION(BlueprintCallable)
	void AddCharacter(ACharacterBase* pointer);
	UFUNCTION(BlueprintCallable)
	void RemoveByIndex(int index);
	UFUNCTION(BlueprintCallable)
	void RemoveByValue(ACharacterBase* pointer);
	UFUNCTION(BlueprintCallable)
	const TArray<ACharacterBase*> GetParty() const;	

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FPartyChanged);
	UPROPERTY()
	FPartyChanged PartyChanged;
};
