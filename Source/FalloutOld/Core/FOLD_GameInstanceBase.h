// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "FalloutOld/Unsorted/PlayerParty.h"
#include "FOLD_GameInstanceBase.generated.h"

/**
 *
 */
UCLASS()
class FALLOUTOLD_API UFOLD_GameInstanceBase : public UGameInstance
{
	GENERATED_BODY()

	
private:

	UPROPERTY()
	TObjectPtr<UPlayerParty> PlayerParty;

	public:
	virtual void Init() override;
};
