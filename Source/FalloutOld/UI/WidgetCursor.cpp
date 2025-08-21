// Fill out your copyright notice in the Description page of Project Settings.


#include "WidgetCursor.h"

void UWidgetCursor::SetCursorAppearance(UTexture2D* CursorAppearance)
{
	cursorImage->SetBrushFromTexture(CursorAppearance);	
}
