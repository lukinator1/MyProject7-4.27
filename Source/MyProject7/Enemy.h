// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Sound/SoundCue.h"
#include "Math/Vector.h"
#include "Components/SkeletalMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"
#include "Containers/UnrealString.h"
#include "Containers/Map.h"
#include "Components/BoxComponent.h"
#include "Enemy.generated.h"

UCLASS(Blueprintable)
class MYPROJECT7_API AEnemy : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemy();
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stats")
    float hp;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stats")
    UMaterialInterface* baseenemymaterial;
    //UBoxComponent enemymeleehitbox;
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Stats")
    void takeDamage(float damagetaken, FVector damageorigin = FVector(0.0f, 0.0f, 0.0f));
    virtual void takeDamage_Implementation(float damagetaken, FVector damageorigin);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category="Stats")
    void Attack();
    UFUNCTION(BlueprintCallable, Category="Stats")
    void takeDamageOverTime(float damagetaken, float rate, float duration);
    UFUNCTION(BlueprintCallable, Category="Stats")
    void setStatusEffect(FString statuseffect);
    UFUNCTION(BlueprintCallable, Category="Stats")
    void cancelTakeDamageOverTime(FTimerHandle canceldamagetimerhandle);
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Stats")
    void Die();
    virtual void Die_Implementation();
    UFUNCTION(BlueprintCallable, Category="Stats")
    void Alert();
    TMap<FString, int> statuseffects;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Resources")
    USkeletalMeshComponent *enemymesh;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Resources")
    USoundCue *alertnoise;
    
    
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
