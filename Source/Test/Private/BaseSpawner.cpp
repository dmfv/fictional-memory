 // Fill out your copyright notice in the Description page of Project Settings.


#include "BaseSpawner.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include <AudioDevice.h>

DEFINE_LOG_CATEGORY_STATIC(LogBaseSpawner, All, All)

// Sets default values
ABaseSpawner::ABaseSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABaseSpawner::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ABaseSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

UFUNCTION(BlueprintCallable)
void ABaseSpawner::SpawnTurtle()
{
    UWorld* World = GetWorld();
    if (World)
    {
        FVector SpawnerOrigin;
        FVector SpawnerBoxExtent;
        GetActorBounds(false, SpawnerOrigin, SpawnerBoxExtent);
        UE_LOG(LogBaseSpawner, Display, TEXT("Spawner Bounds: Origin: %f %f %f BoxExtent: %f %f %f"), 
                            SpawnerOrigin.X, SpawnerOrigin.Y, SpawnerOrigin.Z,
                            SpawnerBoxExtent.X, SpawnerBoxExtent.Y, SpawnerBoxExtent.Z);
        FVector TurtleOrigin;
        FVector TurtleBoxExtent;
        GetActorBounds(true, TurtleOrigin, TurtleBoxExtent);
        TurtleOrigin = SpawnerOrigin;
        TurtleOrigin.Z = TurtleBoxExtent.Z * 2;
        TurtleOrigin.X += TurtleBoxExtent.X;
        TurtleOrigin.X += SpawnerBoxExtent.X;

        const FTransform GeometryTransform = FTransform(FRotator::ZeroRotator, TurtleOrigin);
        AMovableTurtle* Geometry = World->SpawnActor<AMovableTurtle>(TurtleClass, GeometryTransform);
        // play sound here

        UE_LOG(LogBaseSpawner, Display, TEXT("Turtle spawned"));
    }
}