#include "ActionMoveToPoint.h"

void UActionMoveToPoint::SetupAction(ACharacterEntity* receiver, AGridActor* grid, FVector destination)
{
	Receiver = receiver;
	Grid = grid;
	Destination = destination;
}










