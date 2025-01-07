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

    static inline const juce::Identifier PresetTypeId { "Preset" };

    void initValueTree () {}
    void processValueTree () {}

private:
};