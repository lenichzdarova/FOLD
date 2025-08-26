// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AActorBase.h"
#include "DoorBehaviourComponentBase.h"
#include "DoorBase.generated.h"

UCLASS(Abstract)
class FALLOUTOLD_API ADoorBase : public AActorBase
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ADoorBase();

public:
	UFUNCTION(BlueprintCallable, Category="Door")
	virtual void Open();
	UFUNCTION(BlueprintCallable, Category="Door")
	virtual void Close();
	UFUNCTION(BlueprintCallable, Category="Door")
	virtual void SetDoorState(bool bOpened);
protected:
	UPROPERTY(EditAnywhere, Category="Door")
	bool bReverseBehaviour = false;
	UPROPERTY(SaveGame, EditAnywhere, Category="Door")
	bool bIsOpened = false;

	UFUNCTION()
	void OnEvaluationCompleted();
	private:
	UPROPERTY()
	UDoorBehaviourComponentBase* Longest = nullptr;
public:
	virtual void PostLoadInit_Implementation() override;
};
