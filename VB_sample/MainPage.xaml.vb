' The Blank Page item template is documented at http://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x409

Imports VungleSDK

Public NotInheritable Class MainPage
    Inherits Page

    Private sdkInstance As VungleAd

    Public Sub New()
        InitializeComponent()
        sdkInstance = AdFactory.GetInstance("pushokTest")
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
