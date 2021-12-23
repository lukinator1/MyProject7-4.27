// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Ability.h"
#include "GameFramework/Character.h"
#include "Animation/AnimMontage.h"
#include "Sound/SoundCue.h"
#include "NiagaraComponent.h"
#include "Spell.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT7_API ASpell : public AAbility
{
public:
    ASpell();
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stats")
    UNiagaraSystem* particlesystem;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Test")
    UAnimMontage* spellanimation;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Test")
    USoundWave* spellcastsound;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Test")
    ACharacter* caster;
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Stats")
    void Cast();
    virtual void Cast_Implementation();
    
private:
	GENERATED_BODY()
    
};
