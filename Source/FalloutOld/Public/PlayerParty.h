// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayActors/CharacterBase.h"
#include "PlayerParty.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class FALLOUTOLD_API UPlayerParty : public UObject
{
	GENERATED_BODY()

	UPROPERTY(ReplicatedUsing = OnRep_CharactersID)
	TArray<FString> PartyMembersID;	

public:
	
	UFUNCTION(BlueprintCallable)
	void AddID(FString CharID);
	UFUNCTION(BlueprintCallable)
	void RemoveID(FString CharID);
	UFUNCTION()
	void Swap(FString First, FString Second);
	
	UFUNCTION(BlueprintCallable)
	bool ContainsID(FString CharID) const;
	
	UFUNCTION(BlueprintCallable)
	TArray<FString> GetPartyMembersID() const;
	UFUNCTION(BlueprintCallable)
	void SetPartyMembersID(TArray<FString> CharIDs);

	
	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;
	virtual bool IsSupportedForNetworking() const override {return true;};
	UFUNCTION()
	void OnRep_CharactersID();

	//Delegates
	DECLARE_MULTICAST_DELEGATE(FChanged);	
	FChanged Changed;	
};
