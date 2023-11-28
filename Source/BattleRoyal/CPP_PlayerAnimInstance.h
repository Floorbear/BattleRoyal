// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "CPP_PlayerAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class BATTLEROYAL_API UCPP_PlayerAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
public:
	void SetForwardAxis(float _Axis);
	void SetRightAxis(float _Axis);



protected:

	void NativeUpdateAnimation(float DeltaSeconds) override;

private:
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = "Movement",meta = (AllowPrivateAccess = "true"))
	float ForwardAxis;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = "Movement",meta = (AllowPrivateAccess = "true"))
	float RightAxis;


	float RightRotation = 0.f;
	UPROPERTY(VisibleDefaultsOnly,BlueprintReadOnly,Category = "Movement", meta = (AllowPrivateAccess = "true"))
	float CurrentRightRotation;
};
