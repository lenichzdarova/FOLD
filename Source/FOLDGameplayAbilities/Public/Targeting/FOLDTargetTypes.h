#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbilityTargetTypes.h"
#include "FOLDTargetTypes.generated.h"

USTRUCT()
struct FFOLDTargetData : public FGameplayAbilityTargetData
{
	GENERATED_USTRUCT_BODY()	

	virtual ~FFOLDTargetData() override{};
	FHitResult HitResult;

	virtual const FHitResult* GetHitResult() const override {return &HitResult;}
	virtual UScriptStruct* GetScriptStruct() const override
	{
		return FFOLDTargetData::StaticStruct();
	}
};
