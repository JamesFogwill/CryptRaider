// Fill out your copyright notice in the Description page of Project Settings.


#include "Mover.h"
#include "MATH/UnrealMathUtility.h"

// Sets default values for this component's properties
UMover::UMover()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMover::BeginPlay()
{
	Super::BeginPlay();

	AActor* PtrOwner = GetOwner();
	FVector PtrOwnerLocation = PtrOwner ->GetActorLocation();
	FString PtrOwnerName = PtrOwner ->GetActorNameOrLabel();
	FString PtrOwnerLocationStr = PtrOwnerLocation.ToCompactString();

	UE_LOG(LogTemp, Display, TEXT("The %s Actor is at location: %s"), *PtrOwnerName, *PtrOwnerLocationStr);
	UE_LOG(LogTemp, Display, TEXT("Mover Owner Address: %u"),PtrOwner); 
	

	StartLocation = PtrOwner -> GetActorLocation();
	
}


// Called every frame
void UMover::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if(Move){

		FVector CurrentLocation = GetOwner() -> GetActorLocation(); // call the getactorlocation function on the owning actor.
		FVector TargetLocation = StartLocation + MoveDistance;
		float Speed = FVector::Distance(StartLocation, TargetLocation) / MoveTime; // speed = d/t using the distance function in the fvector class
		FVector NewLocation = FMath::VInterpConstantTo(CurrentLocation, TargetLocation, DeltaTime, Speed);// interpolates vector to new vector at constant step
		GetOwner() -> SetActorLocation(NewLocation);

	}
}

