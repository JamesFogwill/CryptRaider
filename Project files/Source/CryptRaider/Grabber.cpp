// Fill out your copyright notice in the Description page of Project Settings.


#include "Grabber.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	
	// ...
	
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	FVector Start;
	FVector End;

	Start = GetComponentLocation();
	
	End = Start + GetForwardVector() * MaxGrabDistance;

	DrawDebugLine(GetWorld(),Start,End,FColor::Red);

	FCollisionShape Sphere = FCollisionShape::MakeSphere(GrabRadius);

	FHitResult BlockingHit;
	bool HasHit = GetWorld()->SweepSingleByChannel(BlockingHit, Start, End,FQuat::Identity,ECC_GameTraceChannel2,Sphere);

	if(HasHit){
		
		AActor* HitActor = BlockingHit.GetActor(); //  getActor returns a pointer to an actor
		// You can use the dereferencing arrow because HitActor is a pointer to an address
		UE_LOG(LogTemp, Display, TEXT("The Hit actor is: %s"), *HitActor->GetActorNameOrLabel()); //  star to display the hit actor because its a string
	}
	// ...
}

