// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Projectile.h"
#include "NiagaraComponent.h"
#include "DarkTouchProjectile.generated.h"

UCLASS()
class MYPROJECT7_API ADarkTouchProjectile : public AProjectile
{
	GENERATED_BODY()
    UNiagaraSystem* particlesystem;
public:	
	// Sets default values for this actor's properties
	ADarkTouchProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
