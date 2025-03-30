// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/FOLDGameState.h"

#include "Engine/ActorChannel.h"
#include "Net/UnrealNetwork.h"

AFOLDGameState::AFOLDGameState()
{
	//bReplicateUsingRegisteredSubObjectList = true;
	PlayerParty = CreateDefaultSubobject<UPlayerParty>("PlayerParty");
	AddReplicatedSubObject(PlayerParty);	
}

void AFOLDGameState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFOLDGameState, PlayerParty);
}

bool AFOLDGameState::ReplicateSubobjects(class UActorChannel* Channel, class FOutBunch* Bunch,
	FReplicationFlags* RepFlags)
{
	bool result = Super::ReplicateSubobjects(Channel, Bunch, RepFlags);
	if (PlayerParty ) result |= Channel->ReplicateSubobject(PlayerParty , *Bunch, *RepFlags);
	return result;
}


