// Fill out your copyright notice in the Description page of Project Settings.


#include "InputActions.h"

#include "EnhancedInputComponent.h"

UInputActions::UInputActions(const FObjectInitializer& initializer)
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
    static ConstructorHelpers::FObjectFinder<UInputAction> BattleMode(TEXT("/Script/EnhancedInput.InputAction'/Game/Blueprints/Input/IA_ToggleBattleMode.IA_ToggleBattleMode'"));
    if(BattleMode.Succeeded())
    {
        ToggleBattleMode = BattleMode.Object.Get();
    }
    static ConstructorHelpers::FObjectFinder<UInputAction> SkipTurn(TEXT("/Script/EnhancedInput.InputAction'/Game/Blueprints/Input/IA_EndTurn.IA_EndTurn'"));
    if(SkipTurn.Succeeded())
    {
        EndTurn = SkipTurn.Object.Get();
    }
}







