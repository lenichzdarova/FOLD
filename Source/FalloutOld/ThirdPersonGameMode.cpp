// Fill out your copyright notice in the Description page of Project Settings.


#include "ThirdPersonGameMode.h"

#include "CharacterEntity.h"
#include "PlayerControllerBase.h"

AThirdPersonGameMode::AThirdPersonGameMode()
{
	DefaultPawnClass = nullptr;
	InputController = CreateDefaultSubobject<UInputController>("Input controller");
	PlayerControllerClass = APlayerControllerBase::StaticClass();
}

void AThirdPersonGameMode::BeginPlay()
{	
	auto controller = GetWorld()->GetFirstPlayerController();
	APlayerControllerBase* myController = Cast<APlayerControllerBase>(controller);
    //InputController->Initialize(myController->GetInputSubsystem());
	//myController->Initialize(InputController->GetInputActions());
}

