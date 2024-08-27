# Advanced Data Asset Plugin for Unreal Engine 5.3
More advanced and convenient Data Asset based on Primary Data Asset with its own Thumbnail Render
## Description
This asset has a feature in the form of an overridden ID function.
### UAdvancedDataAsset::GetPrimaryAssetId()
The ID is formed as follows: ```FPrimaryAssetId(FPrimaryAssetType(AssetType), AssetId)```
### Asset Type
You can set the asset type directly in the C++ constructor: 
```C++
class YOUR_API UMyAdvancedDataAsset : public UAdvancedDataAsset {
	GENERATED_BODY()
public:
  UMyAdvancedDataAsset();
}
```
```C++
UMyAdvancedDataAsset::UMyAdvancedDataAsset()
{
  AssetType = TEXT("MyAsset");
}
```
### Asset ID
You can set the ID in the asset editor:

![AssetId](https://github.com/user-attachments/assets/536bf481-d701-47b5-ad82-c89ea0583233)

### Asset Manager
Don't forget to add your asset to Asset Manager

![AssetManager](https://github.com/user-attachments/assets/f05e0657-b71e-4995-a240-ebe323d797e7)

### Thumbnail renderer
You can select any icon from the project to display. You can also add a short name for the display.

![UnrealRender](https://github.com/user-attachments/assets/d05ff025-fccc-4cc6-9ce6-40838f48024a)


## Tips
Due to ID-Type you can use the following snippet code to load the data asset directly

```C++
class YOUR_API UMyAssetManager : public UAssetManager
{
	GENERATED_BODY()

public:

	template <class T>
	T* LoadAsset(FName ID)
	{
		if (const UAdvancedDataAsset* Default = Cast<UAdvancedDataAsset>(T::StaticClass()->GetDefaultObject()))
		{
			const FPrimaryAssetId PrimaryAssetId = FPrimaryAssetId(Default->GetType(), ID);
			const FSoftObjectPath path = GetPrimaryAssetPath(PrimaryAssetId);
			if (T* LoadedItem = Cast<T>(path.TryLoad()))
			{
				return LoadedItem;
			}
		}
		return nullptr;
	}
};
```

## Documentation
Doxygen documentation: [GitHubPages](https://artemiyx.github.io/AdvancedAssetUnrealDoc/annotated.html)

Documentation sources: [GitHub](https://github.com/ArtemIyX/AdvancedAssetUnrealDoc)
