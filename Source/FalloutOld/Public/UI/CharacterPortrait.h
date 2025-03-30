// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Image.h"
#include "Mechanics/CharacterProfile.h"
#include "CharacterPortrait.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, Abstract)
class FALLOUTOLD_API UCharacterPortrait : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(meta = (BindWidget))
	UImage* Portrait;
private:
	UPROPERTY()
	TWeakObjectPtr<UCharacterProfile> CharacterProfile;
	FString ID;
	
public:	
	void SetCharacterID(FString Value);
	FString GetCharacterID() const;	
	
private:
	bool FindCharacterProfile();
	void SetPortrait();
	UTexture2D* LoadPortraitTexture() const;
	void SetPortraitTexture(UTexture2D* Texture);	
};


