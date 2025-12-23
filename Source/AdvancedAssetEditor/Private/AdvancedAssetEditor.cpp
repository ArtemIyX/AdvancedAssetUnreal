#include "AdvancedAssetEditor.h"

#include "AdvancedAssetThumbnailRenderer.h"
#include "Data/AdvancedDataAsset.h"
#include "ThumbnailRendering/ThumbnailManager.h"

#define LOCTEXT_NAMESPACE "FAdvancedAssetEditorModule"

void FAdvancedAssetEditorModule::StartupModule()
{
	if (GIsEditor)
	{
		UThumbnailManager& tm = UThumbnailManager::Get();
		UThumbnailManager::Get().RegisterCustomRenderer(UAdvancedDataAsset::StaticClass(),
			UAdvancedAssetThumbnailRenderer::StaticClass());
	}
}

void FAdvancedAssetEditorModule::ShutdownModule()
{
	if (GIsEditor && FSlateApplication::IsInitialized())
	{
		UThumbnailManager& tm = UThumbnailManager::Get();
		tm.UnregisterCustomRenderer(UAdvancedDataAsset::StaticClass());
	}
	//UThumbnailManager::Get().UnregisterCustomRenderer(UAdvancedDataAsset::StaticClass());
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FAdvancedAssetEditorModule, AdvancedAssetEditor)