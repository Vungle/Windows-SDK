﻿//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------
#include "pch.h"
#include "XamlTypeInfo.g.h"

#include "App.xaml.h"
#include "MainPage.xaml.h"
#include "XamlBindingInfo.g.hpp"
#include "App.g.hpp"
#include "MainPage.g.hpp"

template<typename T>
::Platform::Object^ ActivateType()
{
    return ref new T;
}

template<typename TInstance, typename TItem>
void CollectionAdd(::Platform::Object^ instance, ::Platform::Object^ item)
{
    safe_cast<TInstance^>(instance)->Append((TItem)item);
}

template<typename TInstance, typename TKey, typename TItem>
void DictionaryAdd(::Platform::Object^ instance, ::Platform::Object^ key, ::Platform::Object^ item)
{
    safe_cast<TInstance^>(instance)->Insert((TKey)key, (TItem)item);
}

template<typename T>
::Platform::Object^ FromStringConverter(::XamlTypeInfo::InfoProvider::XamlUserType^ userType, ::Platform::String^ input)
{
    return ref new ::Platform::Box<T>((T)userType->CreateEnumUIntFromString(input));
}

template<typename TDeclaringType, typename TValue>
::Platform::Object^ GetValueTypeMember_CleanStart(::Platform::Object^ instance)
{
    return ref new ::Platform::Box<TValue>(safe_cast<TDeclaringType^>(instance)->CleanStart);
}

template<typename TDeclaringType, typename TValue>
::Platform::Object^ GetValueTypeMember_SoundEnabled(::Platform::Object^ instance)
{
    return ref new ::Platform::Box<TValue>(safe_cast<TDeclaringType^>(instance)->SoundEnabled);
}

template<typename TDeclaringType, typename TValue>
::Platform::Object^ GetValueTypeMember_BackButtonImmediatelyEnabled(::Platform::Object^ instance)
{
    return ref new ::Platform::Box<TValue>(safe_cast<TDeclaringType^>(instance)->BackButtonImmediatelyEnabled);
}

template<typename TDeclaringType>
::Platform::Object^ GetReferenceTypeMember_AdConfig(::Platform::Object^ instance)
{
    return safe_cast<TDeclaringType^>(instance)->AdConfig;
}

template<typename TDeclaringType>
::Platform::Object^ GetReferenceTypeMember_AppID(::Platform::Object^ instance)
{
    return safe_cast<TDeclaringType^>(instance)->AppID;
}

template<typename TDeclaringType>
::Platform::Object^ GetReferenceTypeMember_Placements(::Platform::Object^ instance)
{
    return safe_cast<TDeclaringType^>(instance)->Placements;
}

template<typename TDeclaringType>
::Platform::Object^ GetReferenceTypeMember_Placement(::Platform::Object^ instance)
{
    return safe_cast<TDeclaringType^>(instance)->Placement;
}

template<typename TDeclaringType>
::Platform::Object^ GetReferenceTypeMember_ApiEndpoint(::Platform::Object^ instance)
{
    return safe_cast<TDeclaringType^>(instance)->ApiEndpoint;
}

template<typename TDeclaringType>
::Platform::Object^ GetReferenceTypeMember_UserId(::Platform::Object^ instance)
{
    return safe_cast<TDeclaringType^>(instance)->UserId;
}

template<typename TDeclaringType>
::Platform::Object^ GetReferenceTypeMember_IncentivizedDialogTitle(::Platform::Object^ instance)
{
    return safe_cast<TDeclaringType^>(instance)->IncentivizedDialogTitle;
}

template<typename TDeclaringType>
::Platform::Object^ GetReferenceTypeMember_IncentivizedDialogBody(::Platform::Object^ instance)
{
    return safe_cast<TDeclaringType^>(instance)->IncentivizedDialogBody;
}

template<typename TDeclaringType>
::Platform::Object^ GetReferenceTypeMember_IncentivizedDialogCloseButton(::Platform::Object^ instance)
{
    return safe_cast<TDeclaringType^>(instance)->IncentivizedDialogCloseButton;
}

