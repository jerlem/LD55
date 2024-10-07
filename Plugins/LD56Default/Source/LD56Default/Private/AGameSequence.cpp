// Fill out your copyright notice in the Description page of Project Settings.


#include "AGameSequence.h"


// Sets default values
AAGameSequence::AAGameSequence()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CurrentWaveIndex = 1;
	CurrentWaveStatus = WaveStatus::Idle;
}

/*
 * Picking up 
 */
void AAGameSequence::OnWeaponPicked()
{
	UE_LOG(LogTemp, Log, TEXT("Weapon picked. starting game"));
	CurrentWaveIndex = 1;
	ChangeWaveStatus(WaveStatus::Idle);
}

void AAGameSequence::ChangeWaveStatus(WaveStatus Status)
{
	CurrentWaveStatus = Status;

	// Setting timer for new wave
	if (Status == WaveStatus::Idle)
	{
		UE_LOG(LogTemp, Log, TEXT("Starting timer for Wave"));
		WaveStartTimer = Waves[CurrentWaveIndex].Timer;
		CurrentWave = Waves[CurrentWaveIndex].Data;
	}
	// Wave has started
	else if (Status == WaveStatus::Started)
	{
		UE_LOG(LogTemp, Log, TEXT("Wave has started"));
	}
	// change wave if finished;
	if (Status == WaveStatus::Finished)
	{
		UE_LOG(LogTemp, Log, TEXT("Wave Finished"));
		CurrentWaveIndex++;
		CurrentWaveStatus = WaveStatus::Idle;
	}
}

void AAGameSequence::BeginPlay()
{
	Super::BeginPlay();
}

void AAGameSequence::Tick(float DeltaTime)
{
	// Check for timer to start Wave
	if (WaveStartTimer != -1.0f)
	{
		if (WaveStartTimer > 0.0f)
		{
			WaveStartTimer -= DeltaTime;
		}
		else
		{
			WaveStartTimer = -1.0f;
			ChangeWaveStatus(WaveStatus::Started);
		}
	}
}

