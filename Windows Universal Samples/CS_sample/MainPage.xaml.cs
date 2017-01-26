using System;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
// Using VungleSDK namespace
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
            InitializeComponent();

            // Obtain Vungle SDK instance
            sdkInstance = AdFactory.GetInstance("57ae1919198401ab3100004a");

            // Register event handlers
            sdkInstance.OnAdPlayableChanged += SdkInstance_OnAdPlayableChanged;
            sdkInstance.OnAdStart           += VungleAd_OnAdStart;
            sdkInstance.OnVideoView         += VungleAd_OnVideoView;
            sdkInstance.OnAdEnd             += VungleAd_OnAdEnd;
            sdkInstance.Diagnostic          += VungleAd_Diagnostic;
        }

        // Event handler called when e.AdPlayable is changed
        private async void SdkInstance_OnAdPlayableChanged(object sender, AdPlayableEventArgs e)
        {
            // e.AdPlayble is true when SDK has an ad ready to be played
            // e.AdPlayble is false when there is no ad available to play 
            adPlayable = e.AdPlayable;
            // Run asynchronously on the UI thread
            await this.Dispatcher.RunAsync(CoreDispatcherPriority.Normal,
                new DispatchedHandler(() => ChangeButtonsState()));
        }

        // Event Handler called before plahying an ad
        private void VungleAd_OnAdStart(object sender, AdEventArgs e)
        {
            System.Diagnostics.Debug.WriteLine("OnAdStart(Id: " + e.Id + ")");
        }

        // Event handler called each time an ad completes
        private void VungleAd_OnVideoView(object sender, AdViewEventArgs e)
        {
            // e.IsCompletedView is true when 80% of the video was watched
            // e.VideoDuration is actual time the user watched the video
            // e.VideoDuration is total duration of the video displayed
            System.Diagnostics.Debug.WriteLine("OnVideoView(Id: " + e.Id + ")" +
               "\n\tIsCompletedView: " + e.IsCompletedView +
               "\n\tVideoDuration: " + e.VideoDuration +
               "\n\tWatchedDuration: " + e.WatchedDuration);
        }

        // Event handler called when the user leaves ad and control is return to the hosting app
        private void VungleAd_OnAdEnd(object sender, AdEndEventArgs e)
        {
            // e.CallToActionClicked is true when the user has clicked download button on end card
            System.Diagnostics.Debug.WriteLine("OnAdEnd(Id: " + e.Id + ")" + 
                "\n\tCallToActionClicked: " + e.CallToActionClicked);
        }

        // Event handler called when SDK wants to print diagnostic logs
        private void VungleAd_Diagnostic(object sender, DiagnosticLogEvent e)
        {
            System.Diagnostics.Debug.WriteLine(e.Level + " " + e.Type + " " + e.Exception + " " + e.Message);
        }

        private void ChangeButtonsState()
        {
            // Change IsEnabled property for each button
            DefaultConfigButton.IsEnabled = adPlayable;
            IncentivizedConfigButton.IsEnabled = adPlayable;
            MutedConfigButton.IsEnabled = adPlayable;
        }

        private async void DefaultConfigButton_Click(object sender, RoutedEventArgs e)
        {
            // Play ad with default configuration
            await sdkInstance.PlayAdAsync(new AdConfig());
        }

        private async void IncentivizedConfigButton_Click(object sender, RoutedEventArgs e)
        {
            // Play ad with enabled 'incentivized' option
            // IncentivizedDialog objects are used only when incentivied is set to true
            // Default values are assigned for illustrative purpose for Body, CloseButton, ContinueButton 
            await sdkInstance.PlayAdAsync(new AdConfig
            {
                Incentivized = true,
                UserId = "VungleTestUser",                          // Default: null
                IncentivizedDialogTitle = "Close Incentivized Ad",  // Default: null
                IncentivizedDialogBody = "Are you sure you want to skip this ad? If you do, you might not get your reward",
                IncentivizedDialogCloseButton = "Close",
                IncentivizedDialogContinueButton = "Continue Watching"
            });
        }

        private async void MutedConfigButton_Click(object sender, RoutedEventArgs e)
        {
            // Play ad with sound muted
            await sdkInstance.PlayAdAsync(new AdConfig { SoundEnabled = false });
        }
    }
}
