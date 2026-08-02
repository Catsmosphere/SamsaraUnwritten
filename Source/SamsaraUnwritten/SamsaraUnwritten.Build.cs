// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class SamsaraUnwritten : ModuleRules
{
	public SamsaraUnwritten(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"SamsaraUnwritten",
			"SamsaraUnwritten/Variant_Platforming",
			"SamsaraUnwritten/Variant_Platforming/Animation",
			"SamsaraUnwritten/Variant_Combat",
			"SamsaraUnwritten/Variant_Combat/AI",
			"SamsaraUnwritten/Variant_Combat/Animation",
			"SamsaraUnwritten/Variant_Combat/Gameplay",
			"SamsaraUnwritten/Variant_Combat/Interfaces",
			"SamsaraUnwritten/Variant_Combat/UI",
			"SamsaraUnwritten/Variant_SideScrolling",
			"SamsaraUnwritten/Variant_SideScrolling/AI",
			"SamsaraUnwritten/Variant_SideScrolling/Gameplay",
			"SamsaraUnwritten/Variant_SideScrolling/Interfaces",
			"SamsaraUnwritten/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
