'Import VungleSDK namespace'
Imports VungleSDK
Imports Windows.ApplicationModel.Core
Imports Windows.UI.Core

Public NotInheritable Class MainPage
    Inherits Page

    Private WithEvents sdkInstance As VungleAd
    Private adPlayable As Boolean

    Public Sub New()
        InitializeComponent()
        'Obtain Vungle SDK instance'
        sdkInstance = AdFactory.GetInstance("Test_Windows")
    End Sub

    'Register OnAdPlayableChanged event handler'
    Private Async Sub OnAdPlayable_EventHandler(sender As Object, args As AdPlayableEventArgs) Handles sdkInstance.OnAdPlayableChanged
        adPlayable = args.AdPlayable
        'Run asynchronously on the UI thread'
        Await Me.Dispatcher.RunAsync(CoreDispatcherPriority.Normal,
                                                           New DispatchedHandler(AddressOf ChangeButtonsState))

    End Sub

    Private Sub ChangeButtonsState()
        'Change IsEnabled property for each button'
        DefaultConfigButton.IsEnabled = adPlayable
        IncentivizedConfigButton.IsEnabled = adPlayable
        MutedConfigButton.IsEnabled = adPlayable
    End Sub

    Private Async Sub DefaultConfigButton_Click(sender As Object, e As RoutedEventArgs)
        'Play ad with default configuration'
        Dim adConfig As New AdConfig
        Await sdkInstance.PlayAdAsync(adConfig)
    End Sub

    Private Async Sub IncentivizedConfigButton_Click(sender As Object, e As RoutedEventArgs)
        'Play ad with enabled 'incentivized' option'
        Dim adConfig As New AdConfig
        adConfig.Incentivized = True
        Await sdkInstance.PlayAdAsync(adConfig)
    End Sub

    Private Async Sub MutedConfigButton_Click(sender As Object, e As RoutedEventArgs)
        'Play ad without sound'
        Dim adConfig As New AdConfig
        adConfig.SoundEnabled = False
        Await sdkInstance.PlayAdAsync(adConfig)
    End Sub
End Class
