// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "MPPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class SAMSARAUNWRITTEN_API AMPPlayerState : public APlayerState
{
	GENERATED_BODY()

protected:
	UPROPERTY(Replicated)
	int32 Gold = 0;

public:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UFUNCTION(BlueprintCallable, Category = "Economy")
	void AddGold(int32 Amount);

	UFUNCTION(BlueprintCallable, Category = "Economy")
	bool SpendGold(int32 Amount);

	UFUNCTION(BlueprintPure, Category = "Economy")
	int32 GetGold() const { return Gold; }
};
