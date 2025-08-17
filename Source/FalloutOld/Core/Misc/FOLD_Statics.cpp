// Fill out your copyright notice in the Description page of Project Settings.


#include "FOLD_Statics.h"

#include "FOLD_ActorRefSubsystem.h"
#include "Unsorted/PlayerParty.h"

AActor* UFOLD_Statics::GetPlayerCharacter(UObject* WorldContext)
{
	UWorld* World = GetWorldFromContext(WorldContext);
	if (!World) return nullptr;
	UFOLD_ActorRefSubsystem* RefSubsystem = World->GetSubsystem<UFOLD_ActorRefSubsystem>();
	UPlayerParty* Party = UPlayerParty::GetPlayerParty();
	return RefSubsystem->GetActorByTag(Party->GetPlayerTag());
}

UWorld* UFOLD_Statics::GetWorldFromContext(const UObject* Context)
{
	if (!Context) return nullptr;
	if ( UWorld* World = Context->GetWorld())
	{
		return World;
	}
	return GetWorldFromContext(Context->GetOuter());
}
