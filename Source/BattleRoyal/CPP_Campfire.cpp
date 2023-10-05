// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_Campfire.h"

// Sets default values
ACPP_Campfire::ACPP_Campfire()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//static ConstructorHelpers::FObjectFinder<UStaticMesh

	//WoodMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WoodMeshh"));
	//WoodMesh->SetStaticMesh(Wood_1);

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	Wood_12 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Wood_11"));
	Wood_12->SetupAttachment(Root);

}

// Called when the game starts or when spawned
void ACPP_Campfire::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPP_Campfire::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



