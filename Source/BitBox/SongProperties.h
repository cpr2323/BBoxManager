#pragma once

#include <JuceHeader.h>
#include "../Utility/ValueTreeWrapper.h"

class SongProperties : public ValueTreeWrapper<SongProperties>
{
public:
    SongProperties () noexcept : ValueTreeWrapper<SongProperties> (SongTypeId) {}
    SongProperties (juce::ValueTree vt, WrapperType wrapperType, EnableCallbacks shouldEnableCallbacks)
        : ValueTreeWrapper<SongProperties> (SongTypeId, vt, wrapperType, shouldEnableCallbacks) {}

    void setGlobTempo (int globTempo, bool includeSelfCallback) { setValue (globTempo, GlobTempoPropertyId, includeSelfCallback); }
    int getGlobTempo () { return getValue<int> (GlobTempoPropertyId); }

    void setSongMode (int songMode, bool includeSelfCallback) { setValue (songMode, SongModePropertyId, includeSelfCallback); }
    int getSongMode () { return getValue<int> (SongModePropertyId); }

    void setSectCount (int sectCount, bool includeSelfCallback) { setValue (sectCount, SectCountPropertyId, includeSelfCallback); }
    int getSectCount () { return getValue<int> (SectCountPropertyId); }

    void setSectLoop (int sectLoop, bool includeSelfCallback) { setValue (sectLoop, SectLoopPropertyId, includeSelfCallback); }
    int getSectLoop () { return getValue<int> (SectLoopPropertyId); }

    void setSwing (int swing, bool includeSelfCallback) { setValue (swing, SwingPropertyId, includeSelfCallback); }
    int getSwing () { return getValue<int> (SwingPropertyId); }

    void setKeyMode (int keyMode, bool includeSelfCallback) { setValue (keyMode, KeyModePropertyId, includeSelfCallback); }
    int getKeyMode () { return getValue<int> (KeyModePropertyId); }

    void setKeyRoot (int keyRoot, bool includeSelfCallback) { setValue (keyRoot, KeyRootPropertyId, includeSelfCallback); }
    int getKeyRoot () { return getValue<int> (KeyRootPropertyId); }

    static inline const juce::Identifier SongTypeId { "Song" };
    static inline const juce::Identifier GlobTempoPropertyId { "globTempo" };
    static inline const juce::Identifier SongModePropertyId { "songMode" };
    static inline const juce::Identifier SectCountPropertyId { "sectCount" };
    static inline const juce::Identifier SectLoopPropertyId { "sectLoop" };
    static inline const juce::Identifier SwingPropertyId { "swing" };
    static inline const juce::Identifier KeyModePropertyId { "keyMode" };
    static inline const juce::Identifier KeyRootPropertyId { "keyRoot" };

    std::function<void (int globTempo)> onGlobTempoChange;
    std::function<void (int songMode)> onSongModeChange;
    std::function<void (int sectCount)> onSectCountChange;
    std::function<void (int sectLoop)> onSectLoopChange;
    std::function<void (int swing)> onSwingChange;
    std::function<void (int keyMode)> onKeyModeChange;
    std::function<void (int keyRoot)> onKeyRootChange;

    void copyPropertiesFrom (juce::ValueTree source)
    {
        SongProperties srcSongProperties { source, SongProperties::WrapperType::client, SongProperties::EnableCallbacks::no };
        setGlobTempo (srcSongProperties.getGlobTempo (), false);
        setSongMode (srcSongProperties.getSongMode (), false);
        setSectCount (srcSongProperties.getSectCount (), false);
        setSectLoop (srcSongProperties.getSectLoop (), false);
        setSwing (srcSongProperties.getSwing (), false);
        setKeyMode (srcSongProperties.getKeyMode (), false);
        setKeyRoot (srcSongProperties.getKeyRoot (), false);
    }

    void initValueTree () {}
    void processValueTree () {}

private:
    void valueTreePropertyChanged (juce::ValueTree& treeWhosePropertyHasChanged, const juce::Identifier& property) override
    {
        if (treeWhosePropertyHasChanged == data)
        {
            if (property == GlobTempoPropertyId && onGlobTempoChange != nullptr)
                onGlobTempoChange (getGlobTempo ());
            else if (property == SongModePropertyId && onSongModeChange != nullptr)
                onSongModeChange (getSongMode ());
            else if (property == SectCountPropertyId && onSectCountChange != nullptr)
                onSectCountChange (getSectCount ());
            else if (property == SectLoopPropertyId && onSectLoopChange != nullptr)
                onSectLoopChange (getSectLoop ());
            else if (property == SwingPropertyId && onSwingChange != nullptr)
                onSwingChange (getSwing ());
            else if (property == KeyModePropertyId && onKeyModeChange != nullptr)
                onKeyModeChange (getKeyMode ());
            else if (property == KeyRootPropertyId && onKeyRootChange != nullptr)
                onKeyRootChange (getKeyRoot ());
        }
    }
};