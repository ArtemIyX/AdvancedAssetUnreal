#include "AdvancedAssetEditor.h"

#include "AdvancedAssetThumbnailRenderer.h"
#include "Data/AdvancedDataAsset.h"
#include "ThumbnailRendering/ThumbnailManager.h"

#define LOCTEXT_NAMESPACE "FAdvancedAssetEditorModule"

void FAdvancedAssetEditorModule::StartupModule()
{
	UThumbnailManager::Get().RegisterCustomRenderer(UAdvancedDataAsset::StaticClass(),
													UAdvancedAssetThumbnailRenderer::StaticClass());
}

void FAdvancedAssetEditorModule::ShutdownModule()
{
    
}

#undef LOCTEXT_NAMESPACE
    
IMPLEMENT_MODULE(FAdvancedAssetEditorModule, AdvancedAssetEditor)