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

![Screenshot1](https://cdn.discordapp.com/attachments/1026083841791754250/1275811694571950142/image.png?ex=66c73fbb&is=66c5ee3b&hm=57df8fb0a65dcb22a903bcfa7a771df616c0a2dab0dbcd9f9f5406f9cec5b635&)

### Asset Manager
Don't forget to add your asset to Asset Manager

![Screenshot2](https://cdn.discordapp.com/attachments/1026083841791754250/1275813469916237914/image.png?ex=66c74162&is=66c5efe2&hm=536aa5266804e1f350d8adcd4f0e0870c43e3887146ce1b876d6d11c86821528&)

### Thumbnail renderer
You can select any icon from the project to display. You can also add a short name for the display.

![Screenshot3](https://cdn.discordapp.com/attachments/1026083841791754250/1275813785055268864/image.png?ex=66c741ad&is=66c5f02d&hm=8922c1ed41fb8844a37f99f710bc869429625327096dc84c8b1c2a19661db3c0&)

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
