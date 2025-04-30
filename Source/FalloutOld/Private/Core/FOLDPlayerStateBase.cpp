// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/FOLDPlayerStateBase.h"

#include "Engine/ActorChannel.h"
#include "Net/UnrealNetwork.h"

AFOLDPlayerStateBase::AFOLDPlayerStateBase()
{
	bReplicateUsingRegisteredSubObjectList = true;
	PlayerParty = CreateDefaultSubobject<UPlayerParty>("PlayerParty");
	AddReplicatedSubObject(PlayerParty);
}

void AFOLDPlayerStateBase::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFOLDPlayerStateBase, PlayerParty);
}
