// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "CharacterTemplate.generated.h"

/**
 * 
 */
UCLASS()
class FALLOUTOLD_API UCharacterTemplate : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSoftObjectPtr<UTexture2D> Portrait;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSoftObjectPtr<USkeletalMesh> Mesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText Description;	
};
