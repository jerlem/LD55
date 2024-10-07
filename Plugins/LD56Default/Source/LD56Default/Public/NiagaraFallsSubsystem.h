// Copyright Luscious Mustache All Rights Reserved. 2024

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "NiagaraComponent.h"
#include "NiagaraFallsSubsystem.generated.h"

// Forward declaration of Niagara system and component
//class UNiagaraSystem;
//class UNiagaraComponent;

UCLASS()
class LD56DEFAULT_API UNiagaraFallsSubsystem : public UGameInstanceSubsystem
{
    GENERATED_BODY()

public:
    // Function to get the number of particles rendered as meshes in a given Niagara system
    UFUNCTION(BlueprintCallable, Category = "Niagara")
    int32 GetMeshRenderedParticleCount(UNiagaraComponent* NiagaraComponent);
};

