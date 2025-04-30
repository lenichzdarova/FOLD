// Fill out your copyright notice in the Description page of Project Settings.


#include "Party.h"

#include "Net/UnrealNetwork.h"

void UParty::AddPlayerCharacters(UPlayerParty* PlayerControlledCharacters)
{
}

void UParty::RemovePlayerCharacters(UPlayerParty* PlayerControlledCharacters)
{
}

void UParty::OnRep_Party()
{
}

void UParty::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	UObject::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UParty, Party);
}
