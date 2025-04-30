// Fill out your copyright notice in the Description page of Project Settings.


#include "Mechanics/Health.h"

void UHealth::SetMaxHealth(int Value)
{
}

void UHealth::AddMaxHealth(int Value)
{
}

void UHealth::RemoveMaxHealth(int Value)
{
}

void UHealth::SetCurrentHealth(int Value)
{	
	CurrentHealth = FMath::Clamp(Value, 0, MaxHealth);
	OnHealthChanged.Broadcast(CurrentHealth);
}

void UHealth::AddCurrentHealth(int Value)
{
	SetCurrentHealth(CurrentHealth + Value);
}

void UHealth::RemoveCurrentHealth(int Value)
{
	SetCurrentHealth(CurrentHealth - Value);
}
