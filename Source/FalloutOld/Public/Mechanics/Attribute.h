// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Modificator.h"
#include "UObject/Object.h"
#include "Attribute.generated.h"


UENUM(BlueprintType)
enum EAttribute: uint8
{
	Strength,
	Dexterity,
	Intelligence,
	Wisdom,
	Constitution,
	Charisma	
};
/**
 * 
 */
UCLASS()
class FALLOUTOLD_API UAttribute : public UObject
{
	GENERATED_BODY()

private:
	static constexpr int DefaultValue = 10;
	UPROPERTY(SaveGame)
	TEnumAsByte<EAttribute> AttributeID;
	UPROPERTY(SaveGame)
	int Value = 10;
	UPROPERTY(SaveGame)
	TArray<UModificator*> Modifiers;
	
public:
	UFUNCTION()
	int GetBonus() const;
	UFUNCTION()
	int GetValue() const {return Value;};
	UFUNCTION()
	TArray<UModificator*> GetModifiers() const {return Modifiers;}
};
