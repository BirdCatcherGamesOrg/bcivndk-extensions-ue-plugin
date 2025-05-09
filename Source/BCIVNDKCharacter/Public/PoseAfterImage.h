// SPDX-License-Identifier: MPL-2.0

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "PoseAfterImage.generated.h"

/**
 * @brief UBCIVNDKCharacterPoseAfterImage wraps poseable skeletal meshes and controls fading between them.
 *
 * Use this class to gracefully change a character's pose as a transition effect in the movie scene. This skips needing
 * to fully animate a character's movements in the scene without resorting to camera changes. Custom dissolve materials
 * can be provided, which can, for example, have different characters subtle fade with different thematic colors.
 * e.g. antagonist cross-fades with a hint of red.
 * 
 * The approach is to swap the character's mesh for before and after poseable meshes,
 * dissolve the before mesh, fade in the after, then swap the character's mesh back in.
 * This creates a cross-fade for subtle poses like a head twisting or hand gesture,
 * or big changes like moving to a new place.
 *
 * On the same frame the character's skeletal mesh moves:
 * 1. Take a "snapshot" of the current bone transforms of the character's skeletal mesh BEFORE it moves.
 * 2. Set the character's skeletal mesh to be invisible.
 * 3. Set the CurrentPoseMesh to be visible.
 * 4. Set the opacity of the CurrentPoseMesh's materials to be fully visible.
 * 5. Wait a frame so the character's mesh moves to the new position
 * 6. Set the NextPoseMesh bone transforms to the now updated position of the invisible character's mesh
 * 7. Set the NextPoseMesh to be visible
 * 8. Set the opacity of the NextPoseMesh to be completely invisible
 * 9. Apply an easing function to the opacity of the Current and Next meshes to cross-fade between them
 * 10. When the cross-fade completes, set the Poseable meshes to be invisible, make the character's mesh visible again.
 */
UCLASS(ClassGroup=(Custom), MinimalAPI, meta=(BlueprintSpawnableComponent))
class UBCIVNDKCharacterPoseAfterImage : public USceneComponent
{
	GENERATED_BODY()

public:

	UBCIVNDKCharacterPoseAfterImage();
	
	virtual void OnRegister() override;

	virtual void InitializeComponent() override;
	
	BCIVNDKCHARACTER_API void SetDependencies(class USkeletalMeshComponent& InSkeletalMeshComponent);

	BCIVNDKCHARACTER_API bool CrossFadePoses();

private:
	
	UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
	TObjectPtr<class UPoseableMeshComponent> CurrentPoseMesh;

	UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
	TObjectPtr<class UPoseableMeshComponent> NextPoseMesh;
	
	UPROPERTY(VisibleAnywhere, Transient, meta=(AllowPrivateAccess=true))
	TObjectPtr<class USkeletalMeshComponent> BaseMesh;

	/**
	 * TODO: https://github.com/BirdCatcherGamesOrg/bcivndk-ue-plugin/issues/1
	 */
	
	UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
	FName DissolveParameterName;

	/**
	 * TODO: https://github.com/BirdCatcherGamesOrg/bcivndk-ue-plugin/issues/1
	 */
	
	UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
	float DissolveOverSeconds = 0.0f;

	UPROPERTY(VisibleAnywhere, meta=(AllowPrivateAccess=true))
	float DissolveTime = 0.0f;
	
	UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
	TArray<class UMaterialInstanceDynamic*> CurrentMaterialInstances;


	UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
	TArray<class UMaterialInstanceDynamic*> NextPoseMaterialInstances;
	
	FTSTicker::FDelegateHandle DelegateHandle;
	
	
};
