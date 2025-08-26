// Fill out your copyright notice in the Description page of Project Settings.


#include "IDComponent.h"

#include "FOLD_ActorRefSubsystem.h"
#include "StorableObject.h"


// Sets default values for this component's properties
UIDComponent::UIDComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
	bAutoActivate = true;	
	// ...	
}
void UIDComponent::OnRegister()
{
	Super::OnRegister();
	/*
	 *Присваивает GUID для инстанса компонента (не для CDO). Вызывается при создании актора в режиме редактора и
	 *рантайм спавне. Чтобы присвоенные в редакторе айди не перезаписывались рантайм, делаем проверку на валидность.
	 */
	if(!Guid.IsValid())
	{
		Guid = FGuid::NewGuid();
	}	
}

void UIDComponent::RegisterActor()
{	
	if (Tag.IsValid())
	{
		UFOLD_ActorRefSubsystem* RefSubsystem = GetWorld()->GetSubsystem<UFOLD_ActorRefSubsystem>();
		RefSubsystem->RegisterActor(GetOwner(), Tag, Guid);				
	}
	if (GetOwner()->Implements<UStorableObject>())
	{
		IStorableObject::Execute_PostLoadInit(GetOwner());
	}
}

void UIDComponent::UnregisterActor() const
{
}



