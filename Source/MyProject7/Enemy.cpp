// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"

// Sets default values
AEnemy::AEnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    static ConstructorHelpers::FObjectFinder<USoundCue> alertsoundcue(TEXT("SoundCue'/Game/Alert.Alert'"));
    alertnoise = alertsoundcue.Object;
}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{	Super::BeginPlay();
	
}

void AEnemy::takeDamage_Implementation(float damagetaken, FVector damageorigin = FVector(0.0f, 0.0f, 0.0f)){
    hp-= damagetaken;
    GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, "health: " + FString::SanitizeFloat(hp) + ", damage taken: " + FString::SanitizeFloat(damagetaken));
    if (hp <= 0){
        this->Die();
    }
}

void AEnemy::setStatusEffect(FString statuseffect){
    statuseffects.FindOrAdd(statuseffect) += 1;
}

void AEnemy::takeDamageOverTime(float damagetaken, float rate, float duration){ 
    FTimerDelegate damagetimerdelegate;
    FTimerDelegate canceldamagetimerdelegate;
    FTimerHandle damagetimerhandle;
    FTimerHandle canceldamagetimerhandle;
    if (!this){
        return;
    }
    damagetimerdelegate.BindUFunction(this, FName("takeDamage"), damagetaken);
    GetWorld()->GetTimerManager().SetTimer(damagetimerhandle, damagetimerdelegate, (1.0f/rate), true);
    canceldamagetimerdelegate.BindUFunction(this, FName("cancelTakeDamageOverTime"), damagetimerhandle);
    //GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, "argument3: " + damagetimerhandle.ToString());
    //GetWorld()->GetTimerManager().SetTimer(canceldamagetimerhandle, this, AEnemy::takeDamage(damagetaken), duration, true, 0.0f);
    GetWorld()->GetTimerManager().SetTimer(canceldamagetimerhandle, canceldamagetimerdelegate, duration, false);
    //timermanager.SetTimer(canceldamagetimerhandle, , 5.0f, false, 0.0f);
    setStatusEffect("Cursed");
    //GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, "canceled" + FString::FromInt(statuseffects["Cursed"]));
}

void AEnemy::cancelTakeDamageOverTime(FTimerHandle handle){
    //GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, "canceled");
    //GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, "member variable: " + damagetimerhandle.ToString());
    if (statuseffects.Find("Cursed")){
        statuseffects["Cursed"]--;
        if (statuseffects["Cursed"] == 0){
            statuseffects.Remove("Cursed");
        }
    }
    GetWorld()->GetTimerManager().ClearTimer(handle);
}


void AEnemy::Die_Implementation(){
    this->Destroy();
}

void AEnemy::Alert(){
    UGameplayStatics::PlaySound2D(this, alertnoise);
}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    /*(if (statuseffects.Num() != 0){
        TArray<UTexture*> textures1;
        TArray<UTexture*> textures2;
        UMaterialInterface* mat1;
        UMaterialInterface* mat2;
        GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, FString::FromInt(this->enemymesh->GetNumMaterials()));
        mat1 = this->enemymesh->GetMaterial(0);
        mat1->GetUsedTextures(textures1, EMaterialQualityLevel::Medium, false, ERHIFeatureLevel::ES3_1, false);
        for (int i = 0; i < textures1.Num(); i++){
            textures1[i]->AdjustHue = 130.0f;
            textures1[i]->AdjustSaturation = 1.0f;
        }
        mat2 = this->enemymesh->GetMaterial(1);
        mat2->GetUsedTextures(textures2, EMaterialQualityLevel::Medium, false, ERHIFeatureLevel::ES3_1, false);
        for (int i = 0; i < textures2.Num(); i++){
            textures2[i]->AdjustHue = 130.0f;
            textures2[i]->AdjustSaturation = 1.0f;
        }
    }*/
}

// Called to bind functionality to input
void AEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

