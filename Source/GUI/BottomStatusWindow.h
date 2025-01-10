#pragma once

#include <JuceHeader.h>
#include "../AppProperties.h"
#include "../BitBox/PresetManagerProperties.h"
//#include "SquidSalmple/BankList/BankListProperties.h"
#include "../BitBox/Audio/AudioPlayerProperties.h"

class BottomStatusWindow : public juce::Component
{
public:
    BottomStatusWindow ();
    void init (juce::ValueTree rootPropertiesVT);

private:
    AudioPlayerProperties audioPlayerProperties;
    AppProperties appProperties;
    PresetManagerProperties presetManagerProperties;
    juce::TextButton loadPresetButton;
    std::unique_ptr<juce::FileChooser> fileChooser;

    juce::Label statusLabel;
    juce::TextButton settingsButton;
    std::unique_ptr<juce::AlertWindow> settingsAlertWindow;

    void paint (juce::Graphics& g) override;
    void resized () override;
};
