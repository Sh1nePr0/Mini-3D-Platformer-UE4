// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ActivationTrap.generated.h"


UENUM(BlueprintType)
enum class ETrapStatus : uint8
{
	ETS_Normal	UMETA(DisplayName = "Normal"),
	ETS_Active	UMETA(DisplayName = "Active"),
	ETS_Hit		UMETA(DisplayName = "Hit"),
	ETS_Reload	UMETA(DisplayName = "Reload"),

	ETS_MAX UMETA(DisplayName = "DefaultMAX")
};

UCLASS()
class PROJECTFORTEST_API AActivationTrap : public AActor
{
	GENERATED_BODY()

public:
	/** Overlap volume for functionality to be triggered */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Crossing Start")
	class UBoxComponent* TriggerBox;


	/** Switch for the character to step on */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Crossing Start")
	class UStaticMeshComponent* BlockMesh;

	UPROPERTY(EditAnywhere, Category = "Material")
	class UMaterialInstanceDynamic* Material;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Enums")
	ETrapStatus TrapStatus;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage")
	float Damage;

	FTimerHandle SwitchHandle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Time")
	float DelayTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Time")
	float ReloadTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Time")
	FLinearColor ActiveColor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Time")
	FLinearColor HitColor;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Time")
	bool bCharacterOnSwitch;

	
public:	
	// Sets default values for this actor's properties
	AActivationTrap();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);


	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	FORCEINLINE void SetTrapStatus(ETrapStatus Status) { TrapStatus = Status; }
};
