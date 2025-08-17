// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GameFramework/Actor.h"
#include "IDComponent.h"
#include "TravelTriggerBase.generated.h"

UCLASS(Abstract, Blueprintable, Category="FOLD")
class FALLOUTOLD_API ATravelTriggerBase : public AActor
{
	GENERATED_BODY()

	private:
	UPROPERTY(EditAnywhere, Category="FOLD")
	FGameplayTag TargetedSpawnZone;
	UPROPERTY(EditAnywhere, Category="FOLD")
	TSoftObjectPtr<UWorld> MapToLoad;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category= "ID", meta=(AllowPrivateAccess = "true"))
	TObjectPtr<UIDComponent> IDComponent;

public:
	// Sets default values for this actor's properties
	ATravelTriggerBase();

protected:	
	
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
	virtual FString CreateLevelOpenOptions();

public:

	//включает отключает переход
	void SetActive(bool bActive);
	
	//геттер и сеттер геймлпей тага точки спавна на целевой карте
	FGameplayTag GetTravelTarget() const {return TargetedSpawnZone;}	
	void SetTravelTarget(const FGameplayTag NewTravelTarget) {TargetedSpawnZone = NewTravelTarget;}
};
