// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "PlayerParty.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class FALLOUTOLD_API UPlayerParty : public UObject
{
	GENERATED_BODY()	

	UPROPERTY()
	FGameplayTag PlayerTag = FGameplayTag::RequestGameplayTag("Actors.Player");
	UPROPERTY()
	FGameplayTagContainer Tags{PlayerTag};	

public:		
	
	UFUNCTION()
	const FGameplayTag& GetPlayerTag();	
	
	UFUNCTION(BlueprintCallable)
	void AddID(const FGameplayTag& Tag);
	UFUNCTION(BlueprintCallable)
	void RemoveID(const FGameplayTag& Tag);	
	
	UFUNCTION(BlueprintCallable)
	bool ContainsID(const FGameplayTag& Tag) const;
	
	UFUNCTION(BlueprintCallable)
	const TArray<FGameplayTag> GetPartyMembersID() const;
	UFUNCTION(BlueprintCallable)
	void SetPartyMembersID(TArray<FGameplayTag> InTags);	

	//Delegates
	DECLARE_MULTICAST_DELEGATE(FChanged);	
	FChanged Changed;	
};
