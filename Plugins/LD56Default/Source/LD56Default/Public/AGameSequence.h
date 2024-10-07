// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AGameSequence.generated.h"

UENUM(BlueprintType)
enum WaveStatus : uint8
{
	Idle,
	Started,
	Finished
};

USTRUCT(BlueprintType)
struct FBoid
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int BoidInitialSize;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector Position;
};


USTRUCT(BlueprintType)
struct FWave
{
	GENERATED_BODY();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<AActor*, FBoid> MapBoid;
};

//USTRUCT(BlueprintType)
//struct FWave
//{
//	GENERATED_BODY()
//
//	UPROPERTY(EditAnywhere, BlueprintReadWrite)
//	float Timer;
//
//	TMap<AActor*, FBoid> Boid;
//
//	FWave(float timer, TMap<AActor*, FBoid> boid)
//	{
//		Timer = timer;
//		Boid = boid;
//	}
//};

UCLASS()
class LD56DEFAULT_API AAGameSequence : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAGameSequence();

	//<FWave> Waves;
	FWave Wave1;
	FWave Wave2;
	FWave Wave3;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	// virtual void Tick(float DeltaTime) override;

	
	
};
