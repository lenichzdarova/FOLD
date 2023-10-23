// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WidgetCharacterSheet.h"
#include "WidgetDownPanel.h"
#include "WidgetInventory.h"
#include "GameFramework/HUD.h"
#include "HUDBase.generated.h"

/**
 * 
 */
UCLASS()
class FALLOUTOLD_API AHUDBase : public AHUD
{
	GENERATED_BODY()

	UPROPERTY()
	UWidgetDownPanel* DownPanel;
	UPROPERTY()
	UWidgetCharacterSheet* CharacterSheet;
	UPROPERTY()
	UWidgetInventory* Inventory;	
};
