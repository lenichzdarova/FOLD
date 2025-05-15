// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameSession.h"
#include "OnlineSessionSettings.h"
#include "OnlineSessionClient.h"
#include "OnlineSubsystem.h"
#include "FOLDGameSession.generated.h"

UCLASS()
class FALLOUTOLD_API AFOLDGameSession : public AGameSession
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AFOLDGameSession();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:	
	TSharedPtr<FOnlineSessionSearch> SearchSettings;
	TSharedPtr<FOnlineSessionSettings> HostSettings;
	
	

	//поиск сессий
public:
	void FindSessions();
	FOnFindSessionsCompleteDelegate OnFindSessionsCompleteDelegate;
	FDelegateHandle OnFindSessionsCompleteDelegateHandle;
	void OnFindSessionsComplete(bool bWasSuccessful);

	//присоединение к сессии
public:
	bool JoinSession(TSharedPtr<const FUniqueNetId> UserId, FName InSessionName, const FOnlineSessionSearchResult& SearchResult);
private:
	void OnJoinSessionComplete(FName SessionName, EOnJoinSessionCompleteResult::Type Result);
	FOnJoinSessionCompleteDelegate OnJoinSessionCompleteDelegate;
	FDelegateHandle OnJoinSessionCompleteDelegateHandle;

	//создание сессии
public:
	UFUNCTION(BlueprintCallable)
	bool CreateSession();
private:	
	FOnCreateSessionCompleteDelegate OnCreateSessionCompleteDelegate;
	FDelegateHandle OnCreateSessionCompleteDelegateHandle;
	virtual void OnCreateSessionComplete(FName SessionName, bool bWasSuccessful);

	//старт сессии	
	FOnStartSessionCompleteDelegate OnStartSessionCompleteDelegate;
	FDelegateHandle OnStartSessionCompleteDelegateHandle;
	void OnStartOnlineGameComplete(FName SessionName, bool bWasSuccessful);

	//уничтожении сессии
	FOnDestroySessionCompleteDelegate OnDestroySessionCompleteDelegate;
	FDelegateHandle OnDestroySessionCompleteDelegateHandle;
	virtual void OnDestroySessionComplete(FName SessionName, bool bWasSuccessful);		
	  
};
