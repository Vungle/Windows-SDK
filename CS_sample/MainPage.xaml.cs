using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using Windows.Foundation;
using Windows.Foundation.Collections;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Controls.Primitives;
using Windows.UI.Xaml.Data;
using Windows.UI.Xaml.Input;
using Windows.UI.Xaml.Media;
using Windows.UI.Xaml.Navigation;
using VungleSDK;

// The Blank Page item template is documented at http://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x409

namespace CS_sample
{
    /// <summary>
    /// An empty page that can be used on its own or navigated to within a Frame.
    /// </summary>
    public sealed partial class MainPage : Page
    {
        vungleSDK sdk;
        AdConfig cfg;
        public MainPage()
        {
            this.InitializeComponent();
            cfg = new AdConfig();
            
        }

        private async void Sdk_OnAdPlayableChanged(object sender, AdPlayableEventArgs e)
        {
            await Windows.ApplicationModel.Core.CoreApplication.MainView.Dispatcher.RunAsync(Windows.UI.Core.CoreDispatcherPriority.Normal, () =>
            {
                play.IsEnabled = e.AdPlayable;
            });
        }

        private void start_Tapped(object sender, TappedRoutedEventArgs e)
        {
            if (sdk != null)
                return;
            start.IsEnabled = false;
            sdk = vungleSDK.VungleSDK("vungleTest");
            sdk.OnAdPlayableChanged += Sdk_OnAdPlayableChanged;
        }

        private async void play_Tapped(object sender, TappedRoutedEventArgs e)
        {
            if (sdk.AdPlayable)
            {
                await sdk.PlayAdAsync(cfg);
            }
        }
    }
}
