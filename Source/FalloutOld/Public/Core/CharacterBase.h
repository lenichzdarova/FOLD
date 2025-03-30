// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactable.h"
#include "NavTargetActor.h"
#include "Movement.h"
#include "GameFramework/Character.h"
#include "Mechanics/CharacterProfile.h"
#include "SaveGame/StorableActor.h"
#include "CharacterBase.generated.h"

UCLASS(Blueprintable)
class FALLOUTOLD_API ACharacterBase : public ACharacter, public INavTargetActor, public IInteractable, public IStorableActor
{
	GENERATED_BODY()

private:
	UPROPERTY(SaveGame)
	UCharacterProfile* CharacterProfile;
	
public:
	// Sets default values for this pawn's properties
	ACharacterBase(const FObjectInitializer& ObjectInitializer);
	virtual void Tick(float DeltaTime) override;	
	virtual bool IsCellCenterOriented_Implementation() override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;	

};
