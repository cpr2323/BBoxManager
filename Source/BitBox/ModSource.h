#pragma once

#include <JuceHeader.h>
#include "../Utility/ValueTreeWrapper.h"

class ModSourceProperties : public ValueTreeWrapper<ModSourceProperties>
{
public:
    ModSourceProperties () noexcept : ValueTreeWrapper<ModSourceProperties> (ModSourceTypeId) {}
    ModSourceProperties (juce::ValueTree vt, WrapperType wrapperType, EnableCallbacks shouldEnableCallbacks)
        : ValueTreeWrapper<ModSourceProperties> (ModSourceTypeId, vt, wrapperType, shouldEnableCallbacks) {}

    void setModDest (juce::String modDest, bool includeSelfCallback) { setValue (modDest, ModDestPropertyId, includeSelfCallback); }
    juce::String getModDest () { return getValue<juce::String> (ModDestPropertyId); }

    void setModSrc (juce::String modSrc, bool includeSelfCallback) { setValue (modSrc, ModSrcPropertyId, includeSelfCallback); }
    juce::String getModSrc () { return getValue<juce::String> (ModSrcPropertyId); }

    void setModSlot (int modSlot, bool includeSelfCallback) { setValue (modSlot, ModSlotPropertyId, includeSelfCallback); }
    int getModSlot () { return getValue<int> (ModSlotPropertyId); }

    void setModAmount (int modAmount, bool includeSelfCallback) { setValue (modAmount, ModAmountPropertyId, includeSelfCallback); }
    int getModAmount () { return getValue<int> (ModAmountPropertyId); }

    static inline const juce::Identifier ModSourceTypeId { "ModSource" };
    static inline const juce::Identifier ModDestPropertyId { "modDest" };
    static inline const juce::Identifier ModSrcPropertyId { "modSrc" };
    static inline const juce::Identifier ModSlotPropertyId { "modSlot" };
    static inline const juce::Identifier ModAmountPropertyId { "modAmount" };

    std::function<void (juce::String modDest)> onModDestChange;
    std::function<void (juce::String modSrc)> onModSrcChange;
    std::function<void (int modSlot)> onModSlotChange;
    std::function<void (int modAmount)> onModAmountChange;

    void initValueTree () {}
    void processValueTree () {}

private:
    void valueTreePropertyChanged (juce::ValueTree& treeWhosePropertyHasChanged, const juce::Identifier& property) override
    {
        if (treeWhosePropertyHasChanged == data)
        {
            if (property == ModDestPropertyId)
            {
                if (onModDestChange != nullptr)
                    onModDestChange (getModDest ());
            }
            else if (property == ModSrcPropertyId)
            {
                if (onModSrcChange != nullptr)
                    onModSrcChange (getModSrc ());
            }
            else if (property == ModSlotPropertyId)
            {
                if (onModSlotChange != nullptr)
                    onModSlotChange (getModSlot ());
            }
            else if (property == ModAmountPropertyId)
            {
                if (onModAmountChange != nullptr)
                    onModAmountChange (getModAmount ());
            }
        }
    }
};