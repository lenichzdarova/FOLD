// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/OnlineServiseConnection/SessionsListViewEntry.h"
#include "UI/OnlineServiseConnection/SessionListViewEntryObject.h"

void USessionsListViewEntry::NativeOnListItemObjectSet(UObject* ListItemObject)
{
	IUserObjectListEntry::NativeOnListItemObjectSet(ListItemObject);
	if (USessionListViewEntryObject* EntryObject = Cast<USessionListViewEntryObject>(ListItemObject))
	{
		auto Session = EntryObject->GetSession().Session;		
		SessionName->SetText(FText::FromString(Session.OwningUserName));
	}
}
