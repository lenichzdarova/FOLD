// Fill out your copyright notice in the Description page of Project Settings.


#include "SkillListComponent.h"

USkillListComponent::USkillListComponent()
{
	//первичная инициализация через дата ассет. !!! Не учитывает, если скиллист изменился!!!
	if (Config)
	{
		
	}
}

USkill* USkillListComponent::GetSkill(FGameplayTag SkillTag)
{
	return *Skills.Find(SkillTag);
}
