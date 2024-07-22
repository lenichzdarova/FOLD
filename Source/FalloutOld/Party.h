// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Core/PawnBase.h"

#include "Party.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class FALLOUTOLD_API UParty : public UObject
{
	GENERATED_BODY()

	UPROPERTY()
	TArray<APawnBase*> partyMembers;	

public:
	UFUNCTION(BlueprintCallable)
	void AddCharacter(APawnBase* pointer);
	UFUNCTION(BlueprintCallable)
	void RemoveByIndex(int index);
	UFUNCTION(BlueprintCallable)
	void RemoveByValue(APawnBase* pointer);
	UFUNCTION(BlueprintCallable)
	const TArray<APawnBase*> GetParty() const;	

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FPartyChanged);
	UPROPERTY()
	FPartyChanged PartyChanged;
};
