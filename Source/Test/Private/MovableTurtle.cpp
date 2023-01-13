// Fill out your copyright notice in the Description page of Project Settings.


#include "MovableTurtle.h"

AMovableTurtle::AMovableTurtle() {
	PrimaryActorTick.bCanEverTick = true;
}

void AMovableTurtle::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMovableTurtle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Move(DeltaTime);
}

void AMovableTurtle::Move(float DeltaTime) 
{
	if (MoveType == FMoveType::Stop)
		return;
	Location = GetActorLocation();
	Location += GetActorForwardVector() * Speed * DeltaTime;
	SetActorLocation(Location);
} 