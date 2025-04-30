// Fill out your copyright notice in the Description page of Project Settings.
#include "Core/FOLDGameMode.h"
#include "OnlineSubsystem.h"
#include "Core/WorldPresetSubsystem.h"



void AFOLDGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);
	UE_LOG(LogTemp, Display, TEXT("AFOLDGameMode::PostLogin"));		
}

void AFOLDGameMode::StartPlay()
{
	Super::StartPlay();
	UE_LOG(LogTemp, Display, TEXT("AFOLDGameMode::StartPlay"));
}

void AFOLDGameMode::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);
	UWorldPresetSubsystem* PresetSubsystem = GetGameInstance()->GetSubsystem<UWorldPresetSubsystem>();
	if (PresetSubsystem)
	{
		PresetSubsystem->InitializeWorld(GetWorld());
	}
	SpawnPlayerGroup();
	auto OnlineSubSystem = IOnlineSubsystem::Get();
	FString name = OnlineSubSystem->GetSubsystemName().ToString();
	GEngine->AddOnScreenDebugMessage(-1,20, FColor::Emerald, name);
	UE_LOG(LogTemp, Display, TEXT("AFOLDGameMode::InitGame"));	
}


void AFOLDGameMode::SpawnPlayerGroup()
{
}







