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
using namespace VungleSDK;

// The Blank Page item template is documented at http://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x409

MainPage::MainPage()
{
	InitializeComponent();
	sdkInstance = AdFactory::GetInstance("vungleTest");
	sdkInstance->OnAdPlayableChanged += ref new Windows::Foundation::EventHandler<VungleSDK::AdPlayableEventArgs ^>(this, &CPP_sample::MainPage::OnOnAdPlayableChanged);
}

void CPP_sample::MainPage::OnOnAdPlayableChanged(Platform::Object ^sender, VungleSDK::AdPlayableEventArgs ^args)
{
	CoreApplication::MainView->Dispatcher->RunAsync(Windows::UI::Core::CoreDispatcherPriority::Normal,
		ref new Windows::UI::Core::DispatchedHandler(
			[this, args] 
	{
		bool adPlayable = args->AdPlayable;
		this->DefaultConfigButton->IsEnabled = adPlayable;
		this->IncentivizedConfigButton->IsEnabled = adPlayable;
		this->MutedConfigButton->IsEnabled = adPlayable;
	}));
}


void CPP_sample::MainPage::DefaultConfigButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	sdkInstance->PlayAdAsync(ref new AdConfig());
}


void CPP_sample::MainPage::IncentivizedConfigButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	AdConfig^ adConfig = ref new AdConfig();
	adConfig->Incentivized = true;
	sdkInstance->PlayAdAsync(adConfig);
}


void CPP_sample::MainPage::MutedConfigButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	AdConfig^ adConfig = ref new AdConfig();
	adConfig->SoundEnabled = false;
	sdkInstance->PlayAdAsync(adConfig);
}
