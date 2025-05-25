// Fill out your copyright notice in the Description page of Project Settings.


#include "Tasks/GameplayTaskWithCostBase.h"

void UGameplayTaskWithCostBase::ShouldApplyCost_Implementation(bool bShouldApply)
{
	bShouldApplyCost = bShouldApply;
}
