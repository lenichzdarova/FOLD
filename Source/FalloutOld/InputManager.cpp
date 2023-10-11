// Fill out your copyright notice in the Description page of Project Settings.


#include "InputManager.h"

#include "EnhancedInputComponent.h"

UInputManager::UInputManager(const FObjectInitializer& initializer)
{    
    static ConstructorHelpers::FObjectFinder<UInputAction> moveInput(TEXT("/Script/EnhancedInput.InputAction'/Game/Blueprints/Input/IA_CameraMove.IA_CameraMove'"));
    if(moveInput.Succeeded())
    {
        MoveCamera = moveInput.Object.Get();
    }    
    static ConstructorHelpers::FObjectFinder<UInputAction> rotateInput(TEXT("/Script/EnhancedInput.InputAction'/Game/Blueprints/Input/IA_CameraRotate.IA_CameraRotate'"));
    if(rotateInput.Succeeded())
    {
        RotateCamera = rotateInput.Object.Get();
    }
    static ConstructorHelpers::FObjectFinder<UInputAction> LMBInput(TEXT("/Script/EnhancedInput.InputAction'/Game/Blueprints/Input/IA_Move.IA_Move'"));
    if(LMBInput.Succeeded())
    {
        Move = LMBInput.Object.Get();
    }
    static ConstructorHelpers::FObjectFinder<UInputMappingContext> inputMappingContext(TEXT("/Script/EnhancedInput.InputMappingContext'/Game/Blueprints/Input/IMC_InputMapping.IMC_InputMapping'"));
    if(inputMappingContext.Succeeded())
    {
        InputMapping = inputMappingContext.Object.Get();
    }

    
    
}







