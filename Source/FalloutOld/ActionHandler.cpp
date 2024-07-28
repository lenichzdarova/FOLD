// Fill out your copyright notice in the Description page of Project Settings.


#include "ActionHandler.h"

void UActionHandler::ExecuteAction(APawnBase* pawn, ActionBase* action)
{		
	if(auto activeAction = ActiveActions.Find(pawn))
	{
		delete *activeAction;
	}	
	ActiveActions.Add(pawn, action);
	action->Execute();	
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 5,FColor::Green, pawn->GetName());
}
