// Fill out your copyright notice in the Description page of Project Settings.
using System.IO;
using UnrealBuildTool;

public class FalloutOld : ModuleRules
{
	public FalloutOld(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"UMG",
			"AIModule",
			"GridNavigation",
			"NavigationSystem",
			"GameplayTags",
			"OnlineSubsystem",
			"OnlineSubsystemUtils", 
			"GameplayAbilities",
			"GameplayTasks",
			"FOLDGameplayAbilities"
		});
        
		// Добавляем папки, где лежат заголовочные файлы
		PublicIncludePaths.Add(ModuleDirectory);  // Корень модуля
		PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "Core"));
		PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "GameplayActors"));
		PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "SaveGame"));
		PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "UI"));
        
		// Если заголовки используются только в приватных файлах (.cpp)
		// PrivateIncludePaths.Add(Path.Combine(ModuleDirectory, "PrivateSubfolder"));
	}
}
