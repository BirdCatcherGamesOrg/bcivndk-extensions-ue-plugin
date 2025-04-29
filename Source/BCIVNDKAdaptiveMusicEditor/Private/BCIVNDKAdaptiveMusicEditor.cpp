// SPDX-License-Identifier: MPL-2.0

#include "BCIVNDKAdaptiveMusicEditor.h"

#include "ISequencerModule.h"
#include "SequencerChannelInterface.h"
#include "MovieScene/AdaptiveMusicChannel.h"

#define LOCTEXT_NAMESPACE "FBCIVNDKAdaptiveMusicEditorModule"

void FBCIVNDKAdaptiveMusicEditorModule::StartupModule()
{
	ISequencerModule& SequencerModule = FModuleManager::LoadModuleChecked<ISequencerModule>("Sequencer");
	SequencerModule.RegisterChannelInterface<FBCIVNDKAdapativeMusicMovieSceneChannel>();
}

#undef LOCTEXT_NAMESPACE
    
IMPLEMENT_MODULE(FBCIVNDKAdaptiveMusicEditorModule, BCIVNDKAdaptiveMusicEditor)