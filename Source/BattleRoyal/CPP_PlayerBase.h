// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CPP_PlayerAnimInstance.h"
#include "CPP_PlayerBase.generated.h"

UCLASS()
class BATTLEROYAL_API ACPP_PlayerBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACPP_PlayerBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	UFUNCTION(BlueprintCallable, Category = Movement)
	void MoveFront(float _Axis);

	UFUNCTION(BlueprintCallable, Category = Movement)
	void MoveRight(float _Axis);


private:
	//,Category = Campfire,meta	= (AllowPrivateAccess = "true")
	UPROPERTY(VisibleDefaultsOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* Camera;

	UPROPERTY(VisibleDefaultsOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, Category = Visual , meta = (AllowPrivateAccess = "true"))
	class USkeletalMeshComponent* WeaponBack;

	UPROPERTY(VisibleAnywhere, Category = Visual , meta = (AllowPrivateAccess = "true"))
	class USkeletalMeshComponent* WeaponRight;

	
	// 통신 클래스 
	TWeakObjectPtr<class UCPP_PlayerAnimInstance> PlayerAnimInstance;
};
