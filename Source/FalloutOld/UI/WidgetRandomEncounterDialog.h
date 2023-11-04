// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "WidgetRandomEncounterDialog.generated.h"

/**
 * 
 */
UCLASS()
class FALLOUTOLD_API UWidgetRandomEncounterDialog : public UUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(meta=(BindWidget))
	UTextBlock* EncounterDescription;
	UPROPERTY(meta=(BindWidget))
	UButton* Accept;
	UPROPERTY(meta=(BindWidget))
	UButton* Decline;

public:	
	virtual void Initialize(class RandomEncounterData*);

	DECLARE_MULTICAST_DELEGATE(FMulticastDelegate)
	FMulticastDelegate ChooseAccept;
	FMulticastDelegate ChooseDecline;

protected:
	void OnAcceptButtonClick();
	void OnDeclineButtonClick();
	void SetEncounterDescription();
};
