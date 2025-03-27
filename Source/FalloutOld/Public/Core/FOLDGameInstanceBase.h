// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "PlayerParty.h"
#include "Selector.h"
#include "ActionHandler.h"
#include"SaveGame/FOLDGameplayActorData.h"
#include "FOLDGameInstanceBase.generated.h"

/**
 * 
 */
UCLASS()
class FALLOUTOLD_API UFOLDGameInstanceBase : public UGameInstance
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	FString PlayerStartTag = "MainMenu";	

public:

	UPROPERTY()
	TMap<FString, UObject*> ActorsGameplayData;

	
	UPROPERTY()
	FVector2D PlayerWorldPosition;	
	UPROPERTY(BlueprintReadWrite)
	TObjectPtr<UPlayerParty> Party = nullptr;
	UPROPERTY()
	TObjectPtr<USelector> characterSelector = nullptr;
	UPROPERTY()
	TObjectPtr<UActionHandler> WorldActions;
	
	UFOLDGameInstanceBase(const FObjectInitializer& ObjectInitializer);
	
	UFUNCTION()
	void OnPartyChanged();
};