template<typename TDeclaringType>
::Platform::Object^ GetReferenceTypeMember_IncentivizedDialogContinueButton(::Platform::Object^ instance)
{
    return safe_cast<TDeclaringType^>(instance)->IncentivizedDialogContinueButton;
}

template<typename TDeclaringType, typename TValue>
void SetValueTypeMember_CleanStart(::Platform::Object^ instance, ::Platform::Object^ value)
{
    safe_cast<TDeclaringType^>(instance)->CleanStart = safe_cast<::Platform::IBox<TValue>^>(value)->Value;
}

template<typename TDeclaringType, typename TValue>
void SetValueTypeMember_SoundEnabled(::Platform::Object^ instance, ::Platform::Object^ value)
{
    safe_cast<TDeclaringType^>(instance)->SoundEnabled = safe_cast<::Platform::IBox<TValue>^>(value)->Value;
}

template<typename TDeclaringType, typename TValue>
void SetValueTypeMember_BackButtonImmediatelyEnabled(::Platform::Object^ instance, ::Platform::Object^ value)
{
    safe_cast<TDeclaringType^>(instance)->BackButtonImmediatelyEnabled = safe_cast<::Platform::IBox<TValue>^>(value)->Value;
}

template<typename TDeclaringType, typename TValue>
void SetReferenceTypeMember_AdConfig(::Platform::Object^ instance, ::Platform::Object^ value)
{
    safe_cast<TDeclaringType^>(instance)->AdConfig = safe_cast<TValue^>(value);
}

template<typename TDeclaringType, typename TValue>
void SetReferenceTypeMember_AppID(::Platform::Object^ instance, ::Platform::Object^ value)
{
    safe_cast<TDeclaringType^>(instance)->AppID = safe_cast<TValue^>(value);
}

template<typename TDeclaringType, typename TValue>
void SetReferenceTypeMember_Placements(::Platform::Object^ instance, ::Platform::Object^ value)
{
    safe_cast<TDeclaringType^>(instance)->Placements = safe_cast<TValue^>(value);
}

template<typename TDeclaringType, typename TValue>
void SetReferenceTypeMember_Placement(::Platform::Object^ instance, ::Platform::Object^ value)
{
    safe_cast<TDeclaringType^>(instance)->Placement = safe_cast<TValue^>(value);
}

template<typename TDeclaringType, typename TValue>
void SetReferenceTypeMember_ApiEndpoint(::Platform::Object^ instance, ::Platform::Object^ value)
{
    safe_cast<TDeclaringType^>(instance)->ApiEndpoint = safe_cast<TValue^>(value);
}

template<typename TDeclaringType, typename TValue>
void SetReferenceTypeMember_UserId(::Platform::Object^ instance, ::Platform::Object^ value)
{
    safe_cast<TDeclaringType^>(instance)->UserId = safe_cast<TValue^>(value);
}

template<typename TDeclaringType, typename TValue>
void SetReferenceTypeMember_IncentivizedDialogTitle(::Platform::Object^ instance, ::Platform::Object^ value)
{
    safe_cast<TDeclaringType^>(instance)->IncentivizedDialogTitle = safe_cast<TValue^>(value);
}

template<typename TDeclaringType, typename TValue>
void SetReferenceTypeMember_IncentivizedDialogBody(::Platform::Object^ instance, ::Platform::Object^ value)
{
    safe_cast<TDeclaringType^>(instance)->IncentivizedDialogBody = safe_cast<TValue^>(value);
}

template<typename TDeclaringType, typename TValue>
void SetReferenceTypeMember_IncentivizedDialogCloseButton(::Platform::Object^ instance, ::Platform::Object^ value)
{
    safe_cast<TDeclaringType^>(instance)->IncentivizedDialogCloseButton = safe_cast<TValue^>(value);
}

template<typename TDeclaringType, typename TValue>
void SetReferenceTypeMember_IncentivizedDialogContinueButton(::Platform::Object^ instance, ::Platform::Object^ value)
{
    safe_cast<TDeclaringType^>(instance)->IncentivizedDialogContinueButton = safe_cast<TValue^>(value);
}

