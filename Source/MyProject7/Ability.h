// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Ability.generated.h"


UCLASS( Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MYPROJECT7_API AAbility : public AActor
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
    AAbility();
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Test")
    float windup = 0.5f;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Test")
    float cooldown = 1.0f;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Test")
    int type = -1;
    //UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Test")
    //UAnimMontage* animation;
    //*UCharacter playercharacter;
		
};
