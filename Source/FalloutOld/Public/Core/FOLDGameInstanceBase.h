// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "PlayerParty.h"
#include "Selector.h"
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
	
	virtual void Init() override;	
	void OnLoginComplete(int , bool , const FUniqueNetId& , const FString&);

public:
	void LoginEOS(FString DevToken);
	UPROPERTY()
	TMap<FString, UObject*> ActorsGameplayData;			
};
