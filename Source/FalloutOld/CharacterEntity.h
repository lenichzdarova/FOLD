// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Movement.h"
#include "GameFramework/Pawn.h"
#include "CharacterEntity.generated.h"

UCLASS(Blueprintable)
class FALLOUTOLD_API ACharacterEntity : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ACharacterEntity();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintReadWrite)
	UMovement* movementComponent;

protected:	
	UPROPERTY(BlueprintReadWrite)
	USkeletalMeshComponent* skeletalMesh;	
};
