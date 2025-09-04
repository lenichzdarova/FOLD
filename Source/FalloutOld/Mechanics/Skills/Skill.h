// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "SkillModificator.h"
#include "SkillData.h"
#include "UObject/Object.h"
#include "Skill.generated.h"

/**
 * 
 */

UCLASS(Blueprintable)
class  FALLOUTOLD_API USkill: public UObject
{
	GENERATED_BODY()
	
private:	
	UPROPERTY(SaveGame)
	FSkillData SkillData;
	UPROPERTY()
	TSet<USkillModificator*> Modifiers;
	
public:
	UFUNCTION()
	FSkillData GetBaseSkillData() const { return SkillData; }
	UFUNCTION()
	void SetSkillData(const FSkillData& InSkillData )  {SkillData = InSkillData ;}
	UFUNCTION()
	FSkillData GetSkillData() const;
};
