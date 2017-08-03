//
// MainPage.xaml.cpp
// Implementation of the MainPage class.
//

#include "pch.h"
#include "MainPage.xaml.h"
#include "sstream"
#include "iostream"

using namespace CPP_sample;

using namespace Windows::Foundation;
using namespace Windows::UI::Xaml::Navigation;
using namespace Windows::ApplicationModel::Core;

//Using VungleSDK namespace
using namespace VungleSDK;


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

//Event handler for OnInitComleted event
void CPP_sample::MainPage::OnInitCompleted(Platform::Object ^sender, VungleSDK::ConfigEventArgs ^args)
{
	//Run asynchronously on the UI thread
	CoreApplication::MainView->Dispatcher->RunAsync(Windows::UI::Core::CoreDispatcherPriority::Normal,
		ref new Windows::UI::Core::DispatchedHandler(
			[this, args]
	{
		size_t converted;
		std::stringstream placementsInfo;
		placementsInfo << std::endl << "OnInitCompleted: ";
		const wchar_t* wcInitialized = args->Initialized.ToString()->Data();
		char cInitialized[512];
		wcstombs_s(&converted, cInitialized, 512, wcInitialized, 512);
		placementsInfo << cInitialized;

		if (args->Initialized == true)
		{
			for (int i = 0; i < args->Placements->Length; i++)
			{
				placementsInfo << "\n\tPlacement" << (i + 1) << ": ";
				const wchar_t* wcPlacement = args->Placements[i]->ReferenceId->Data();
				char cPlacement[512];
				wcstombs_s(&converted, cPlacement, 512, wcPlacement, 512);
				placementsInfo << cPlacement;

				if (args->Placements[i]->IsAutoCached == true) {
					placementsInfo << " (Auto-Cached)";
				}
			}
		}
		else
		{
			placementsInfo << "\n\t";
			const wchar_t* wcEmessage = args->ErrorMessage->Data();
			char cEmessage[512];
			wcstombs_s(&converted, cEmessage, 512, wcEmessage, 512);
			placementsInfo << cEmessage;
		}
		placementsInfo << std::endl;

		OutputDebugStringA(placementsInfo.str().c_str());

		//Change IsEnabled property for each button
		bool isInitialized = args->Initialized;
		this->LoadPlacement2->IsEnabled = isInitialized;
		this->LoadPlacement3->IsEnabled = isInitialized;
	}));
}

// Event handler called when e->AdPlayable is changed
void CPP_sample::MainPage::OnOnAdPlayableChanged(Platform::Object ^sender, VungleSDK::AdPlayableEventArgs ^args)
{
	//Run asynchronously on the UI thread
	CoreApplication::MainView->Dispatcher->RunAsync(Windows::UI::Core::CoreDispatcherPriority::Normal,
		ref new Windows::UI::Core::DispatchedHandler(
			[this, args] 
	{
		// args->AdPlayable - true if an ad is available to play, false otherwise
		// args->Placement  - placement ID in string

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

		std::stringstream dmess;
		dmess << std::endl <<  "OnAdPlayable: " << placement << " - " << adPlayable << std::endl;
		
		OutputDebugStringA(dmess.str().c_str());
	}));
}

// Event Handler called before playing an ad
void CPP_sample::MainPage::OnAdStart(Platform::Object^ sender, VungleSDK::AdEventArgs^ e) 
{ 
	// e.Id        - Vungle app ID in string
	// e.Placement - placement ID in string
	std::stringstream dmess;
	size_t converted;
	const wchar_t* wcId = e->Id->Data();
	char cId[512];
	wcstombs_s(&converted, cId, 512, wcId, 512);
	const wchar_t* wcPlacement = e->Placement->Data();
	char cPlacement[512];
	wcstombs_s(&converted, cPlacement, 512, wcPlacement, 512);

	dmess << std::endl << "OnAdStart(" << cId << "): " << cPlacement << std::endl;

	OutputDebugStringA(dmess.str().c_str());
}

// DEPRECATED - use SdkInstance_OnAdEnd() instead
void CPP_sample::MainPage::OnVideoView(Platform::Object^ sender, VungleSDK::AdViewEventArgs^ e) { }

