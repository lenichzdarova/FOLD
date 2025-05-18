// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/ListView.h"
#include "Components/EditableText.h"
#include "DEVAuthToolLogin.generated.h"

/**
 * 
 */
UCLASS(Abstract, Blueprintable)
class FALLOUTOLD_API UDEVAuthToolLogin : public UUserWidget
{
	GENERATED_BODY()


protected:
	virtual void NativeConstruct() override;
	
	UPROPERTY(meta = (BindWidget))
	UEditableText* CredentialInput;
	UPROPERTY(meta = (BindWidget))
	UButton* Login;
	UPROPERTY(meta = (BindWidget))
	UButton* CreateSession;
	UPROPERTY(meta = (BindWidget))
	UButton* FindSessions;
	UPROPERTY(meta = (BindWidget))
	UButton* JoinSession;
	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	UListView* SessionsList;

	UFUNCTION()
	void OnLoginPressed();
	UFUNCTION()
	void OnCreateSessionPressed();
	UFUNCTION()
	void OnFindSessionPressed();
	void OnFindSessionCompleted(bool bWasSuccessful);
	UFUNCTION()
	void OnJoinSessionPressed();

	FDelegateHandle OnFindSessionsCompletedDelegateHandle;
};
