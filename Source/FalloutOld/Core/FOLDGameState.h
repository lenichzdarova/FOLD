// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FalloutOld/Unsorted/PlayerParty.h"
#include "GameFramework/GameStateBase.h"
#include "FOLDGameState.generated.h"

/**
 * 
 */
DECLARE_MULTICAST_DELEGATE(FOnPlayersCountChange)
UCLASS()
class FALLOUTOLD_API AFOLDGameState : public AGameStateBase
{
	GENERATED_BODY()	
};
