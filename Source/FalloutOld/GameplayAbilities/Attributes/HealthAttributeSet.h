// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "HealthAttributeSet.generated.h"

UCLASS()
class FALLOUTOLD_API UHealthAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

	//current health
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, ReplicatedUsing = OnRep_CurrentHealth, Category = "Health")
	FGameplayAttributeData CurrentHealth;
	UFUNCTION()
	void OnRep_CurrentHealth(const FGameplayAttributeData& OldData);

public:	
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(UHealthAttributeSet, CurrentHealth);
	float GetCurrentHealth() const;
	void SetCurrentHealth(float NewValue);
	GAMEPLAYATTRIBUTE_VALUE_INITTER(CurrentHealth);

	//maxhealth
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly,ReplicatedUsing = OnRep_MaxHealth, Category = "Health")
	FGameplayAttributeData MaxHealth;
	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldData);
public:
	
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(UHealthAttributeSet, MaxHealth);
	float GetMaxHealth() const;
	void SetMaxHealth(float NewValue);
	float GetMaxHealthBase() const;	
	GAMEPLAYATTRIBUTE_VALUE_INITTER(MaxHealth);

	//replication
public:
	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data) override;	
};
