// Fill out your copyright notice in the Description page of Project Settings.

#include "Core/InteractionComponent.h"
#include "Core/Interactable.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/Controller.h"
#include "Components/PrimitiveComponent.h"
#include "Engine/OverlapResult.h"
#include "Engine/World.h"
#include "CollisionQueryParams.h"

UInteractionComponent::UInteractionComponent()
{
	// the component looks for interactables every frame
	PrimaryComponentTick.bCanEverTick = true;
}

void UInteractionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	UpdateFocus();
}

void UInteractionComponent::UpdateFocus()
{
	const APawn* OwnerPawn = Cast<APawn>(GetOwner());

	// only a possessed pawn can interact
	if (OwnerPawn == nullptr || OwnerPawn->GetController() == nullptr)
	{
		CurrentFocusActor = nullptr;
		return;
	}

	const FVector Origin = OwnerPawn->GetActorLocation();

	FCollisionQueryParams Params;
	Params.AddIgnoredActor(OwnerPawn);

	// find everything around the character, then pick the closest interactable
	TArray<FOverlapResult> Overlaps;
	GetWorld()->OverlapMultiByObjectType(
		Overlaps,
		Origin,
		FQuat::Identity,
		FCollisionObjectQueryParams::AllObjects,
		FCollisionShape::MakeSphere(InteractionRange),
		Params
	);

	AActor* BestActor = nullptr;
	float BestDistance = TNumericLimits<float>::Max();

	for (const FOverlapResult& Overlap : Overlaps)
	{
		AActor* Candidate = Overlap.GetActor();
		if (Candidate == nullptr || !Candidate->Implements<UInteractable>())
		{
			continue;
		}

		// measure to the closest point of the collision, so big objects count from their surface
		float Distance = -1.0f;
		if (const UPrimitiveComponent* Component = Overlap.GetComponent())
		{
			FVector ClosestPoint;
			Distance = Component->GetDistanceToCollision(Origin, ClosestPoint);
		}

		// fall back to the distance between the actors if the component can't measure it
		if (Distance < 0.0f)
		{
			Distance = Candidate->GetDistanceTo(OwnerPawn);
		}

		if (Distance < BestDistance)
		{
			BestDistance = Distance;
			BestActor = Candidate;
		}
	}

	CurrentFocusActor = BestActor;
}

void UInteractionComponent::TryInteract()
{
	if (CurrentFocusActor != nullptr && CurrentFocusActor->Implements<UInteractable>())
	{
		IInteractable::Execute_OnInteract(CurrentFocusActor, GetOwner());
	}
}

FText UInteractionComponent::GetFocusPrompt() const
{
	if (CurrentFocusActor != nullptr && CurrentFocusActor->Implements<UInteractable>())
	{
		return IInteractable::Execute_GetInteractionPrompt(CurrentFocusActor);
	}

	return FText::GetEmpty();
}
