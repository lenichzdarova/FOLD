// Fill out your copyright notice in the Description page of Project Settings.
#include "AttributesListComponent.h"

//#include "Types/AttributeStorage.h"

UAttributesListComponent::UAttributesListComponent()
{
	if (Config)
	{
	}
}

UAttribute* UAttributesListComponent::GetAttribute(FGameplayTag Tag)
{
	UAttribute* Result = nullptr;
	if (Attributes.Contains(Tag))
	{
		Result = *Attributes.Find(Tag);
	}
	return Result;
}

void UAttributesListComponent::SetAttribute(FGameplayTag Tag, UAttribute* Attribute)
{
	Attributes.Add(Tag, Attribute);
}

