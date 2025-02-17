// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Skill.generated.h"

/**
 * 
 */

UENUM(BlueprintType)
enum ESkillMastery: uint8
{
	Normal,
	Expert,
	Master
};

USTRUCT()
struct  FALLOUTOLD_API FSkill
{
	GENERATED_BODY()

	UPROPERTY()
	int BaseValue = 0;
	UPROPERTY()
	int Value = 0;
	UPROPERTY()
	TEnumAsByte<ESkillMastery> MasteryLevel = ESkillMastery::Normal;
};
