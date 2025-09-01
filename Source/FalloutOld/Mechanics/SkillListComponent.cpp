// Fill out your copyright notice in the Description page of Project Settings.


#include "SkillListComponent.h"

USkillListComponent::USkillListComponent()
{
	//первичная инициализация через дата ассет. !!! Не учитывает, если скиллист изменился!!!
	if (SkillSet)
	{
		auto Iter = SkillSet->SkillInitialSet.CreateConstIterator();
		for (; Iter; ++Iter)
		{
			USkill* Skill = NewObject<USkill>();
			Skill->SetValue(Iter.Value());
			Skills[Iter.Key()] = Skill;
		}		
	}
}

USkill* USkillListComponent::GetSkill(FGameplayTag SkillTag)
{
	return *Skills.Find(SkillTag);
}

void USkillListComponent::AddSkill(FGameplayTag SkillTag, int InitialValue)
{
	USkill* Skill = NewObject<USkill>();
	Skill->SetValue(InitialValue);
	Skills[SkillTag] = Skill;
}
