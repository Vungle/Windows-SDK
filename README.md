# publisher-sample-windows

## Introduction
These sample apps shows how to integrate the Vungle Windows SDK into an Windows Universal Application or Windows 8.1 Application. Each of the sample apps are written in the different languages but using the same SDK.

## Integration
NOTE: This document contains examples written in C#. View code for more examples. There are six sample apps: C++ sample 
app, C# sample app, Visual Basic sample app and DirectX+XAML sample app - this samples uses standart Vungle Windows SDK; C# Windows 8.1 sample app, C++ Windows 8.1 sample app - this samples uses the special SDK adjusted for Windows 8.1.

- In Visual Studio 2015 create new project using some template (depends on the type of your application and the language
you want to use)
- Download the Windows SDK
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
  await CoreApplication.MainView.Dispatcher.RunAsync(CoreDispatcherPriority.Normal,
  new DispatchedHandler(() => someMethod()));
}
```
- Register this event handler for OnAdPlayableChanged event. For example:
```c#
sdkInstance.OnAdPlayableChanged += SdkInstance_OnAdPlayableChanged;
```
- Play the ad with the options you prefer. For example:
```c#
private async void IncentivizedConfigButton_Click(object sender, RoutedEventArgs e)
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
