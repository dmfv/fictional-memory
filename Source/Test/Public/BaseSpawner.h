// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovableTurtle.h"
#include "BaseMeshObj.h"
#include "BaseSpawner.generated.h"

UCLASS()
class TEST_API ABaseSpawner : public ABaseMeshObj
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseSpawner();

	//UPROPERTY(VisibleAnywhere)
	UPROPERTY(EditAnywhere)
	TSubclassOf<AMovableTurtle> TurtleClass;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	virtual void SpawnTurtle();

};
