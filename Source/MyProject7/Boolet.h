// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Math/Vector.h"
#include "Gun.h"
#include "Enemy.h"
#include "Projectile.h"
#include "Engine/EngineTypes.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Math/TransformNonVectorized.h"
#include "Math/Rotator.h"
#include "Math/Quat.h"
#include "Boolet.generated.h"

UCLASS()
class MYPROJECT7_API ABoolet : public AProjectile
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABoolet();
    //UFUNCTION(BlueprintCallable, Category="Stats")
    //void Init(AGun* &gun);
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Test")
    float dmg = 20.0f;
    //AGun *gunsource;
    UCapsuleComponent *booletcapsule;
    
private:
    UFUNCTION()
    void ABooletHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
