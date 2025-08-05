// Fill out your copyright notice in the Description page of Project Settings.
#include "Attribute.h"

int UAttribute::GetBonus() const
{
	return GetValue()/2 - DefaultValue/2;
}
