// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributesList.h"
#include "Health.h"
#include "SkillList.h"
#include "UObject/Object.h"
#include "CharacterProfile.generated.h"

/**
 * 
 */
UCLASS()
class FALLOUTOLD_API UCharacterProfile : public UObject
{
	GENERATED_BODY()

	private:
	UPROPERTY()
	UHealth* Health;

	UPROPERTY()
	USkillList* SkillSheet;
	UPROPERTY()
	UAttributesList* Attributes;

	UFUNCTION()
	UHealth* GetHealth() const {return Health;}
	UFUNCTION()
	USkillList* GetSkillSheet() const {return SkillSheet;}
	UFUNCTION()
	UAttributesList* GetAttributes() const {return Attributes;}
};
