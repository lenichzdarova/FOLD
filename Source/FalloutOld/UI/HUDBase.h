// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WidgetCharacterSheet.h"
#include "WidgetDialog.h"
#include "WidgetDownPanel.h"
#include "WidgetWorldTravel.h"
#include "WidgetInventory.h"
#include "WidgetLocalMap.h"
#include "WidgetMainMenu.h"
#include "WidgetOptions.h"
#include "WidgetPipBoy.h"
#include "FalloutOld/Core/CharacterBase.h"
#include "FalloutOld/Interfaces/InputReceiver.h"
#include "FalloutOld/Interfaces/InputProvider.h"
#include "FalloutOld/WorldTravelHandler.h"
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
	//widgets
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<UWidgetDownPanel> DownPanel;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<UWidgetCharacterSheet> CharacterSheet;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<UWidgetInventory> Inventory;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<UWidgetMainMenu> MainMenu;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<UWidgetLocalMap> LocalMap;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<UWidgetWorldTravel> Travel;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<UWidgetPipBoy> PipBoy;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<UWidgetOptions> Options;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<UWidgetDialog> Dialog;
};
