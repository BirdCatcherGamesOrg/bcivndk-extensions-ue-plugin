using UnrealBuildTool;

public class BCIVNDKAdaptiveMusicEditor : ModuleRules
{
    public BCIVNDKAdaptiveMusicEditor(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "BCIVNDKAdaptiveMusic",
                "Core",
                "MovieScene",
                "MovieSceneTracks",
            }
        );

        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "CoreUObject",
                "Engine",
                "Sequencer",
                "Slate",
                "SlateCore",
            }
        );
    }
}