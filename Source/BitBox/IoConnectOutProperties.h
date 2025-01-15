#pragma once

#include <JuceHeader.h>
#include "../Utility/ValueTreeWrapper.h"

class IoConnectOutProperties : public ValueTreeWrapper<IoConnectOutProperties>
{
public:
    IoConnectOutProperties () noexcept : ValueTreeWrapper<IoConnectOutProperties> (IoConnectOutTypeId) {}
    IoConnectOutProperties (juce::ValueTree vt, WrapperType wrapperType, EnableCallbacks shouldEnableCallbacks)
        : ValueTreeWrapper<IoConnectOutProperties> (IoConnectOutTypeId, vt, wrapperType, shouldEnableCallbacks) {}

    void setOutputIoCon (juce::String outputIoCon, bool includeSelfCallback) { setValue (outputIoCon, OutputIoConPropertyId, includeSelfCallback); }
    juce::String getOutputIoCon () { return getValue<juce::String> (OutputIoConPropertyId); }

    static inline const juce::Identifier IoConnectOutTypeId { "IoConnectOut" };
    static inline const juce::Identifier OutputIoConPropertyId { "outputIoCon" };

    std::function<void (juce::String outputIoCon)> onOutputIoConChange;

    void copyPropertiesFrom (juce::ValueTree source)
    {
        IoConnectOutProperties srcIoConnectOutProperties { source, IoConnectOutProperties::WrapperType::client, IoConnectOutProperties::EnableCallbacks::no };
        setOutputIoCon (srcIoConnectOutProperties.getOutputIoCon (), false);
    }

    void initValueTree ()
    {
        setOutputIoCon ("", false);
    }
    void processValueTree () {}

private:
    void valueTreePropertyChanged (juce::ValueTree& treeWhosePropertyHasChanged, const juce::Identifier& property) override
    {
        if (treeWhosePropertyHasChanged == data)
        {
            if (property == OutputIoConPropertyId)
            {
                if (onOutputIoConChange != nullptr)
                    onOutputIoConChange (getOutputIoCon ());
            }
        }
    }
};