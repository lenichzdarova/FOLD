// Fill out your copyright notice in the Description page of Project Settings.


#include "Skill.h"

int USkill::GetModificatorsValue() const
{
	return 0;
}

void USkill::SetValue(int InValue)
{
	BaseValue = InValue;
}

void USkill::AddModificator(UModificator* value)
{
	Modificators.Add(value);
}

void USkill::RemoveModificator(UModificator* value)
{
	Modificators.Remove(value);
}
