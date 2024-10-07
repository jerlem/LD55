// Fill out your copyright notice in the Description page of Project Settings.


#include "APooledObject.h"


// Sets default values
AAPooledObject::AAPooledObject()
{
	PrimaryActorTick.bCanEverTick = false;

}

void AAPooledObject::Clear()
{
}

void AAPooledObject::Init(TSubclassOf<AActor> ActorClass, int Size)
{
	FActorSpawnParameters SpawnParameters;
	SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	Index = 0;

	if (Size > 0)
		PoolSize = Size;

	for (int i = 0; i < PoolSize; i++) 
	{
		AActor* SpawnedActor = GetWorld()->SpawnActor<AActor>(ActorClass, FVector().ZeroVector, FRotator().ZeroRotator, SpawnParameters);
		Actors[i] = SpawnedActor;
	}
}

void AAPooledObject::BeginPlay()
{
	Super::BeginPlay();

	Init(ActorType, PoolSize);
	
}

void AAPooledObject::Next()
{
	HideActor(Index);

	Index++;

	if (Index > PoolSize)
	{
		Index = 0;
	}

	ShowActor(Index);
}

void AAPooledObject::HideActor(int Idx)
{
	SetActorVisibility(Actors[Idx], false);
}

void AAPooledObject::ShowActor(int Idx, FVector Position, FRotator Rotation)
{
	AActor* actor = Actors[Idx];
	SetActorVisibility(Actors[Idx], true);

	if (Position != FVector().ZeroVector)
	{
		actor->SetActorLocation(Position);
	}

	if(Rotation != FRotator().ZeroRotator)
	{
		actor->SetActorRotation(Rotation);
	}
}

void AAPooledObject::SetActorVisibility(AActor* Act, bool visible)
{
	Act->SetActorHiddenInGame(visible);
}
