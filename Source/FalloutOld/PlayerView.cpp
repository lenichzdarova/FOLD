// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerView.h"
#include "EnhancedInputComponent.h"
#include "Camera/CameraComponent.h"


// Sets default values
APlayerView::APlayerView()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	
	//SpringArm setup
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	SpringArm->TargetArmLength = DefaultArmLength;
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->bDoCollisionTest = false;

	//Camera setup	
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));	
	Camera->SetupAttachment(SpringArm,SpringArm->SocketName);

	FRotator rotator;
	rotator.Pitch = DefaultViewAngle;
	SpringArm->SetWorldRotation(rotator);
	RotationDelta = 0.f;
	
}

// Called when the game starts or when spawned
void APlayerView::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void APlayerView::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if(RotationDelta!=0)
	{
		Rotate();
	}	
}

void APlayerView::Move(FVector value)
{
	//need implement borders check etc
	AddActorLocalOffset(value);	
}
void APlayerView::OnMoveInput(const FInputActionValue& inputValue)
{
	auto inputVector = inputValue.Get<FVector2D>();
	inputVector.Normalize();	
	FVector moveVector{inputVector.X,inputVector.Y,0};
	moveVector*=MoveSensitivity;
	Move(moveVector);
}


void APlayerView::OnRotateInput(const FInputActionValue& inputValue)
{	
	if(RotationDelta == 0)
	{
		auto input = inputValue.Get<float>();
		RotationDelta = input * RotationValue;
	}	
}

void APlayerView::Rotate()
{
	FRotator rotator = GetActorRotation();	
	float currentRotationValue = FMath::Lerp(0,RotationDelta,0.05f);
	if(RotationDelta < 0)
	{
		currentRotationValue = FMath::Clamp(currentRotationValue, RotationDelta,-MinRotationValueAbs);
	}
	else
	{
		currentRotationValue = FMath::Clamp(currentRotationValue, MinRotationValueAbs,RotationDelta);
	}
	if((FMath::Abs(RotationDelta) - FMath::Abs(currentRotationValue)) < 0)
	{
		currentRotationValue = RotationDelta;
	}	
	rotator.Add(0,currentRotationValue,0);
	SetActorRotation(rotator);
	RotationDelta -= currentRotationValue;	
}





