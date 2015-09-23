' The Blank Page item template is documented at http://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x409

Imports VungleSDK
Imports Windows.ApplicationModel.Core
Imports Windows.UI.Core

Public NotInheritable Class MainPage
    Inherits Page

    Private WithEvents sdkInstance As VungleAd
    Private adPlayable As Boolean

    Public Sub New()
        InitializeComponent()
        sdkInstance = AdFactory.GetInstance("vungleTest")
    End Sub

    Private Async Sub OnAdPlayable_EventHandler(sender As Object, args As AdPlayableEventArgs) Handles sdkInstance.OnAdPlayableChanged
        adPlayable = args.AdPlayable
        Await CoreApplication.MainView.Dispatcher.RunAsync(CoreDispatcherPriority.Normal,
                                                           New DispatchedHandler(AddressOf ChangeButtonsState))

    End Sub

    Private Sub ChangeButtonsState()
        DefaultConfigButton.IsEnabled = adPlayable
        IncentivizedConfigButton.IsEnabled = adPlayable
        MutedConfigButton.IsEnabled = adPlayable
    End Sub

    Private Async Sub DefaultConfigButton_Click(sender As Object, e As RoutedEventArgs)
        Dim adConfig As New AdConfig
        Await sdkInstance.PlayAdAsync(adConfig)
    End Sub

    Private Async Sub IncentivizedConfigButton_Click(sender As Object, e As RoutedEventArgs)
        Dim adConfig As New AdConfig
        adConfig.Incentivized = True
        Await sdkInstance.PlayAdAsync(adConfig)
    End Sub

    Private Async Sub MutedConfigButton_Click(sender As Object, e As RoutedEventArgs)
        Dim adConfig As New AdConfig
        adConfig.SoundEnabled = False
        Await sdkInstance.PlayAdAsync(adConfig)
    End Sub
End Class
