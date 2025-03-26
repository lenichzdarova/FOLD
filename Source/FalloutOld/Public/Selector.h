// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerParty.h"

#include "Selector.generated.h"

/**
 * 
 */
UCLASS()
class FALLOUTOLD_API USelector : public UObject
{
	GENERATED_BODY()

	UPROPERTY()
	TArray<ACharacterBase*> partyMembers;
	UPROPERTY()
	TObjectPtr<ACharacterBase> focused = nullptr;	

public:	
	ACharacterBase* GetFocusedCharacter() const;
	void SetFocusedByIndex(int);
	void SetFocusedByValue(ACharacterBase*);
	void SetNext();
	
	void SetPartyMembers(const TArray<ACharacterBase*>);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FFocusedChanged);
	FFocusedChanged FocusedCharacterChanged;
	
};
