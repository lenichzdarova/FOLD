// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "SessionsListViewEntry.generated.h"

/**
 * 
 */
UCLASS(Abstract,Blueprintable)
class FALLOUTOLD_API USessionsListViewEntry : public UUserWidget, public IUserObjectListEntry
{
	GENERATED_BODY()


protected:
	UPROPERTY(meta = (BindWidget))
	UTextBlock* SessionName;

	virtual void NativeOnListItemObjectSet(UObject* ListItemObject) override;
};
