﻿

#pragma once
//------------------------------------------------------------------------------
//     This code was generated by a tool.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
//------------------------------------------------------------------------------

namespace Windows {
    namespace UI {
        namespace Xaml {
            namespace Controls {
                ref class Grid;
                ref class Button;
            }
        }
    }
}

namespace CPP_sample_Windows8_1
{
    partial ref class MainPage : public ::Windows::UI::Xaml::Controls::Page, 
        public ::Windows::UI::Xaml::Markup::IComponentConnector
    {
    public:
        void InitializeComponent();
        virtual void Connect(int connectionId, ::Platform::Object^ target);
    
    private:
        bool _contentLoaded;
    
        private: ::Windows::UI::Xaml::Controls::Grid^ ButtonsPanel;
        private: ::Windows::UI::Xaml::Controls::Button^ DefaultConfigButton;
        private: ::Windows::UI::Xaml::Controls::Button^ IncentivizedConfigButton;
        private: ::Windows::UI::Xaml::Controls::Button^ MutedConfigButton;
    };
}

