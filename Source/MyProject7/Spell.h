// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Ability.h"
#include "TimerManager.h"
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
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Test")
    bool oncooldown;
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Stats")
    void Cast();
    virtual void Cast_Implementation();
    //UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Test")
    FTimerDelegate spelltimerdelegate;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Test")
    FTimerHandle spelltimerhandle;
    UFUNCTION(BlueprintCallable, Category="Stats")
    void initiateCooldown();
    UFUNCTION(BlueprintCallable, Category="Stats")
    void endCooldown();
    
private:
	GENERATED_BODY()
    
};
