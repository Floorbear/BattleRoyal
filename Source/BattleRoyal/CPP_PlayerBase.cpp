// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_PlayerBase.h"
#include <Camera\CameraComponent.h>
#include <GameFrameWork\SpringArmComponent.h>
#include <GameFramework\CharacterMovementComponent.h>
#include <Kismet\KismetMathLibrary.h>
// Sets default values
ACPP_PlayerBase::ACPP_PlayerBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	


	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SPRINGARM"));
	SpringArm->SetupAttachment(GetRootComponent());

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("CAMERA"));
	Camera->SetupAttachment(SpringArm);

}

// Called when the game starts or when spawned
void ACPP_PlayerBase::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ACPP_PlayerBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACPP_PlayerBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ACPP_PlayerBase::MoveFront(float _Axis)
{
	FRotator ControllerRotator = GetController()->GetControlRotation();
	FRotator DesireRotator = FRotator(0, ControllerRotator.Yaw, 0);


	FVector ForwardVector = UKismetMathLibrary::GetForwardVector(DesireRotator);



	ForwardVector *= _Axis;
	GetCharacterMovement()->AddInputVector(ForwardVector);
}

void ACPP_PlayerBase::MoveRight(float _Axis)
{
	FRotator ControllerRotator = GetController()->GetControlRotation();
	FRotator DesireRotator = FRotator(0, ControllerRotator.Yaw, 0);

	FVector RightVector = UKismetMathLibrary::GetRightVector(DesireRotator);



	RightVector *= _Axis;
	GetCharacterMovement()->AddInputVector(RightVector);
}

