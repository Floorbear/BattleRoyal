// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_MyCharacter.h"
#include "Kismet\KismetMaterialLibrary.h"
#include "Kismet\KismetSystemLibrary.h"
#include <Components/ArrowComponent.h>
#include "CPP_Campfire.h"
// Sets default values
ACPP_MyCharacter::ACPP_MyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CampfireSpawnPos = CreateDefaultSubobject<UArrowComponent>(TEXT("CampfireSpawnPos"));
	CampfireSpawnPos->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void ACPP_MyCharacter::BeginPlay()
{
	Super::BeginPlay();
	//BodyMaterial = UKismetMaterialLibrary::CreateDynamicMaterialInstance(GetMesh(), GetMesh()->GetMaterial(0));

}

// Called every frame
void ACPP_MyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACPP_MyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ACPP_MyCharacter::SpawnCampfire()
{
	FTransform SpawnTranform = CampfireSpawnPos->GetComponentTransform();
	GetWorld()->SpawnActor<AActor>(SpawnToActor, SpawnTranform);
}

void ACPP_MyCharacter::DeleteNearbyCampfire()
{
	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;
	TArray<AActor*> OutActors;
	TEnumAsByte<EObjectTypeQuery> filter1 = UEngineTypes::ConvertToObjectType(ECC_WorldDynamic);
	ObjectTypes.Add(filter1);
	UKismetSystemLibrary::SphereOverlapActors(GetWorld(), GetActorLocation(), 200.f, ObjectTypes, ACPP_Campfire::StaticClass(), {}, OutActors);

	
	for (AActor * Actor : OutActors)
	{
		if (Cast<ACPP_Campfire>(Actor))
		{
			GetWorld()->DestroyActor(Actor);
		}
	}
}

void ACPP_MyCharacter::PossessNearbyCharacter()
{
	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;
	TArray<AActor*> OutActors;
	TEnumAsByte<EObjectTypeQuery> filter1 = UEngineTypes::ConvertToObjectType(ECC_Pawn);
	ObjectTypes.Add(filter1);

	TArray<AActor*> IgnoreActor;
	IgnoreActor.Add(this);
	UKismetSystemLibrary::SphereOverlapActors(GetWorld(), GetActorLocation(), 100.f, ObjectTypes, StaticClass(),IgnoreActor, OutActors);

	for (AActor* Actor : OutActors)
	{
		if (Cast<ACPP_MyCharacter>(Actor))
		{
			AController* MyController = GetController();
			if (IsValid(MyController))
			{
				MyController->Possess(Cast<APawn>(Actor));
			}
		}
		break;
	}
}

