// SPDX-License-Identifier: MPL-2.0

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FBCIVNDKAdaptiveMusicEditorModule : public IModuleInterface
{
public:
    virtual void StartupModule() override;
};
