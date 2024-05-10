// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "FalloutOld/Party.h"
#include "FalloutOld/Selector.h"
#include "GameInstanceBase.generated.h"

/**
 * 
 */
UCLASS()
class FALLOUTOLD_API UGameInstanceBase : public UGameInstance
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	FString PlayerStartTag = "MainMenu";	

public:
	UPROPERTY()
	FVector2D PlayerWorldPosition;
	
	UPROPERTY(BlueprintReadWrite)
	TObjectPtr<UParty> Party = nullptr;
	UPROPERTY()
	TObjectPtr<USelector> characterSelector = nullptr;

	UGameInstanceBase(const FObjectInitializer& ObjectInitializer);
	
	UFUNCTION()
	void OnPartyChanged();
};
