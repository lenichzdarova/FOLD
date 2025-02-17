#pragma once

#include "Attributes.generated.h"

USTRUCT(BlueprintType,Category = "Attributes")
struct FAttributes
{
	GENERATED_BODY();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	int Strength;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	int Perception;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	int Endurance;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	int Charisma;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	int Intelligence;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	int Agility;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	int Luck;
};
