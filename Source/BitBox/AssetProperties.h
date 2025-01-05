#pragma once

#include <JuceHeader.h>
#include "../Utility/ValueTreeWrapper.h"

class AssetProperties : public ValueTreeWrapper<AssetProperties>
{
public:
    AssetProperties () noexcept : ValueTreeWrapper<AssetProperties> (AssetTypeId) {}
    AssetProperties (juce::ValueTree vt, WrapperType wrapperType, EnableCallbacks shouldEnableCallbacks)
        : ValueTreeWrapper<AssetProperties> (AssetTypeId, vt, wrapperType, shouldEnableCallbacks) {}

    void setFileName (juce::String fileName, bool includeSelfCallback) { setValue (fileName, FileNamePropertyId, includeSelfCallback); }
    juce::String getFileName () { return getValue<juce::String> (FileNamePropertyId); }

    void setRootNote (int rootNote, bool includeSelfCallback) { setValue (rootNote, RootNotePropertyId, includeSelfCallback); }
    int getRootNote () { return getValue<int> (RootNotePropertyId); }

    void setKeyRangeBottom (int keyRangeBottom, bool includeSelfCallback) { setValue (keyRangeBottom, KeyRangeBottomPropertyId, includeSelfCallback); }
    int getKeyRangeBottom () { return getValue<int> (KeyRangeBottomPropertyId); }

    void setKeyRangeTop (int keyRangeTop, bool includeSelfCallback) { setValue (keyRangeTop, KeyRangeTopPropertyId, includeSelfCallback); }
    int getKeyRangeTop () { return getValue<int> (KeyRangeTopPropertyId); }

    void setAssSrcRow (int assSrcRow, bool includeSelfCallback) { setValue (assSrcRow, AssSrcRowPropertyId, includeSelfCallback); }
    int getAssSrcRow () { return getValue<int> (AssSrcRowPropertyId); }

    void setAssSrcCol (int assSrcCol, bool includeSelfCallback) { setValue (assSrcCol, AssSrcColPropertyId, includeSelfCallback); }
    int getAssSrcCol () { return getValue<int> (AssSrcColPropertyId); }

    static inline const juce::Identifier AssetTypeId { "Asset" };
    static inline const juce::Identifier FileNamePropertyId { "fileName" };
    static inline const juce::Identifier RootNotePropertyId { "rootNote" };
    static inline const juce::Identifier KeyRangeBottomPropertyId { "keyRangeBottom" };
    static inline const juce::Identifier KeyRangeTopPropertyId { "keyRangeTop" };
    static inline const juce::Identifier AssSrcRowPropertyId { "assSrcRow" };
    static inline const juce::Identifier AssSrcColPropertyId { "assSrcCol" };

    std::function<void (juce::String fileName)> onFileNameChange;
    std::function<void (int rootNote)> onRootNoteChange;
    std::function<void (int keyRangeBottom)> onKeyRangeBottomChange;
    std::function<void (int keyRangeTop)> onKeyRangeTopChange;
    std::function<void (int assSrcRow)> onAssSrcRowChange;
    std::function<void (int assSrcCol)> onAssSrcColChange;

    void initValueTree () {}
    void processValueTree () {}

private:
    void valueTreePropertyChanged (juce::ValueTree& treeWhosePropertyHasChanged, const juce::Identifier& property) override
    {
        if (treeWhosePropertyHasChanged == data)
        {
            if (property == FileNamePropertyId && onFileNameChange != nullptr)
                onFileNameChange (getFileName ());
            else if (property == RootNotePropertyId && onRootNoteChange != nullptr)
                onRootNoteChange (getRootNote ());
            else if (property == KeyRangeBottomPropertyId && onKeyRangeBottomChange != nullptr)
                onKeyRangeBottomChange (getKeyRangeBottom ());
            else if (property == KeyRangeTopPropertyId && onKeyRangeTopChange != nullptr)
                onKeyRangeTopChange (getKeyRangeTop ());
            else if (property == AssSrcRowPropertyId && onAssSrcRowChange != nullptr)
                onAssSrcRowChange (getAssSrcRow ());
            else if (property == AssSrcColPropertyId && onAssSrcColChange != nullptr)
                onAssSrcColChange (getAssSrcCol ());
        }
    }
};