// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Ability.h"
#include "Components/BoxComponent.h"
#include "Math/Vector.h"
#include "PhysicalAttack.generated.h"

UCLASS()
class MYPROJECT7_API APhysicalAttack : public AAbility
{
	GENERATED_BODY()
    UBoxComponent hitbox(FObjectInitializer());
};
