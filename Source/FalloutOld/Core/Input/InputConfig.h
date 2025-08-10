// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "InputAction.h"
#include "InputMappingContext.h"
#include "Engine/DataAsset.h"
#include "InputConfig.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class FALLOUTOLD_API UInputConfig : public UPrimaryDataAsset
{
	GENERATED_BODY()

	public:
	UPROPERTY(EditAnywhere)
	TObjectPtr<UInputMappingContext> InputMappingContext;
	UPROPERTY(EditAnywhere)
	TMap<FGameplayTag, TObjectPtr<UInputAction>> InputActions;
};
