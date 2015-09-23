using System;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
using VungleSDK;


namespace CS_sample
{

    public sealed partial class MainPage : Page
    {
        VungleAd sdkInstance;

        public MainPage()
        {
            sdkInstance = AdFactory.GetInstance("pushokTest");
            sdkInstance.OnAdPlayableChanged += SdkInstance_OnAdPlayableChanged;
            this.InitializeComponent();
        }

        private void SdkInstance_OnAdPlayableChanged(object sender, AdPlayableEventArgs e)
        {
            if (e.AdPlayable)
            {
                //ad became playable
            }
            else
            {
                //ad became not playable
            }
        }

        private async void DefaultConfigButton_Click(object sender, RoutedEventArgs e)
        {
            await sdkInstance.PlayAdAsync(new AdConfig());
        }

        private async void IncentivizedConfigButton_Click(object sender, RoutedEventArgs e)
        {
            await sdkInstance.PlayAdAsync(new AdConfig { Incentivized = true });
        }

        private async void MutedConfigButton_Click(object sender, RoutedEventArgs e)
        {
            await sdkInstance.PlayAdAsync(new AdConfig { SoundEnabled = false });
        }
    }
}
