// Fill out your copyright notice in the Description page of Project Settings.


#include "APooledObject.h"


// Sets default values
AAPooledObject::AAPooledObject()
{
	PrimaryActorTick.bCanEverTick = false;

	UE_LOG(LogTemp, Log, TEXT("Init Pool"));
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
	{
		PoolSize = Size;
	}

	for (int i = 0; i < PoolSize; i++) 
	{
		FVector newPosition = FVector(0, i * 100, -1000);
		AActor* SpawnedActor = GetWorld()->SpawnActor<AActor>(ActorClass, newPosition, FRotator().ZeroRotator, SpawnParameters);
		Actors.Add(SpawnedActor);
	}
}

void AAPooledObject::BeginPlay()
{
	Super::BeginPlay();

	Init(ActorType, PoolSize);
}

void AAPooledObject::Next(FVector Position, FRotator Rotation)
{
	HideActor(Index);

	Index++;

	if (Index > PoolSize)
	{
		Index = 0;
	}

	ShowActor(Index, Position, Rotation);
}

void AAPooledObject::HideActor(int Idx)
{
	SetActorShown(Actors[Idx], false);
}

void AAPooledObject::ShowActor(int Idx, FVector Position, FRotator Rotation)
{
	AActor* actor = Actors[Idx];
	actor->SetActorLocation(Position);
	actor->SetActorRotation(Rotation);

	SetActorShown(Actors[Idx], true);
}

void AAPooledObject::SetActorShown(AActor* Act, bool Visible)
{
	Act->SetActorHiddenInGame(Visible);
	Act->SetActorTickEnabled(Visible);
	Act->SetActorEnableCollision(Visible);
}