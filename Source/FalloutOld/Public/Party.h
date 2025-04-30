// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "PlayerParty.h"
#include "Party.generated.h"

/**
 * 
 */
UCLASS()
class FALLOUTOLD_API UParty : public UObject
{
	GENERATED_BODY()

private:
	UPROPERTY(ReplicatedUsing=OnRep_Party)
	TArray<UPlayerParty*> Party;

public:
	void AddPlayerCharacters(UPlayerParty* PlayerControlledCharacters);
	void RemovePlayerCharacters(UPlayerParty* PlayerControlledCharacters);

private:
	UFUNCTION()
	void OnRep_Party();

	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;
	virtual bool IsSupportedForNetworking() const override {return true;}
};
