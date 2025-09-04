// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Skill.h"
#include "SkillListConfig.h"
#include "SkillModificator.h"
#include "UObject/Object.h"
#include "SkillListComponent.generated.h"

/**
 * 
 */


UCLASS(BlueprintType, meta=(BlueprintSpawnableComponent))
class FALLOUTOLD_API USkillListComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	USkillListComponent();
private:
	UPROPERTY()
	TMap<FGameplayTag, USkill*> Skills;
	UPROPERTY(EditAnywhere)
	TObjectPtr<USkillListConfig> Config;
	
public:	
	UFUNCTION()
	USkill* GetSkill(FGameplayTag SkillTag);
	UFUNCTION()
	void SetSkill(FGameplayTag SkillTag, USkill* InValue) {Skills.Add(SkillTag, InValue);}	
};
