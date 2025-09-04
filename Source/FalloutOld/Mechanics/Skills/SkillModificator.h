// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SkillData.h"
#include "SkillModificator.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class FALLOUTOLD_API USkillModificator : public UObject
{
	GENERATED_BODY()

	public:
	UFUNCTION()
	virtual void ApplyModificator(FSkillData& InSkillData){};
};
