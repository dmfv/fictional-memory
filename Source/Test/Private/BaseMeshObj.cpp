// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseMeshObj.h"

// Sets default values
ABaseMeshObj::ABaseMeshObj()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>("DefaultMesh");
	SetRootComponent(BaseMesh);
	BaseMesh->SetStaticMesh(ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Game/TestMeshes/ghost/ghost.ghost'")).Object);

}
// Called when the game starts or when spawned
void ABaseMeshObj::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseMeshObj::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

