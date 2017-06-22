//
// MainPage.xaml.cpp
// Implementation of the MainPage class.
//

#include "pch.h"
#include "MainPage.xaml.h"

using namespace CPP_sample_WP8_1;

using namespace Windows::Foundation;
using namespace Windows::UI::Xaml::Navigation;
using namespace Windows::ApplicationModel::Core;

//Using VungleSDK namespace
using namespace VungleSDK;

std::string appID = "591236625b2480ac40000028";
std::string placement1 = "DEFAULT18080";
std::string placement2 = "PLMT02I58745";
std::string placement3 = "PLMT03R02739";

MainPage::MainPage()
{
	InitializeComponent();

	std::string str;
	str = "AppID: " + appID;
	appIDTextBlock->Text = ref new Platform::String(std::wstring(str.begin(), str.end()).c_str());
	str = "PlacementID: " + placement1;
	placement1IDTextBlock->Text = ref new Platform::String(std::wstring(str.begin(), str.end()).c_str());
	str = "PlacementID: " + placement2;
	placement2IDTextBlock->Text = ref new Platform::String(std::wstring(str.begin(), str.end()).c_str());
	str = "PlacementID: " + placement3;
	placement3IDTextBlock->Text = ref new Platform::String(std::wstring(str.begin(), str.end()).c_str());
}

void CPP_sample_WP8_1::MainPage::OnInitCompleted(Platform::Object ^sender, VungleSDK::ConfigEventArgs ^args)
{
	//Run asynchronously on the UI thread
	this->Dispatcher->RunAsync(Windows::UI::Core::CoreDispatcherPriority::Normal,
		ref new Windows::UI::Core::DispatchedHandler(
			[this, args]
	{
		//Change IsEnabled property for each button
		bool isInitialized = args->Initialized;
		LoadPlacement2->IsEnabled = isInitialized;
		LoadPlacement3->IsEnabled = isInitialized;
	}));
}

//Event handler for OnAdPlayableChanged event
void CPP_sample_WP8_1::MainPage::OnOnAdPlayableChanged(Platform::Object ^sender, VungleSDK::AdPlayableEventArgs ^args)
{
	//Run asynchronously on the UI thread
	this->Dispatcher->RunAsync(Windows::UI::Core::CoreDispatcherPriority::Normal,
		ref new Windows::UI::Core::DispatchedHandler(
			[this, args]
	{
		//Change IsEnabled property for each button
		bool adPlayable = args->AdPlayable;
		const wchar_t* wide_chars = args->Placement->Data();
		char chars[512];
		size_t converted;
		wcstombs_s(&converted, chars, 512, wide_chars, 512);
		std::string placement = chars;
		if (placement.compare(placement1) == 0) {
			this->PlayPlacement1->IsEnabled = adPlayable;
		}
		else if (placement.compare(placement2) == 0) {
			this->PlayPlacement2->IsEnabled = adPlayable;
		}
		else if (placement.compare(placement3) == 0) {
			this->PlayPlacement3->IsEnabled = adPlayable;
		}
	}));
}

//Event handlers
void CPP_sample_WP8_1::MainPage::OnAdStart(Platform::Object^ sender, VungleSDK::AdEventArgs^ e) { }
void CPP_sample_WP8_1::MainPage::OnVideoView(Platform::Object^ sender, VungleSDK::AdViewEventArgs^ e) { }
void CPP_sample_WP8_1::MainPage::OnAdEnd(Platform::Object^ sender, VungleSDK::AdEndEventArgs^ e) { }
void CPP_sample_WP8_1::MainPage::Diagnostic(Platform::Object^ sender, VungleSDK::DiagnosticLogEvent^ e) { }


void CPP_sample_WP8_1::MainPage::InitSDK_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	//Obtain Vungle SDK instance
	Platform::Array<Platform::String^>^ placements = ref new Platform::Array<Platform::String^>(3);
	placements[0] = ref new Platform::String(std::wstring(placement1.begin(), placement1.end()).c_str());
	placements[1] = ref new Platform::String(std::wstring(placement2.begin(), placement2.end()).c_str());
	placements[2] = ref new Platform::String(std::wstring(placement3.begin(), placement3.end()).c_str());
	sdkInstance = AdFactory::GetInstance(ref new Platform::String(std::wstring(appID.begin(), appID.end()).c_str()), placements);

	//Register event handlers
	sdkInstance->OnAdPlayableChanged += ref new EventHandler<VungleSDK::AdPlayableEventArgs ^>(this, &CPP_sample_WP8_1::MainPage::OnOnAdPlayableChanged);
	sdkInstance->OnAdStart += ref new EventHandler<VungleSDK::AdEventArgs ^>(this, &CPP_sample_WP8_1::MainPage::OnAdStart);
	sdkInstance->OnVideoView += ref new EventHandler<VungleSDK::AdViewEventArgs ^>(this, &CPP_sample_WP8_1::MainPage::OnVideoView);
	sdkInstance->OnAdEnd += ref new EventHandler<VungleSDK::AdEndEventArgs ^>(this, &CPP_sample_WP8_1::MainPage::OnAdEnd);
	sdkInstance->Diagnostic += ref new EventHandler<VungleSDK::DiagnosticLogEvent ^>(this, &CPP_sample_WP8_1::MainPage::Diagnostic);
	sdkInstance->OnInitCompleted += ref new EventHandler<VungleSDK::ConfigEventArgs ^>(this, &CPP_sample_WP8_1::MainPage::OnInitCompleted);

	this->InitSDK->IsEnabled = false;
}

void CPP_sample_WP8_1::MainPage::LoadPlacement2_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	//Load ad for placement2
	sdkInstance->LoadAd(ref new Platform::String(std::wstring(placement2.begin(), placement2.end()).c_str()));
}

void CPP_sample_WP8_1::MainPage::LoadPlacement3_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	//Load ad for placement3
	sdkInstance->LoadAd(ref new Platform::String(std::wstring(placement3.begin(), placement3.end()).c_str()));
}

void CPP_sample_WP8_1::MainPage::PlayPlacement1_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	//Play ad for placement1
	sdkInstance->PlayAdAsync(ref new AdConfig, ref new Platform::String(std::wstring(placement1.begin(), placement1.end()).c_str()));
}

void CPP_sample_WP8_1::MainPage::PlayPlacement2_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	//Play ad for placement2
	sdkInstance->PlayAdAsync(ref new AdConfig, ref new Platform::String(std::wstring(placement2.begin(), placement2.end()).c_str()));
}

void CPP_sample_WP8_1::MainPage::PlayPlacement3_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	//Play ad for placement3
	sdkInstance->PlayAdAsync(ref new AdConfig, ref new Platform::String(std::wstring(placement3.begin(), placement3.end()).c_str()));
}


void MainPage::OnNavigatedTo(NavigationEventArgs^ e)
{
	
}


