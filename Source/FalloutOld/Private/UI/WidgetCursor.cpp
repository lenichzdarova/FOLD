// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WidgetCursor.h"
void UWidgetCursor::SetDefault()
{
	cursorImage->SetBrushFromTexture(Default);
}

void UWidgetCursor::SetDialog()
{
	cursorImage->SetBrushFromTexture(Dialog);
}

void UWidgetCursor::SetTake()
{
	cursorImage->SetBrushFromTexture(Take);
}

void UWidgetCursor::SetUse()
{
	cursorImage->SetBrushFromTexture(Use);
}


