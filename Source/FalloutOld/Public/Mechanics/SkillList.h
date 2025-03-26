// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Skill.h"
#include "UObject/Object.h"
#include "SkillList.generated.h"

/**
 * 
 */


UCLASS()
class FALLOUTOLD_API USkillList : public UObject
{
	GENERATED_BODY()
	
	private:
	UPROPERTY()
	TMap<TEnumAsByte<ESkill>, USkill*> Skills;

	public:
	USkillList();
	
	
	UFUNCTION()
	const TMap<TEnumAsByte<ESkill>, USkill*>& GetSkills() const { return Skills; }
	UFUNCTION()
	USkill* GetSkill(TEnumAsByte<ESkill> Skill);
	UFUNCTION()
	void AddSkill(TEnumAsByte<ESkill> Name, USkill* Skill);	
};
