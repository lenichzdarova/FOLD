// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributesList.h"
#include "Health.h"
#include "SkillList.h"
#include "UObject/Object.h"
#include "Character/CharacterTemplate.h"
#include "CharacterProfile.generated.h"

/**
 * 
 */
UCLASS()
class FALLOUTOLD_API UCharacterProfile : public UObject
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
};
