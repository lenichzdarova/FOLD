// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/FOLDGameSession.h"

#include "Online.h"
#include "OnlineSubsystem.h"
#include "OnlineSubsystemUtils.h"
#include "Kismet/GameplayStatics.h"
#include "Online/OnlineSessionNames.h"

// Sets default values
AFOLDGameSession::AFOLDGameSession()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MaxPlayers = 4;
	OnCreateSessionCompleteDelegate = FOnCreateSessionCompleteDelegate::CreateUObject(this, &AFOLDGameSession::OnCreateSessionComplete);
	OnStartSessionCompleteDelegate = FOnStartSessionCompleteDelegate::CreateUObject(this, &AFOLDGameSession::OnStartOnlineGameComplete);
	OnFindSessionsCompleteDelegate = FOnFindSessionsCompleteDelegate::CreateUObject(this, &AFOLDGameSession::OnFindSessionsComplete);
	OnJoinSessionCompleteDelegate = FOnJoinSessionCompleteDelegate::CreateUObject(this, &AFOLDGameSession::OnJoinSessionComplete);
	OnDestroySessionCompleteDelegate = FOnDestroySessionCompleteDelegate::CreateUObject(this, &AFOLDGameSession::OnDestroySessionComplete);
}

// Called when the game starts or when spawned
void AFOLDGameSession::BeginPlay()
{
	Super::BeginPlay();	
	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Blue, "Session started");	
}

// Called every frame
void AFOLDGameSession::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AFOLDGameSession::FindSessions()
{	
	IOnlineSubsystem* OnlineSubsystem = Online::GetSubsystem(GetWorld());	
	if (OnlineSubsystem)
	{			
		IOnlineSessionPtr OnlineSessionPtr = OnlineSubsystem->GetSessionInterface();

		if (OnlineSessionPtr.IsValid())
		{
			SearchSettings = MakeShareable(new FOnlineSessionSearch());
			SearchSettings->bIsLanQuery = false;
			SearchSettings->MaxSearchResults = 100;			
			SearchSettings->QuerySettings.Set(SEARCH_KEYWORDS, FString("FOLD"), EOnlineComparisonOp::Equals);			

			auto LocalPlayer = GetWorld()->GetFirstLocalPlayerFromController();
			auto PlayerID = LocalPlayer->GetPreferredUniqueNetId().GetUniqueNetId();
			if (!PlayerID.IsValid())
				{
					GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, "FindSession invalid playerID");
					return;
				}
			OnFindSessionsCompleteDelegateHandle = OnlineSessionPtr->AddOnFindSessionsCompleteDelegate_Handle(OnFindSessionsCompleteDelegate);			
			OnlineSessionPtr->FindSessions(*PlayerID, SearchSettings.ToSharedRef());
		}
	}
}

void AFOLDGameSession::OnFindSessionsComplete(bool bWasSuccessful)
{	
	IOnlineSubsystem* const OnlineSubsystem = Online::GetSubsystem(GetWorld());
	if (OnlineSubsystem)
	{		
		IOnlineSessionPtr OnlineSessionPtr = OnlineSubsystem->GetSessionInterface();
		if (OnlineSessionPtr.IsValid())
		{			
			OnlineSessionPtr->ClearOnFindSessionsCompleteDelegate_Handle(OnFindSessionsCompleteDelegateHandle);			
			if (SearchSettings->SearchResults.Num() > 0)
			{				
				for (int32 SearchIdx = 0; SearchIdx < SearchSettings->SearchResults.Num(); SearchIdx++)
				{					
					GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, FString::Printf(TEXT("Session Number: %d | Sessionname: %s "), SearchIdx + 1, *(SearchSettings->SearchResults[SearchIdx].Session.OwningUserName)));
				}
			}
			else
			{
				GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, "no session found");
			}
		}
	}
}
bool AFOLDGameSession::JoinSession(const FOnlineSessionSearchResult& InSearchResult)
{
	bool bSuccessful = false;	
	IOnlineSubsystem* OnlineSubsystem = Online::GetSubsystem(GetWorld());    
	if (OnlineSubsystem)
	{
		IOnlineSessionPtr Sessions = OnlineSubsystem->GetSessionInterface();
    
		if (Sessions.IsValid())
		{			
			OnJoinSessionCompleteDelegateHandle = Sessions->AddOnJoinSessionCompleteDelegate_Handle(OnJoinSessionCompleteDelegate);
			bSuccessful = Sessions->JoinSession(0, NAME_GameSession, InSearchResult);
		}
	}
	return bSuccessful;
}

