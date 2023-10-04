#include "MoveCommand.h"

MoveCommand::MoveCommand(ACharacterEntity* receiver, FVector2D destination) : Command(receiver)
{
	Destination = destination;
}

void MoveCommand::Execute()
{
	
}


