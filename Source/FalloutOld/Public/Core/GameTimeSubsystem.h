// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayActors/CharacterBase.h"

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