enum TypeInfo_Flags
{
    TypeInfo_Flags_None                 = 0x00,
    TypeInfo_Flags_IsLocalType          = 0x01,
    TypeInfo_Flags_IsSystemType         = 0x02,
    TypeInfo_Flags_IsReturnTypeStub     = 0x04,
    TypeInfo_Flags_IsBindable           = 0x08,
    TypeInfo_Flags_IsMarkupExtension    = 0x10, 
};

struct TypeInfo
{
    PCWSTR  typeName;
    PCWSTR contentPropertyName;
    ::Platform::Object^ (*activator)();
    void (*collectionAdd)(::Platform::Object^, ::Platform::Object^);
    void (*dictionaryAdd)(::Platform::Object^, ::Platform::Object^, ::Platform::Object^);
    ::Platform::Object^ (*fromStringConverter)(::XamlTypeInfo::InfoProvider::XamlUserType^, ::Platform::String^);
    int     baseTypeIndex;
    int     firstMemberIndex;
    int     firstEnumValueIndex;
    int     createFromStringIndex;
    ::Windows::UI::Xaml::Interop::TypeKind kindofType;
    unsigned int flags;
};

const TypeInfo TypeInfos[] = 
{
    //   0
    L"Object", L"",
    nullptr, nullptr, nullptr, nullptr,
    -1,
    0, 0, -1, ::Windows::UI::Xaml::Interop::TypeKind::Metadata,
    TypeInfo_Flags_IsSystemType | TypeInfo_Flags_None,
    //   1
    L"String", L"",
    nullptr, nullptr, nullptr, nullptr,
    -1,
    0, 0, -1, ::Windows::UI::Xaml::Interop::TypeKind::Metadata,
    TypeInfo_Flags_IsSystemType | TypeInfo_Flags_None,
    //   2
    L"Boolean", L"",
    nullptr, nullptr, nullptr, nullptr,
    -1,
    0, 0, -1, ::Windows::UI::Xaml::Interop::TypeKind::Metadata,
    TypeInfo_Flags_IsSystemType | TypeInfo_Flags_None,
    //   3
    L"VungleSDK.AdConfig", L"",
    nullptr, nullptr, nullptr, nullptr,
    0, // Object
    0, 0, -1, ::Windows::UI::Xaml::Interop::TypeKind::Metadata,
    TypeInfo_Flags_IsReturnTypeStub | TypeInfo_Flags_None,
    //   4
    L"CPP_sample.MainPage", L"",
    &ActivateType<::CPP_sample::MainPage>, nullptr, nullptr, nullptr,
    6, // Windows.UI.Xaml.Controls.Page
    0, 0, -1, ::Windows::UI::Xaml::Interop::TypeKind::Custom,
    TypeInfo_Flags_IsLocalType | TypeInfo_Flags_None,
    //   5
    L"VungleSDK.UI.VungleAdControl", L"",
    &ActivateType<::VungleSDK::UI::VungleAdControl>, nullptr, nullptr, nullptr,
    7, // Windows.UI.Xaml.Controls.UserControl
    0, 0, -1, ::Windows::UI::Xaml::Interop::TypeKind::Metadata,
    TypeInfo_Flags_None,
    //   6
    L"Windows.UI.Xaml.Controls.Page", L"",
    nullptr, nullptr, nullptr, nullptr,
    -1,
    13, 0, -1, ::Windows::UI::Xaml::Interop::TypeKind::Metadata,
    TypeInfo_Flags_IsSystemType | TypeInfo_Flags_None,
    //   7
    L"Windows.UI.Xaml.Controls.UserControl", L"",
    nullptr, nullptr, nullptr, nullptr,
    -1,
    13, 0, -1, ::Windows::UI::Xaml::Interop::TypeKind::Metadata,
    TypeInfo_Flags_IsSystemType | TypeInfo_Flags_None,
    //  Last type here is for padding
    L"", L"",
    nullptr, nullptr, nullptr, nullptr,
    -1, 
    13, 0, -1, ::Windows::UI::Xaml::Interop::TypeKind::Custom,
    TypeInfo_Flags_None,
};

