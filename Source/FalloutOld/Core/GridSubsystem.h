// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "GridSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class FALLOUTOLD_API UGridSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

private:
	float minX;
	float minY;
	const float CELL_SIZE = 100.f;

public:
	FVector ConvertVectorToCell(FVector);
};
