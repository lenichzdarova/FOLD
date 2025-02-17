// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "CharacterConstruction.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class FALLOUTOLD_API UCharacterConstruction : public UDataAsset
{
	GENERATED_BODY()

	public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TAssetPtr<UTexture2D> Portrait;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TAssetPtr<USkeletalMesh> Mesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText Description;	
};
