// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveBackTurtle.h"

void AMoveBackTurtle::TimeCallback()
{
	switch (MoveType) {
	case (FMoveType::Forward):
		if (CheckGoForwardTimed()) {
			TurnAround();
			MoveType = FMoveType::Backward;
		}
		break;
	case (FMoveType::Backward):
		TurnAround();
		MoveType = FMoveType::Forward;
		break;
	}
}

void AMoveBackTurtle::TurnAround() 
{
	FRotator Rotator = BaseMesh->GetRelativeRotation();
	// mirror Rotator around Z component
	Rotator.Yaw += 180;
	BaseMesh->SetRelativeRotation(Rotator, false, nullptr, ETeleportType::None);
}