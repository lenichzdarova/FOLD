// Fill out your copyright notice in the Description page of Project Settings.


#include "Attribute.h"

int UAttribute::GetValue() const
{
	int Result = Value;
	for (auto Modifier : Modifiers)
	{
		Result += Modifier->GetValue();
	}
	return Result;
}

int UAttribute::GetAttributeBonus(FGameplayTag Tag) const
{
	int Result = GetValue();
	return Result/2 - 5;
}
