// Fill out your copyright notice in the Description page of Project Settings.


#include "HUDStateBase.h"

void UHUDStateBase::Start()
{
	BindEvents();	
}
void UHUDStateBase::Stop()
{
	UnbindEvents();	
}

