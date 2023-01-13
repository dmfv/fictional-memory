// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "BaseMeshObj.h"
#include "MovableTurtle.generated.h"


UENUM(BlueprintType)
enum class FMoveType : uint8 {
	Forward = 0  UMETA(DisplayName = "Forward"),
	Backward = 1  UMETA(DisplayName = "Backward"),
	Stop = 2  UMETA(DisplayName = "Stop")
};

/**
 * 
 */
UCLASS()
class TEST_API AMovableTurtle : public ABaseMeshObj
{
	GENERATED_BODY()
protected:
	virtual void BeginPlay() override;

public:
	AMovableTurtle();
	virtual void Tick(float DeltaTime) override;
	virtual void Move(float DeltaTime);

	FVector Location;
	UPROPERTY()
	UStaticMesh* Asset;

	UPROPERTY(EditAnywhere)
	float Speed = 50;

	UPROPERTY(EditAnywhere)
	FMoveType MoveType = FMoveType::Forward;
};
