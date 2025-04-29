// SPDX-License-Identifier: MPL-2.0

#pragma once

#include "CoreMinimal.h"
#include "AdaptiveMusicPayload.generated.h"

USTRUCT()
struct FBCIVNDKAdapativeMusicPayload
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, meta=(AllowedClasses="/Script/Script.PresentationSceneAsset"))
	FPrimaryAssetId SceneAsset;

		/*
	UPROPERTY(EditAnywhere, meta = (RowType = "/Script/Script.PresentationScriptTableRow"))
	TArray<FDataTableRowHandle> AdapativeMusicLines;
*/
#if WITH_EDITORONLY_DATA
	/**
	 * CachedSerializedData is a copy of the data at the time of creating the keyframe.
	 * Helpful for being resilient if the script data is going out of sync.
	 */
	UPROPERTY(VisibleAnywhere)
	TArray<FString> CachedSerializedData;
#endif WITH_EDITORONLY_DATA
};

inline bool operator==(const FBCIVNDKAdapativeMusicPayload& A, const FBCIVNDKAdapativeMusicPayload& B) { return false; }
inline bool operator<(const FBCIVNDKAdapativeMusicPayload& A, const FBCIVNDKAdapativeMusicPayload& B) { return false; }
