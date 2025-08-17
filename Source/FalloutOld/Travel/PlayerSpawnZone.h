// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IDComponent.h"
#include "PlayerSpawnZone.generated.h"

UCLASS(Abstract)
class FALLOUTOLD_API APlayerSpawnZone : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	APlayerSpawnZone();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category= "ID", meta=(AllowPrivateAccess = "true"))
	TObjectPtr<UIDComponent> IDComponent;
	
	void MovePlayerActorsToSpawnZone();
};
