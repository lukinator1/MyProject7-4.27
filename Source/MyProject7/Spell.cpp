// Fill out your copyright notice in the Description page of Project Settings.


#include "Spell.h"

ASpell::ASpell(){
    static ConstructorHelpers::FObjectFinder<UNiagaraSystem> niagarasystemasset(TEXT("NiagaraSystem'/Game/Blueprints/TeleportNiagara.TeleportNiagara'"));
    spelltimerdelegate.BindUFunction(this, FName("endCooldown"));
    particlesystem = niagarasystemasset.Object;
}

void ASpell::initiateCooldown(){
    GetWorld()->GetTimerManager().SetTimer(spelltimerhandle, spelltimerdelegate, cooldown, false);
    oncooldown = true;
}

void ASpell::endCooldown(){
    oncooldown = false;
}

void ASpell::Cast_Implementation(){
    initiateCooldown();
    GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, "Parent");
}

