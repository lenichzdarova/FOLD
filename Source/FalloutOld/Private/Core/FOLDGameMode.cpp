// Fill out your copyright notice in the Description page of Project Settings.
#include "Core/FOLDGameMode.h"

void AFOLDGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);

	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 5, FColor::Red, "Player Login");	
}

void AFOLDGameMode::StartPlay()
{
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 5, FColor::Red, "Map loaded");
	Super::StartPlay();
	//проверяем состояние карты. удаляем ненужные акторы, добавляем нужные, восстанавливаем состояние акторов.
	//передаем плеер контроллерам данные о группе.
		
}

void AFOLDGameMode::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 5, FColor::Red, "initgame");
}
