using System;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
using VungleSDK;
using Windows.ApplicationModel.Core;
using Windows.UI.Core;


namespace CS_sample
{

    public sealed partial class MainPage : Page
    {
        VungleAd sdkInstance;
        bool adPlayable;

        public MainPage()
        {
            sdkInstance = AdFactory.GetInstance("pushokTest");
            sdkInstance.OnAdPlayableChanged += SdkInstance_OnAdPlayableChanged;
            this.InitializeComponent();
        }

        private async void SdkInstance_OnAdPlayableChanged(object sender, AdPlayableEventArgs e)
        {
            adPlayable = e.AdPlayable;
            await CoreApplication.MainView.Dispatcher.RunAsync(CoreDispatcherPriority.Normal,
                new DispatchedHandler(() => ChangeButtonsState()));
        }

        private void ChangeButtonsState()
        {
            DefaultConfigButton.IsEnabled = adPlayable;
            IncentivizedConfigButton.IsEnabled = adPlayable;
            MutedConfigButton.IsEnabled = adPlayable;
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
