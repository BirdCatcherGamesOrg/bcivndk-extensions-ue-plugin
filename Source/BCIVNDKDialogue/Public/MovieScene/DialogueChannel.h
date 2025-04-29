// SPDX-License-Identifier: MPL-2.0

#pragma once
#pragma warning(disable: 4584)

#include "BaseChannel.h"
#include "CoreTypes.h"
#include "DialoguePayload.h"
#include "UObject/ObjectMacros.h"
#include "Curves/KeyHandle.h"
#include "MovieSceneClipboard.h"
#include "Channels/MovieSceneChannel.h"
#include "Channels/MovieSceneChannelTraits.h"
#include "DialogueChannel.generated.h"

USTRUCT()
struct FBCIVNDKDialogueMovieSceneChannel
#if CPP
	: public TBCIVNDKMovieSceneBaseChannel<FBCIVNDKDialogueMovieSceneChannel, FBCIVNDKDialoguePayload>
#endif
{
	using Super = FMovieSceneChannel;
		
	GENERATED_BODY()
	
	/** Sorted array of key times as frame numbers in the sequence's tick resolution */
	UPROPERTY(meta=(KeyTimes))
	TArray<FFrameNumber> Times;

	/** Array of values that correspond to each key time */
	UPROPERTY(meta=(KeyValues))
	TArray<FBCIVNDKDialoguePayload> KeyValues;
	
};

/**
 * Movie Scene traits class defining several properties of TBCIMovieSceneChannel.
 * This specialization is only necessary if you want to change the default traits.
 */
template<>
struct TMovieSceneChannelTraits<FBCIVNDKDialogueMovieSceneChannel> : TMovieSceneChannelTraitsBase<FBCIVNDKDialogueMovieSceneChannel>
{
	/* This DialogueLines channel does not have default values */
	enum { SupportsDefaults = false };

#if WITH_EDITOR

	/* This DialogueLines channel supports retrieving an external value from an object */
	typedef TMovieSceneExternalValue<FBCIVNDKDialoguePayload> ExtendedEditorDataType;

#endif
};


namespace MovieSceneClipboard
{
	/** Specialization required for clipboard interaction for FMyDialogueLinesChannelType keys */
	template<> inline FName GetKeyTypeName<FBCIVNDKDialoguePayload>()
	{
		return "BCIVNDKDialoguePayload";
	}
}