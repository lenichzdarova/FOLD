// Fill out your copyright notice in the Description page of Project Settings.


#include "DoorBase.h"

#include "DoorBehaviourComponentBase.h"


// Sets default values
ADoorBase::ADoorBase()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	InteractableComponent = CreateDefaultSubobject<UInteractableActorComponent>("Interactable component");
}

void ADoorBase::Open()
{	
	TArray<UDoorBehaviourComponentBase*> ComponentsArray;
	GetComponents<UDoorBehaviourComponentBase>(ComponentsArray);	
	for (UDoorBehaviourComponentBase* Component : ComponentsArray)
	{
		Component->StartOpen();
		if (!Longest)
		{
			Longest = Component;
			continue;
		}
		if (Longest->GetEvaluationTime() < Component->GetEvaluationTime())
		{
			Longest = Component;
		}		
	}
	Longest->OnEvaluationComplete.AddDynamic(this, &ADoorBase::OnEvaluationCompleted);
	bIsOpened = true;	
}

void ADoorBase::Close()
{
	TArray<UDoorBehaviourComponentBase*> ComponentsArray;
	GetComponents<UDoorBehaviourComponentBase>(ComponentsArray);	
	for (UDoorBehaviourComponentBase* Component : ComponentsArray)
	{
		Component->StartClose();
		if (!Longest)
		{
			Longest = Component;
			continue;
		}
		if (Longest->GetEvaluationTime() < Component->GetEvaluationTime())
		{
			Longest = Component;
		}		
	}
	Longest->OnEvaluationComplete.AddDynamic(this, &ADoorBase::OnEvaluationCompleted);
	bIsOpened = false;	
}

void ADoorBase::SetDoorState(bool bOpened)
{
	TArray<UDoorBehaviourComponentBase*> ComponentsArray;
	GetComponents<UDoorBehaviourComponentBase>(ComponentsArray);	
	for (UDoorBehaviourComponentBase* Component : ComponentsArray)
	{
		Component->SetCurrentState(bIsOpened);
	}
	bIsOpened = bOpened;
}

void ADoorBase::OnEvaluationCompleted()
{
	Longest->OnEvaluationComplete.RemoveAll(this);	
}

void ADoorBase::PostLoadInit_Implementation()
{
	SetDoorState(bIsOpened);
	Super::PostLoadInit_Implementation();
}

void ADoorBase::Interact_Implementation(const AActor* InInstigator)
{	
	IInteractable::Interact_Implementation(InInstigator);
	if (bIsOpened)
	{
		Close();
	}
	else
	{
		Open();
	}		
}

