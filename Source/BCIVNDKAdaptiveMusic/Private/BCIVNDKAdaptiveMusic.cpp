// SPDX-License-Identifier: MPL-2.0

#include "BCIVNDKAdaptiveMusic.h"

#include "EvalTemplate.h"
#include "BCIVNDKMovieScene/BCIVNDKMovieScene.h"
#include "MovieScene/AdaptiveMusicChannel.h"
#include "MovieScene/AdaptiveMusicSection.h"

#define LOCTEXT_NAMESPACE "FBCIVNDKAdaptiveMusicModule"

void FBCIVNDKAdaptiveMusicModule::StartupModule()
{
	FBCIVNDKMovieSceneModule* MovieSceneModule = FModuleManager::GetModulePtr<FBCIVNDKMovieSceneModule>("BCIVNDKMovieScene");
	if (MovieSceneModule)
	{
		MovieSceneModule->AddSceneSectionBridge<UBCIVNDKAdaptiveMusicMovieSceneSection>(&TBCIVNDKMovieSceneSectionTemplateBridge<FBCIVNDKAdapativeMusicMovieSceneChannel, FBCIVNDKAdapativeMusicPayload>::AddData);
	}
}

#undef LOCTEXT_NAMESPACE
    
IMPLEMENT_MODULE(FBCIVNDKAdaptiveMusicModule, BCIVNDKAdaptiveMusic)