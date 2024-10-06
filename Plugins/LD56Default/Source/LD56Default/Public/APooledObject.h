// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "APooledObject.generated.h"

// DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FActorStateChangedDelegate, AActor*, Actor);

UCLASS(Blueprintable, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class LD56DEFAULT_API AAPooledObject : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAPooledObject();

	void Clear();

	void Init(TSubclassOf<AActor> ActorClass, int PoolSize=-1);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ExposeOnSpawn = "true"))
	int PoolSize;

	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> ActorType;

private:	
	UPROPERTY()
	TArray<AActor*> Actors;

	int Index;

	void Next();
	
	void HideActor(int Idx);

	void ShowActor(int Idx, FVector Position = FVector().ZeroVector, FRotator = FRotator().ZeroRotator);
	
	void SetActorVisibility(AActor* Act, bool visible);
};
