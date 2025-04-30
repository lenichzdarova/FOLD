// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PartySidePanelViewModel.h"
#include "PartyView.h"
#include "Blueprint/UserWidget.h"
#include "Components/VerticalBox.h"
#include "PartySidePanelView.generated.h"

/**
 * 
 */
UCLASS(Blueprintable,Abstract)
class FALLOUTOLD_API UPartySidePanelView : public UUserWidget
{
	GENERATED_BODY()

public:	
	UPROPERTY(BlueprintReadWrite)
	TSubclassOf<UPartyView> PartyViewClass;	
	virtual void RemoveFromParent() override;
	
protected:	
	UPROPERTY(meta = (BindWidget))
	UVerticalBox* VerticalBox;
	UPROPERTY()
	UPartySidePanelViewModel* ViewModel;
	UPROPERTY()
	TArray<UPartyView*> PartyWidgets;
	
protected:
	virtual void NativeConstruct() override;	
	void OnPartyChanged();
	void CreatePartyWidget(UPlayerParty*);	
};


