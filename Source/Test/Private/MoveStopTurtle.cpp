// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveStopTurtle.h"

void AMoveStopTurtle::BeginPlay()
{
	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(TimerHandle, this, &AMoveStopTurtle::TimeCallback, TimerPeriod, true);
}


void AMoveStopTurtle::TimeCallback()
{
	switch (MoveType) {
	case (FMoveType::Forward):
		if (CheckGoForwardTimed())
			MoveType = FMoveType::Stop;
		break;
	case (FMoveType::Stop):
		MoveType = FMoveType::Forward;
		break;
	}
}

bool AMoveStopTurtle::CheckGoForwardTimed()
{
	if (++MovedForwardTimes == TimerPeriodGoForward) {
		MovedForwardTimes = 0;
		return true;
	}
	return false;
}
