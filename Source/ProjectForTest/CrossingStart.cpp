// Fill out your copyright notice in the Description page of Project Settings.


#include "CrossingStart.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ACrossingStart::ACrossingStart()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerBox"));
	RootComponent = TriggerBox;


	TriggerBox->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	TriggerBox->SetCollisionObjectType(ECollisionChannel::ECC_WorldStatic);
	TriggerBox->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	TriggerBox->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);

	TriggerBox->SetBoxExtent(FVector(404.f , 34.f , 22.f));

	BlockMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CrossingStart"));
	BlockMesh->SetupAttachment(GetRootComponent());

	bCharacterOnSwitch = false;

}

// Called when the game starts or when spawned
void ACrossingStart::BeginPlay()
{
	Super::BeginPlay();

	TriggerBox->OnComponentBeginOverlap.AddDynamic(this, &ACrossingStart::OnOverlapBegin);
	
}

// Called every frame
void ACrossingStart::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void ACrossingStart::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("Overlap Begin."));
	if (!bCharacterOnSwitch)
	{
		bCharacterOnSwitch = true;
	}
}

