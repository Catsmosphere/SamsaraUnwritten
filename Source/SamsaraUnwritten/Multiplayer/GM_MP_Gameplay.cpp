// Fill out your copyright notice in the Description page of Project Settings.


#include "Multiplayer/GM_MP_Gameplay.h"
#include "SamsaraUnwrittenCharacter.h"
#include "Multiplayer/MPPlayerState.h"

AGM_MP_Gameplay::AGM_MP_Gameplay()
{
    DefaultPawnClass = ASamsaraUnwrittenCharacter::StaticClass();
    PlayerStateClass = AMPPlayerState::StaticClass();
    bUseSeamlessTravel = true;
}
