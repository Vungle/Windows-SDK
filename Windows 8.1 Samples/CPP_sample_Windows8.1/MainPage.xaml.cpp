//
// MainPage.xaml.cpp
// Implementation of the MainPage class.
//

#include "pch.h"
#include "MainPage.xaml.h"

using namespace CPP_sample_Windows8_1;
using namespace Windows::ApplicationModel::Core;
//Using VungleSDK namespace
using namespace VungleSDK;

MainPage::MainPage()
{
	InitializeComponent();

	//Obtain Vungle SDK instance
	sdkInstance = AdFactory::GetInstance("vungleTest");

	//Register OnAdPlayableChanged event handler
	sdkInstance->OnAdPlayableChanged += ref new Windows::Foundation::EventHandler<VungleSDK::AdPlayableEventArgs ^>(this, &CPP_sample_Windows8_1::MainPage::OnOnAdPlayableChanged);
}

//Event handler for OnAdPlayableChanged event
void CPP_sample_Windows8_1::MainPage::OnOnAdPlayableChanged(Platform::Object ^sender, VungleSDK::AdPlayableEventArgs ^args)
{
	//Run asynchronously on the UI thread
	CoreApplication::MainView->Dispatcher->RunAsync(Windows::UI::Core::CoreDispatcherPriority::Normal,
		ref new Windows::UI::Core::DispatchedHandler(
			[this, args]
	{
		//Change IsEnabled property for each button
		bool adPlayable = args->AdPlayable;
		this->DefaultConfigButton->IsEnabled = adPlayable;
		this->IncentivizedConfigButton->IsEnabled = adPlayable;
		this->MutedConfigButton->IsEnabled = adPlayable;
	}));
}


void CPP_sample_Windows8_1::MainPage::DefaultConfigButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	//Play ad with default configuration
	sdkInstance->PlayAdAsync(ref new AdConfig());
}


void CPP_sample_Windows8_1::MainPage::IncentivizedConfigButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	//Play ad with enabled 'incentivized' option
	AdConfig^ adConfig = ref new AdConfig();
	adConfig->Incentivized = true;
	sdkInstance->PlayAdAsync(adConfig);
}


void CPP_sample_Windows8_1::MainPage::MutedConfigButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	//Play ad without sound
	AdConfig^ adConfig = ref new AdConfig();
	adConfig->SoundEnabled = false;
	sdkInstance->PlayAdAsync(adConfig);
}
