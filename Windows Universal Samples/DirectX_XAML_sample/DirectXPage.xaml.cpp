//
// DirectXPage.xaml.cpp
// Implementation of the DirectXPage class.
//

#include "pch.h"
#include "DirectXPage.xaml.h"
#include "sstream"
#include "iostream"

using namespace DirectX_XAML_sample;

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::Graphics::Display;
using namespace Windows::System::Threading;
using namespace Windows::UI::Core;
using namespace Windows::UI::Input;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;
using namespace concurrency;
using namespace Windows::ApplicationModel::Core;
//Using VungleSDK namespace
using namespace VungleSDK;

std::string appID = "59792a4f057243276200298a";
std::string placement1 = "DEFAULT18154";
std::string placement2 = "PLACEME92007";
std::string placement3 = "REWARDP93292";

DirectXPage::DirectXPage():
	m_windowVisible(true),
	m_coreInput(nullptr)
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

	//Rest initialization
	CoreWindow^ window = Window::Current->CoreWindow;

	window->VisibilityChanged +=
		ref new TypedEventHandler<CoreWindow^, VisibilityChangedEventArgs^>(this, &DirectXPage::OnVisibilityChanged);

	DisplayInformation^ currentDisplayInformation = DisplayInformation::GetForCurrentView();

	currentDisplayInformation->DpiChanged +=
		ref new TypedEventHandler<DisplayInformation^, Object^>(this, &DirectXPage::OnDpiChanged);

	currentDisplayInformation->OrientationChanged +=
		ref new TypedEventHandler<DisplayInformation^, Object^>(this, &DirectXPage::OnOrientationChanged);

	DisplayInformation::DisplayContentsInvalidated +=
		ref new TypedEventHandler<DisplayInformation^, Object^>(this, &DirectXPage::OnDisplayContentsInvalidated);

	swapChainPanel->CompositionScaleChanged += 
		ref new TypedEventHandler<SwapChainPanel^, Object^>(this, &DirectXPage::OnCompositionScaleChanged);

	swapChainPanel->SizeChanged +=
		ref new SizeChangedEventHandler(this, &DirectXPage::OnSwapChainPanelSizeChanged);

	m_deviceResources = std::make_shared<DX::DeviceResources>();
	m_deviceResources->SetSwapChainPanel(swapChainPanel);

	auto workItemHandler = ref new WorkItemHandler([this] (IAsyncAction ^)
	{
		m_coreInput = swapChainPanel->CreateCoreIndependentInputSource(
			Windows::UI::Core::CoreInputDeviceTypes::Mouse |
			Windows::UI::Core::CoreInputDeviceTypes::Touch |
			Windows::UI::Core::CoreInputDeviceTypes::Pen
			);

		m_coreInput->PointerPressed += ref new TypedEventHandler<Object^, PointerEventArgs^>(this, &DirectXPage::OnPointerPressed);
		m_coreInput->PointerMoved += ref new TypedEventHandler<Object^, PointerEventArgs^>(this, &DirectXPage::OnPointerMoved);
		m_coreInput->PointerReleased += ref new TypedEventHandler<Object^, PointerEventArgs^>(this, &DirectXPage::OnPointerReleased);

		m_coreInput->Dispatcher->ProcessEvents(CoreProcessEventsOption::ProcessUntilQuit);
	});

	m_inputLoopWorker = ThreadPool::RunAsync(workItemHandler, WorkItemPriority::High, WorkItemOptions::TimeSliced);

	m_main = std::unique_ptr<DirectX_XAML_sampleMain>(new DirectX_XAML_sampleMain(m_deviceResources));
	m_main->StartRenderLoop();
}


void DirectX_XAML_sample::DirectXPage::InitSDK_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	//Obtain Vungle SDK instance
	Platform::Array<Platform::String^>^ placements = ref new Platform::Array<Platform::String^>(3);
	placements[0] = ref new Platform::String(std::wstring(placement1.begin(), placement1.end()).c_str());
	placements[1] = ref new Platform::String(std::wstring(placement2.begin(), placement2.end()).c_str());
	placements[2] = ref new Platform::String(std::wstring(placement3.begin(), placement3.end()).c_str());
	sdkInstance = AdFactory::GetInstance(ref new Platform::String(std::wstring(appID.begin(), appID.end()).c_str()), placements);

	//Register event handlers
	sdkInstance->OnAdPlayableChanged += ref new EventHandler<VungleSDK::AdPlayableEventArgs ^>(this, &DirectX_XAML_sample::DirectXPage::OnOnAdPlayableChanged);
	sdkInstance->OnInitCompleted += ref new EventHandler<VungleSDK::ConfigEventArgs ^>(this, &DirectX_XAML_sample::DirectXPage::OnInitCompleted);

	this->InitSDK->IsEnabled = false;
}

void DirectX_XAML_sample::DirectXPage::LoadPlacement2_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	//Load ad for placement2
	sdkInstance->LoadAd(ref new Platform::String(std::wstring(placement2.begin(), placement2.end()).c_str()));
}

void DirectX_XAML_sample::DirectXPage::LoadPlacement3_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	//Load ad for placement3
	sdkInstance->LoadAd(ref new Platform::String(std::wstring(placement3.begin(), placement3.end()).c_str()));
}

void DirectX_XAML_sample::DirectXPage::PlayPlacement1_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	//Play ad for placement1
	sdkInstance->PlayAdAsync(ref new AdConfig, ref new Platform::String(std::wstring(placement1.begin(), placement1.end()).c_str()));
}

