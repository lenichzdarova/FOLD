// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ActionBase.h"
#include "ActionHandler.generated.h"

/**
 * 
 */
UCLASS()
class FALLOUTOLD_API UActionHandler : public UObject
{
	GENERATED_BODY()

public:
	void SetAction(ActionBase*);
};
