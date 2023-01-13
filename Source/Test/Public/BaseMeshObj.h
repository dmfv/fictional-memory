// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseMeshObj.generated.h"

UCLASS()
class TEST_API ABaseMeshObj : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseMeshObj();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	UPROPERTY(VisibleAnywhere);
	UStaticMeshComponent* BaseMesh;
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
