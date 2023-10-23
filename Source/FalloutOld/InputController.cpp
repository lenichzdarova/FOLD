// Fill out your copyright notice in the Description page of Project Settings.


#include "InputController.h"

UInputController::UInputController()
{
	Actions = CreateDefaultSubobject<UInputActions>("Input Actions");
	static ConstructorHelpers::FObjectFinder<UInputMappingContext> inputMappingContext(TEXT("/Script/EnhancedInput.InputMappingContext'/Game/Blueprints/Input/IMC_InputMapping.IMC_InputMapping'"));
	if(inputMappingContext.Succeeded())
	{
		DefaultContext = inputMappingContext.Object.Get();
	}
}

void UInputController::Initialize(UEnhancedInputLocalPlayerSubsystem* subsystem)
{
	InputSubsystem = subsystem;
	subsystem->AddMappingContext(DefaultContext,0);
}
