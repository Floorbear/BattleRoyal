// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPP_Campfire.generated.h"

UCLASS()
class BATTLEROYAL_API ACPP_Campfire : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACPP_Campfire();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//UPROPERTY()
	//TObjectPtr<UStaticMeshComponent> WoodMesh;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Object)
	//UStaticMesh* Wood_1;
	//	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Object)
	//UStaticMeshComponent* Wood_2;
	//		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Object)
	//UStaticMeshComponent* Wood_3;
	//			UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Object)
	//UStaticMeshComponent* Wood_4;

	UPROPERTY(VisibleAnywhere	,BlueprintReadOnly)
	USceneComponent* Root;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray< UStaticMeshComponent*> Woods;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UParticleSystemComponent* Fire;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class USphereComponent* Sphere;


};
