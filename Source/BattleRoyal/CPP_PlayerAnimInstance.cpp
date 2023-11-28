// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_PlayerAnimInstance.h"
#include <Kismet/KismetMathLibrary.h>

void UCPP_PlayerAnimInstance::SetForwardAxis(float _Axis)
{
	ForwardAxis = _Axis;	
}

void UCPP_PlayerAnimInstance::SetRightAxis(float _Axis)
{
	RightAxis = _Axis;
}

void UCPP_PlayerAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if (ForwardAxis == 0.f && RightAxis != 0)
	{
		ForwardAxis = 1.f;
	}

	float DefaultRightRotation = 40.f;
	RightRotation = DefaultRightRotation * RightAxis * ForwardAxis;

	CurrentRightRotation = UKismetMathLibrary::FInterpTo(CurrentRightRotation, RightRotation, DeltaSeconds, 10.f);
}
