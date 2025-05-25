// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "ActionPointsAttributeSet.generated.h"

/**
 * 
 */
UCLASS()
class FOLDGAMEPLAYABILITIES_API UActionPointsAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

	//current health
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, ReplicatedUsing = OnRep_CurrentPoints, Category = "Attributes")
	FGameplayAttributeData CurrentPoints	;
	UFUNCTION()
	void OnRep_CurrentPoints(const FGameplayAttributeData& OldData);

public:	
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(UActionPointsAttributeSet, CurrentPoints);
	float GetCurrentPoints() const;
	void SetCurrentPoints(float NewValue);
	GAMEPLAYATTRIBUTE_VALUE_INITTER(CurrentPoints);

	//maxhealth
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly,ReplicatedUsing = OnRep_MaxPoints, Category = "Attributes")
	FGameplayAttributeData MaxPoints;
	UFUNCTION()
	void OnRep_MaxPoints(const FGameplayAttributeData& OldData);
public:
	
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(UActionPointsAttributeSet, MaxPoints);
	float GetMaxPoints() const;
	void SetMaxPoints(float NewValue);
	float GetMaxPointsBase() const;	
	GAMEPLAYATTRIBUTE_VALUE_INITTER(MaxPoints);

	//replication
public:
	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data) override;	
};
