// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/PartySidePanel/CharacterPortraitViewModel.h"
#include "Blueprint/UserWidget.h"
#include "Core/FOLDActorsDataSubsystem.h"
#include "Kismet/GameplayStatics.h"


void UCharacterPortraitViewModel::SetCharacterID(FString Value)
{
	ID = Value;
	UnbindDelegates();
	
	SetCharacterProfile();
	if (!CharacterProfile.IsValid()) return;

	OnPortraitUpdateHandle = CharacterProfile.Get()->OnPortraitUpdate.AddUObject(this, &UCharacterPortraitViewModel::OnPortraitUpdate);
	OnPortraitUpdate();
	
	UHealth* Health = CharacterProfile.Get()->GetHealth();
	OnHealthUpdateHandle = Health->OnHealthChanged.AddUObject(this, &UCharacterPortraitViewModel::OnCurrentHealthUpdate);
	CurrentHealth = Health->GetCurrentHealth();
	OnMaxHealthUpdateHandle = Health->OnMaxHealthChanged.AddUObject(this, &UCharacterPortraitViewModel::OnMaxHealthUpdate);
	MaxHealth = Health->GetMaxHealth();	
}

void UCharacterPortraitViewModel::SetCharacterProfile()
{
	UUserWidget* widget = Cast<UUserWidget>(GetOuter());
	if (!widget) return;
	UGameInstance* GameInstance = UGameplayStatics::GetGameInstance(widget->GetWorld());
	if (!GameInstance) return;
	UFOLDActorsDataSubsystem* ActorsDataSubsystem = GameInstance->GetSubsystem<UFOLDActorsDataSubsystem>();
	if (!ActorsDataSubsystem) return;
	CharacterProfile = ActorsDataSubsystem->GetActorGameplayData<UCharacterProfile>(ID);	
}

void UCharacterPortraitViewModel::OnPortraitUpdate()
{
	PortraitTexture = LoadPortraitTexture();
	OnPortraitUpdated.Broadcast();
}

UTexture2D* UCharacterPortraitViewModel::LoadPortraitTexture() const
{
	UTexture2D* Texture = nullptr;
	if (CharacterProfile.IsValid())
	{
		FSoftObjectPath AssetPath = CharacterProfile->PortraitAssetPath;
		Texture = Cast<UTexture2D>(AssetPath.TryLoad());
	}	
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
	if (!CharacterProfile.IsValid()) return;
	CharacterProfile.Get()->OnPortraitUpdate.Remove(OnPortraitUpdateHandle);
	UHealth* Health = CharacterProfile.Get()->GetHealth();
	Health->OnHealthChanged.Remove(OnHealthUpdateHandle);
	Health->OnHealthChanged.Remove(OnMaxHealthUpdateHandle);
}

