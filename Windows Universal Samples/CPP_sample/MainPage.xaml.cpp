//
// MainPage.xaml.cpp
// Implementation of the MainPage class.
//

#include "pch.h"
#include "MainPage.xaml.h"

using namespace CPP_sample;

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;
using namespace Windows::ApplicationModel::Core;
//Using VungleSDK namespace
using namespace VungleSDK;


MainPage::MainPage()
{
	InitializeComponent();

	//Obtain Vungle SDK instance
	sdkInstance = AdFactory::GetInstance("vungleTest");

	//Register OnAdPlayableChanged event handler
	sdkInstance->OnAdPlayableChanged += ref new Windows::Foundation::EventHandler<VungleSDK::AdPlayableEventArgs ^>(this, &CPP_sample::MainPage::OnOnAdPlayableChanged);
}

//Event handler for OnAdPlayableChanged event
void CPP_sample::MainPage::OnOnAdPlayableChanged(Platform::Object ^sender, VungleSDK::AdPlayableEventArgs ^args)
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


void CPP_sample::MainPage::DefaultConfigButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	//Play ad with default configuration
	sdkInstance->PlayAdAsync(ref new AdConfig());
}


void CPP_sample::MainPage::IncentivizedConfigButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	//Play ad with enabled 'incentivized' option
	AdConfig^ adConfig = ref new AdConfig();
	adConfig->Incentivized = true;
	sdkInstance->PlayAdAsync(adConfig);
}


void CPP_sample::MainPage::MutedConfigButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	//Play ad without sound
	AdConfig^ adConfig = ref new AdConfig();
	adConfig->SoundEnabled = false;
	sdkInstance->PlayAdAsync(adConfig);
}