const UINT TypeInfoLookup[] = { 
      0,   //   0
      0,   //   1
      0,   //   2
      0,   //   3
      0,   //   4
      0,   //   5
      0,   //   6
      2,   //   7
      3,   //   8
      3,   //   9
      3,   //  10
      3,   //  11
      3,   //  12
      3,   //  13
      3,   //  14
      3,   //  15
      3,   //  16
      3,   //  17
      3,   //  18
      4,   //  19
      5,   //  20
      5,   //  21
      5,   //  22
      5,   //  23
      5,   //  24
      5,   //  25
      5,   //  26
      5,   //  27
      5,   //  28
      6,   //  29
      7,   //  30
      7,   //  31
      7,   //  32
      7,   //  33
      7,   //  34
      7,   //  35
      7,   //  36
      8,   //  37
};

struct MemberInfo 
{
    PCWSTR shortName;
    ::Platform::Object^ (*getter)(::Platform::Object^);
    void (*setter)(::Platform::Object^, ::Platform::Object^);
    int typeIndex;
    int targetTypeIndex;
    bool isReadOnly;
    bool isDependencyProperty;
    bool isAttachable;
};

const MemberInfo MemberInfos[] = 
{
    //   0 - VungleSDK.UI.VungleAdControl.AdConfig
    L"AdConfig",
    &GetReferenceTypeMember_AdConfig<::VungleSDK::UI::VungleAdControl>,
    &SetReferenceTypeMember_AdConfig<::VungleSDK::UI::VungleAdControl, ::VungleSDK::AdConfig>,
    3, // VungleSDK.AdConfig
    -1,
    false, false, false,
    //   1 - VungleSDK.UI.VungleAdControl.AppID
    L"AppID",
    &GetReferenceTypeMember_AppID<::VungleSDK::UI::VungleAdControl>,
    &SetReferenceTypeMember_AppID<::VungleSDK::UI::VungleAdControl, ::Platform::String>,
    1, // String
    -1,
    false, false, false,
    //   2 - VungleSDK.UI.VungleAdControl.Placements
    L"Placements",
    &GetReferenceTypeMember_Placements<::VungleSDK::UI::VungleAdControl>,
    &SetReferenceTypeMember_Placements<::VungleSDK::UI::VungleAdControl, ::Platform::String>,
    1, // String
    -1,
    false, false, false,
    //   3 - VungleSDK.UI.VungleAdControl.Placement
    L"Placement",
    &GetReferenceTypeMember_Placement<::VungleSDK::UI::VungleAdControl>,
    &SetReferenceTypeMember_Placement<::VungleSDK::UI::VungleAdControl, ::Platform::String>,
    1, // String
    -1,
    false, false, false,
    //   4 - VungleSDK.UI.VungleAdControl.ApiEndpoint
    L"ApiEndpoint",
    &GetReferenceTypeMember_ApiEndpoint<::VungleSDK::UI::VungleAdControl>,
    &SetReferenceTypeMember_ApiEndpoint<::VungleSDK::UI::VungleAdControl, ::Platform::String>,
    1, // String
    -1,
    false, false, false,
    //   5 - VungleSDK.UI.VungleAdControl.CleanStart
    L"CleanStart",
    &GetValueTypeMember_CleanStart<::VungleSDK::UI::VungleAdControl, ::Platform::Boolean>,
    &SetValueTypeMember_CleanStart<::VungleSDK::UI::VungleAdControl, ::Platform::Boolean>,
    2, // Boolean
    -1,
    false, false, false,
    //   6 - VungleSDK.UI.VungleAdControl.UserId
    L"UserId",
    &GetReferenceTypeMember_UserId<::VungleSDK::UI::VungleAdControl>,
    &SetReferenceTypeMember_UserId<::VungleSDK::UI::VungleAdControl, ::Platform::String>,
    1, // String
    -1,
    false, false, false,
    //   7 - VungleSDK.UI.VungleAdControl.SoundEnabled
    L"SoundEnabled",
    &GetValueTypeMember_SoundEnabled<::VungleSDK::UI::VungleAdControl, ::Platform::Boolean>,
    &SetValueTypeMember_SoundEnabled<::VungleSDK::UI::VungleAdControl, ::Platform::Boolean>,
    2, // Boolean
    -1,
    false, false, false,
    //   8 - VungleSDK.UI.VungleAdControl.BackButtonImmediatelyEnabled
    L"BackButtonImmediatelyEnabled",
    &GetValueTypeMember_BackButtonImmediatelyEnabled<::VungleSDK::UI::VungleAdControl, ::Platform::Boolean>,
    &SetValueTypeMember_BackButtonImmediatelyEnabled<::VungleSDK::UI::VungleAdControl, ::Platform::Boolean>,
    2, // Boolean
    -1,
    false, false, false,
    //   9 - VungleSDK.UI.VungleAdControl.IncentivizedDialogTitle
    L"IncentivizedDialogTitle",
    &GetReferenceTypeMember_IncentivizedDialogTitle<::VungleSDK::UI::VungleAdControl>,
    &SetReferenceTypeMember_IncentivizedDialogTitle<::VungleSDK::UI::VungleAdControl, ::Platform::String>,
    1, // String
    -1,
    false, false, false,
    //  10 - VungleSDK.UI.VungleAdControl.IncentivizedDialogBody
    L"IncentivizedDialogBody",
    &GetReferenceTypeMember_IncentivizedDialogBody<::VungleSDK::UI::VungleAdControl>,
    &SetReferenceTypeMember_IncentivizedDialogBody<::VungleSDK::UI::VungleAdControl, ::Platform::String>,
    1, // String
    -1,
    false, false, false,
    //  11 - VungleSDK.UI.VungleAdControl.IncentivizedDialogCloseButton
    L"IncentivizedDialogCloseButton",
    &GetReferenceTypeMember_IncentivizedDialogCloseButton<::VungleSDK::UI::VungleAdControl>,
    &SetReferenceTypeMember_IncentivizedDialogCloseButton<::VungleSDK::UI::VungleAdControl, ::Platform::String>,
    1, // String
    -1,
    false, false, false,
    //  12 - VungleSDK.UI.VungleAdControl.IncentivizedDialogContinueButton
    L"IncentivizedDialogContinueButton",
    &GetReferenceTypeMember_IncentivizedDialogContinueButton<::VungleSDK::UI::VungleAdControl>,
    &SetReferenceTypeMember_IncentivizedDialogContinueButton<::VungleSDK::UI::VungleAdControl, ::Platform::String>,
    1, // String
    -1,
    false, false, false,
};

