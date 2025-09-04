#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "SkillData.generated.h"

UENUM(BlueprintType)
enum ESkillMastery: uint8
{	
	Normal,
	Expert,
	Master
};

USTRUCT()
struct FSkillData
{
	GENERATED_BODY()
	
	UPROPERTY(SaveGame, EditAnywhere)
	int SkillLevel = 0;
	UPROPERTY(SaveGame, EditAnywhere)
	TEnumAsByte<ESkillMastery> SkillMastery = Normal;
	UPROPERTY(SaveGame, EditAnywhere)
	FGameplayTag AffectingAttribute;
	UPROPERTY(SaveGame, EditAnywhere)
	uint8 AttributeModificator = 2; 
	UPROPERTY(SaveGame, EditAnywhere)
	bool bAllowed = true;	
};