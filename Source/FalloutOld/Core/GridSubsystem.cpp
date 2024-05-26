// Fill out your copyright notice in the Description page of Project Settings.


#include "GridSubsystem.h"
#include <cmath>

FVector UGridSubsystem::ConvertVectorToCell(FVector value)
{	
	float cellX = value.X - minX;
	float reminder = fmod(cellX,CELL_SIZE);
	cellX = (cellX - reminder) + CELL_SIZE/2 + minX;

	float cellY = value.Y - minY;
	reminder = fmod(cellY,CELL_SIZE);
	cellY = (cellY - reminder) + CELL_SIZE/2 + minY;

	return FVector{cellX, cellY, value.Z};	
}
