// Fill out your copyright notice in the Description page of Project Settings.


#include "CursorController.h"

// Sets default values for this component's properties
UCursorController::UCursorController()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


void UCursorController::Init(TSubclassOf<UWidgetCursor> WidgetClass, TMap<FGameplayTag, UTexture2D*> InTextureMap)
{
	TextureMap = InTextureMap;
	APlayerController* PlayerController = Cast<APlayerController>(GetOwner());
	auto RowWidget = CreateWidget(PlayerController, WidgetClass);
	Widget = Cast<UWidgetCursor>(RowWidget);
	
	PlayerController->bShowMouseCursor = true;
	PlayerController->SetMouseCursorWidget(EMouseCursor::Default, Widget);
	Widget->SetCursorAppearance(*TextureMap.Find(FGameplayTag::RequestGameplayTag("Interaction.Type.Default")));	
}

void UCursorController::SetCursorContextGameplayTag(const FGameplayTag ContextTag)
{	
	if (ContextTag == LastContextTag) return;
	if (ContextTag.IsValid())
	{
		LastContextTag = ContextTag;
	}
	else
	{
		LastContextTag = FGameplayTag::RequestGameplayTag("Interaction.Type.Default");
	}
	if (UTexture2D* Texture = *TextureMap.Find(LastContextTag))
	{
		Widget->SetCursorAppearance(Texture);
	}		
}

