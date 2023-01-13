// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MovableTurtle.h"
//#include "TimerManager.h"
#include "MoveStopTurtle.generated.h"

/**
 * 
 */
UCLASS()
class TEST_API AMoveStopTurtle : public AMovableTurtle
{
	GENERATED_BODY()
	virtual void BeginPlay() override;
protected:
	virtual void TimeCallback();
	virtual bool CheckGoForwardTimed(); // check how many times moved forward
public:
	float TimerPeriod = 0.5f; // 0.5 seconds timer period
	static const int TimerPeriodGoForward = 2; // how many periods of timer go forward
	int MovedForwardTimes = 0; // Counter
	FTimerHandle TimerHandle;
};
