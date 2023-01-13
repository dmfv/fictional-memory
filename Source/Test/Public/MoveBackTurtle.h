// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MoveStopTurtle.h"
#include "MoveBackTurtle.generated.h"

/**
 * 
 */
UCLASS()
class TEST_API AMoveBackTurtle : public AMoveStopTurtle
{
	GENERATED_BODY()
protected:
	virtual void TimeCallback() override;
	virtual void TurnAround(); // if takes too long inside TimerCallback so move it to Move function
};
