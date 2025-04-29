// SPDX-License-Identifier: MPL-2.0

#pragma once

#include "BaseSection.h"
#include "AdaptiveMusicChannel.h"
#include "MovieSceneSection.h"
#include "AdaptiveMusicSection.generated.h"

UCLASS(MinimalAPI)
class UBCIVNDKAdaptiveMusicMovieSceneSection : public UMovieSceneSection, public TBCIVNDKMovieSceneBaseSection<UBCIVNDKAdaptiveMusicMovieSceneSection, FBCIVNDKAdapativeMusicMovieSceneChannel, FBCIVNDKAdapativeMusicPayload>
{
	friend TBCIVNDKMovieSceneBaseSection;
	
	GENERATED_BODY()

	UPROPERTY()
	FBCIVNDKAdapativeMusicMovieSceneChannel Channel;
	
};
