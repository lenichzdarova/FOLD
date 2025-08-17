// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerParty.h"

UPlayerParty* UPlayerParty::PlayerParty = nullptr;

UPlayerParty* UPlayerParty::GetPlayerParty()
{
	if (!PlayerParty)
	{
		PlayerParty=NewObject<UPlayerParty>();
	}
	return PlayerParty;
}

const FGameplayTag& UPlayerParty::GetPlayerTag() const
{
	return PlayerTag;
}

void UPlayerParty::AddID(const FGameplayTag& Tag)
{	
	Tags.AddTag(Tag);
	UE_LOG(LogTemp, Log, TEXT("%s присоединился к группе"), *Tag.ToString());	
	Changed.Broadcast();
}

void UPlayerParty::RemoveID(const FGameplayTag& Tag)
{
	Tags.RemoveTag(Tag);
	UE_LOG(LogTemp, Log, TEXT("%s покинул группу"), *Tag.ToString());
	Changed.Broadcast();
}

bool UPlayerParty::ContainsID(const FGameplayTag& Tag) const
{
	return Tags.HasTag(Tag);
}

const TArray<FGameplayTag> UPlayerParty::GetPartyMembersID() const
{
	return Tags.GetGameplayTagArray();
}

void UPlayerParty::SetPartyMembersID(TArray<FGameplayTag> InTags)
{
	Tags.CreateFromArray(InTags);
	Changed.Broadcast();
}







