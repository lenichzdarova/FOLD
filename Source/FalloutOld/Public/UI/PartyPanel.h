// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CharacterPortrait.h"
#include "Blueprint/UserWidget.h"
#include "Components/VerticalBox.h"
#include "PartyPanel.generated.h"

/**
 * 
 */
UCLASS(Blueprintable,Abstract)
class FALLOUTOLD_API UPartyPanel : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite)
	TSubclassOf<UCharacterPortrait> PortraitClass;
protected:
	UPROPERTY(BlueprintReadWrite)
	TArray<UCharacterPortrait*> Portraits;
	UPROPERTY(meta = (BindWidget))
	UVerticalBox* VerticalBox;
	
protected:
	virtual void NativeConstruct() override;	
	void OnPartyChanged(const TArray<FString>& CharactersID);
	UCharacterPortrait* ConstructPortraitWidget(FString ID);
};


