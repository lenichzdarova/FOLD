// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "FalloutOld/Unsorted/PlayerParty.h"
#include "FOLDGameInstanceBase.generated.h"

/**
 *
 */
UCLASS()
class FALLOUTOLD_API UFOLDGameInstanceBase : public UGameInstance
{
	GENERATED_BODY()

	
private:
		
	TSharedPtr<UPlayerParty> PlayerParty;

	public:
	virtual void Init() override;
};
