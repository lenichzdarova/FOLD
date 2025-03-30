// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/CharacterPortrait.h"
#include "Core/FOLDGameState.h"

void UCharacterPortrait::SetCharacterID(FString Value)
{
	ID = Value;
	FindCharacterProfile();
	SetPortrait();
}

FString UCharacterPortrait::GetCharacterID() const
{
	return ID;
}

bool UCharacterPortrait::FindCharacterProfile()
{
	//not implemented yet
	return false;
}

void UCharacterPortrait::SetPortrait()
{
	UTexture2D* Texture = LoadPortraitTexture();
	SetPortraitTexture(Texture);
}

UTexture2D* UCharacterPortrait::LoadPortraitTexture() const
{
	UTexture2D* Texture = nullptr;
	if (CharacterProfile.IsValid())
	{
		FSoftObjectPath AssetPath = CharacterProfile->PortraitAssetPath;
		Texture = Cast<UTexture2D>(AssetPath.TryLoad());
	}	
	return Texture;
}

void UCharacterPortrait::SetPortraitTexture(UTexture2D* Texture)
{
	Portrait->SetBrushFromTexture(Texture);
}



