// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InteractionComponent.generated.h"

/**
 * Finds the closest IInteractable actor around the owning pawn and lets the pawn interact with it.
 * Add this component to any character (campaign or combat) to give it the interact key behavior.
 */
UCLASS(ClassGroup=(Interaction), meta=(BlueprintSpawnableComponent))
class SAMSARAUNWRITTEN_API UInteractionComponent : public UActorComponent
{
	GENERATED_BODY()

public:

	UInteractionComponent();

	/** Interactables within this distance of the character can be used */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Interaction", meta=(ClampMin=0, ClampMax=2000, Units="cm"))
	float InteractionRange = 300.0f;

	/** The interactable currently in range (the closest one), or null if there is none */
	UPROPERTY(BlueprintReadOnly, Category="Interaction")
	TObjectPtr<AActor> CurrentFocusActor;

	/** Interacts with the focused actor, if there is one. Bind this to the interact key. */
	UFUNCTION(BlueprintCallable, Category="Interaction")
	void TryInteract();

	/** Prompt text of the focused actor, or empty text if nothing is in range. Useful for a "Press E" widget. */
	UFUNCTION(BlueprintPure, Category="Interaction")
	FText GetFocusPrompt() const;

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:

	/** Looks around the owner and updates CurrentFocusActor with the closest interactable */
	void UpdateFocus();
};
