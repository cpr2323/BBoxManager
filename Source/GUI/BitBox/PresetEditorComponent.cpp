#include "PresetEditorComponent.h"
#include "../../BitBox/PresetManagerProperties.h"
#include "../../Utility/PersistentRootProperties.h"
#include "../../Utility/RuntimeRootProperties.h"

PresetEditorComponent::PresetEditorComponent ()
    : padTabs (juce::TabbedButtonBar::TabsAtTop)
{
    addAndMakeVisible (presetNameLabel);
    presetNameLabel.setText ("Preset Name:", juce::dontSendNotification);

    addAndMakeVisible (presetNameEditor);
    presetNameEditor.setText ("Preset Name");

    for (int i = 0; i < 8; ++i)
    {
        padEditorComponents [i] = std::make_unique<SampleEditorComponent> ();
        padTabs.addTab ("Pad " + juce::String (i + 1), juce::Colours::lightgrey, padEditorComponents [i].get (), false);
    }

    addAndMakeVisible (padTabs);

    saveButton.setButtonText ("Save");
    addChildComponent (saveButton);

    startTimer (1000); // Check every second
}

void PresetEditorComponent::init (juce::ValueTree rootPropertiesVT)
{
    PersistentRootProperties persistentRootProperties (rootPropertiesVT, PersistentRootProperties::WrapperType::client, PersistentRootProperties::EnableCallbacks::no);
    appProperties.wrap (persistentRootProperties.getValueTree (), AppProperties::WrapperType::client, AppProperties::EnableCallbacks::yes);

    RuntimeRootProperties runtimeRootProperties (rootPropertiesVT, RuntimeRootProperties::WrapperType::client, RuntimeRootProperties::EnableCallbacks::no);
    PresetManagerProperties presetManagerProperties { runtimeRootProperties.getValueTree (), PresetManagerProperties::WrapperType::client, PresetManagerProperties::EnableCallbacks::no };
    uneditedPresetProperties.wrap (presetManagerProperties.getPreset ("unedited"), PresetProperties::WrapperType::client, PresetProperties::EnableCallbacks::yes);
    presetProperties.wrap (presetManagerProperties.getPreset ("edit"), PresetProperties::WrapperType::client, PresetProperties::EnableCallbacks::yes);
    audioPlayerProperties.wrap (runtimeRootProperties.getValueTree (), AudioPlayerProperties::WrapperType::client, AudioPlayerProperties::EnableCallbacks::yes);

    // TODO - this is failing, because there are no Cells in the preset yet
    //        so, when a preset is loaded there are no callbacks from forEachPad
    presetProperties.forEachPad ([this] (juce::ValueTree padPropertiesVT, int padIndex)
    {
        padEditorComponents[padIndex]->init (padPropertiesVT);
        return true;
    });
}

void PresetEditorComponent::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colours::white);
}

void PresetEditorComponent::resized ()
{
    auto area = getLocalBounds ();
    auto headerArea = area.removeFromTop (30).reduced (10);
    presetNameLabel.setBounds (headerArea.removeFromLeft (100));
    presetNameEditor.setBounds (headerArea.removeFromLeft (200));
    saveButton.setBounds (headerArea.removeFromRight (100));
    padTabs.setBounds (area.reduced (10));
}

void PresetEditorComponent::timerCallback ()
{
    // Compare edited and unedited copies to enable/disable the save button
    // saveButton.setEnabled(...);
}

void PresetEditorComponent::nameUiChanged (juce::String name)
{
    presetProperties.setName (name, true);
}

void PresetEditorComponent::nameDataChanged (juce::String name)
{
    presetNameEditor.setText (name, juce::NotificationType::dontSendNotification);
}