//
// MainPage.xaml.h
// Declaration of the MainPage class.
//

#pragma once

#include "MainPage.g.h"

namespace CPP_sample
{
	/// <summary>
	/// An empty page that can be used on its own or navigated to within a Frame.
	/// </summary>
	public ref class MainPage sealed
	{
	public:
		MainPage();

	private:

		//REPLACE WITH YOUR CREDENTIALS
		//std::string appID = "5ad92d2e49eb2d04561b75de";
		//std::string placement1 = "DEFAULT-0929587";
		//std::string placement2 = "FLF-5107050";
		//std::string placement3 = "REW-1278468";

		//Alternate test credentials
		std::string appID = "598a531697c455bc70001f98";
		std::string placement1 = "DEFAULT59086";
		std::string placement2 = "NONREWA96669";
		std::string placement3 = "REWARDE30999";

		VungleSDK::VungleAd^ sdkInstance;



		void OnInitCompleted(Platform::Object ^ sender, VungleSDK::ConfigEventArgs ^ args);
		void OnOnAdPlayableChanged(Platform::Object ^sender, VungleSDK::AdPlayableEventArgs ^args);
		void OnAdStart(Platform::Object^ sender, VungleSDK::AdEventArgs^ e);
		void OnVideoView(Platform::Object^ sender, VungleSDK::AdViewEventArgs^ e);
		void OnAdEnd(Platform::Object^ sender, VungleSDK::AdEndEventArgs^ e);
		void Diagnostic(Platform::Object^ sender, VungleSDK::DiagnosticLogEvent^ e);

		void Embedded_OnAdStart(Platform::Object^ sender, VungleSDK::AdEventArgs^ e);
		void Embedded_OnAdEnd(Platform::Object^ sender, VungleSDK::AdEndEventArgs^ e);
		void AnimateHeight(double value);

		void InitSDK_Click(Platform::Object ^ sender, Windows::UI::Xaml::RoutedEventArgs ^ e);
		void ToggleConsent_Click(Platform::Object ^ sender, Windows::UI::Xaml::RoutedEventArgs ^ e);
		void GetConsent_Click(Platform::Object ^ sender, Windows::UI::Xaml::RoutedEventArgs ^ e);
		void LoadPlacement2_Click(Platform::Object ^ sender, Windows::UI::Xaml::RoutedEventArgs ^ e);
		void LoadPlacement3_Click(Platform::Object ^ sender, Windows::UI::Xaml::RoutedEventArgs ^ e);
		void PlayPlacement1_Click(Platform::Object ^ sender, Windows::UI::Xaml::RoutedEventArgs ^ e);
		void PlayPlacement2_Click(Platform::Object ^ sender, Windows::UI::Xaml::RoutedEventArgs ^ e);
		void PlayPlacement3_Click(Platform::Object ^ sender, Windows::UI::Xaml::RoutedEventArgs ^ e);
		void ClosePlacement_Click(Platform::Object ^ sender, Windows::UI::Xaml::RoutedEventArgs ^ e);
	};
}
