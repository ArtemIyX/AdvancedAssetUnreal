// Fill out your copyright notice in the Description page of Project Settings.


// Include the header file for the custom thumbnail renderer class
#include "AdvancedAssetThumbnailRenderer.h"

// Include the necessary Unreal Engine headers
#include "CanvasItem.h"
#include "CanvasTypes.h"
#include "Data/AdvancedDataAsset.h"

// This method checks if the given asset can be visualized (has an icon or a title)
bool UAdvancedAssetThumbnailRenderer::CanVisualizeAsset(UObject* Object)
{
	// Try to cast the object to the custom data asset type
	if (UAdvancedDataAsset* ItemObj = Cast<UAdvancedDataAsset>(Object))
	{
		// Check if the asset has a non-null icon or a non-empty title
		return !ItemObj->DisplayIcon.IsNull() || !ItemObj->DisplayTitle.IsEmpty();
	}
	// Return false if the cast fails or the asset has neither an icon nor a title
	return false;
}

// This method sets the size of the thumbnail to 256x256 pixels
void UAdvancedAssetThumbnailRenderer::GetThumbnailSize(UObject* Object, float Zoom, uint32& OutWidth, uint32& OutHeight) const
{
	// Set the output width and height to 256 pixels each
	OutWidth = 256;
	OutHeight = 256;
}

// This method draws the thumbnail for the given asset
void UAdvancedAssetThumbnailRenderer::Draw(UObject* Object, int32 X, int32 Y, uint32 Width, uint32 Height,
                                           FRenderTarget* Viewport, FCanvas* Canvas, bool bAdditionalViewFamily)
{
    // Try to cast the object to the custom data asset type
    if (UAdvancedDataAsset* item = Cast<UAdvancedDataAsset>(Object)) {
        // If the asset has a non-null icon, draw the icon
        if (!item->DisplayIcon.IsNull()) {
            // Load the icon texture synchronously
            if (UTexture2D* icon = item->DisplayIcon.LoadSynchronous()) {
                // Create a canvas tile item to represent the icon
                FCanvasTileItem CanvasTile(FVector2D(X, Y), icon->GetResource(), FVector2D(Width, Height),
                                           FLinearColor::White);
                // Set the blend mode to masked (transparent areas won't be drawn)
                CanvasTile.BlendMode = SE_BLEND_Masked;
                // Draw the tile on the canvas
                CanvasTile.Draw(Canvas);
            }
        }
        
        // If the asset has a non-empty title, draw the title text
        if (!item->DisplayTitle.IsEmpty()) {
            // Get the title as a string
            const FString tittle = item->DisplayTitle;
            // Convert the title to a TCHAR array (UTF-8 to TCHAR conversion)
            auto vtChars = UTF8_TO_TCHAR(*tittle);

            // Get a reference to the large font from the engine
            UFont* font = GEngine->GetLargeFont();
            int32 vtWidth = 0;
            int32 vtHeight = 0;
        	
            // Calculate the size of the text using the large font
            StringSize(font, vtWidth, vtHeight, vtChars);
            // Calculate padding and scale factors based on the width and height of the thumbnail
            float padding = Height / 128.0f;
            float scaleX = Width / 64.0f;
            float scaleY = Height / 64.0f;
            
            // Create a canvas text item to represent the title
            FCanvasTextItem textItem(FVector2D(0.f, Height - padding - vtHeight * scaleY), FText::FromString(tittle),
                                     GEngine->GetMediumFont(), FLinearColor::White);

            // Enable a black shadow for the text to improve visibility
            textItem.EnableShadow(FLinearColor::Black);
            // Set the scale of the text item
            textItem.Scale = FVector2D(scaleX, scaleY);
            // Draw the text item on the canvas
            textItem.Draw(Canvas);
        }
    }
}

// This method allows the thumbnail renderer to update in real-time
bool UAdvancedAssetThumbnailRenderer::AllowsRealtimeThumbnails(UObject* Object) const
{
	// Return true to allow real-time thumbnail updates
	return true;
}
