// Fill out your copyright notice in the Description page of Project Settings.


#include "AActorSpawner.h"


void AAActorSpawner::SpawnActor(TSubclassOf<AActor> ActorClass, FTransform Transform)
{
	if (!ActorClass)
	{
		UE_LOG(LogTemp, Warning, TEXT("Actor class is null! Cannot spawn."));
		return;
	}

	if (World)
	{
		AActor* SpawnedActor = World->SpawnActor<AActor>(ActorClass, Transform);
		UE_LOG(LogTemp, Log, TEXT("Actor spawned at location: %s"), *Transform.ToString());
	}
}

void AAActorSpawner::SpawnActorsList(TSubclassOf<AActor> ActorClass, TArray<FTransform> Transforms)
{
	for (const FTransform& Tr : Transforms)
	{
		SpawnActor(ActorClass, Tr);
	}
}

// Sets default values
AAActorSpawner::AAActorSpawner()
{
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void AAActorSpawner::BeginPlay()
{
	Super::BeginPlay();
	
	World = GetWorld();

	if (!World) {
		UE_LOG(LogTemp, Error, TEXT("No World found"));
		return;
	}

}