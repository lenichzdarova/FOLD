// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FalloutOld/InputReceiver.h"
#include "FalloutOld/PawnBase.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "WidgetDownPanel.generated.h"

/**
 * 
 */
UCLASS(Blueprintable,BlueprintType)
class FALLOUTOLD_API UWidgetDownPanel : public UUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(meta=(BindWidget))
	UButton* InventoryButton = nullptr;
	UPROPERTY(meta=(BindWidget))
	UButton* CharacterButton = nullptr;
	UPROPERTY(meta=(BindWidget))
	UButton* OptionsButton = nullptr;
	UPROPERTY(meta=(BindWidget))
	UButton* PipBoyButton = nullptr;
	UPROPERTY(meta=(BindWidget))
	UButton* MapButton = nullptr;	

public:
	UFUNCTION()
	void Initialize( APawnBase* playerCharacter);


	DECLARE_MULTICAST_DELEGATE(FMulticastDelegate)
	FMulticastDelegate InventoryButtonClicked;
	FMulticastDelegate CharacterButtonClicked;
	FMulticastDelegate OptionsButtonClicked;
	FMulticastDelegate PipBoyButtonClicked;
	FMulticastDelegate MapButtonClicked;
	
protected:
	virtual void OnInventoryButtonClick();
	virtual void OnCharacterButtonClick();
	virtual void OnOptionsButtonClick();
	virtual void OnPipBoyButtonClick();
	virtual void OnMapButtonClick();

	virtual void BindEvents();
};
