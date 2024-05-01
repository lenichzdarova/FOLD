// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FalloutOld/CharacterBase.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "DialogSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class FALLOUTOLD_API UDialogSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	void StartDialog(ACharacterBase*, ACharacterBase*);
};
