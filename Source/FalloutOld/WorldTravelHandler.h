// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameInstanceBase.h"
#include "UObject/NoExportTypes.h"
#include "WorldTravelHandler.generated.h"

/**
 * 
 */


UCLASS()
class FALLOUTOLD_API UWorldTravelHandler : public UObject
{
	GENERATED_BODY()

protected:
	
	UPROPERTY()
	FVector2D TravelDestination;
	UPROPERTY()
	FVector2D CurrentPosition = FVector2D{ 725,775};
	UPROPERTY()
	float TravelSpeed = 5;
	UPROPERTY()
	bool IsMoving = false;	

public:

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
