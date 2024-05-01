// Fill out your copyright notice in the Description page of Project Settings.


#include "DialogSubsystem.h"

#include "FalloutOld/UI/HUDBase.h"
#include "Kismet/GameplayStatics.h"


void UDialogSubsystem::StartDialog(ACharacterBase* a, ACharacterBase* b)
{
	UWorld* world = GetWorld();	
	APlayerController* playerController = UGameplayStatics::GetPlayerController(world,0);	
	AHUDBase* hud =  Cast<AHUDBase>(playerController->GetHUD());
	UUserWidget* dialog = CreateWidget(playerController, hud->Dialog);
	dialog->AddToViewport();
	FString text = a->GetName();
	text.Append("/");
	text.Append(b->GetName());	
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 10.0f, FColor::Green, text);
}
