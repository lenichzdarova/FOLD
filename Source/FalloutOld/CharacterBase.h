// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/Character.h"
#include "Navigation/PathFollowingComponent.h"
#include "CharacterBase.generated.h"

class UActionHandler;

UCLASS(Blueprintable)
class FALLOUTOLD_API ACharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ACharacterBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;	 

protected:
	virtual void PossessedBy(AController* NewController) override;

public:
	UPROPERTY()
	UPathFollowingComponent* PathFollowingComponent;
	UPROPERTY()
	UActionHandler* ActionHandler;		
};
