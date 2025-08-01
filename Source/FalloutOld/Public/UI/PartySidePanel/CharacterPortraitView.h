// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CharacterPortraitViewModel.h"
#include "Blueprint/UserWidget.h"
#include "Components/Image.h"
#include "Components/ProgressBar.h"
#include "CharacterPortraitView.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, Abstract)
class FALLOUTOLD_API UCharacterPortraitView : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(meta = (BindWidget))
	UImage* Portrait;
	UPROPERTY(meta = (BindWidget))
	UProgressBar* HealthBar;

	virtual void NativeConstruct() override;
	
private:
	UPROPERTY()
	UCharacterPortraitViewModel* ViewModel;	
	
public:
	UCharacterPortraitViewModel* GetViewModel() { return ViewModel; }
	virtual void RemoveFromParent() override;
	
private:	
	void SetPortrait() const;	

	void UpdateHealthBar() const;
	
	void OnCurrentHealthUpdated();
	void OnMaxHealthUpdated();
};


