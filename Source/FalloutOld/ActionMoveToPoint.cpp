#include "ActionMoveToPoint.h"

void UActionMoveToPoint::SetupAction(APawnBase* receiver, AGridActor* grid, FVector destination)
{
	Receiver = receiver;
	Grid = grid;
	Destination = destination;
}