PCWSTR GetShortName(PCWSTR longName)
{
    PCWSTR separator = wcsrchr(longName, '.');
    return separator != nullptr ? separator + 1: longName;
}

const TypeInfo* GetTypeInfo(::Platform::String^ typeName)
{
    auto typeNameLength = typeName->Length();
    if (typeNameLength < _countof(TypeInfoLookup) - 1)
    {
        for (UINT i = TypeInfoLookup[typeNameLength]; i < TypeInfoLookup[typeNameLength+1]; i++)
        {
            if (typeName == ::Platform::StringReference(TypeInfos[i].typeName))
            {
                return &TypeInfos[i];
            }
        }
    }
    return nullptr;
}

const MemberInfo* GetMemberInfo(::Platform::String^ longMemberName)
{
    auto lastDotIndex = longMemberName->Length();
    while (true)
    {
        if (longMemberName->Data()[lastDotIndex] == '.')
        {
            const TypeInfo* pTypeInfo = GetTypeInfo(ref new ::Platform::String(longMemberName->Data(), lastDotIndex));
            const TypeInfo* pNextTypeInfo = pTypeInfo + 1;
            if (pTypeInfo)
            {
                PCWSTR shortMemberName = GetShortName(longMemberName->Data());
                for (int i = pTypeInfo->firstMemberIndex; i < pNextTypeInfo->firstMemberIndex; i++)
                {
                    if (wcscmp(shortMemberName, MemberInfos[i].shortName) == 0)
                    {
                        return &MemberInfos[i];
                    }
                }
            }
            break;
        }
        if (lastDotIndex == 0)
        {
            break;
        }
        lastDotIndex--;
    }
    return nullptr;
}

