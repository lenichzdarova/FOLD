// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/PartySidePanel/PartySidePanelView.h"

void UPartySidePanelView::RemoveFromParent()
{
	Super::RemoveFromParent();
	for (const auto PartyView : PartyWidgets)
	{
		PartyView->RemoveFromParent();
	}
	if (ViewModel)
	{
		ViewModel->ConditionalBeginDestroy();
	}			
	PartyWidgets.Empty();
}

void UPartySidePanelView::NativeConstruct()
{
	Super::NativeConstruct();
	ViewModel = NewObject<UPartySidePanelViewModel>(this, "ViewModel");
	ViewModel->OnChanged.AddUObject(this, &UPartySidePanelView::OnPartyChanged);
	ViewModel->Initialize();
}

void UPartySidePanelView::OnPartyChanged()
{	
	auto Parties = ViewModel->PlayersPartyData;
	if (Parties.Num() < PartyWidgets.Num())
	{
		//TODO
		return;
	}
	if (!Parties.IsEmpty())
	{/*
		auto Widget = CreateWidget<UPartyView>(this, PartyViewClass.Get());
		VerticalBox->AddChild(Widget);		
		Widget->GetViewModel()->SetPlayerParty(Parties.Last().Get());*/
	}	
}

void UPartySidePanelView::CreatePartyWidget(UPlayerParty* Party)
{	
	auto Widget = CreateWidget<UPartyView>(this, PartyViewClass.Get());
	VerticalBox->AddChild(Widget);		
	Widget->GetViewModel()->SetPlayerParty(Party);
	PartyWidgets.Add(Widget);	
}
