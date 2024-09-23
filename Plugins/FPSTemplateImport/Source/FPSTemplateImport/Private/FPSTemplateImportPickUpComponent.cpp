// Copyright Epic Games, Inc. All Rights Reserved.

#include "FPSTemplateImportPickUpComponent.h"

UFPSTemplateImportPickUpComponent::UFPSTemplateImportPickUpComponent()
{
	// Setup the Sphere Collision
	SphereRadius = 32.f;
}

void UFPSTemplateImportPickUpComponent::BeginPlay()
{
	Super::BeginPlay();

	// Register our Overlap Event
	OnComponentBeginOverlap.AddDynamic(this, &UFPSTemplateImportPickUpComponent::OnSphereBeginOverlap);
}

void UFPSTemplateImportPickUpComponent::OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// Checking if it is a First Person Character overlapping
	AFPSTemplateImportCharacter* Character = Cast<AFPSTemplateImportCharacter>(OtherActor);
	if(Character != nullptr)
	{
		// Notify that the actor is being picked up
		OnPickUp.Broadcast(Character);

		// Unregister from the Overlap Event so it is no longer triggered
		OnComponentBeginOverlap.RemoveAll(this);
	}
}
