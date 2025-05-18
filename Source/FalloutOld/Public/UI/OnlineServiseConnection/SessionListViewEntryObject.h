// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OnlineSessionSettings.h"

#include "SessionListViewEntryObject.generated.h"

/**
 * 
 */
UCLASS()
class FALLOUTOLD_API USessionListViewEntryObject : public UObject
{
	GENERATED_BODY()

	private:
	FOnlineSessionSearchResult SearchResult;
	
	public:
	void SetSessionData(const FOnlineSessionSearchResult& InSearchResult){SearchResult  = InSearchResult;};
	FOnlineSessionSearchResult& GetSession() {return SearchResult;};
};
