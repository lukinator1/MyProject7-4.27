// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../Spell.h"
#include "GameFramework/Actor.h"
#include "Channeled_Spell.generated.h"

UCLASS()
class MYPROJECT7_API AChanneled_Spell : public ASpell
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Stats")
    void cancelCast();
    virtual void cancelCast_Implementation();
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Test")
    float cancelanimationstarttime;
	AChanneled_Spell();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
