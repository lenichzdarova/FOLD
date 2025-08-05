// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CursorController.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FALLOUTOLD_API UCursorController : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCursorController();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:

	//arrow - with opening submenu - interraction, talk, inspect etc
	UPROPERTY()
	UUserWidget* InteractionMode = nullptr;
	
	//red cross - target selection
	UPROPERTY()
	UUserWidget* CombatMode = nullptr;
	
	//yellow cross - skill and items use
	UPROPERTY()
	UUserWidget* ActionMode = nullptr;

	//rectangle
	UPROPERTY()
	UUserWidget* MoveMode = nullptr;		
};
