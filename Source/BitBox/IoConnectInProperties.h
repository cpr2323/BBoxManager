#pragma once

#include <JuceHeader.h>
#include "../Utility/ValueTreeWrapper.h"

class IoConnectInProperties : public ValueTreeWrapper<IoConnectInProperties>
{
public:
    IoConnectInProperties () noexcept : ValueTreeWrapper<IoConnectInProperties> (IoConnectInTypeId) {}
    IoConnectInProperties (juce::ValueTree vt, WrapperType wrapperType, EnableCallbacks shouldEnableCallbacks)
        : ValueTreeWrapper<IoConnectInProperties> (IoConnectInTypeId, vt, wrapperType, shouldEnableCallbacks) {}

    void setInputIoCon (juce::String inputIoCon, bool includeSelfCallback) { setValue (inputIoCon, InputIoConPropertyId, includeSelfCallback); }
    juce::String getInputIoCon () { return getValue<juce::String> (InputIoConPropertyId); }

    static inline const juce::Identifier IoConnectInTypeId { "IoConnectIn" };
    static inline const juce::Identifier InputIoConPropertyId { "inputIoCon" };

    std::function<void (juce::String inputIoCon)> onInputIoConChange;

    void copyPropertiesFrom (juce::ValueTree source)
    {
        IoConnectInProperties srcIoConnectInProperties { source, IoConnectInProperties::WrapperType::client, IoConnectInProperties::EnableCallbacks::no };
        setInputIoCon (srcIoConnectInProperties.getInputIoCon (), false);
    }

    void initValueTree ()
    {
        setInputIoCon ("", false);
    }
    void processValueTree () {}

private:
    void valueTreePropertyChanged (juce::ValueTree& treeWhosePropertyHasChanged, const juce::Identifier& property) override
    {
        if (treeWhosePropertyHasChanged == data)
        {
            if (property == InputIoConPropertyId)
            {
                if (onInputIoConChange != nullptr)
                    onInputIoConChange (getInputIoCon ());
            }
        }
    }
};