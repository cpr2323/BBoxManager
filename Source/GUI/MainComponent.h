#pragma once

#include <JuceHeader.h>
#include "BottomStatusWindow.h"
#include "CurrentFolderComponent.h"
#include "GuiProperties.h"
#include "BitBox/PresetEditorComponent.h"
//#include "SquidSalmple/FileView/FileViewComponent.h"
//#include "SquidSalmple/BankList/BankListComponent.h"
#include "../Utility/SplitWindowComponent.h"

class MainComponent : public juce::Component
{
public:
    MainComponent (juce::ValueTree rootPropertiesVT);
    ~MainComponent () = default;

private:
    GuiProperties guiProperties;
    PresetEditorComponent presetEditorComponent;
    BottomStatusWindow bottomStatusWindow;
    CurrentFolderComponent currentFolderComponent;
//    FileViewComponent fileViewComponent;
//    BankListComponent bankListComponent;
//    SplitWindowComponent bankListEditorSplitter;
//    SplitWindowComponent folderBrowserEditorSplitter;

    juce::TooltipWindow tooltipWindow;

    void restoreLayout ();
    void saveLayoutChanges ();

    void resized () override;
    void paint (juce::Graphics& g) override;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