// Event handler called when the user leaves ad and control is return to the hosting app
void CPP_sample::MainPage::OnAdEnd(Platform::Object^ sender, VungleSDK::AdEndEventArgs^ e) 
{
	// e->Id                  - Vungle app ID in string
	// e->Placement           - placement ID in string
	// e->IsCompletedView     - true when 80% or more of the video was watched
	// e->CallToActionClicked - true when the user has clicked download button on end card
	// e->WatchedDuration     - duration of video watched
	// e->VideoDuration       - DEPRECATED
	std::stringstream dmess;
	size_t converted;
	const wchar_t* wcId = e->Id->Data();
	char cId[512];
	wcstombs_s(&converted, cId, 512, wcId, 512);

	const wchar_t* wcPlacement = e->Placement->Data();
	char cPlacement[512];
	wcstombs_s(&converted, cPlacement, 512, wcPlacement, 512);

	dmess << std::endl << "OnVideoEnd(" << cId << "): " << "\n\tPlacement: " << cPlacement << "\n\tIsCompletedView: " << e->IsCompletedView;
	dmess << "\n\tCallToActionClicked: " << e->CallToActionClicked << "\n\tWatchedDuration: " << e->WatchedDuration.Duration << std::endl;

	OutputDebugStringA(dmess.str().c_str());
}

// Event handler called when SDK wants to print diagnostic logs
void CPP_sample::MainPage::Diagnostic(Platform::Object^ sender, VungleSDK::DiagnosticLogEvent^ e) 
{ 
	std::stringstream dmess;
	size_t converted;
	const wchar_t* wcLevel = e->Level.ToString()->Data();
	char cLevel[512];
	wcstombs_s(&converted, cLevel, 512, wcLevel, 512);

	const wchar_t* wcType = e->Type.Name->Data();
	char cType[512];
	wcstombs_s(&converted, cType, 512, wcType, 512);

	const wchar_t* wcException = e->Exception.ToString()->Data();
	char cException[512];
	wcstombs_s(&converted, cException, 512, wcException, 512);

	const wchar_t* wcMessage = e->Message->Data();
	char cMessage[512];
	wcstombs_s(&converted, cMessage, 512, wcMessage, 512);

	dmess << std::endl << "Diagnostics: " << cLevel << " " << cType << " " << cException << " " << cMessage;

	OutputDebugStringA(dmess.str().c_str());
}

void CPP_sample::MainPage::InitSDK_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	//Obtain Vungle SDK instance
	Platform::Array<Platform::String^>^ placements = ref new Platform::Array<Platform::String^>(3);
	placements[0] = ref new Platform::String(std::wstring(placement1.begin(), placement1.end()).c_str());
	placements[1] = ref new Platform::String(std::wstring(placement2.begin(), placement2.end()).c_str());
	placements[2] = ref new Platform::String(std::wstring(placement3.begin(), placement3.end()).c_str());
	sdkInstance = AdFactory::GetInstance(ref new Platform::String(std::wstring(appID.begin(), appID.end()).c_str()), placements);

	//Register event handlers
	sdkInstance->OnAdPlayableChanged += ref new EventHandler<VungleSDK::AdPlayableEventArgs ^>(this, &CPP_sample::MainPage::OnOnAdPlayableChanged);
	sdkInstance->OnAdStart += ref new EventHandler<VungleSDK::AdEventArgs ^>(this, &CPP_sample::MainPage::OnAdStart);
	sdkInstance->OnAdEnd += ref new EventHandler<VungleSDK::AdEndEventArgs ^>(this, &CPP_sample::MainPage::OnAdEnd);
	sdkInstance->Diagnostic += ref new EventHandler<VungleSDK::DiagnosticLogEvent ^>(this, &CPP_sample::MainPage::Diagnostic);
	sdkInstance->OnInitCompleted += ref new EventHandler<VungleSDK::ConfigEventArgs ^>(this, &CPP_sample::MainPage::OnInitCompleted);

	this->InitSDK->IsEnabled = false;
}

