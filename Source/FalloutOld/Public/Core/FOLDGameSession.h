// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameSession.h"
#include "FOLDGameSession.generated.h"

UCLASS()
class FALLOUTOLD_API AFOLDGameSession : public AGameSession
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AFOLDGameSession();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
