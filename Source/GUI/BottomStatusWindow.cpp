#include "BottomStatusWindow.h"
#include "../BitBox/PresetProperties.h"
#include "../Utility/PersistentRootProperties.h"
#include "../Utility/RuntimeRootProperties.h"

// TODO - put this in an include
juce::ValueTree parse (juce::XmlElement* bitBoxPresetSessionElement);

BottomStatusWindow::BottomStatusWindow ()
{
    setOpaque (true);

    addAndMakeVisible (statusLabel);

    loadPresetButton.setButtonText ("Load");
    loadPresetButton.onClick = [this] ()
    {
        fileChooser.reset (new juce::FileChooser ("Load Preset",
                                                   appProperties.getMostRecentFolder (), ""));
        fileChooser->launchAsync (juce::FileBrowserComponent::openMode, [this] (const juce::FileChooser& fc) mutable
        {
            if (fc.getURLResults ().size () == 1 && fc.getURLResults () [0].isLocalFile ())
            {
                auto presetFile { fc.getURLResults () [0].getLocalFile () };
                if (presetFile.existsAsFile () && presetFile.getFileName () == "preset.xml")
                {
                    juce::Logger::outputDebugString ("Preset: " + presetFile.getParentDirectory ().getFullPathName ());
                    auto presetXmlDocument { juce::XmlDocument (presetFile).getDocumentElement () };
                    auto presetProperties { PresetProperties { parse (presetXmlDocument.get ()), PresetProperties::WrapperType::owner, PresetProperties::EnableCallbacks::no } };

                    // copy this into the unedited and the edited presets
                    PresetProperties uneditedPresetProperties { presetManagerProperties.getPreset ("unedited"), PresetProperties::WrapperType::client, PresetProperties::EnableCallbacks::no };
                    uneditedPresetProperties.copyPropertiesFrom (presetProperties.getValueTree ());
                    PresetProperties editedPresetProperties { presetManagerProperties.getPreset ("edit"), PresetProperties::WrapperType::client, PresetProperties::EnableCallbacks::no };
                    editedPresetProperties.copyPropertiesFrom (presetProperties.getValueTree ());
                    appProperties.setMostRecentFolder (fc.getURLResults () [0].getLocalFile ().getFullPathName ());
                }
            }
        }, nullptr);
    };
    addAndMakeVisible (loadPresetButton);

    settingsButton.setButtonText ("SETTINGS");
    settingsButton.onClick = [this] ()
    {
        audioPlayerProperties.showConfigDialog (false);
    };
    addAndMakeVisible (settingsButton);
}

void BottomStatusWindow::init (juce::ValueTree rootPropertiesVT)
{
    PersistentRootProperties persistentRootProperties (rootPropertiesVT, PersistentRootProperties::WrapperType::client, PersistentRootProperties::EnableCallbacks::no);
    appProperties.wrap (persistentRootProperties.getValueTree (), AppProperties::WrapperType::client, AppProperties::EnableCallbacks::yes);

    RuntimeRootProperties runtimeRootProperties (rootPropertiesVT, RuntimeRootProperties::WrapperType::client, RuntimeRootProperties::EnableCallbacks::no);
    presetManagerProperties.wrap (runtimeRootProperties.getValueTree (), PresetManagerProperties::WrapperType::client, PresetManagerProperties::EnableCallbacks::yes);
    audioPlayerProperties.wrap (runtimeRootProperties.getValueTree (), AudioPlayerProperties::WrapperType::owner, AudioPlayerProperties::EnableCallbacks::yes);
//    bankListProperties.wrap (runtimeRootProperties.getValueTree (), BankListProperties::WrapperType::client, BankListProperties::EnableCallbacks::yes);
//    bankListProperties.onStatusChange = [this] (juce::String status)
//     {
//         juce::MessageManager::callAsync ([this, status] ()
//         {
//             statusLabel.setText (status, juce::NotificationType::dontSendNotification);
//         });
//     };
}

void BottomStatusWindow::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colours::black);
    g.setColour (juce::Colours::white);
    g.drawRect (getLocalBounds (), 1);
}

void BottomStatusWindow::resized ()
{
    auto localBounds { getLocalBounds () };
    localBounds.reduce (5, 3);
    statusLabel.setBounds (localBounds);
    const auto buttonWidth { 70 };
    settingsButton.setBounds (getWidth () - 5 - buttonWidth, getHeight () / 2 - 10, buttonWidth, 20);
    loadPresetButton.setBounds (settingsButton.getX () - 5 - buttonWidth, getHeight () / 2 - 10, buttonWidth, 20);
}
