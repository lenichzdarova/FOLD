// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "WidgetCursor.h"
#include "Components/ActorComponent.h"
#include "CursorController.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FALLOUTOLD_API UCursorController : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCursorController();

protected:
	UPROPERTY()
	TObjectPtr<UWidgetCursor> Widget;
	UPROPERTY()
	TMap<FGameplayTag,UTexture2D*> TextureMap;
	UPROPERTY()
	FGameplayTag LastContextTag;
public:
	void Init(TSubclassOf<UWidgetCursor> WidgetClass, TMap<FGameplayTag, UTexture2D*> InTextureMap);
	void SetCursorContextGameplayTag(const FGameplayTag ContextTag);
};
