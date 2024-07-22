// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Party.h"

#include "Selector.generated.h"

/**
 * 
 */
UCLASS()
class FALLOUTOLD_API USelector : public UObject
{
	GENERATED_BODY()

	UPROPERTY()
	TArray<APawnBase*> partyMembers;
	UPROPERTY()
	TObjectPtr<APawnBase> focused = nullptr;	

public:	
	APawnBase* GetFocusedCharacter() const;
	void SetFocusedByIndex(int);
	void SetFocusedByValue(APawnBase*);
	void SetNext();
	
	void SetPartyMembers(const TArray<APawnBase*>);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FFocusedChanged);
	FFocusedChanged FocusedCharacterChanged;
	
};
