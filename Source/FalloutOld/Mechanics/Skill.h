// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Attribute.h"
#include "GameplayTagContainer.h"
#include "Modificator.h"
#include "UObject/Object.h"
#include "Skill.generated.h"

/**
 * 
 */

UENUM(BlueprintType)
enum ESkillMastery: uint8
{
	Denied,
	Normal,
	Expert,
	Master
};
UCLASS(Blueprintable)
class  FALLOUTOLD_API USkill: public UObject
{
	GENERATED_BODY()
	
private:
	UPROPERTY(SaveGame)
	FGameplayTag SkillTag;
	UPROPERTY()
	UAttribute* AffectingAttribute;
	UPROPERTY(SaveGame)
	int BaseValue = 0;
	UPROPERTY(SaveGame)
	TArray<UModificator*> Modificators;	
	UPROPERTY(SaveGame)
	TEnumAsByte<ESkillMastery> MasteryLevel = ESkillMastery::Normal;
public:

	UFUNCTION()
	int GetBaseValue() const { return BaseValue; }
	UFUNCTION()
	int GetValue() const {return BaseValue + GetModificatorsValue();};
	int GetModificatorsValue() const;
	UFUNCTION()
	void SetValue(int InValue);

	UFUNCTION()
	void AddModificator(UModificator* value);
	UFUNCTION()
	void RemoveModificator(UModificator* value);

	DECLARE_DYNAMIC_DELEGATE(FSkillChanged);
	UPROPERTY()
	FSkillChanged OnSkillChanged;	
};
