// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "AdvancedDataAsset.generated.h"

/**
 * @brief A class representing an advanced data asset, derived from UPrimaryDataAsset.
 * 
 * This class provides additional functionality to manage assets, including an asset type,
 * display icon, and display title. The primary purpose of this class is to extend the 
 * functionality of the standard data asset with extra metadata and a method to retrieve the 
 * primary asset ID.
 */
UCLASS(Blueprintable, BlueprintType)
class ADVANCEDASSET_API UAdvancedDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UAdvancedDataAsset();
protected:
	/** @brief The type of the asset, used to categorize the asset.
	 *
	 * @note Must be set in the constructor, must be unique.
	 */
	UPROPERTY(BlueprintReadOnly)
	FName AssetType;

public:

	/** 
	 * @brief The ID of the asset.
	 * 
	 * This ID is used in conjunction with the asset type to uniquely identify the asset.
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Info")
	FName AssetId;

	/** 
	 * @brief The display icon for the asset.
	 * 
	 * This is a soft object pointer to a texture that represents the icon displayed for this asset.
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Info", meta=(AllowPrivateAccess=true))
	TSoftObjectPtr<UTexture2D> DisplayIcon;

	/** 
	 * @brief The display title for the asset.
	 * 
	 * This string holds the title that is displayed to the developer.
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Info", meta=(AllowPrivateAccess=true))
	FString DisplayTitle;

public:
	/**
	 * @brief Retrieves the primary asset ID for this asset.
	 * 
	 * @return FPrimaryAssetId The primary asset ID, constructed from the asset type and asset ID.
	 */
	virtual FPrimaryAssetId GetPrimaryAssetId() const override;
	
	/**
	 * @brief Gets the asset type associated with this data asset.
	 * 
	 * @return FName The name representing the asset type.
	 */
	UFUNCTION(BlueprintCallable, BlueprintPure)
	FName GetType() const { return AssetType; }
};
