#pragma once

#include <JuceHeader.h>
#include "SampleEditorComponent.h"
#include "../../AppProperties.h"
#include "../../BitBox/Audio/AudioPlayerProperties.h"
#include "../../BitBox/PresetProperties.h"

class PresetEditorComponent : public juce::Component,
                              public juce::Timer
{
public:
    PresetEditorComponent ();

    void init (juce::ValueTree rootPropertiesVT);

private:
    AppProperties appProperties;
    AudioPlayerProperties audioPlayerProperties;
    PresetProperties presetProperties;
    PresetProperties uneditedPresetProperties;

    class TabbedComponentWithChangeCallback : public juce::TabbedComponent
    {
    public:
        TabbedComponentWithChangeCallback (juce::TabbedButtonBar::Orientation orientation) : juce::TabbedComponent (orientation) {}

        std::function<void (int)> onSelectedTabChanged;

    private:
        void currentTabChanged (int newTabIndex, const juce::String& tabName) override
        {
            if (onSelectedTabChanged != nullptr)
                onSelectedTabChanged (newTabIndex);
        }
    };

    juce::Label presetNameLabel;
    juce::TextEditor presetNameEditor;
    juce::TextButton saveButton;
    TabbedComponentWithChangeCallback padTabs { juce::TabbedButtonBar::Orientation::TabsAtTop };
    std::unique_ptr<juce::FileChooser> fileChooser;

    std::array<std::unique_ptr<SampleEditorComponent>, 8> padEditorComponents;

    void nameUiChanged (juce::String name);
    void nameDataChanged (juce::String name);

    void timerCallback () override;
    void resized () override;
    void paint (juce::Graphics& g) override;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PresetEditorComponent)
};