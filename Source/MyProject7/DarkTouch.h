// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Spell.h"
#include "GameFramework/Actor.h"
#include "Enemy.h"
#include "Camera/CameraComponent.h"
#include "Engine/World.h"
#include "Engine/EngineTypes.h"
#include "Math/Vector.h"
#include "Math/Rotator.h"
#include "TimerManager.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"
#include "DarkTouch.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT7_API ADarkTouch : public ASpell
{
	GENERATED_BODY()
    ADarkTouch();
    float dmg = 5.0f;
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stats")
    UCameraComponent* camera;
    UMaterial* darktouchmaterial;
    UFUNCTION(BlueprintCallable, Category="Stats")
    void removeDarkTouchMaterial(AEnemy* enemy, UMaterial* originalenemymaterial);
    void Cast_Implementation();
};
