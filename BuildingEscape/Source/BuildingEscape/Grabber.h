// Mateusz Kochanek BuildingEscape Game

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Runtime/Engine/Classes/GameFramework/PlayerController.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"
#include "DrawDebugHelpers.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "Runtime/Engine/Classes/Engine/EngineTypes.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Runtime/Engine/Classes/Components/InputComponent.h"

#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
		float Reach = 100.f;
		
		UPhysicsHandleComponent* PhysicsHandle = nullptr;
		UInputComponent* InputComponent = nullptr;

		//RAy-cast and grav whats in reach
		void Grab();
		//realease what was grabbed
		void Release();
		//Find attached physics component
		void FindPhysicsHandleComponent();
		//Setup (assumed) attached InputComponent
		void SetupInputComponent();
		//Return hit for first physics body in reach
		const FHitResult GetFirstPhysicsBodyInReach();
		//returns current start of reach line
		FVector GetReachLineStart();
		//returns current end of reach line
		FVector GetReachLineEnd();
};
