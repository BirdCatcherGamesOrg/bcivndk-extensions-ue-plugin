// SPDX-License-Identifier: MPL-2.0

#include "BCIVNDKDialogueEditor.h"

#include "ISequencerModule.h"
#include "SequencerChannelInterface.h"
#include "MovieScene/DialogueChannel.h"

#define LOCTEXT_NAMESPACE "FBCIVNDKDialogueEditorModule"

void FBCIVNDKDialogueEditorModule::StartupModule()
{
	ISequencerModule& SequencerModule = FModuleManager::LoadModuleChecked<ISequencerModule>("Sequencer");
	SequencerModule.RegisterChannelInterface<FBCIVNDKDialogueMovieSceneChannel>();
}

#undef LOCTEXT_NAMESPACE
    
IMPLEMENT_MODULE(FBCIVNDKDialogueEditorModule, BCIVNDKDialogueEditor)