::Platform::Collections::Vector<::Windows::UI::Xaml::Markup::IXamlMetadataProvider^>^ ::XamlTypeInfo::InfoProvider::XamlTypeInfoProvider::OtherProviders::get()
{
    if(_otherProviders == nullptr)
    {
        auto otherProviders = ref new ::Platform::Collections::Vector<::Windows::UI::Xaml::Markup::IXamlMetadataProvider^>();
        _otherProviders = otherProviders;
    }
    return _otherProviders;
}

::Windows::UI::Xaml::Markup::IXamlType^ ::XamlTypeInfo::InfoProvider::XamlTypeInfoProvider::CreateXamlType(::Platform::String^ typeName)
{
    const TypeInfo* pTypeInfo = GetTypeInfo(typeName);
    const TypeInfo* pNextTypeInfo = pTypeInfo + 1;
    if (pTypeInfo == nullptr || pNextTypeInfo == nullptr)
    {
        return nullptr;
    }
    else if (pTypeInfo->flags & TypeInfo_Flags_IsSystemType)
    {
        return ref new ::XamlTypeInfo::InfoProvider::XamlSystemBaseType(typeName);
    }
    else
    {
        ::XamlTypeInfo::InfoProvider::XamlUserType^ userType = ref new ::XamlTypeInfo::InfoProvider::XamlUserType(
            this, 
            ::Platform::StringReference(pTypeInfo->typeName), 
            this->GetXamlTypeByName(::Platform::StringReference(pTypeInfo->baseTypeIndex >= 0 ? TypeInfos[pTypeInfo->baseTypeIndex].typeName : L"")));
        userType->KindOfType = pTypeInfo->kindofType;
        userType->Activator = pTypeInfo->activator;
        userType->CollectionAdd = pTypeInfo->collectionAdd;
        userType->DictionaryAdd = pTypeInfo->dictionaryAdd;
        userType->FromStringConverter = pTypeInfo->fromStringConverter;
        userType->ContentPropertyName = ::Platform::StringReference(pTypeInfo->contentPropertyName);
        userType->IsLocalType = pTypeInfo->flags & TypeInfo_Flags_IsLocalType;
        userType->IsReturnTypeStub = pTypeInfo->flags & TypeInfo_Flags_IsReturnTypeStub;
        userType->IsBindable = pTypeInfo->flags & TypeInfo_Flags_IsBindable;
        userType->IsMarkupExtension = pTypeInfo->flags & TypeInfo_Flags_IsMarkupExtension;
        userType->CreateFromStringMethod = nullptr;
        int nextMemberIndex = pTypeInfo->firstMemberIndex;
        for (int i=pTypeInfo->firstMemberIndex; i < pNextTypeInfo->firstMemberIndex; i++)
        {
            userType->AddMemberName(::Platform::StringReference(MemberInfos[i].shortName));
            nextMemberIndex++;
        }
        return userType;
    }
}

::Windows::UI::Xaml::Markup::IXamlMember^ ::XamlTypeInfo::InfoProvider::XamlTypeInfoProvider::CreateXamlMember(::Platform::String^ longMemberName)
{
    ::XamlTypeInfo::InfoProvider::XamlMember^ xamlMember = nullptr;
    const MemberInfo* pMemberInfo = GetMemberInfo(longMemberName);
    if (pMemberInfo != nullptr)
    {
        xamlMember = ref new ::XamlTypeInfo::InfoProvider::XamlMember(
            this,
            ::Platform::StringReference(pMemberInfo->shortName),
            ::Platform::StringReference(TypeInfos[pMemberInfo->typeIndex].typeName));
        xamlMember->Getter = pMemberInfo->getter;
        xamlMember->Setter = pMemberInfo->setter;
        xamlMember->TargetTypeName = pMemberInfo->targetTypeIndex >= 0 ? ::Platform::StringReference(TypeInfos[pMemberInfo->targetTypeIndex].typeName) : L"";
        xamlMember->IsReadOnly = pMemberInfo->isReadOnly;
        xamlMember->IsDependencyProperty = pMemberInfo->isDependencyProperty;
        xamlMember->IsAttachable = pMemberInfo->isAttachable;
    }
    return xamlMember;
}

