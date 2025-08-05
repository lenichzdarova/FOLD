// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CharacterPortraitView.h"
#include "PartyViewModel.h"
#include "Blueprint/UserWidget.h"
#include "Components/VerticalBox.h"
#include "PartyView.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class FALLOUTOLD_API UPartyView : public UUserWidget
{
	GENERATED_BODY()

	private:
	UPROPERTY()
	UPartyViewModel* ViewModel;

	public:
	UPartyViewModel* GetViewModel() { return ViewModel; }
	virtual void RemoveFromParent() override;
protected:
	virtual void NativeConstruct() override;
	UPROPERTY(BlueprintReadWrite)
	TSubclassOf<UCharacterPortraitView> PortraitViewClass;
	UPROPERTY()
	TArray<UCharacterPortraitView*> CharacterPortraitWidgets;
	UPROPERTY(meta = (BindWidget))
	UVerticalBox* VerticalBox;
	
	void OnPartyUpdate();	
};
