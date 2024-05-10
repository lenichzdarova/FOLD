// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FalloutOld/CharacterBase.h"

#include "GameTimeSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class FALLOUTOLD_API UGameTimeSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	void StartCombat(ACharacterBase*, ACharacterBase*);		
};
