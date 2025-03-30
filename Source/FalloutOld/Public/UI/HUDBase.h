// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PartyPanel.h"
#include "WidgetCharacterSheet.h"
#include "GameFramework/HUD.h"
#include "HUDBase.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class FALLOUTOLD_API AHUDBase : public AHUD
{
	GENERATED_BODY()

public:	
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<UWidgetCharacterSheet> CharacterSheet;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<UPartyPanel> PartyPanel;	
};
