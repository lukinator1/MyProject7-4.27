// Fill out your copyright notice in the Description page of Project Settings.


#include "Boolet.h"

// Sets default values
ABoolet::ABoolet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    
    booletcapsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("booletcapsule"));
    booletcapsule->SetCapsuleHalfHeight(0.7f); //1.1f
    booletcapsule->SetCapsuleRadius(0.9f); //4.0f
    booletcapsule->SetNotifyRigidBodyCollision(true);
    //booletcapsule->BodyInstance.bNotifyRigidBodyCollision = true;
    //booletcapsule->SetSimulatePhysics(true);
    booletcapsule->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
    booletcapsule->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Block);
    booletcapsule->SetCollisionResponseToChannel(ECollisionChannel::ECC_GameTraceChannel1, ECollisionResponse::ECR_Ignore);
    //collision response pawn = block
    booletcapsule->SetHiddenInGame(false);
    booletcapsule->SetEnableGravity(false);
    booletcapsule->OnComponentHit.AddDynamic(this, &ABoolet::ABooletHit);
    //booletcapsule->GetComponentTransform().SetRotation(FQuat(0.0f, 90.0f, 0.0f, 1.0f));
    FTransform trans = booletcapsule->GetComponentTransform();
    trans.SetRotation(FQuat(0.0f, 90.0f, 0.0f, 0.0f));
    //trans.SetScale3D(FVector(40.0f , 40.0f, 40.0f));
    //booletcapsule->SetWorldTransform(
    //trans.SetRotation(FQuat(0.0f, 90.0f, 0.0f, 0.0f));
    //FVector thescale = trans.GetScale3D();
    //UE_LOG(LogTemp, Warning, TEXT("Scale: %s"), *thescale.ToString());
    booletcapsule->SetRelativeTransform(trans);
    booletcapsule->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
    
    //projectilemesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("booletmesh"));
    projectilemesh->AttachToComponent(booletcapsule, FAttachmentTransformRules::KeepRelativeTransform);
    static ConstructorHelpers::FObjectFinder<UStaticMesh> boolet(TEXT("/Game/FirstPerson/Meshes/boolet.boolet"));
    projectilemesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    projectilemesh->SetStaticMesh(boolet.Object);
    FTransform transf = FTransform();
    transf.SetScale3D(FVector(0.05f, 0.05f, 0.05f));
    projectilemesh->SetWorldTransform(transf);
    
    //projectilemovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("booletmovement"));
    projectilemovement->SetUpdatedComponent(booletcapsule);
    projectilemovement->MaxSpeed = 35000.0f;
    //booletmovement->InitialSpeed = 100.0f;
    projectilemovement->Velocity = FVector(0.0f, 0.0f, 35000.0f);
    projectilemovement->ProjectileGravityScale = 0.0f;
}

/*void ABoolet::Init(AGun* &gun){
    gunsource = gun;
}*/

void ABoolet::ABooletHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit){
    //GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, "EVENT CALLED");
    FQuat therot = booletcapsule->GetComponentTransform().GetRotation();
    UE_LOG(LogTemp, Warning, TEXT("Scale: %s"), *therot.ToString());
    AEnemy* enemy = Cast<AEnemy>(OtherActor);
    if (enemy != nullptr){
        UE_LOG(LogTemp, Warning, TEXT("Scale: %s"), *therot.ToString());
        FVector vec(GetInstigator()->GetActorLocation());
        enemy->takeDamage(dmg, vec);
        this->Destroy();
    }
    UE_LOG(LogTemp, Warning, TEXT("POIADSPNAP"));
}

// Called when the game starts or when spawned
void ABoolet::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABoolet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

