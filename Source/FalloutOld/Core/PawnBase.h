// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/CapsuleComponent.h"
#include "FalloutOld/Interactable.h"
#include "Movement.h"
#include "NavTargetActor.h"
#include "PawnBase.generated.h"

UCLASS(Blueprintable)
class FALLOUTOLD_API APawnBase : public APawn, public INavTargetActor, public IInteractable
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

protected:
	virtual void PossessedBy(AController* NewController) override;

public:
	UPROPERTY(VisibleAnywhere)
	USceneComponent* SceneComponent;	
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite)
	UMovement* Movement;
	UPROPERTY(VisibleAnywhere)
	USkeletalMeshComponent* Mesh;
	
	virtual bool IsCellCenterOriented_Implementation() override;
};
