// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTags.h"
#include "IDComponent.generated.h"


UCLASS(BlueprintType, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class FALLOUTOLD_API UIDComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UIDComponent();	
	
	const FGuid& GetID() const {return Guid;}
	void SetID(const FGuid& NewID) {Guid = NewID;}
	const FGameplayTag& GetTag() const {return Tag;}
	void SetTag(const FGameplayTag& NewTag) {Tag = NewTag;}	
	virtual void OnRegister() override;
	void RegisterActor();
	void UnregisterActor() const;

private:
	//Используется для идентификации и при хранениии даных актора
	UPROPERTY(EditAnywhere, SaveGame)
	FGuid Guid;
	//именование значимых геймплейных акторов.  Является ключом для получения ссылки на такого актора.
	UPROPERTY(EditAnywhere, SaveGame, meta=(Categories = "Actors"))
	FGameplayTag Tag;
};
