#pragma once

#include <JuceHeader.h>
#include "../Utility/ValueTreeWrapper.h"

class SliceListProperties : public ValueTreeWrapper<SliceListProperties>
{
public:
    SliceListProperties () noexcept : ValueTreeWrapper<SliceListProperties> (SliceListTypeId) {}
    SliceListProperties (juce::ValueTree vt, WrapperType wrapperType, EnableCallbacks shouldEnableCallbacks)
        : ValueTreeWrapper<SliceListProperties> (SliceListTypeId, vt, wrapperType, shouldEnableCallbacks) {}

    static inline const juce::Identifier SliceListTypeId { "SliceList" };

    void initValueTree () {}
    void processValueTree () {}

private:
    void valueTreePropertyChanged (juce::ValueTree& treeWhosePropertyHasChanged, const juce::Identifier& property) override
    {
        // Handle property changes if needed
    }
};