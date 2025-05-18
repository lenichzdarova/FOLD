// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/OnlineServiseConnection/DEVAuthToolLogin.h"

#include "Core/FOLDGameInstanceBase.h"
#include "Core/FOLDGameSession.h"
#include "GameFramework/GameModeBase.h"
#include "UI/OnlineServiseConnection/SessionListViewEntryObject.h"

void UDEVAuthToolLogin::NativeConstruct()
{
	Super::NativeConstruct();	
	Login->OnPressed.AddDynamic(this, &UDEVAuthToolLogin::OnLoginPressed);
	CreateSession->OnPressed.AddDynamic(this, &UDEVAuthToolLogin::OnCreateSessionPressed);
	FindSessions->OnPressed.AddDynamic(this, &UDEVAuthToolLogin::OnFindSessionPressed);
	JoinSession->OnPressed.AddDynamic(this, &UDEVAuthToolLogin::OnJoinSessionPressed);
}

void UDEVAuthToolLogin::OnLoginPressed()
{
	UFOLDGameInstanceBase* GameInstance = Cast<UFOLDGameInstanceBase>(GetWorld()->GetGameInstance());
	GameInstance->LoginEOS(CredentialInput->GetText().ToString());
}

void UDEVAuthToolLogin::OnCreateSessionPressed()
{
	auto GameSession = Cast<AFOLDGameSession>(GetWorld()->GetAuthGameMode()->GameSession);
	if (GameSession)
	{
		GameSession->CreateSession();
	}
}

void UDEVAuthToolLogin::OnFindSessionPressed()
{	
	SessionsList->ClearListItems();
	auto GameSession = Cast<AFOLDGameSession>(GetWorld()->GetAuthGameMode()->GameSession);	
	GameSession->OnFindSessionsCompleteDelegate.BindUObject(this, &UDEVAuthToolLogin::OnFindSessionCompleted);
	GameSession->FindSessions();
}

void UDEVAuthToolLogin::OnFindSessionCompleted(bool bWasSuccessful)
{
	if (bWasSuccessful)
	{
		auto GameSession = Cast<AFOLDGameSession>(GetWorld()->GetAuthGameMode()->GameSession);
		auto Result = GameSession->GetSearchResult();
		if (Result)
		{
			const FUniqueNetIdPtr LocalUserId = GetWorld()->GetFirstLocalPlayerFromController()->GetPreferredUniqueNetId().GetUniqueNetId();
			for (auto Session : Result->SearchResults)
			{
				if(Session.Session.OwningUserId!=LocalUserId)
				{
					USessionListViewEntryObject* Entry = NewObject<USessionListViewEntryObject>();
					Entry->SetSessionData(Session);
					SessionsList->AddItem(Entry);
				}				
			}
		}
	}
}

void UDEVAuthToolLogin::OnJoinSessionPressed()
{
	auto EntryObject = SessionsList->GetSelectedItem<USessionListViewEntryObject>();
	if (EntryObject)
	{
		auto GameSession = Cast<AFOLDGameSession>(GetWorld()->GetAuthGameMode()->GameSession);
		if (GameSession)
		{
			GameSession->JoinSession(EntryObject->GetSession());
		}
	}
}
