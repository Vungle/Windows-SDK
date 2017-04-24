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
		void play_Tapped(Platform::Object^ sender, Windows::UI::Xaml::Input::TappedRoutedEventArgs^ e);
		void start_Tapped(Platform::Object^ sender, Windows::UI::Xaml::Input::TappedRoutedEventArgs^ e);
		VungleSDK::VungleAd^ sdkInstance;

		void OnOnAdPlayableChanged(Platform::Object ^sender, VungleSDK::AdPlayableEventArgs ^args);
		void OnAdStart(Platform::Object^ sender, VungleSDK::AdEventArgs^ e);
		void OnVideoView(Platform::Object^ sender, VungleSDK::AdViewEventArgs^ e);
		void OnAdEnd(Platform::Object^ sender, VungleSDK::AdEndEventArgs^ e);
		void Diagnostic(Platform::Object^ sender, VungleSDK::DiagnosticLogEvent^ e);
		
		void DefaultConfigButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void IncentivizedConfigButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void MutedConfigButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	};
}
