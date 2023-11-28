// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CPP_MyCharacter.generated.h"

UCLASS()
class BATTLEROYAL_API ACPP_MyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACPP_MyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
	void SpawnCampfire();

	UFUNCTION(BlueprintCallable)
	void DeleteNearbyCampfire();

	UFUNCTION(BlueprintCallable)
	void PossessNearbyCharacter();

private:
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = Material,meta	= (AllowPrivateAccess = "true"))
	UMaterialInstanceDynamic* BodyMaterial;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category = Campfire,meta	= (AllowPrivateAccess = "true"))
	UArrowComponent* CampfireSpawnPos;

public:
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Default")
	TSubclassOf<AActor> SpawnToActor;

};
