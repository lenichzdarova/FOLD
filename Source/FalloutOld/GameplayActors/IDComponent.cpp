// Fill out your copyright notice in the Description page of Project Settings.


#include "IDComponent.h"

#include "FOLDActorRefSubsystem.h"


// Sets default values for this component's properties
UIDComponent::UIDComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
	bAutoActivate = true;
	bWantsInitializeComponent = true;
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

void UIDComponent::InitializeComponent()
{
	Super::InitializeComponent();	
	if (ID.IsValid())
	{
		UFOLDActorRefSubsystem* RefSubsystem = GetWorld()->GetSubsystem<UFOLDActorRefSubsystem>();
		RefSubsystem->RegisterActor(GetOwner(), ID, Guid);		
	}	
}



