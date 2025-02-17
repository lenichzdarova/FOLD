// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Skill.h"
#include "UObject/Object.h"
#include "SkillSheet.generated.h"

/**
 * 
 */
UENUM(BlueprintType)
enum ESkill: uint8
{
	Unarmed,
	FirstAid,
	Lockpicking
};

UCLASS()
class FALLOUTOLD_API USkillSheet : public UObject
{
	GENERATED_BODY()

	private:
	UPROPERTY()
	TMap<TEnumAsByte<ESkill>, FSkill> Skills;

	public:
	UFUNCTION()
	const TMap<TEnumAsByte<ESkill>, FSkill>& GetSkills() const { return Skills; }
	UFUNCTION()
	FSkill GetSkill(TEnumAsByte<ESkill> Skill);
	UFUNCTION()
	void AddSkill(TEnumAsByte<ESkill> Name, ESkill Skill);	
};
