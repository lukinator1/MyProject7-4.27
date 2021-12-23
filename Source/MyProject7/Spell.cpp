// Fill out your copyright notice in the Description page of Project Settings.


#include "Spell.h"

ASpell::ASpell(){
    static ConstructorHelpers::FObjectFinder<UNiagaraSystem> niagarasystemasset(TEXT("NiagaraSystem'/Game/Blueprints/TeleportNiagara.TeleportNiagara'"));
    particlesystem = niagarasystemasset.Object;
}

void ASpell::Cast_Implementation(){
    //GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, "Parent");
}

