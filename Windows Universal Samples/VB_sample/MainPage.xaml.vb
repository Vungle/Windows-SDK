'Import VungleSDK namespace'
Imports VungleSDK
Imports Windows.ApplicationModel.Core
Imports Windows.UI.Core

Public NotInheritable Class MainPage
    Inherits Page

    Private WithEvents sdkInstance As VungleAd

    Private appID As String = "59792a4f057243276200298a"
    Private placement1 As String = "DEFAULT18154"
    Private placement2 As String = "PLACEME92007"
    Private placement3 As String = "REWARDP93292"

    Public Sub New()
        InitializeComponent()

        appIDTextBlock.Text = "AppID: " + appID
        placement1IDTextBlock.Text = "PlacementID: " + placement1
        placement2IDTextBlock.Text = "PlacementID: " + placement2
        placement3IDTextBlock.Text = "PlacementID: " + placement3
    End Sub

    'Event handler for OnInitComleted event'
    Private Async Sub OnInitCompleted_EventHandler(sender As Object, args As ConfigEventArgs) Handles sdkInstance.OnInitCompleted
        'size_t converted;'
        'std: stringstream placementsInfo;'
        Dim placementsInfo As String
        placementsInfo = "OnInitCompleted: " + args.Initialized.ToString()
        If (args.Initialized = True) Then
            For i As Integer = 0 To (args.Placements.Length - 1)
                Dim refId As String
                placementsInfo += "\n\tPlacement" + (i + 1).ToString() + ": " + args.Placements(i).ReferenceId

                If args.Placements(i).IsAutoCached = True Then
                    placementsInfo += " (Auto-Cached)"
                End If
            Next

        Else
            placementsInfo += "\n\t" + args.ErrorMessage
        End If

        System.Diagnostics.Debug.WriteLine(placementsInfo)

        Await Me.Dispatcher.RunAsync(CoreDispatcherPriority.Normal,
                                                           New DispatchedHandler(Sub() ChangeLoadButtonsState(args.Initialized)))

    End Sub

    '// Event handler called when e->AdPlayable is changed'
    Private Async Sub OnAdPlayable_EventHandler(sender As Object, args As AdPlayableEventArgs) Handles sdkInstance.OnAdPlayableChanged
        'args->AdPlayable - true if an ad Is available to play, false otherwise'
        'args->Placement  - placement ID in string'

        System.Diagnostics.Debug.WriteLine("OnAdPlayable: " + args.Placement + " - " + args.AdPlayable.ToString())

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
        Dim adConfig As New AdConfig
        adConfig.Orientation = DisplayOrientations.Portrait
        adConfig.SoundEnabled = False ' Default: true'

        Await sdkInstance.PlayAdAsync(adConfig, placement2)
    End Sub

    Private Async Sub PlayPlacement3_Click(sender As Object, e As RoutedEventArgs)
        'Play ad for placement3'
        Dim adConfig As New AdConfig

        adConfig.IncentivizedDialogBody = "Are you sure you want to skip this ad? You must finish watching to claim your reward."
        adConfig.IncentivizedDialogCloseButton = "Close"
        adConfig.IncentivizedDialogContinueButton = "Continue"
        adConfig.IncentivizedDialogTitle = "Close this ad?"
        adConfig.UserId = "VungleTest"

        Await sdkInstance.PlayAdAsync(adConfig, placement3)
    End Sub

End Class
