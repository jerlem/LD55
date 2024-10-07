// Copyright Luscious Mustache All Rights Reserved. 2024

#include "NiagaraFallsSubsystem.h"

#include "NiagaraSystem.h"
#include "NiagaraSystemInstance.h"
#include "NiagaraEmitterHandle.h"
#include "NiagaraEmitterInstance.h"

// Function to get the number of particles rendered as meshes
int32 UNiagaraFallsSubsystem::GetMeshRenderedParticleCount(UNiagaraComponent* NiagaraComponent)
{
    if (!NiagaraComponent || !NiagaraComponent->GetAsset())
    {
        return 0;
    }

    int32 MeshParticleCount = 0;
    UNiagaraSystem* NiagaraSystem = NiagaraComponent->GetAsset();

    // Iterate over the emitters in the system
    for (const FNiagaraEmitterHandle& EmitterHandle : NiagaraSystem->GetEmitterHandles())
    {
        if (EmitterHandle.GetIsEnabled())  // Check if the emitter is enabled
        {
            // Get the corresponding emitter instance
            if (NiagaraComponent->GetSystemInstance())
            {
                TArrayView<FNiagaraEmitterInstanceRef, int32> EmitterInstances = NiagaraComponent->GetSystemInstance()->GetEmitters();
                //const TArray<TSharedRef<FNiagaraEmitterInstance>>& EmitterInstances = NiagaraComponent->GetSystemInstance()->GetEmitters();

                for (const TSharedRef<FNiagaraEmitterInstance>& EmitterInstance : EmitterInstances)
                {
                    // Compare by EmitterHandle's ID to ensure we're handling the correct emitter instance
                    if (EmitterInstance->GetEmitterHandle().GetIdName() == EmitterHandle.GetIdName())
                    {
                        // Get the number of particles currently alive for this emitter
                        MeshParticleCount += EmitterInstance->GetNumParticles();
                    }
                }
            }
            
        }
    }

    return MeshParticleCount;
}
