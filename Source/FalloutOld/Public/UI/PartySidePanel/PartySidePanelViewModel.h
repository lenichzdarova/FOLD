// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerParty.h"
#include "Core/FOLDGameState.h"
#include "Mechanics/CharacterProfile.h"
#include "UObject/Object.h"
#include "PartySidePanelViewModel.generated.h"

/**
 * 
 */

DECLARE_MULTICAST_DELEGATE(FOnChanged);

UCLASS()
class FALLOUTOLD_API UPartySidePanelViewModel : public UObject
{
	GENERATED_BODY()

	UPROPERTY()
	TWeakObjectPtr<AFOLDGameState> GameState;
public:	
	UPROPERTY()
	TArray<TWeakObjectPtr<UPlayerParty>> PlayersPartyData;

	void Initialize();
	virtual void BeginDestroy() override;

private:
	
	void FindPlayersPartyData();	
	void OnPlayersCountUpdated();

//delegates
public:
	FOnChanged OnChanged;
private:
	FDelegateHandle OnChangedDelegateHandle;
};
