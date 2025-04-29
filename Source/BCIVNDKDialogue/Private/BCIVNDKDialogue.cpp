// SPDX-License-Identifier: MPL-2.0

#include "BCIVNDKDialogue.h"

#include "BCIVNDKMovieScene/BCIVNDKMovieScene.h"
#include "EvalTemplate.h"
#include "MovieScene/DialogueChannel.h"
#include "MovieScene/DialogueSection.h"

#define LOCTEXT_NAMESPACE "FBCIVNDKDialogueModule"

void FBCIVNDKDialogueModule::StartupModule()
{
	FBCIVNDKMovieSceneModule* MovieSceneModule = FModuleManager::GetModulePtr<FBCIVNDKMovieSceneModule>("BCIVNDKMovieScene");
	if (MovieSceneModule)
	{
		MovieSceneModule->AddSceneSectionBridge<UBCIVNDKDialogueMovieSceneSection>(&TBCIVNDKMovieSceneSectionTemplateBridge<FBCIVNDKDialogueMovieSceneChannel, FBCIVNDKDialoguePayload>::AddData);
	}
}

#undef LOCTEXT_NAMESPACE
    
IMPLEMENT_MODULE(FBCIVNDKDialogueModule, BCIVNDKDialogue)