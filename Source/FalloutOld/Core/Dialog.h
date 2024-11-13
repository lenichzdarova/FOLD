// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Dialog.generated.h"

/**
 * 
 */
UCLASS()
class FALLOUTOLD_API UDialog : public UObject
{
	GENERATED_BODY()

public:
	void OpenDialog(FString TreeID);

protected:
};
