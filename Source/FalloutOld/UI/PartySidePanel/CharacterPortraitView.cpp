// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterPortraitView.h"
#include "FalloutOld/Core/FOLDGameState.h"

void UCharacterPortraitView::NativeConstruct()
{
	Super::NativeConstruct();
	ViewModel = NewObject<UCharacterPortraitViewModel>(this,"ViewModel");
	ViewModel->OnPortraitUpdated.AddUObject(this, &UCharacterPortraitView::SetPortrait);
	ViewModel->OnCurrentHealthUpdated.AddUObject(this, &UCharacterPortraitView::OnCurrentHealthUpdated);
	ViewModel->OnCurrentHealthUpdated.AddUObject(this, &UCharacterPortraitView::OnMaxHealthUpdated);
}

void UCharacterPortraitView::RemoveFromParent()
{
	Super::RemoveFromParent();
	if (ViewModel)
	{
		ViewModel->ConditionalBeginDestroy();
	}	
}

void UCharacterPortraitView::SetPortrait() const
{
	Portrait->SetBrushFromTexture(ViewModel->PortraitTexture);
}

void UCharacterPortraitView::UpdateHealthBar() const
{
	int currentHealth = ViewModel->CurrentHealth;
	int maxHealth = ViewModel->MaxHealth;
	HealthBar->SetPercent(currentHealth/maxHealth);	
}

void UCharacterPortraitView::OnCurrentHealthUpdated()
{	
	UpdateHealthBar();
}

void UCharacterPortraitView::OnMaxHealthUpdated()
{	
	UpdateHealthBar();
}



