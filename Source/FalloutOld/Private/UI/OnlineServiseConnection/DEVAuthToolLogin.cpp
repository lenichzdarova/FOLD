// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/OnlineServiseConnection/DEVAuthToolLogin.h"

#include "Core/FOLDGameInstanceBase.h"
#include "Core/FOLDGameSession.h"
#include "GameFramework/GameModeBase.h"

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
	auto GameSession = Cast<AFOLDGameSession>(GetWorld()->GetAuthGameMode()->GameSession);
	GameSession->FindSessions();
}

void UDEVAuthToolLogin::OnJoinSessionPressed()
{
	
}