void AFOLDGameSession::OnJoinSessionComplete(FName InSessionName, EOnJoinSessionCompleteResult::Type Result)
{
	IOnlineSubsystem* OnlineSubsystem = Online::GetSubsystem(GetWorld());
	if (OnlineSubsystem)
	{
		IOnlineSessionPtr Sessions = OnlineSubsystem->GetSessionInterface();
		if (Sessions.IsValid())
		{			
			Sessions->ClearOnJoinSessionCompleteDelegate_Handle(OnJoinSessionCompleteDelegateHandle);    
			APlayerController* const PlayerController = GetGameInstance()->GetFirstLocalPlayerController();    
			// Поскольку у всех Online subsystem разные URL для подключения
			//Необходимо попоросить наш интерфес собрать для нас этот URL и положить его в эту стрингу
			FString TravelURL;
			if (PlayerController && Sessions->GetResolvedConnectString(InSessionName, TravelURL))
			{
				PlayerController->ClientTravel(TravelURL, TRAVEL_Absolute);
			}
		}
	}
}

bool AFOLDGameSession::CreateSession()
{
	IOnlineSubsystem* const OnlineSubsystem = Online::GetSubsystem(GetWorld());
	if (OnlineSubsystem)
	{		
		IOnlineSessionPtr Sessions = OnlineSubsystem->GetSessionInterface();		
		if (Sessions.IsValid())
		{
			auto Session = Sessions->GetNamedSession(NAME_GameSession);
			if (Session)
			{
				Sessions->DestroySession(NAME_GameSession);
			}

			HostSettings = MakeShareable(new FOnlineSessionSettings());
			HostSettings->bAllowJoinInProgress = true;
			HostSettings->bIsLANMatch = false;
			HostSettings->bAllowJoinViaPresence = true;
			HostSettings->bUsesPresence = true;
			HostSettings->bShouldAdvertise = true;
			HostSettings->bAllowInvites = true;
			HostSettings->NumPublicConnections = MaxPlayers;
			HostSettings->Set(SEARCH_KEYWORDS, FString("FOLD"), EOnlineDataAdvertisementType::ViaOnlineService);			
			
			auto LocalPlayer = GetWorld()->GetFirstLocalPlayerFromController();
			auto PlayerID = LocalPlayer->GetPreferredUniqueNetId().GetUniqueNetId();			
			if (!PlayerID.IsValid())
			{
				GEngine->AddOnScreenDebugMessage(-1, 100.f, FColor::Red, "CreateSession invalid playerID");
				return false;
			}			
			OnCreateSessionCompleteDelegateHandle = Sessions->AddOnCreateSessionCompleteDelegate_Handle(OnCreateSessionCompleteDelegate);
			return Sessions->CreateSession(*PlayerID, NAME_GameSession, *HostSettings );
		}
	}
	return false;
}

void AFOLDGameSession::OnCreateSessionComplete(FName InSessionName, bool bWasSuccessful)
{
	IOnlineSubsystem* OnlineSub = Online::GetSubsystem(GetWorld());
	if (OnlineSub)
	{		
		IOnlineSessionPtr Sessions = OnlineSub->GetSessionInterface();
		if (Sessions.IsValid())
		{
			//Чистим делегат
			Sessions->ClearOnCreateSessionCompleteDelegate_Handle(OnCreateSessionCompleteDelegateHandle);			
		}
		GEngine->AddOnScreenDebugMessage(-1, 20, FColor::Emerald, FString::Format(
		TEXT("Session Created: {0}"), { FString::FromInt(bWasSuccessful)			 
		}));
	}
}

void AFOLDGameSession::OnStartOnlineGameComplete(FName InSessionName, bool bWasSuccessful)
{
	IOnlineSubsystem* OnlineSub = Online::GetSubsystem(GetWorld());
	if (OnlineSub)
	{
		IOnlineSessionPtr Sessions = OnlineSub->GetSessionInterface();
		if (Sessions.IsValid())
		{			
			Sessions->ClearOnStartSessionCompleteDelegate_Handle(OnStartSessionCompleteDelegateHandle);
		}
		
		if (bWasSuccessful)
		{			
			UGameplayStatics::OpenLevel(GetWorld(), "MapName" , true, "listen");
		}
	}
}

void AFOLDGameSession::OnDestroySessionComplete(FName InSessionName, bool bWasSuccessful)
{
}



