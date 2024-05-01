// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "FalloutOld/Party.h"
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
	UPROPERTY()
	UParty* Party;

public:
	UPROPERTY()
	FVector2D PlayerWorldPosition;

	UGameInstanceBase(const FObjectInitializer& ObjectInitializer);	
};
