'Import VungleSDK namespace'
Imports VungleSDK
Imports Windows.ApplicationModel.Core
Imports Windows.UI.Core

Public NotInheritable Class MainPage
    Inherits Page

    Private WithEvents sdkInstance As VungleAd

    Private appID As String = "591236625b2480ac40000028"
    Private placement1 As String = "DEFAULT18080"
    Private placement2 As String = "PLMT02I58745"
    Private placement3 As String = "PLMT03R02739"

    Public Sub New()
        InitializeComponent()

        appIDTextBlock.Text = "AppID: " + appID
        placement1IDTextBlock.Text = "PlacementID: " + placement1
        placement2IDTextBlock.Text = "PlacementID: " + placement2
        placement3IDTextBlock.Text = "PlacementID: " + placement3
    End Sub

    Private Async Sub OnInitCompleted_EventHandler(sender As Object, args As ConfigEventArgs) Handles sdkInstance.OnInitCompleted
        Await Me.Dispatcher.RunAsync(CoreDispatcherPriority.Normal,
                                                           New DispatchedHandler(Sub() ChangeLoadButtonsState(args.Initialized)))

    End Sub

    'Register OnAdPlayableChanged event handler'
    Private Async Sub OnAdPlayable_EventHandler(sender As Object, args As AdPlayableEventArgs) Handles sdkInstance.OnAdPlayableChanged
        'adPlayable = args.AdPlayable'
        'Run asynchronously on the UI thread'
        Await Me.Dispatcher.RunAsync(CoreDispatcherPriority.Normal,
                                                           New DispatchedHandler(Sub() ChangePlayButtonState(args.AdPlayable, args.Placement)))

    End Sub

    Private Sub ChangeLoadButtonsState(initialized As Boolean)
        LoadPlacement2.IsEnabled = initialized
        LoadPlacement3.IsEnabled = initialized
    End Sub

    Private Sub ChangePlayButtonState(playable As Boolean, placement As String)
        If (placement.Equals(placement1)) Then
            PlayPlacement1.IsEnabled = playable
        ElseIf (placement.Equals(placement2)) Then
            PlayPlacement2.IsEnabled = playable
        ElseIf (placement.Equals(placement3)) Then
            PlayPlacement3.IsEnabled = playable
        End If
    End Sub

    Private Async Sub MutedConfigButton_Click(sender As Object, e As RoutedEventArgs)
        'Play ad without sound'
        Dim adConfig As New AdConfig
        adConfig.SoundEnabled = False
        Await sdkInstance.PlayAdAsync(adConfig)
    End Sub

    Private Sub InitSDK_Click(sender As Object, e As RoutedEventArgs)
        'Obtain Vungle SDK instance'
        Dim placements(2) As String
        placements(0) = placement1
        placements(1) = placement2
        placements(2) = placement3
        sdkInstance = AdFactory.GetInstance(appID, placements)
        InitSDK.IsEnabled = False
    End Sub

    Private Sub LoadPlacement2_Click(sender As Object, e As RoutedEventArgs)
        'Load ad for placement2'
        sdkInstance.LoadAd(placement2)
    End Sub

    Private Sub LoadPlacement3_Click(sender As Object, e As RoutedEventArgs)
        'Load ad for placement3'
        sdkInstance.LoadAd(placement3)
    End Sub

    Private Async Sub PlayPlacement1_Click(sender As Object, e As RoutedEventArgs)
        'Play ad for placement1'
        Await sdkInstance.PlayAdAsync(New AdConfig(), placement1)
    End Sub

    Private Async Sub PlayPlacement2_Click(sender As Object, e As RoutedEventArgs)
        'Play ad for placement2'
        Await sdkInstance.PlayAdAsync(New AdConfig(), placement2)
    End Sub

    Private Async Sub PlayPlacement3_Click(sender As Object, e As RoutedEventArgs)
        'Play ad for placement3'
        Await sdkInstance.PlayAdAsync(New AdConfig(), placement3)
    End Sub

End Class
