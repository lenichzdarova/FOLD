// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "CharacterPortraitViewModel.generated.h"

/**
 * 
 */

DECLARE_MULTICAST_DELEGATE(FOnProfileInternalValueUpdated)
UCLASS()
class FALLOUTOLD_API UCharacterPortraitViewModel : public UObject
{
	GENERATED_BODY()

private:
	FString ID;
	
	FDelegateHandle OnPortraitUpdateHandle;
	FDelegateHandle OnHealthUpdateHandle;
	FDelegateHandle OnMaxHealthUpdateHandle;
	
public:
	UPROPERTY()
	UTexture2D* PortraitTexture = nullptr;
	int MaxHealth = 0;
	int CurrentHealth = 0;	
	void SetCharacterID(FString Value);
	FString GetCharacterID() const {return ID;}

	private:	
	void SetCharacterProfile();
	void OnPortraitUpdate();	
	UTexture2D* LoadPortraitTexture() const;

	void OnMaxHealthUpdate(int NewValue);
	void OnCurrentHealthUpdate(int NewValue);
	virtual void BeginDestroy() override;
	void UnbindDelegates();

public:
	//Delegates	
	FOnProfileInternalValueUpdated OnPortraitUpdated;
	FOnProfileInternalValueUpdated OnCurrentHealthUpdated;
	FOnProfileInternalValueUpdated OnMaxHealthUpdated;
};

