// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "GameFramework/Actor.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "PlayerView.generated.h"

UCLASS(BlueprintType,Blueprintable)
class FALLOUTOLD_API APlayerView : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlayerView();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	
	UPROPERTY()
	UCameraComponent* Camera;
	UPROPERTY()
	USpringArmComponent* SpringArm;

	float DefaultArmLength = 1000.0f;	
		
	//rotation properties
	float DefaultViewAngle{300.f};
	float RotationDelta;
	const float RotationValue = 90.f;
	float MinRotationValueAbs = 1.f;
	//move properties	
	float MoveSensitivity = 50.f;
	FVector2d MinBorder;
	FVector2d MaxBorder;

public:
	UFUNCTION(BlueprintCallable)	
	void Move(FVector value);
	
	UFUNCTION(BlueprintCallable)
	void SetRotation(float value);
	void Rotate();
};
