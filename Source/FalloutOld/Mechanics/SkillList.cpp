// Fill out your copyright notice in the Description page of Project Settings.


#include "SkillList.h"

USkillList::USkillList()
{
	UEnum* EnumStatic = StaticEnum<ESkill>();
	if (EnumStatic)
	{
		auto NumValues = EnumStatic->NumEnums();
        	for (int i = 0; i < NumValues; ++i)
        	{
        		auto value = EnumStatic->GetValueByIndex(i);        		
        		ESkill EnumValue = static_cast<ESkill>(value);       		
        		if (USkill* Skill = CreateDefaultSubobject<USkill>(EnumStatic->GetNameByIndex(i)))
        		{
        			Skills.Add(EnumValue,Skill);
        		}        		
        	}
	}	
}

USkill* USkillList::GetSkill(TEnumAsByte<ESkill> Skill)
{
	return *Skills.Find(Skill);
}

void USkillList::AddSkill(TEnumAsByte<ESkill> Name, USkill* Skill)
{
	Skills[Name] = Skill;
}
