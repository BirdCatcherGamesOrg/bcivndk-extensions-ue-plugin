// SPDX-License-Identifier: MPL-2.0

#pragma once
#pragma warning(disable: 4584)

#include "AdaptiveMusicPayload.h"
#include "BaseChannel.h"
#include "CoreTypes.h"
#include "UObject/ObjectMacros.h"
#include "Curves/KeyHandle.h"
#include "MovieSceneClipboard.h"
#include "Channels/MovieSceneChannel.h"
#include "Channels/MovieSceneChannelTraits.h"
#include "AdaptiveMusicChannel.generated.h"

/**
 * A AdapativeMusicLines channel of curve data that returns FAdapativeMusicLinesChannelType values
 */
USTRUCT()
struct FBCIVNDKAdapativeMusicMovieSceneChannel
#if CPP
	: public TBCIVNDKMovieSceneBaseChannel<FBCIVNDKAdapativeMusicMovieSceneChannel, FBCIVNDKAdapativeMusicPayload>
#endif
{
	using Super = FMovieSceneChannel;
		
	GENERATED_BODY()
	
	/** Sorted array of key times as frame numbers in the sequence's tick resolution */
	UPROPERTY(meta=(KeyTimes))
	TArray<FFrameNumber> Times;

	/** Array of values that correspond to each key time */
	UPROPERTY(meta=(KeyValues))
	TArray<FBCIVNDKAdapativeMusicPayload> KeyValues;
	
};

/**
 * Movie Scene traits class defining several properties of TBCIMovieSceneChannel.
 * This specialization is only necessary if you want to change the default traits.
 */
template<>
struct TMovieSceneChannelTraits<FBCIVNDKAdapativeMusicMovieSceneChannel> : TMovieSceneChannelTraitsBase<FBCIVNDKAdapativeMusicMovieSceneChannel>
{
	/* This AdapativeMusicLines channel does not have default values */
	enum { SupportsDefaults = false };

#if WITH_EDITOR

	/* This AdapativeMusicLines channel supports retrieving an external value from an object */
	typedef TMovieSceneExternalValue<FBCIVNDKAdapativeMusicPayload> ExtendedEditorDataType;

#endif
};


namespace MovieSceneClipboard
{
	/** Specialization required for clipboard interaction for FMyAdapativeMusicLinesChannelType keys */
	template<> inline FName GetKeyTypeName<FBCIVNDKAdapativeMusicPayload>()
	{
		return "BCIVNDKAdapativeMusicPayload";
	}
}