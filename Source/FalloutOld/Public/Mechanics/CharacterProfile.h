// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributesList.h"
#include "Health.h"
#include "SkillList.h"
#include "UObject/Object.h"
#include "Character/CharacterTemplate.h"
#include "Character/GameplayDataObjectBase.h"
#include "CharacterProfile.generated.h"

/**
 * 
 */

DECLARE_MULTICAST_DELEGATE(FOnCharacterPortraitUpdate);
UCLASS()
class FALLOUTOLD_API UCharacterProfile : public UGameplayDataObjectBase
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FSoftObjectPath PortraitAssetPath;
	UPROPERTY()
	FString CharacterID;
	
protected:	
	UPROPERTY()
	UHealth* Health;
	UPROPERTY()
	USkillList* SkillSheet;
	UPROPERTY()
	UAttributesList* Attributes;
	
public:
	UFUNCTION()
	UHealth* GetHealth() const {return Health;}
	UFUNCTION()
	USkillList* GetSkillSheet() const {return SkillSheet;}
	UFUNCTION()
	UAttributesList* GetAttributes() const {return Attributes;}

	void ApplyTemplate(UCharacterTemplate* Template);

	FOnCharacterPortraitUpdate OnPortraitUpdate;
};
