using System;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
//using VungleSDK namespace
using VungleSDK;
using Windows.ApplicationModel.Core;
using Windows.UI.Core;

namespace CS_sample_Windows8._1
{
    public sealed partial class MainPage : Page
    {

        VungleAd sdkInstance;
        bool adPlayable;

        public MainPage()
        {
            this.InitializeComponent();

            //Obtain Vungle SDK instance
            sdkInstance = AdFactory.GetInstance("vungleTest");

            //Register OnAdPlayableChanged event handler
            sdkInstance.OnAdPlayableChanged += SdkInstance_OnAdPlayableChanged;
        }

        //Event handler for OnAdPlayableChanged event
        private async void SdkInstance_OnAdPlayableChanged(object sender, AdPlayableEventArgs e)
        {
            adPlayable = e.AdPlayable;
            //Run asynchronously on the UI thread
            await this.Dispatcher.RunAsync(CoreDispatcherPriority.Normal,
                new DispatchedHandler(() => ChangeButtonsState()));
        }

        private void ChangeButtonsState()
        {
            //Change IsEnabled property for each button
            DefaultConfigButton.IsEnabled = adPlayable;
            IncentivizedConfigButton.IsEnabled = adPlayable;
            MutedConfigButton.IsEnabled = adPlayable;
        }

        private async void DefaultConfigButton_Click(object sender, RoutedEventArgs e)
        {
            //Play ad with default configuration
            await sdkInstance.PlayAdAsync(new AdConfig());
        }

        private async void IncentivizedConfigButton_Click(object sender, RoutedEventArgs e)
        {
            //Play ad with enabled 'incentivized' option
            await sdkInstance.PlayAdAsync(new AdConfig { Incentivized = true });
        }

        private async void MutedConfigButton_Click(object sender, RoutedEventArgs e)
        {
            //Play ad without sound
            await sdkInstance.PlayAdAsync(new AdConfig { SoundEnabled = false });
        }
    }
}
