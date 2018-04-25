# Vungle's Windows SDK

## Getting Started
To get up and running with Vungle, you'll need to [Create an Account With Vungle](https://v.vungle.com/dashboard) and [Add an Application to the Vungle Dashboard](https://support.vungle.com/hc/en-us/articles/210468678)

Once you've created an account you can follow our [Getting Started for Windows Guide](https://support.vungle.com/hc/en-us/articles/211339368-Get-started-with-Vungle-Windows-SDK) to complete the integration. Remember to get the Vungle App ID from the Vungle dashboard.

### Requirements
* Visual Studio 2015, Windows 10.0 or later
#### Recommendations
* The latest version of Windows 10 and Visual Studio 2015, because Microsoft would fix bugs in their latest patch.

## Release Notes

### VERSION 6.2.0
* GDPR Compliance
* License updated
* Bug Fixes

### VERSION 5.3.2
* Additional bug fixes

### VERSION 5.1.0
* Launched Native (embedded) ads feature and VungleAdControl XAML control

### VERSION 2.0.8
* Launched new Placements feature

### VERSION 1.3.16
* Fix for ad serving issue on devices with certain language locale
* Fix for stability issue when going from suspended and resume state
* Minor fixes and performance improvements

### VERSION 1.3.15
*	Support Xbox controller in win 8.1 and win 10
*	Support MRAID in Windows 10 Universal platform, Windows 8.1 Phone platform and Windows 8.1
*	Add a warning for a wrong App ID 
*	Fix crash issue when disk full
*	Fix video view buttons layout in win8.1 phone

### VERSION 1.1.6
* Added support for Windows 8.1

### VERSION 1.0.18
* Removed assets from the manifest resources table for passing the WACK tests.

### VERSION 1.0.17
* Initial release

### Integration
NOTE: This document contains examples written in C++ and C#. View code for more examples. Sample apps shows how to integrate the Vungle Windows SDK into an Windows 10 Universal Application or Windows 8.1 Application or Windows Phone 8.1 Application. There are three groups of the samples:  

1. Windows Universal Apps:
  1. CS_sample
  2. CPP_sample
  3. DirectX_XAML_sample
  4. VB_sample
2. Windows 8.1 Apps:
  1. CPP_sample_Windows8.1
  2. CS_sample_Windows8.1
3. Windows Phone 8.1 Apps:
  1. CPP_sample_WP8.1
  2. CS_sample_WP8.1  

Each of the groups uses a special Vungle SDK adjusted for this type of the apps.

- In Visual Studio 2015 create new project using some template (depends on the type of your application and the language
you want to use)
- Download the Vungle Windows SDK
- Add reference for the project to the Windows SDK file that has been downloaded
- Import VungleSDK namespace. For example:
```c#
using VungleSDK;
```
- Obtain a VungleAd instance. For example:
```c#
VungleAd sdkInstance;
...
sdkInstance = AdFactory.GetInstance("vungleTest");
```
- Create event handler for OnAdPlayableChanged event. For example:
```c#
//Event handler for OnAdPlayableChanged event
private async void SdkInstance_OnAdPlayableChanged(object sender, AdPlayableEventArgs e)
{
  //Run asynchronously on the UI thread
  await this.Dispatcher.RunAsync(CoreDispatcherPriority.Normal,
  new DispatchedHandler(() => someMethod()));
}
```
- Register this event handler for OnAdPlayableChanged event. For example:
```c#
sdkInstance.OnAdPlayableChanged += SdkInstance_OnAdPlayableChanged;
```
- Play the ad with the options you prefer. For example:
```c#
private async void CustomConfigButton_Click(object sender, RoutedEventArgs e)
{
  await sdkInstance.PlayAdAsync(new AdConfig { Incentivized = true , SoundEnabled = false});
}
```

NOTE: Make sure that your project has "internetClient" capability in the package.appxmanifest file:
```
<Capabilities>
    ...
    <Capability Name="internetClient" />
    ...
</Capabilities>
```
## License
The Vungle Windows-SDK is available under a commercial license. See the LICENSE.md file for more info.
