// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterPortraitViewModel.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"


void UCharacterPortraitViewModel::SetCharacterID(FString Value)
{
}

void UCharacterPortraitViewModel::SetCharacterProfile()
{
	
}

void UCharacterPortraitViewModel::OnPortraitUpdate()
{
	PortraitTexture = LoadPortraitTexture();
	OnPortraitUpdated.Broadcast();
}

UTexture2D* UCharacterPortraitViewModel::LoadPortraitTexture() const
{
	UTexture2D* Texture = nullptr;
	
	return Texture;
}

void UCharacterPortraitViewModel::OnMaxHealthUpdate(int NewValue)
{	
	MaxHealth = NewValue;
	OnMaxHealthUpdated.Broadcast();
}

void UCharacterPortraitViewModel::OnCurrentHealthUpdate(int NewValue)
{	
	CurrentHealth = NewValue;
	OnCurrentHealthUpdated.Broadcast();
}

void UCharacterPortraitViewModel::BeginDestroy()
{
	UObject::BeginDestroy();
	UnbindDelegates();	
}

void UCharacterPortraitViewModel::UnbindDelegates()
{
	
}

