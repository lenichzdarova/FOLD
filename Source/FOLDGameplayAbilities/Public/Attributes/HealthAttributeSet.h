// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "HealthAttributeSet.generated.h"

/**
 * 
 */
UCLASS()
class FOLDGAMEPLAYABILITIES_API UHealthAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, ReplicatedUsing = OnRep_CurrentHealth, Category = "Health")
	FGameplayAttributeData CurrentHealth;
	UFUNCTION()
	virtual void OnRep_CurrentHealth(const FGameplayAttributeData& OldData);

public:
	//~ Helper functions for "Health" attributes
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(UHealthAttributeSet, CurrentHealth);
	float GetCurrentHealth() const;
	void SetCurrentHealth(float NewValue);
	GAMEPLAYATTRIBUTE_VALUE_INITTER(CurrentHealth);
	virtual void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data) override;
	
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Health")
	FGameplayAttributeData MaxHealth;
public:
	//~ Helper functions for "Health" attributes
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(UHealthAttributeSet, MaxHealth);
	float GetMaxHealth() const;
	void SetMaxHealth(float NewValue);
	GAMEPLAYATTRIBUTE_VALUE_INITTER(MaxHealth);

public:
virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;	
	
};
