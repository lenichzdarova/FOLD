// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FalloutOld/Unsorted/PlayerParty.h"
#include "UObject/Object.h"
#include "PartyViewModel.generated.h"

/**
 * 
 */
DECLARE_MULTICAST_DELEGATE(FOnPlayerPartyUpdated);
UCLASS()
class FALLOUTOLD_API UPartyViewModel : public UObject
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TWeakObjectPtr<UPlayerParty> Party = nullptr;
	FDelegateHandle DelegateHandle;

	public:
	TArray<FString> CharactersID;
	void SetPlayerParty(UPlayerParty* PlayerParty);	
	FOnPlayerPartyUpdated OnPlayerPartyUpdated;
	virtual void BeginDestroy() override;

private:
	void OnPlayerPartyUpdate();
};
