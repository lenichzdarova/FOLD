// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Health.h"
#include "SkillSheet.h"
#include "UObject/Object.h"
#include "CharacterProfile.generated.h"

/**
 * 
 */
UCLASS()
class FALLOUTOLD_API UCharacterProfile : public UObject
{
	GENERATED_BODY()

	UPROPERTY()
	UHealth* Health;

	UPROPERTY()
	USkillSheet* SkillSheet;	
};
