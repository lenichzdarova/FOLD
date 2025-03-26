// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Core/CharacterBase.h"

#include "PlayerParty.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class FALLOUTOLD_API UPlayerParty : public UObject
{
	GENERATED_BODY()

	UPROPERTY()
	TArray<FString> CharactersID	;	

public:
	UFUNCTION(BlueprintCallable)
	void AddID(FString CharID);
	UFUNCTION(BlueprintCallable)
	void RemoveID(FString CharID);
	
	UFUNCTION(BlueprintCallable)
	bool ContainsID(FString CharID) const;
	
	UFUNCTION(BlueprintCallable)
	TArray<FString> GetParty() const;
	UFUNCTION(BlueprintCallable)
	void SetParty(TArray<FString> CharIDs);	

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPartyChanged, FString,ID);
	UPROPERTY()
	FPartyChanged IDAdded;
	UPROPERTY()
	FPartyChanged IDRemoved;	
};
