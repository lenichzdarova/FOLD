// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractableActorComponent.h"

#include "Interactable.h"


// Add default functionality here for any IIInteractable functions that are not pure virtual.
void UInteractableActorComponent::Interact(const AActor* InInstigator)
{	
	if (IInteractable * Interactable = Cast<IInteractable>(GetOwner()))
	{		
		IInteractable::Execute_Interact(GetOwner(), InInstigator);
	}
}
