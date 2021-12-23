// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Item.h"
#include "Components/BoxComponent.h"
#include "Engine/StaticMesh.h"
#include "Components/StaticMeshComponent.h"
#include "Animation/AnimMontage.h"
#include "Sound/SoundCue.h"
#include "Components/SceneComponent.h"
#include "Math/Box.h"
#include "Math/Vector.h"
#include "Weapon.generated.h"
/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class MYPROJECT7_API AWeapon : public AItem
{
	GENERATED_BODY()
public:
    //UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Test")
    //FBox boxer;
    //UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Test")
    //UBoxComponent* hitbox;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Test")
    float dmg;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Test")
    UStaticMeshComponent *meshcomponent;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Test")
    FVector equiplocationoffset;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Test")
    UAnimMontage* weaponanimation;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Test")
    USoundWave* weaponattacksound;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Test")
    float windup;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Test")
    float cooldown;
public:
    //UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Test")
    //UStaticMesh *mesh;
    AWeapon(){
        /*hitbox = CreateDefaultSubobject<UBoxComponent>(TEXT("Hitbox"));
        hitbox->SetBoxExtent(FVector(20.0f, 20.0f, 20.0f));
        //SetRootComponent(hitbox);
        hitbox->SetHiddenInGame(false);
        hitbox->SetVisibleFlag(true);
        hitbox->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
        //hitbox->bGenerateOverlapEvents = true;
         
        boxer.ExpandBy(40.0f);*/
        
        meshcomponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("knife"));
        //SetRootComponent(meshcomponent);
        //meshcomponent->SetStaticMesh(mesh);
        meshcomponent->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
        /*static ConstructorHelpers::FObjectFinder<UStaticMesh> weaponMesh(TEXT("/Game/Weapon_Pack/Mesh/Weapons/Weapons_Kit/SM_Dagger_2.SM_Dagger_2"));
            mesh = weaponMesh.Object;*/
        
        dmg = 40.0f;
        windup = .25f;
        cooldown = .5f;
    }
};
