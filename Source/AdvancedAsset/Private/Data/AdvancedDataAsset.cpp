// Fill out your copyright notice in the Description page of Project Settings.


#include "Data/AdvancedDataAsset.h"

UAdvancedDataAsset::UAdvancedDataAsset()
{
	AssetType = TEXT("Enter your own asset id");
}

FPrimaryAssetId UAdvancedDataAsset::GetPrimaryAssetId() const
{
	return FPrimaryAssetId(FPrimaryAssetType(AssetType), AssetId);
}
