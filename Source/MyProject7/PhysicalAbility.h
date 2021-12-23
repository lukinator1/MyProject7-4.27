// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "Ability.h"
#include "Components/BoxComponent.h"
#include "PhysicalAbility.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT7_API APhysicalAbility : public AAbility
{
	GENERATED_BODY()
    UBoxComponent hitbox(FObjectInitializer());
    //UPhysicalAbility();
};
