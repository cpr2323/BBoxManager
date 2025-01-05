#pragma once

#include "../Utility/ValueTreeWrapper.h"

// ReverbProperties
class ReverbProperties : public ValueTreeWrapper<ReverbProperties>
{
public:
    ReverbProperties () noexcept : ValueTreeWrapper<ReverbProperties> (ReverbTypeId) {}
    ReverbProperties (juce::ValueTree vt, WrapperType wrapperType, EnableCallbacks shouldEnableCallbacks)
        : ValueTreeWrapper<ReverbProperties> (ReverbTypeId, vt, wrapperType, shouldEnableCallbacks) {}

    void setDecay (int decay, bool includeSelfCallback) { setValue (decay, DecayPropertyId, includeSelfCallback); }
    int getDecay () { return getValue<int> (DecayPropertyId); }

    void setPreDelay (int preDelay, bool includeSelfCallback) { setValue (preDelay, PreDelayPropertyId, includeSelfCallback); }
    int getPreDelay () { return getValue<int> (PreDelayPropertyId); }

    void setDamping (int damping, bool includeSelfCallback) { setValue (damping, DampingPropertyId, includeSelfCallback); }
    int getDamping () { return getValue<int> (DampingPropertyId); }

    std::function<void (int decay)> onDecayChange;
    std::function<void (int preDelay)> onPreDelayChange;
    std::function<void (int damping)> onDampingChange;

    static inline const juce::Identifier ReverbTypeId { "Reverb" };
    static inline const juce::Identifier DecayPropertyId { "decay" };
    static inline const juce::Identifier PreDelayPropertyId { "preDelay" };
    static inline const juce::Identifier DampingPropertyId { "damping" };

    void initValueTree () {}
    void processValueTree () {}

private:
    void valueTreePropertyChanged (juce::ValueTree& treeWhosePropertyHasChanged, const juce::Identifier& property) override
    {
        if (treeWhosePropertyHasChanged == data)
        {
            if (property == DecayPropertyId)
            {
                if (onDecayChange != nullptr)
                    onDecayChange (getDecay ());
            }
            else if (property == PreDelayPropertyId)
            {
                if (onPreDelayChange != nullptr)
                    onPreDelayChange (getPreDelay ());
            }
            else if (property == DampingPropertyId)
            {
                if (onDampingChange != nullptr)
                    onDampingChange (getDamping ());
            }
        }
    }
};