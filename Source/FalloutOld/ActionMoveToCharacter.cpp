#include "ActionMoveToCharacter.h"

void UActionMoveToCharacter::SetupAction(ACharacterEntity* receiver, AGridActor* grid, ACharacterEntity* target)
{
	Receiver = receiver;
	Grid = grid;
	Target = target;
	Destination = Target->GetActorLocation();
}
void UActionMoveToCharacter::BindDelegates()
{
	Super::BindDelegates();
	Target->movementComponent->PositionUpdate.AddUObject(this, &UActionMoveToCharacter::OnTargetPositionUpdate);
}

void UActionMoveToCharacter::UnbindDelegates()
{
	Super::UnbindDelegates();
	Target->movementComponent->PositionUpdate.RemoveAll(this);
}

void UActionMoveToCharacter::OnTargetPositionUpdate()
{
	SetMovePath(Receiver->GetActorLocation(),Target->GetActorLocation());
}


