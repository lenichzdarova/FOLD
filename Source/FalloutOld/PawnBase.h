// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/Pawn.h"
#include "PawnBase.generated.h"

UCLASS(Blueprintable)
class FALLOUTOLD_API APawnBase : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APawnBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;	
	UPROPERTY(BlueprintReadWrite,EditDefaultsOnly)
	UCapsuleComponent* CapsuleComponent; 

protected:	
	UPROPERTY(BlueprintReadWrite,EditDefaultsOnly)
	USkeletalMeshComponent* SkeletalMesh;	
};
