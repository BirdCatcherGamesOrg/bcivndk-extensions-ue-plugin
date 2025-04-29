// SPDX-License-Identifier: MPL-2.0

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FBCIVNDKAdaptiveMusicModule : public IModuleInterface
{
public:
    virtual void StartupModule() override;
};
