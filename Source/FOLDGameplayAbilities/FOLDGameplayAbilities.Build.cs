using UnrealBuildTool;

public class FOLDGameplayAbilities : ModuleRules
{
    public FOLDGameplayAbilities(ReadOnlyTargetRules Target) : base(Target)
    {
        //PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                "CoreUObject",
                "Engine",
                "GameplayAbilities",
                "GameplayTasks",
                "GameplayTags",
                "AIModule",
                "NavigationSystem"
            }
        );
    }
}