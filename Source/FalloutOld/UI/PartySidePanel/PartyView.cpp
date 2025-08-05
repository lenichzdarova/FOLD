// Fill out your copyright notice in the Description page of Project Settings.


#include "FalloutOld/UI/PartySidePanel/PartyView.h"

#include "Components/VerticalBoxSlot.h"

void UPartyView::RemoveFromParent()
{
	Super::RemoveFromParent();
	if (ViewModel)
	{
		ViewModel->ConditionalBeginDestroy();
	}	
	for (const auto Widget: CharacterPortraitWidgets)
	{
		Widget->RemoveFromParent();
	}
	CharacterPortraitWidgets.Empty();	
}

void UPartyView::NativeConstruct()
{
	Super::NativeConstruct();
	ViewModel = NewObject<UPartyViewModel>(this,"ViewModel");
	ViewModel->OnPlayerPartyUpdated.AddUObject(this, &UPartyView::OnPartyUpdate);
}

void UPartyView::OnPartyUpdate()
{
	TArray<FString> IDs = ViewModel->CharactersID;
	for (int i = 0; i < IDs.Num(); ++i)
	{
		UCharacterPortraitView* Widget = nullptr;
		if (CharacterPortraitWidgets.IsValidIndex(i))
		{
			Widget = CharacterPortraitWidgets[i];
		}
		else
		{
			Widget = CreateWidget<UCharacterPortraitView>(this, PortraitViewClass.Get());
			CharacterPortraitWidgets.Add(Widget);
			UVerticalBoxSlot* WidgetSlot = Cast<UVerticalBoxSlot>(VerticalBox->AddChild(Widget));
			WidgetSlot->SetHorizontalAlignment(HAlign_Center);
			WidgetSlot->SetVerticalAlignment(VAlign_Center);
		}
		Widget->GetViewModel()->SetCharacterID(IDs[i]);
	}
	while (CharacterPortraitWidgets.Num() - IDs.Num())
	{
		CharacterPortraitWidgets.Pop()->RemoveFromParent();
	}
}
