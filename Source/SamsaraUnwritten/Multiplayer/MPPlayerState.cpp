// Fill out your copyright notice in the Description page of Project Settings.


#include "Multiplayer/MPPlayerState.h"
#include "Net/UnrealNetwork.h"

void AMPPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AMPPlayerState, Gold);
}

void AMPPlayerState::AddGold(int32 Amount)
{
	if (HasAuthority())
	{
		Gold += Amount;
	}
}

bool AMPPlayerState::SpendGold(int32 Amount)
{
	if (HasAuthority() && Gold >= Amount)
	{
		Gold -= Amount;
		return true;
	}
	return false;
}