// Fill out your copyright notice in the Description page of Project Settings.


#include "Skill.h"

FSkillData USkill::GetSkillData() const
{
	FSkillData Result = SkillData;
	for (USkillModificator* Mod : Modifiers)
	{
		Mod->ApplyModificator(Result);
	}
	return Result;
}
