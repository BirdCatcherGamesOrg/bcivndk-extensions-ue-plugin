// SPDX-License-Identifier: MPL-2.0

#pragma once

#include "BaseSection.h"
#include "DialogueChannel.h"
#include "MovieSceneSection.h"
#include "DialogueSection.generated.h"

UCLASS(MinimalAPI)
class UBCIVNDKDialogueMovieSceneSection : public UMovieSceneSection, public TBCIVNDKMovieSceneBaseSection<UBCIVNDKDialogueMovieSceneSection, FBCIVNDKDialogueMovieSceneChannel, FBCIVNDKDialoguePayload>
{
	friend TBCIVNDKMovieSceneBaseSection;
	
	GENERATED_BODY()

	UPROPERTY()
	FBCIVNDKDialogueMovieSceneChannel Channel;
	
};
