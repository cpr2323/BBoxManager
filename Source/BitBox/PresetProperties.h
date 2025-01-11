#pragma once
#pragma once

#include <JuceHeader.h>
#include "../Utility/ValueTreeWrapper.h"

class PresetProperties : public ValueTreeWrapper<PresetProperties>
{
public:
    PresetProperties () noexcept : ValueTreeWrapper<PresetProperties> (PresetTypeId) {}
    PresetProperties (juce::ValueTree vt, WrapperType wrapperType, EnableCallbacks shouldEnableCallbacks)
        : ValueTreeWrapper<PresetProperties> (PresetTypeId, vt, wrapperType, shouldEnableCallbacks) {}

    void setName (juce::String name, bool doSelfCallback)
    {
        setValue (name, NamePropertyId, doSelfCallback);
    }

    juce::String getName ()
    {
        return getValue<juce::String> (NamePropertyId);
    }

    std::function<void (juce::String)> onNameChanged;

    static inline const juce::Identifier PresetTypeId { "Preset" };
    static inline const juce::Identifier NamePropertyId { "name" };

    void forEachPad (std::function<bool (juce::ValueTree padVT, int padIndex)> padVTCallback);
    void copyPropertiesFrom (juce::ValueTree source);

    void initValueTree ()
    {
        setName ("", false);
    }

    void processValueTree () {}

private:
    void valueTreePropertyChanged (juce::ValueTree& vt, const juce::Identifier& property)
    {
        if (vt == data)
        {
            if (property == NamePropertyId)
            {
                if (onNameChanged != nullptr)
                    onNameChanged (getName ());
            }
        }
    }
};