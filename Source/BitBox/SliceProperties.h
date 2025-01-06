#pragma once

#include <JuceHeader.h>
#include "../Utility/ValueTreeWrapper.h"

class SliceProperties : public ValueTreeWrapper<SliceProperties>
{
public:
    SliceProperties () noexcept : ValueTreeWrapper<SliceProperties> (SliceTypeId) {}
    SliceProperties (juce::ValueTree vt, WrapperType wrapperType, EnableCallbacks shouldEnableCallbacks)
        : ValueTreeWrapper<SliceProperties> (SliceTypeId, vt, wrapperType, shouldEnableCallbacks) {}

    void setSlicePos (int slicePos, bool includeSelfCallback) { setValue (slicePos, SlicePosPropertyId, includeSelfCallback); }
    int getSlicePos () const { return getValue<int> (SlicePosPropertyId); }

    static inline const juce::Identifier SliceTypeId { "Slice" };
    static inline const juce::Identifier SlicePosPropertyId { "slicePos" };

    std::function<void ()> onSliceListChange;

    void initValueTree () {}
    void processValueTree () {}

private:
    void valueTreePropertyChanged (juce::ValueTree& treeWhosePropertyHasChanged, const juce::Identifier& property) override
    {
        if (treeWhosePropertyHasChanged == data)
        {
            if (property == SlicePosPropertyId)
            {
                if (onSliceListChange != nullptr)
                    onSliceListChange ();
            }
        }
    }
};