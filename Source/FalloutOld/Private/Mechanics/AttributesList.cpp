// Fill out your copyright notice in the Description page of Project Settings.
#include "Mechanics/AttributesList.h"

//#include "Types/AttributeStorage.h"

UAttributesList::UAttributesList()
{
	UEnum* AttributeEnum = StaticEnum<EAttribute>();
	auto NumValues = AttributeEnum->NumEnums();
	for (int i = 0; i < NumValues; i++)
	{
		auto value = AttributeEnum->GetValueByIndex(i);
		EAttribute EnumValue = static_cast<EAttribute>(value);
		UAttribute* Attribute = CreateDefaultSubobject<UAttribute>(AttributeEnum->GetNameByIndex(i));
		Attributes.Add(EnumValue,Attribute);
	}
	
}

UAttribute* UAttributesList::GetAttribute(EAttribute ID)
{
	return *Attributes.Find(ID);
}

int UAttributesList::GetAttributeBonus(EAttribute ID) const
{
	UAttribute* attribute = *Attributes.Find(ID);
	return attribute->GetBonus();
}
