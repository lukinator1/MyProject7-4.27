// Fill out your copyright notice in the Description page of Project Settings.


#include "Gun.h"

AGun::AGun(){
    static ConstructorHelpers::FObjectFinder<UStaticMesh> gunmeshasset(TEXT("/Game/Weapon_Pack/Mesh/Weapons/Weapons_Kit/SM_Sickle.SM_Sickle"));
    meshcomponent->SetStaticMesh(gunmeshasset.Object);
    equiplocationoffset = FVector(0.0f, 30.0f, -40.0f);
    static ConstructorHelpers::FObjectFinder<UAnimMontage> gunanimationasset(TEXT("AnimMontage'/Game/ParagonRevenant/Characters/Heroes/Revenant/Animations/GunAttack.GunAttack'"));
    weaponanimation = gunanimationasset.Object;
    static ConstructorHelpers::FObjectFinder<USoundWave> gunattacksoundasset(TEXT("SoundWave'/Game/Gunshot.Gunshot'"));
    weaponattacksound = gunattacksoundasset.Object;
    windup = 0.0f;
    cooldown = .375f;
    dmg = 300.0f; 
}