void CPP_sample::MainPage::LoadPlacement2_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	//Load ad for placement2
	sdkInstance->LoadAd(ref new Platform::String(std::wstring(placement2.begin(), placement2.end()).c_str()));
}

void CPP_sample::MainPage::LoadPlacement3_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	//Load ad for placement3
	sdkInstance->LoadAd(ref new Platform::String(std::wstring(placement3.begin(), placement3.end()).c_str()));
}

void CPP_sample::MainPage::PlayPlacement1_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	//Play ad for placement1
	sdkInstance->PlayAdAsync(ref new AdConfig, ref new Platform::String(std::wstring(placement1.begin(), placement1.end()).c_str()));
}

void CPP_sample::MainPage::PlayPlacement2_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	//Play ad for placement2
	embeddedControl->AppID = ref new Platform::String(std::wstring(appID.begin(), appID.end()).c_str());
	std::string str = placement1 + "," + placement2 + "," + placement3;
	embeddedControl->Placements = ref new Platform::String(std::wstring(str.begin(), str.end()).c_str());
	embeddedControl->Placement = ref new Platform::String(std::wstring(placement2.begin(), placement2.end()).c_str());
	embeddedControl->SoundEnabled = false;

	embeddedControl->OnAdStart += ref new EventHandler<VungleSDK::AdEventArgs ^>(this, &CPP_sample::MainPage::Embedded_OnAdStart);
	embeddedControl->OnAdEnd += ref new EventHandler<VungleSDK::AdEndEventArgs ^>(this, &CPP_sample::MainPage::Embedded_OnAdEnd);
	embeddedControl->PlayAdAsync();
}

void CPP_sample::MainPage::PlayPlacement3_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	//Play ad for placement3
	AdConfig ^adConfig = ref new AdConfig;

	adConfig->IncentivizedDialogBody = "Are you sure you want to skip this ad? You must finish watching to claim your reward.";
	adConfig->IncentivizedDialogCloseButton = "Close";
	adConfig->IncentivizedDialogContinueButton = "Continue";
	adConfig->IncentivizedDialogTitle = "Close this ad?";
	adConfig->UserId = "VungleTest";

	sdkInstance->PlayAdAsync(adConfig, ref new Platform::String(std::wstring(placement3.begin(), placement3.end()).c_str()));
}

// Event Handler called before playing an ad
void CPP_sample::MainPage::Embedded_OnAdStart(Platform::Object^ sender, VungleSDK::AdEventArgs^ e)
{
	CoreApplication::MainView->Dispatcher->RunAsync(Windows::UI::Core::CoreDispatcherPriority::Normal,
		ref new Windows::UI::Core::DispatchedHandler(
			[this, e]
	{
		AnimateHeight(250);
	}));
}

// Event handler called when the user leaves ad and control is return to the hosting app
void CPP_sample::MainPage::Embedded_OnAdEnd(Platform::Object^ sender, VungleSDK::AdEndEventArgs^ e)
{
	CoreApplication::MainView->Dispatcher->RunAsync(Windows::UI::Core::CoreDispatcherPriority::Normal,
		ref new Windows::UI::Core::DispatchedHandler(
			[this, e]
	{
		AnimateHeight(1);
	}));
}

void CPP_sample::MainPage::AnimateHeight(double value)
{
	auto anim = ref new Windows::UI::Xaml::Media::Animation::DoubleAnimation();
	anim->From = embeddedControl->Height;
	anim->To = value;
	anim->EnableDependentAnimation = true;
	auto beginTime = Windows::Foundation::TimeSpan();
	beginTime.Duration = 0;
	auto duration = Windows::Foundation::TimeSpan();
	duration.Duration = 500 * 1000;
	anim->BeginTime = beginTime;
	anim->Duration = duration;

	
	Windows::UI::Xaml::Media::Animation::Storyboard::SetTarget(anim, embeddedControl);
	Windows::UI::Xaml::Media::Animation::Storyboard::SetTargetProperty(anim, "Height");
	Windows::UI::Xaml::Media::Animation::Storyboard::AllowDependentAnimations = true;
	auto storyboard = ref new Windows::UI::Xaml::Media::Animation::Storyboard();
	storyboard->Children->Append(anim);
	storyboard->Begin();
}