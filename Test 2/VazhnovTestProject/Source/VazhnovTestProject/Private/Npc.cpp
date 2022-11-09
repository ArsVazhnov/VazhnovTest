// Fill out your copyright notice in the Description page of Project Settings.

#include "Npc.h"
#include "AIController.h"
#include "NpcData.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"

// Sets default values
ANpc::ANpc()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ANpc::BeginPlay()
{
	Super::BeginPlay();
	NpcDataSetup();
	NpcAISetup();
}

// Sets Npc's data using Data Asset
void ANpc::NpcDataSetup() const
{
	GetMesh()->SetSkeletalMesh(NpcData->NpcMesh);
	GetMesh()->SetAnimInstanceClass(NpcData->NpcAnimBP);
}

// Sets Npc's Behavior Tree Blackboard values
void ANpc::NpcAISetup()
{
	UAIBlueprintHelperLibrary::GetAIController(this)->GetBlackboardComponent()->SetValueAsVector("StartLocation", NpcStartLocation);
	UAIBlueprintHelperLibrary::GetAIController(this)->GetBlackboardComponent()->SetValueAsVector("DestinationLocation", NpcDestinationLocation);
}

// Called every frame
void ANpc::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ANpc::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}