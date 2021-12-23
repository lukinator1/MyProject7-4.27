// Fill out your copyright notice in the Description page of Project Settings.


#include "Channeled_Spell.h"

// Sets default values
AChanneled_Spell::AChanneled_Spell()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AChanneled_Spell::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AChanneled_Spell::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AChanneled_Spell::cancelCast_Implementation(){
    return;
}

