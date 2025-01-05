#pragma once

#include <JuceHeader.h>
#include "../Utility/ValueTreeWrapper.h"

class DelayProperties : public ValueTreeWrapper<DelayProperties>
{
public:
    DelayProperties () noexcept : ValueTreeWrapper<DelayProperties> (DelayTypeId) {}
    DelayProperties (juce::ValueTree vt, WrapperType wrapperType, EnableCallbacks shouldEnableCallbacks)
        : ValueTreeWrapper<DelayProperties> (DelayTypeId, vt, wrapperType, shouldEnableCallbacks) {}

    void setDelay (int delay, bool includeSelfCallback) { setValue (delay, DelayPropertyId, includeSelfCallback); }
    int getDelay () { return getValue<int> (DelayPropertyId); }

    void setDelayMusTime (int delayMusTime, bool includeSelfCallback) { setValue (delayMusTime, DelayMusTimePropertyId, includeSelfCallback); }
    int getDelayMusTime () { return getValue<int> (DelayMusTimePropertyId); }

    void setFeedback (int feedback, bool includeSelfCallback) { setValue (feedback, FeedbackPropertyId, includeSelfCallback); }
    int getFeedback () { return getValue<int> (FeedbackPropertyId); }

    void setCutoff (int cutoff, bool includeSelfCallback) { setValue (cutoff, CutoffPropertyId, includeSelfCallback); }
    int getCutoff () { return getValue<int> (CutoffPropertyId); }

    void setFiltQuality (int filtQuality, bool includeSelfCallback) { setValue (filtQuality, FiltQualityPropertyId, includeSelfCallback); }
    int getFiltQuality () { return getValue<int> (FiltQualityPropertyId); }

    void setDelayBeatSync (int delayBeatSync, bool includeSelfCallback) { setValue (delayBeatSync, DelayBeatSyncPropertyId, includeSelfCallback); }
    int getDelayBeatSync () { return getValue<int> (DelayBeatSyncPropertyId); }

    void setFiltEnable (int filtEnable, bool includeSelfCallback) { setValue (filtEnable, FiltEnablePropertyId, includeSelfCallback); }
    int getFiltEnable () { return getValue<int> (FiltEnablePropertyId); }

    void setDelayPingPong (int delayPingPong, bool includeSelfCallback) { setValue (delayPingPong, DelayPingPongPropertyId, includeSelfCallback); }
    int getDelayPingPong () { return getValue<int> (DelayPingPongPropertyId); }

    static inline const juce::Identifier DelayTypeId { "Delay" };
    static inline const juce::Identifier DelayPropertyId { "delay" };
    static inline const juce::Identifier DelayMusTimePropertyId { "delayMusTime" };
    static inline const juce::Identifier FeedbackPropertyId { "feedback" };
    static inline const juce::Identifier CutoffPropertyId { "cutoff" };
    static inline const juce::Identifier FiltQualityPropertyId { "filtQuality" };
    static inline const juce::Identifier DelayBeatSyncPropertyId { "delayBeatSync" };
    static inline const juce::Identifier FiltEnablePropertyId { "filtEnable" };
    static inline const juce::Identifier DelayPingPongPropertyId { "delayPingPong" };

    std::function<void (int delay)> onDelayChange;
    std::function<void (int delayMusTime)> onDelayMusTimeChange;
    std::function<void (int feedback)> onFeedbackChange;
    std::function<void (int cutoff)> onCutoffChange;
    std::function<void (int filtQuality)> onFiltQualityChange;
    std::function<void (int delayBeatSync)> onDelayBeatSyncChange;
    std::function<void (int filtEnable)> onFiltEnableChange;
    std::function<void (int delayPingPong)> onDelayPingPongChange;

    void initValueTree () {}
    void processValueTree () {}

private:
    void valueTreePropertyChanged (juce::ValueTree& treeWhosePropertyHasChanged, const juce::Identifier& property) override
    {
        if (treeWhosePropertyHasChanged == data)
        {
            if (property == DelayPropertyId)
            {
                if (onDelayChange != nullptr)
                    onDelayChange (getDelay ());
            }
            else if (property == DelayMusTimePropertyId)
            {
                if (onDelayMusTimeChange != nullptr)
                    onDelayMusTimeChange (getDelayMusTime ());
            }
            else if (property == FeedbackPropertyId)
            {
                if (onFeedbackChange != nullptr)
                    onFeedbackChange (getFeedback ());
            }
            else if (property == CutoffPropertyId)
            {
                if (onCutoffChange != nullptr)
                    onCutoffChange (getCutoff ());
            }
            else if (property == FiltQualityPropertyId)
            {
                if (onFiltQualityChange != nullptr)
                    onFiltQualityChange (getFiltQuality ());
            }
            else if (property == DelayBeatSyncPropertyId)
            {
                if (onDelayBeatSyncChange != nullptr)
                    onDelayBeatSyncChange (getDelayBeatSync ());
            }
            else if (property == FiltEnablePropertyId)
            {
                if (onFiltEnableChange != nullptr)
                    onFiltEnableChange (getFiltEnable ());
            }
            else if (property == DelayPingPongPropertyId)
            {
                if (onDelayPingPongChange != nullptr)
                    onDelayPingPongChange (getDelayPingPong ());
            }
        }
    }
};