// Fill out your copyright notice in the Description page of Project Settings.


#include "FOLDActorRefSubsystem.h"

AActor* UFOLDActorRefSubsystem::GetActorByTag(FGameplayTag ActorTag)
{
	return ActorRefs.Find(ActorTag)->Get();
}

AActor* UFOLDActorRefSubsystem::GetActorByTagStatic(const UObject* WorldContext, FGameplayTag ActorTag)
{
	return nullptr;
}
