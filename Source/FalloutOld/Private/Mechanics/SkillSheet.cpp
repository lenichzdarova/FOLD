// Fill out your copyright notice in the Description page of Project Settings.


#include "Mechanics/SkillSheet.h"

FSkill USkillSheet::GetSkill(TEnumAsByte<ESkill> Skill)
{
	return *Skills.Find(Skill);
}

void USkillSheet::AddSkill(TEnumAsByte<ESkill> Name, ESkill Skill)
{
}
