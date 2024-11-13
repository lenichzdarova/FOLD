using UnrealBuildTool;

public class GridNavigation : ModuleRules
{
    public GridNavigation(ReadOnlyTargetRules Target) : base(Target)
    {
        PrivateDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine"});
    }
}