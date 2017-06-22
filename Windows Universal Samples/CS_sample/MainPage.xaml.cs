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

        private string appID = "591236625b2480ac40000028";
        private string placement1 = "DEFAULT18080";
        private string placement2 = "PLMT02I58745";
        private string placement3 = "PLMT03R02739";

        public MainPage()
        {
            InitializeComponent();

            appIDTextBlock.Text = "AppID: " + appID;
            placement1IDTextBlock.Text = "PlacementID: " + placement1;
            placement2IDTextBlock.Text = "PlacementID: " + placement2;
            placement3IDTextBlock.Text = "PlacementID: " + placement3;
        }

        //Event handler for OnInitComleted event
        private async void SdkInstance_OnInitCompleted(object sender, ConfigEventArgs e)
        {
            await this.Dispatcher.RunAsync(CoreDispatcherPriority.Normal, new DispatchedHandler(() => ChangeLoadButtonsState(e.Initialized)));
        }

        // Event handler called when e.AdPlayable is changed
        private async void SdkInstance_OnAdPlayableChanged(object sender, AdPlayableEventArgs e)
        {
            await this.Dispatcher.RunAsync(CoreDispatcherPriority.Normal, new DispatchedHandler(() => ChangePlayButtonState(e.AdPlayable, e.Placement)));
        }

        // Event Handler called before playing an ad
        private void SdkInstance_OnAdStart(object sender, AdEventArgs e)
        {
            System.Diagnostics.Debug.WriteLine("OnAdStart(Id: " + e.Id + ")");
        }

        // Event handler called each time an ad completes
        private void SdkInstance_OnVideoView(object sender, AdViewEventArgs e)
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
        private void SdkInstance_OnAdEnd(object sender, AdEndEventArgs e)
        {
            // e.CallToActionClicked is true when the user has clicked download button on end card
            System.Diagnostics.Debug.WriteLine("OnAdEnd(Id: " + e.Id + ")" + 
                "\n\tCallToActionClicked: " + e.CallToActionClicked);
        }

        // Event handler called when SDK wants to print diagnostic logs
        private void SdkInstance_Diagnostic(object sender, DiagnosticLogEvent e)
        {
            System.Diagnostics.Debug.WriteLine(e.Level + " " + e.Type + " " + e.Exception + " " + e.Message);
        }

        private void InitSDK_Click(Object sender, RoutedEventArgs e)
        {
            //Obtain Vungle SDK instance
            sdkInstance = AdFactory.GetInstance(appID, new string[] { placement1, placement2, placement3 });

            //Register event handlers
            sdkInstance.OnAdPlayableChanged += SdkInstance_OnAdPlayableChanged;
            sdkInstance.OnAdStart += SdkInstance_OnAdStart;
            sdkInstance.OnVideoView += SdkInstance_OnVideoView;
            sdkInstance.OnAdEnd += SdkInstance_OnAdEnd;
            sdkInstance.Diagnostic += SdkInstance_Diagnostic;
            sdkInstance.OnInitCompleted += SdkInstance_OnInitCompleted;

            InitSDK.IsEnabled = false;
        }

        private void LoadPlacement2_Click(Object sender, RoutedEventArgs e)
        {
            //Load ad for placement2
            sdkInstance.LoadAd(placement2);
        }

        private void LoadPlacement3_Click(Object sender, RoutedEventArgs e)
        {
            //Load ad for placement3
            sdkInstance.LoadAd(placement3);
        }

        private async void PlayPlacement1_Click(Object sender, RoutedEventArgs e)
        {
            //Play ad for placement1
            await sdkInstance.PlayAdAsync(new AdConfig(), placement1);
        }

        private async void PlayPlacement2_Click(Object sender, RoutedEventArgs e)
        {
            //Play ad for placement2
            await sdkInstance.PlayAdAsync(new AdConfig(), placement2);
        }

        private async void PlayPlacement3_Click(Object sender, RoutedEventArgs e)
        {
            //Play ad for placement3
            await sdkInstance.PlayAdAsync(new AdConfig(), placement3);
        }

        private void ChangeLoadButtonsState(bool isInitialized)
        {
            LoadPlacement2.IsEnabled = isInitialized;
            LoadPlacement3.IsEnabled = isInitialized;
        }

        private void ChangePlayButtonState(bool adPlayable, string placement)
        {
            if (placement.Equals(placement1))
            {
                PlayPlacement1.IsEnabled = adPlayable;
            }
            else if (placement.Equals(placement2))
            {
                PlayPlacement2.IsEnabled = adPlayable;
            }
            else if (placement.Equals(placement3))
            {
                PlayPlacement3.IsEnabled = adPlayable;
            }
        }
    }
}
