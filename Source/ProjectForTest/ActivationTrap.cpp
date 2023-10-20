// Fill out your copyright notice in the Description page of Project Settings.


#include "ActivationTrap.h"
#include "Main.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "TimerManager.h"
#include "Materials/MaterialInstanceDynamic.h"

// Sets default values
AActivationTrap::AActivationTrap()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerBox"));
	RootComponent = TriggerBox;


	TriggerBox->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	TriggerBox->SetCollisionObjectType(ECollisionChannel::ECC_WorldStatic);
	TriggerBox->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	TriggerBox->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);

	TriggerBox->SetBoxExtent(FVector(399.f, 404.f, 21.13f));

	BlockMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ActivationTrap"));
	BlockMesh->SetupAttachment(GetRootComponent());

	Material = UMaterialInstanceDynamic::Create(BlockMesh->GetMaterial(0), NULL);

	Damage = 15.f;
	DelayTime = 1.f;
	ReloadTime = 5.f;
	
	bCharacterOnSwitch = false;

	ActiveColor = {255.f , 69.f, 0.f };
	HitColor = {255.f ,0.f ,0.f};

	
	TrapStatus = ETrapStatus::ETS_Normal;

}

// Called when the game starts or when spawned
void AActivationTrap::BeginPlay()
{
	Super::BeginPlay();

	TriggerBox->OnComponentBeginOverlap.AddDynamic(this, &AActivationTrap::OnOverlapBegin);
	TriggerBox->OnComponentEndOverlap.AddDynamic(this, &AActivationTrap::OnOverlapEnd);
	
}

// Called every frame
void AActivationTrap::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void AActivationTrap::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("Overlap Begin."));
	if (!bCharacterOnSwitch)
	{
		bCharacterOnSwitch = true;
	}
}


void  AActivationTrap::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	UE_LOG(LogTemp, Warning, TEXT("Overlap End."));
	if (bCharacterOnSwitch)
	{
		bCharacterOnSwitch = false;
	}
}





