// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/FOLDGameInstanceBase.h"

#include "OnlineSubsystemUtils.h"
#include "Core/FOLDGameSession.h"
#include "GameFramework/GameModeBase.h"
#include "Interfaces/OnlineIdentityInterface.h"
#include "Kismet/GameplayStatics.h"

void UFOLDGameInstanceBase::Init()
{	
	Super::Init();	
}

void UFOLDGameInstanceBase::LoginEOS(FString DevToken)
{
	auto IdentityInterface = Online::GetIdentityInterface(GetWorld());
	if (!IdentityInterface)
	{
		GEngine->AddOnScreenDebugMessage(-1, 20, FColor::Red, FString::Printf(TEXT("Identity interface not found!")));
		return;
	}
	FOnlineAccountCredentials Credentials;
	Credentials.Type = "developer";
	Credentials.Id = "127.0.0.1:8081";
	Credentials.Token = DevToken;
	IdentityInterface->OnLoginCompleteDelegates->AddUObject(this, &UFOLDGameInstanceBase::OnLoginComplete);
	IdentityInterface->Login(0, Credentials);	
}

void UFOLDGameInstanceBase::OnLoginComplete(int LocalUserNum, bool bSucceed , const FUniqueNetId& PlayerID, const FString& error)
{
	if (!bSucceed)
	{
		GEngine->AddOnScreenDebugMessage(-1, 20, FColor::Red, error);
		return;
	}
	GEngine->AddOnScreenDebugMessage(-1, 20, FColor::Red, PlayerID.ToString());	
}


