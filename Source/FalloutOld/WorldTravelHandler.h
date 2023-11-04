// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameInstanceBase.h"
#include "UObject/NoExportTypes.h"
#include "WorldTravelHandler.generated.h"

/**
 * 
 */
UENUM()
enum ELandmarks : uint8
{
	Zalupki,
	Podzalupki
};

UENUM()
enum EBiomSpecifier : uint8
{
	Wasteland,
	City,
	Cave
};

UCLASS()
class FALLOUTOLD_API UWorldTravelHandler : public UObject
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	TArray<TEnumAsByte<ELandmarks>> KnownPlaces;
	UPROPERTY()
	UGameInstanceBase* GameInstanceBase;
	UPROPERTY()
	FVector2D TravelDestination;
	UPROPERTY()
	float TravelSpeed;
	UPROPERTY()
	bool IsMoving = false;	

public:

	UFUNCTION()
	void Initialize(UGameInstanceBase* GameInstance);
	UFUNCTION()
	virtual void Update(float DeltaSeconds);
	UFUNCTION()
	void SetDestination(FVector2D destination);
	UFUNCTION()
	FVector2D GetDestination();
	UFUNCTION()
	void SetWorldPosition(FVector2D position);
	UFUNCTION()
	FVector2D GetPlayerPosition();

	DECLARE_MULTICAST_DELEGATE(FMulticastDelegate)
	FMulticastDelegate WorldPositionChanged;
	FMulticastDelegate RandomEncounter;
	FMulticastDelegate StopMoving;
	FMulticastDelegate StartMoving;

protected:	
	UFUNCTION()
	bool CheckRandomEncounter();	
};
