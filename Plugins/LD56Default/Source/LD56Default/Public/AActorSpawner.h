// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AActorSpawner.generated.h"

UCLASS()
class LD56DEFAULT_API AAActorSpawner : public AActor
{
	GENERATED_BODY()
	
public:	

	UFUNCTION(BlueprintCallable, Category = "Spawner")
	void SpawnActor(TSubclassOf<AActor> ActorClass, FTransform transform);

	UFUNCTION(BlueprintCallable, Category = "Spawner")
	void SpawnActorsList(TSubclassOf<AActor> ActorClass, TArray<FTransform> transform);


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	FTimerHandle SpawnTimer;
	UWorld* World;

	
	
};
