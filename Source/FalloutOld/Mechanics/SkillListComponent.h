// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Skill.h"
#include "SkillSet.h"
#include "UObject/Object.h"
#include "SkillListComponent.generated.h"

/**
 * 
 */


UCLASS(BlueprintType, meta=(BlueprintSpawnableComponent))
class FALLOUTOLD_API USkillListComponent : public UActorComponent
{
	GENERATED_BODY()
	
	private:
	UPROPERTY()
	TMap<FGameplayTag, USkill*> Skills;
	UPROPERTY(EditAnywhere)
	TObjectPtr<USkillSet> SkillSet;

	public:
	USkillListComponent();	
	
	UFUNCTION()
	const TMap<FGameplayTag, USkill*>& GetSkills() const { return Skills; }
	UFUNCTION()
	USkill* GetSkill(FGameplayTag SkillTag);
	UFUNCTION()
	void AddSkill(FGameplayTag SkillTag, int InitialValue);	
};
