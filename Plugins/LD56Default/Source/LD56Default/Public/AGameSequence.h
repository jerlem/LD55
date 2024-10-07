// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AGameSequence.generated.h"

UENUM(BlueprintType)
enum WaveStatus : uint8
{
	Init,
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

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FRotator Rotation;
};

USTRUCT(BlueprintType)
struct FWave
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Timer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<AActor*, FBoid> Data;
};

UCLASS()
class LD56DEFAULT_API AAGameSequence : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAGameSequence();

	UFUNCTION(BlueprintCallable)
	void OnWeaponPicked();

	UFUNCTION(BlueprintCallable)
	void ChangeWaveStatus(WaveStatus Status);

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	float WaveStartTimer = 0.0f;
	int CurrentWaveIndex = 1;

	TMap<AActor*, FBoid> CurrentWave;

	WaveStatus CurrentWaveStatus = WaveStatus::Init;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FWave> Waves;
	
};