void DirectX_XAML_sample::DirectXPage::PlayPlacement2_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	//Play ad for placement2
	embeddedControl->AppID = ref new Platform::String(std::wstring(appID.begin(), appID.end()).c_str());
	std::string str = placement1 + "," + placement2 + "," + placement3;
	embeddedControl->Placements = ref new Platform::String(std::wstring(str.begin(), str.end()).c_str());
	embeddedControl->Placement = ref new Platform::String(std::wstring(placement2.begin(), placement2.end()).c_str());
	embeddedControl->SoundEnabled = false;

	embeddedControl->OnAdStart += ref new EventHandler<VungleSDK::AdEventArgs ^>(this, &DirectXPage::Embedded_OnAdStart);
	embeddedControl->OnAdEnd += ref new EventHandler<VungleSDK::AdEndEventArgs ^>(this, &DirectXPage::Embedded_OnAdEnd);
	embeddedControl->PlayAdAsync();
}

void DirectX_XAML_sample::DirectXPage::PlayPlacement3_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
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

//Event handler for OnInitComleted event
void DirectX_XAML_sample::DirectXPage::OnInitCompleted(Platform::Object ^sender, VungleSDK::ConfigEventArgs ^args)
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
void DirectX_XAML_sample::DirectXPage::OnOnAdPlayableChanged(Platform::Object ^sender, VungleSDK::AdPlayableEventArgs ^args)
{
	//Run asynchronously on the UI thread
	CoreApplication::MainView->Dispatcher->RunAsync(Windows::UI::Core::CoreDispatcherPriority::Normal,
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

		std::stringstream dmess;
		dmess << std::endl << "OnAdPlayable: " << placement << " - " << adPlayable << std::endl;

		OutputDebugStringA(dmess.str().c_str());
	}));
}

DirectXPage::~DirectXPage()
{
	m_main->StopRenderLoop();
	m_coreInput->Dispatcher->StopProcessEvents();
}

void DirectXPage::SaveInternalState(IPropertySet^ state)
{
	critical_section::scoped_lock lock(m_main->GetCriticalSection());
	m_deviceResources->Trim();

	m_main->StopRenderLoop();

}

void DirectXPage::LoadInternalState(IPropertySet^ state)
{
	m_main->StartRenderLoop();
}


void DirectXPage::OnVisibilityChanged(CoreWindow^ sender, VisibilityChangedEventArgs^ args)
{
	m_windowVisible = args->Visible;
	if (m_windowVisible)
	{
		m_main->StartRenderLoop();
	}
	else
	{
		m_main->StopRenderLoop();
	}
}


void DirectXPage::OnDpiChanged(DisplayInformation^ sender, Object^ args)
{
	critical_section::scoped_lock lock(m_main->GetCriticalSection());
	m_deviceResources->SetDpi(sender->LogicalDpi);
	m_main->CreateWindowSizeDependentResources();
}

void DirectXPage::OnOrientationChanged(DisplayInformation^ sender, Object^ args)
{
	critical_section::scoped_lock lock(m_main->GetCriticalSection());
	m_deviceResources->SetCurrentOrientation(sender->CurrentOrientation);
	m_main->CreateWindowSizeDependentResources();
}


void DirectXPage::OnDisplayContentsInvalidated(DisplayInformation^ sender, Object^ args)
{
	critical_section::scoped_lock lock(m_main->GetCriticalSection());
	m_deviceResources->ValidateDevice();
}

void DirectXPage::AppBarButton_Click(Object^ sender, RoutedEventArgs^ e)
{
}

void DirectXPage::OnPointerPressed(Object^ sender, PointerEventArgs^ e)
{
	m_main->StartTracking();
}

void DirectXPage::OnPointerMoved(Object^ sender, PointerEventArgs^ e)
{
	if (m_main->IsTracking())
	{
		m_main->TrackingUpdate(e->CurrentPoint->Position.X);
	}
}

void DirectXPage::OnPointerReleased(Object^ sender, PointerEventArgs^ e)
{
	m_main->StopTracking();
}

void DirectXPage::OnCompositionScaleChanged(SwapChainPanel^ sender, Object^ args)
{
	critical_section::scoped_lock lock(m_main->GetCriticalSection());
	m_deviceResources->SetCompositionScale(sender->CompositionScaleX, sender->CompositionScaleY);
	m_main->CreateWindowSizeDependentResources();
}

void DirectXPage::OnSwapChainPanelSizeChanged(Object^ sender, SizeChangedEventArgs^ e)
{
	critical_section::scoped_lock lock(m_main->GetCriticalSection());
	m_deviceResources->SetLogicalSize(e->NewSize);
	m_main->CreateWindowSizeDependentResources();
}

// Event Handler called before playing an ad
void DirectXPage::Embedded_OnAdStart(Platform::Object^ sender, VungleSDK::AdEventArgs^ e)
{
	CoreApplication::MainView->Dispatcher->RunAsync(Windows::UI::Core::CoreDispatcherPriority::Normal,
		ref new Windows::UI::Core::DispatchedHandler(
			[this, e]
	{
		ChangeEmbeddedHeight(250);
	}));
}

// Event handler called when the user leaves ad and control is return to the hosting app
void DirectXPage::Embedded_OnAdEnd(Platform::Object^ sender, VungleSDK::AdEndEventArgs^ e)
{
	CoreApplication::MainView->Dispatcher->RunAsync(Windows::UI::Core::CoreDispatcherPriority::Normal,
		ref new Windows::UI::Core::DispatchedHandler(
			[this, e]
	{
		ChangeEmbeddedHeight(1);
	}));
}

void DirectXPage::ChangeEmbeddedHeight(double value)
{
	embeddedControl->Height = value;
}

