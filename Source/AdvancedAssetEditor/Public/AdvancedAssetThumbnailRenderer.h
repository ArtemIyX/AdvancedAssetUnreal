// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ThumbnailRendering/ThumbnailRenderer.h"
#include "AdvancedAssetThumbnailRenderer.generated.h"

/**
 * @class UAdvancedAssetThumbnailRenderer
 * @brief A custom thumbnail renderer for UAdvancedDataAsset objects.
 *
 * This class provides the functionality to render thumbnails for instances
 * of the UAdvancedDataAsset class within the Unreal Editor. It extends
 * the base UThumbnailRenderer class, allowing for the customization of
 * how thumbnails are generated and displayed for assets of type 
 * UAdvancedDataAsset.
 *
 * Usage of this class ensures that assets of type UAdvancedDataAsset have
 * visually distinct and representative thumbnails in the editor, enhancing
 * the asset management experience.
 *
 * @see UAdvancedDataAsset
 */
UCLASS()
class ADVANCEDASSETEDITOR_API UAdvancedAssetThumbnailRenderer : public UThumbnailRenderer
{
	GENERATED_BODY()
public:
	virtual bool CanVisualizeAsset(UObject* Object) override;
	virtual void GetThumbnailSize(UObject* Object, float Zoom, uint32& OutWidth, uint32& OutHeight) const override;
	virtual void Draw(UObject* Object, int32 X, int32 Y, uint32 Width, uint32 Height, FRenderTarget* Viewport, FCanvas* Canvas, bool bAdditionalViewFamily) override;
	virtual bool AllowsRealtimeThumbnails(UObject* Object) const override;
};
