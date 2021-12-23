// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapon.h"
#include "Math/Vector.h"
#include "MeleeWeapon.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT7_API AMeleeWeapon : public AWeapon
{
	GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Test")
    FVector meleehitboxextents = FVector(20.0f, 20.0f, 20.0f);
};
