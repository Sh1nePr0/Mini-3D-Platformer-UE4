// Fill out your copyright notice in the Description page of Project Settings.


#include "CrossingFinish.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ACrossingFinish::ACrossingFinish()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	PrimaryActorTick.bCanEverTick = true;

	TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerBox"));
	RootComponent = TriggerBox;


	TriggerBox->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	TriggerBox->SetCollisionObjectType(ECollisionChannel::ECC_WorldStatic);
	TriggerBox->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	TriggerBox->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);

	TriggerBox->SetBoxExtent(FVector(404.f, 34.f, 22.f));

	BlockMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CrossingStart"));
	BlockMesh->SetupAttachment(GetRootComponent());

	bCharacterOnSwitch = false;

}

// Called when the game starts or when spawned
void ACrossingFinish::BeginPlay()
{
	Super::BeginPlay();

	
}

// Called every frame
void ACrossingFinish::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}




