// Fill out your copyright notice in the Description page of Project Settings.


#include "CursorContextComponent.h"

#include "CursorController.h"
#include "InteractableActorComponent.h"
#include "Kismet/GameplayStatics.h"


// Sets default values for this component's properties
UCursorContextComponent::UCursorContextComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}


// Called every frame
void UCursorContextComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                            FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	
	if (APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0))
	{
		FGameplayTag ContextTag;
		ETraceTypeQuery Query{ECC_Visibility};
		PlayerController->GetHitResultUnderCursorByChannel(Query, true, HitResult);		
		if (HitResult.bBlockingHit)
		{
			GEngine->AddOnScreenDebugMessage(2222,0.1, FColor::Blue, HitResult.GetActor()->GetName());
			if (AActor* HitActor = HitResult.GetActor())
			{
				if (UInteractableActorComponent* Interactable = HitActor->GetComponentByClass<UInteractableActorComponent>())
				{					
					ContextTag = Interactable->GetInteractionTypeTag();
				}				
			}			
		}
		auto CursorContext = PlayerController->GetComponentByClass<UCursorController>();
		CursorContext->SetCursorContextGameplayTag(ContextTag);
	}	
}

