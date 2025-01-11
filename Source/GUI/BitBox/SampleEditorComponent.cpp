#include "SampleEditorComponent.h"

SampleEditorComponent::SampleEditorComponent ()
{
    addAndMakeVisible (fileNameLabel);
    fileNameLabel.setText ("File Name", juce::dontSendNotification);
    addAndMakeVisible (fileNameSelectLabel);

    addAndMakeVisible (gainLabel);
    gainLabel.setText ("Gain (dB)", juce::dontSendNotification);
    addAndMakeVisible (gainTextEditor);

    addAndMakeVisible (pitchLabel);
    pitchLabel.setText ("Pitch", juce::dontSendNotification);
    addAndMakeVisible (pitchTextEditor);

    addAndMakeVisible (panPosLabel);
    panPosLabel.setText ("Pan Position", juce::dontSendNotification);
    addAndMakeVisible (panPosTextEditor);

    addAndMakeVisible (samTrigTypeLabel);
    samTrigTypeLabel.setText ("Sample Trigger Type", juce::dontSendNotification);
    addAndMakeVisible (samTrigTypeTextEditor);

    addAndMakeVisible (loopModeLabel);
    loopModeLabel.setText ("Loop Mode", juce::dontSendNotification);
    addAndMakeVisible (loopModeComboBox);

    addAndMakeVisible (loopModesLabel);
    loopModesLabel.setText ("Loop Modes", juce::dontSendNotification);
    addAndMakeVisible (loopModesTextEditor);

    addAndMakeVisible (midiModeLabel);
    midiModeLabel.setText ("MIDI Mode", juce::dontSendNotification);
    addAndMakeVisible (midiModeTextEditor);

    addAndMakeVisible (reverseLabel);
    reverseLabel.setText ("Reverse", juce::dontSendNotification);
    addAndMakeVisible (reverseButton);

    addAndMakeVisible (cellModeLabel);
    cellModeLabel.setText ("Cell Mode", juce::dontSendNotification);
    addAndMakeVisible (cellModeTextEditor);

    addAndMakeVisible (envAttackLabel);
    envAttackLabel.setText ("Attack", juce::dontSendNotification);
    addAndMakeVisible (envAttackTextEditor);

    addAndMakeVisible (envDecayLabel);
    envDecayLabel.setText ("Decay", juce::dontSendNotification);
    addAndMakeVisible (envDecayTextEditor);

    addAndMakeVisible (envSusLabel);
    envSusLabel.setText ("Sustain", juce::dontSendNotification);
    addAndMakeVisible (envSusTextEditor);

    addAndMakeVisible (envRelLabel);
    envRelLabel.setText ("Release", juce::dontSendNotification);
    addAndMakeVisible (envRelTextEditor);

    addAndMakeVisible (samStartLabel);
    samStartLabel.setText ("Sample Start", juce::dontSendNotification);
    addAndMakeVisible (samStartTextEditor);

    addAndMakeVisible (samLenLabel);
    samLenLabel.setText ("Sample Length", juce::dontSendNotification);
    addAndMakeVisible (samLenTextEditor);

    addAndMakeVisible (loopStartLabel);
    loopStartLabel.setText ("Loop Start", juce::dontSendNotification);
    addAndMakeVisible (loopStartTextEditor);

    addAndMakeVisible (loopEndLabel);
    loopEndLabel.setText ("Loop End", juce::dontSendNotification);
    addAndMakeVisible (loopEndTextEditor);

    addAndMakeVisible (quantSizeLabel);
    quantSizeLabel.setText ("Quant Size", juce::dontSendNotification);
    addAndMakeVisible (quantSizeTextEditor);

    addAndMakeVisible (syncTypeLabel);
    syncTypeLabel.setText ("Sync Type", juce::dontSendNotification);
    addAndMakeVisible (syncTypeTextEditor);

    addAndMakeVisible (actSliceLabel);
    actSliceLabel.setText ("Active Slice", juce::dontSendNotification);
    addAndMakeVisible (actSliceTextEditor);

    addAndMakeVisible (outputBusLabel);
    outputBusLabel.setText ("Output Bus", juce::dontSendNotification);
    addAndMakeVisible (outputBusTextEditor);

    addAndMakeVisible (polyModeLabel);
    polyModeLabel.setText ("Poly Mode", juce::dontSendNotification);
    addAndMakeVisible (polyModeTextEditor);

    addAndMakeVisible (polyModeSliceLabel);
    polyModeSliceLabel.setText ("Poly Mode Slice", juce::dontSendNotification);
    addAndMakeVisible (polyModeSliceTextEditor);

    addAndMakeVisible (sliceStepModeLabel);
    sliceStepModeLabel.setText ("Slice Step Mode", juce::dontSendNotification);
    addAndMakeVisible (sliceStepModeTextEditor);

    addAndMakeVisible (chokeGrpLabel);
    chokeGrpLabel.setText ("Choke Group", juce::dontSendNotification);
    addAndMakeVisible (chokeGrpTextEditor);

    addAndMakeVisible (dualFilCutoffLabel);
    dualFilCutoffLabel.setText ("Dual Filter Cutoff", juce::dontSendNotification);
    addAndMakeVisible (dualFilCutoffTextEditor);

    addAndMakeVisible (resLabel);
    resLabel.setText ("Resonance", juce::dontSendNotification);
    addAndMakeVisible (resTextEditor);

    addAndMakeVisible (rootNoteLabel);
    rootNoteLabel.setText ("Root Note", juce::dontSendNotification);
    addAndMakeVisible (rootNoteTextEditor);

    addAndMakeVisible (beatCountLabel);
    beatCountLabel.setText ("Beat Count", juce::dontSendNotification);
    addAndMakeVisible (beatCountTextEditor);

    addAndMakeVisible (fx1SendLabel);
    fx1SendLabel.setText ("FX1 Send", juce::dontSendNotification);
    addAndMakeVisible (fx1SendTextEditor);

    addAndMakeVisible (fx2SendLabel);
    fx2SendLabel.setText ("FX2 Send", juce::dontSendNotification);
    addAndMakeVisible (fx2SendTextEditor);

    addAndMakeVisible (multiSamModeLabel);
    multiSamModeLabel.setText ("Multi Sample Mode", juce::dontSendNotification);
    addAndMakeVisible (multiSamModeTextEditor);

    addAndMakeVisible (interpQualLabel);
    interpQualLabel.setText ("Interpolation Quality", juce::dontSendNotification);
    addAndMakeVisible (interpQualTextEditor);

    addAndMakeVisible (playThruLabel);
    playThruLabel.setText ("Play Through", juce::dontSendNotification);
    addAndMakeVisible (playThruTextEditor);

    addAndMakeVisible (slicerQuantSizeLabel);
    slicerQuantSizeLabel.setText ("Slicer Quant Size", juce::dontSendNotification);
    addAndMakeVisible (slicerQuantSizeTextEditor);

    addAndMakeVisible (slicerSyncLabel);
    slicerSyncLabel.setText ("Slicer Sync", juce::dontSendNotification);
    addAndMakeVisible (slicerSyncTextEditor);

    addAndMakeVisible (padNoteLabel);
    padNoteLabel.setText ("Pad Note", juce::dontSendNotification);
    addAndMakeVisible (padNoteTextEditor);

    addAndMakeVisible (loopFadeAmtLabel);
    loopFadeAmtLabel.setText ("Loop Fade Amount", juce::dontSendNotification);
    addAndMakeVisible (loopFadeAmtTextEditor);

    addAndMakeVisible (lfoWaveLabel);
    lfoWaveLabel.setText ("LFO Wave", juce::dontSendNotification);
    addAndMakeVisible (lfoWaveTextEditor);

    addAndMakeVisible (lfoRateLabel);
    lfoRateLabel.setText ("LFO Rate", juce::dontSendNotification);
    addAndMakeVisible (lfoRateTextEditor);

    addAndMakeVisible (lfoAmountLabel);
    lfoAmountLabel.setText ("LFO Amount", juce::dontSendNotification);
    addAndMakeVisible (lfoAmountTextEditor);

    addAndMakeVisible (lfoKeyTrigLabel);
    lfoKeyTrigLabel.setText ("LFO Key Trigger", juce::dontSendNotification);
    addAndMakeVisible (lfoKeyTrigTextEditor);

    addAndMakeVisible (lfoBeatSyncLabel);
    lfoBeatSyncLabel.setText ("LFO Beat Sync", juce::dontSendNotification);
    addAndMakeVisible (lfoBeatSyncTextEditor);

    addAndMakeVisible (lfoRateBeatSyncLabel);
    lfoRateBeatSyncLabel.setText ("LFO Rate Beat Sync", juce::dontSendNotification);
    addAndMakeVisible (lfoRateBeatSyncTextEditor);

    addAndMakeVisible (grainSizePercLabel);
    grainSizePercLabel.setText ("Grain Size Percentage", juce::dontSendNotification);
    addAndMakeVisible (grainSizePercTextEditor);

    addAndMakeVisible (grainScatLabel);
    grainScatLabel.setText ("Grain Scatter", juce::dontSendNotification);
    addAndMakeVisible (grainScatTextEditor);

    addAndMakeVisible (grainPanRndLabel);
    grainPanRndLabel.setText ("Grain Pan Random", juce::dontSendNotification);
    addAndMakeVisible (grainPanRndTextEditor);

    addAndMakeVisible (grainDensityLabel);
    grainDensityLabel.setText ("Grain Density", juce::dontSendNotification);
    addAndMakeVisible (grainDensityTextEditor);

    addAndMakeVisible (sliceModeLabel);
    sliceModeLabel.setText ("Slice Mode", juce::dontSendNotification);
    addAndMakeVisible (sliceModeTextEditor);

    addAndMakeVisible (legatoModeLabel);
    legatoModeLabel.setText ("Legato Mode", juce::dontSendNotification);
    addAndMakeVisible (legatoModeTextEditor);

    addAndMakeVisible (gainSsrcWinLabel);
    gainSsrcWinLabel.setText ("Gain SSRC Window", juce::dontSendNotification);
    addAndMakeVisible (gainSsrcWinTextEditor);

    addAndMakeVisible (grainReadSpeedLabel);
    grainReadSpeedLabel.setText ("Grain Read Speed", juce::dontSendNotification);
    addAndMakeVisible (grainReadSpeedTextEditor);

    addAndMakeVisible (recPresetLenLabel);
    recPresetLenLabel.setText ("Record Preset Length", juce::dontSendNotification);
    addAndMakeVisible (recPresetLenTextEditor);

    addAndMakeVisible (recQuantLabel);
    recQuantLabel.setText ("Record Quantization", juce::dontSendNotification);
    addAndMakeVisible (recQuantTextEditor);

    addAndMakeVisible (recInputLabel);
    recInputLabel.setText ("Record Input", juce::dontSendNotification);
    addAndMakeVisible (recInputTextEditor);

    addAndMakeVisible (recUseThresLabel);
    recUseThresLabel.setText ("Record Use Threshold", juce::dontSendNotification);
    addAndMakeVisible (recUseThresTextEditor);

    addAndMakeVisible (recThresLabel);
    recThresLabel.setText ("Record Threshold", juce::dontSendNotification);
    addAndMakeVisible (recThresTextEditor);

    addAndMakeVisible (recMonOutBusLabel);
    recMonOutBusLabel.setText ("Record Monitor Output Bus", juce::dontSendNotification);
    addAndMakeVisible (recMonOutBusTextEditor);
}

SampleEditorComponent::~SampleEditorComponent ()
{
}

void SampleEditorComponent::init (juce::ValueTree samplePropertiesVT)
{
    sampleProperties.wrap (samplePropertiesVT, SampleProperties::WrapperType::client, SampleProperties::EnableCallbacks::yes);

    // Initialize other components and callbacks here
}

bool SampleEditorComponent::loadFile (juce::String sampleFileName)
{
    // Implement file loading logic here
    return true;
}

juce::ValueTree SampleEditorComponent::getSamplePropertiesVT ()
{
    return sampleProperties.getValueTree ();
}

void SampleEditorComponent::gainDataChanged (int gain) { /* Implement data change logic */ }
void SampleEditorComponent::pitchDataChanged (int pitch) { /* Implement data change logic */ }
void SampleEditorComponent::panPosDataChanged (int panPos) { /* Implement data change logic */ }
void SampleEditorComponent::samTrigTypeDataChanged (int samTrigType) { /* Implement data change logic */ }
void SampleEditorComponent::loopModeDataChanged (int loopMode) { /* Implement data change logic */ }
void SampleEditorComponent::loopModesDataChanged (int loopModes) { /* Implement data change logic */ }
void SampleEditorComponent::midiModeDataChanged (int midiMode) { /* Implement data change logic */ }
void SampleEditorComponent::reverseDataChanged (int reverse) { /* Implement data change logic */ }
void SampleEditorComponent::cellModeDataChanged (int cellMode) { /* Implement data change logic */ }
void SampleEditorComponent::envAttackDataChanged (int envAttack) { /* Implement data change logic */ }
void SampleEditorComponent::envDecayDataChanged (int envDecay) { /* Implement data change logic */ }
void SampleEditorComponent::envSusDataChanged (int envSus) { /* Implement data change logic */ }
void SampleEditorComponent::envRelDataChanged (int envRel) { /* Implement data change logic */ }
void SampleEditorComponent::samStartDataChanged (int samStart) { /* Implement data change logic */ }
void SampleEditorComponent::samLenDataChanged (int samLen) { /* Implement data change logic */ }
void SampleEditorComponent::loopStartDataChanged (int loopStart) { /* Implement data change logic */ }
void SampleEditorComponent::loopEndDataChanged (int loopEnd) { /* Implement data change logic */ }
void SampleEditorComponent::quantSizeDataChanged (int quantSize) { /* Implement data change logic */ }
void SampleEditorComponent::syncTypeDataChanged (int syncType) { /* Implement data change logic */ }
void SampleEditorComponent::actSliceDataChanged (int actSlice) { /* Implement data change logic */ }
void SampleEditorComponent::outputBusDataChanged (int outputBus) { /* Implement data change logic */ }
void SampleEditorComponent::polyModeDataChanged (int polyMode) { /* Implement data change logic */ }
void SampleEditorComponent::polyModeSliceDataChanged (int polyModeSlice) { /* Implement data change logic */ }
void SampleEditorComponent::sliceStepModeDataChanged (int sliceStepMode) { /* Implement data change logic */ }
void SampleEditorComponent::chokeGrpDataChanged (int chokeGrp) { /* Implement data change logic */ }
void SampleEditorComponent::dualFilCutoffDataChanged (int dualFilCutoff) { /* Implement data change logic */ }
void SampleEditorComponent::resDataChanged (int res) { /* Implement data change logic */ }
void SampleEditorComponent::rootNoteDataChanged (int rootNote) { /* Implement data change logic */ }
void SampleEditorComponent::beatCountDataChanged (int beatCount) { /* Implement data change logic */ }
void SampleEditorComponent::fx1SendDataChanged (int fx1Send) { /* Implement data change logic */ }
void SampleEditorComponent::fx2SendDataChanged (int fx2Send) { /* Implement data change logic */ }
void SampleEditorComponent::multiSamModeDataChanged (int multiSamMode) { /* Implement data change logic */ }
void SampleEditorComponent::interpQualDataChanged (int interpQual) { /* Implement data change logic */ }
void SampleEditorComponent::playThruDataChanged (int playThru) { /* Implement data change logic */ }
void SampleEditorComponent::slicerQuantSizeDataChanged (int slicerQuantSize) { /* Implement data change logic */ }
void SampleEditorComponent::slicerSyncDataChanged (int slicerSync) { /* Implement data change logic */ }
void SampleEditorComponent::padNoteDataChanged (int padNote) { /* Implement data change logic */ }
void SampleEditorComponent::loopFadeAmtDataChanged (int loopFadeAmt) { /* Implement data change logic */ }
void SampleEditorComponent::lfoWaveDataChanged (int lfoWave) { /* Implement data change logic */ }
void SampleEditorComponent::lfoRateDataChanged (int lfoRate) { /* Implement data change logic */ }
void SampleEditorComponent::lfoAmountDataChanged (int lfoAmount) { /* Implement data change logic */ }
void SampleEditorComponent::lfoKeyTrigDataChanged (int lfoKeyTrig) { /* Implement data change logic */ }
void SampleEditorComponent::lfoBeatSyncDataChanged (int lfoBeatSync) { /* Implement data change logic */ }
void SampleEditorComponent::lfoRateBeatSyncDataChanged (int lfoRateBeatSync) { /* Implement data change logic */ }
void SampleEditorComponent::grainSizePercDataChanged (int grainSizePerc) { /* Implement data change logic */ }
void SampleEditorComponent::grainScatDataChanged (int grainScat) { /* Implement data change logic */ }
void SampleEditorComponent::grainPanRndDataChanged (int grainPanRnd) { /* Implement data change logic */ }
void SampleEditorComponent::grainDensityDataChanged (int grainDensity) { /* Implement data change logic */ }
void SampleEditorComponent::sliceModeDataChanged (int sliceMode) { /* Implement data change logic */ }
void SampleEditorComponent::legatoModeDataChanged (int legatoMode) { /* Implement data change logic */ }
void SampleEditorComponent::gainSsrcWinDataChanged (int gainSsrcWin) { /* Implement data change logic */ }
void SampleEditorComponent::grainReadSpeedDataChanged (int grainReadSpeed) { /* Implement data change logic */ }
void SampleEditorComponent::recPresetLenDataChanged (int recPresetLen) { /* Implement data change logic */ }
void SampleEditorComponent::recQuantDataChanged (int recQuant) { /* Implement data change logic */ }
void SampleEditorComponent::recInputDataChanged (int recInput) { /* Implement data change logic */ }
void SampleEditorComponent::recUseThresDataChanged (int recUseThres) { /* Implement data change logic */ }
void SampleEditorComponent::recThresDataChanged (int recThres) { /* Implement data change logic */ }
void SampleEditorComponent::recMonOutBusDataChanged (int recMonOutBus) { /* Implement data change logic */ }

void SampleEditorComponent::gainUiChanged (int gain) { /* Implement UI change logic */ }
void SampleEditorComponent::pitchUiChanged (int pitch) { /* Implement UI change logic */ }
void SampleEditorComponent::panPosUiChanged (int panPos) { /* Implement UI change logic */ }
void SampleEditorComponent::samTrigTypeUiChanged (int samTrigType) { /* Implement UI change logic */ }
void SampleEditorComponent::loopModeUiChanged (int loopMode) { /* Implement UI change logic */ }
void SampleEditorComponent::loopModesUiChanged (int loopModes) { /* Implement UI change logic */ }
void SampleEditorComponent::midiModeUiChanged (int midiMode) { /* Implement UI change logic */ }
void SampleEditorComponent::reverseUiChanged (int reverse) { /* Implement UI change logic */ }
void SampleEditorComponent::cellModeUiChanged (int cellMode) { /* Implement UI change logic */ }
void SampleEditorComponent::envAttackUiChanged (int envAttack) { /* Implement UI change logic */ }
void SampleEditorComponent::envDecayUiChanged (int envDecay) { /* Implement UI change logic */ }
void SampleEditorComponent::envSusUiChanged (int envSus) { /* Implement UI change logic */ }
void SampleEditorComponent::envRelUiChanged (int envRel) { /* Implement UI change logic */ }
void SampleEditorComponent::samStartUiChanged (int samStart) { /* Implement UI change logic */ }
void SampleEditorComponent::samLenUiChanged (int samLen) { /* Implement UI change logic */ }
void SampleEditorComponent::loopStartUiChanged (int loopStart) { /* Implement UI change logic */ }
void SampleEditorComponent::loopEndUiChanged (int loopEnd) { /* Implement UI change logic */ }
void SampleEditorComponent::quantSizeUiChanged (int quantSize) { /* Implement UI change logic */ }
void SampleEditorComponent::syncTypeUiChanged (int syncType) { /* Implement UI change logic */ }
void SampleEditorComponent::actSliceUiChanged (int actSlice) { /* Implement UI change logic */ }
void SampleEditorComponent::outputBusUiChanged (int outputBus) { /* Implement UI change logic */ }
void SampleEditorComponent::polyModeUiChanged (int polyMode) { /* Implement UI change logic */ }
void SampleEditorComponent::polyModeSliceUiChanged (int polyModeSlice) { /* Implement UI change logic */ }
void SampleEditorComponent::sliceStepModeUiChanged (int sliceStepMode) { /* Implement UI change logic */ }
void SampleEditorComponent::chokeGrpUiChanged (int chokeGrp) { /* Implement UI change logic */ }
void SampleEditorComponent::dualFilCutoffUiChanged (int dualFilCutoff) { /* Implement UI change logic */ }
void SampleEditorComponent::resUiChanged (int res) { /* Implement UI change logic */ }
void SampleEditorComponent::rootNoteUiChanged (int rootNote) { /* Implement UI change logic */ }
void SampleEditorComponent::beatCountUiChanged (int beatCount) { /* Implement UI change logic */ }
void SampleEditorComponent::fx1SendUiChanged (int fx1Send) { /* Implement UI change logic */ }
void SampleEditorComponent::fx2SendUiChanged (int fx2Send) { /* Implement UI change logic */ }
void SampleEditorComponent::multiSamModeUiChanged (int multiSamMode) { /* Implement UI change logic */ }
void SampleEditorComponent::interpQualUiChanged (int interpQual) { /* Implement UI change logic */ }
void SampleEditorComponent::playThruUiChanged (int playThru) { /* Implement UI change logic */ }
void SampleEditorComponent::slicerQuantSizeUiChanged (int slicerQuantSize) { /* Implement UI change logic */ }
void SampleEditorComponent::slicerSyncUiChanged (int slicerSync) { /* Implement UI change logic */ }
void SampleEditorComponent::padNoteUiChanged (int padNote) { /* Implement UI change logic */ }
void SampleEditorComponent::loopFadeAmtUiChanged (int loopFadeAmt) { /* Implement UI change logic */ }
void SampleEditorComponent::lfoWaveUiChanged (int lfoWave) { /* Implement UI change logic */ }
void SampleEditorComponent::lfoRateUiChanged (int lfoRate) { /* Implement UI change logic */ }
void SampleEditorComponent::lfoAmountUiChanged (int lfoAmount) { /* Implement UI change logic */ }
void SampleEditorComponent::lfoKeyTrigUiChanged (int lfoKeyTrig) { /* Implement UI change logic */ }
void SampleEditorComponent::lfoBeatSyncUiChanged (int lfoBeatSync) { /* Implement UI change logic */ }
void SampleEditorComponent::lfoRateBeatSyncUiChanged (int lfoRateBeatSync) { /* Implement UI change logic */ }
void SampleEditorComponent::grainSizePercUiChanged (int grainSizePerc) { /* Implement UI change logic */ }
void SampleEditorComponent::grainScatUiChanged (int grainScat) { /* Implement UI change logic */ }
void SampleEditorComponent::grainPanRndUiChanged (int grainPanRnd) { /* Implement UI change logic */ }
void SampleEditorComponent::grainDensityUiChanged (int grainDensity) { /* Implement UI change logic */ }
void SampleEditorComponent::sliceModeUiChanged (int sliceMode) { /* Implement UI change logic */ }
void SampleEditorComponent::legatoModeUiChanged (int legatoMode) { /* Implement UI change logic */ }
void SampleEditorComponent::gainSsrcWinUiChanged (int gainSsrcWin) { /* Implement UI change logic */ }
void SampleEditorComponent::grainReadSpeedUiChanged (int grainReadSpeed) { /* Implement UI change logic */ }
void SampleEditorComponent::recPresetLenUiChanged (int recPresetLen) { /* Implement UI change logic */ }
void SampleEditorComponent::recQuantUiChanged (int recQuant) { /* Implement UI change logic */ }
void SampleEditorComponent::recInputUiChanged (int recInput) { /* Implement UI change logic */ }
void SampleEditorComponent::recUseThresUiChanged (int recUseThres) { /* Implement UI change logic */ }
void SampleEditorComponent::recThresUiChanged (int recThres) { /* Implement UI change logic */ }
void SampleEditorComponent::recMonOutBusUiChanged (int recMonOutBus) { /* Implement UI change logic */ }


bool SampleEditorComponent::isInterestedInFileDrag (const juce::StringArray& files)
{
    return true;
}


void SampleEditorComponent::filesDropped (const juce::StringArray& files, int, int)
{

}


void SampleEditorComponent::fileDragEnter (const juce::StringArray& files, int, int)
{

}


void SampleEditorComponent::fileDragExit (const juce::StringArray& files)
{

}

void SampleEditorComponent::resized ()
{
    auto area = getLocalBounds ().reduced (10);
    fileNameLabel.setBounds (area.removeFromTop (20));
    fileNameSelectLabel.setBounds (area.removeFromTop (20));
    gainLabel.setBounds (area.removeFromTop (20));
    gainTextEditor.setBounds (area.removeFromTop (20));
    pitchLabel.setBounds (area.removeFromTop (20));
    pitchTextEditor.setBounds (area.removeFromTop (20));
    panPosLabel.setBounds (area.removeFromTop (20));
    panPosTextEditor.setBounds (area.removeFromTop (20));
    samTrigTypeLabel.setBounds (area.removeFromTop (20));
    samTrigTypeTextEditor.setBounds (area.removeFromTop (20));
    loopModeLabel.setBounds (area.removeFromTop (20));
    loopModeComboBox.setBounds (area.removeFromTop (20));
    loopModesLabel.setBounds (area.removeFromTop (20));
    loopModesTextEditor.setBounds (area.removeFromTop (20));
    midiModeLabel.setBounds (area.removeFromTop (20));
    midiModeTextEditor.setBounds (area.removeFromTop (20));
    reverseLabel.setBounds (area.removeFromTop (20));
    reverseButton.setBounds (area.removeFromTop (20));
    cellModeLabel.setBounds (area.removeFromTop (20));
    cellModeTextEditor.setBounds (area.removeFromTop (20));
    envAttackLabel.setBounds (area.removeFromTop (20));
    envAttackTextEditor.setBounds (area.removeFromTop (20));
    envDecayLabel.setBounds (area.removeFromTop (20));
    envDecayTextEditor.setBounds (area.removeFromTop (20));
    envSusLabel.setBounds (area.removeFromTop (20));
    envSusTextEditor.setBounds (area.removeFromTop (20));
    envRelLabel.setBounds (area.removeFromTop (20));
    envRelTextEditor.setBounds (area.removeFromTop (20));
    samStartLabel.setBounds (area.removeFromTop (20));
    samStartTextEditor.setBounds (area.removeFromTop (20));
    samLenLabel.setBounds (area.removeFromTop (20));
    samLenTextEditor.setBounds (area.removeFromTop (20));
    loopStartLabel.setBounds (area.removeFromTop (20));
    loopStartTextEditor.setBounds (area.removeFromTop (20));
    loopEndLabel.setBounds (area.removeFromTop (20));
    loopEndTextEditor.setBounds (area.removeFromTop (20));
    quantSizeLabel.setBounds (area.removeFromTop (20));
    quantSizeTextEditor.setBounds (area.removeFromTop (20));
    syncTypeLabel.setBounds (area.removeFromTop (20));
    syncTypeTextEditor.setBounds (area.removeFromTop (20));
    actSliceLabel.setBounds (area.removeFromTop (20));
    actSliceTextEditor.setBounds (area.removeFromTop (20));
    outputBusLabel.setBounds (area.removeFromTop (20));
    outputBusTextEditor.setBounds (area.removeFromTop (20));
    polyModeLabel.setBounds (area.removeFromTop (20));
    polyModeTextEditor.setBounds (area.removeFromTop (20));
    polyModeSliceLabel.setBounds (area.removeFromTop (20));
    polyModeSliceTextEditor.setBounds (area.removeFromTop (20));
    sliceStepModeLabel.setBounds (area.removeFromTop (20));
    sliceStepModeTextEditor.setBounds (area.removeFromTop (20));
    chokeGrpLabel.setBounds (area.removeFromTop (20));
    chokeGrpTextEditor.setBounds (area.removeFromTop (20));
    dualFilCutoffLabel.setBounds (area.removeFromTop (20));
    dualFilCutoffTextEditor.setBounds (area.removeFromTop (20));
    resLabel.setBounds (area.removeFromTop (20));
    resTextEditor.setBounds (area.removeFromTop (20));
    rootNoteLabel.setBounds (area.removeFromTop (20));
    rootNoteTextEditor.setBounds (area.removeFromTop (20));
    beatCountLabel.setBounds (area.removeFromTop (20));
    beatCountTextEditor.setBounds (area.removeFromTop (20));
    fx1SendLabel.setBounds (area.removeFromTop (20));
    fx1SendTextEditor.setBounds (area.removeFromTop (20));
    fx2SendLabel.setBounds (area.removeFromTop (20));
    fx2SendTextEditor.setBounds (area.removeFromTop (20));
    multiSamModeLabel.setBounds (area.removeFromTop (20));
    multiSamModeTextEditor.setBounds (area.removeFromTop (20));
    interpQualLabel.setBounds (area.removeFromTop (20));
    interpQualTextEditor.setBounds (area.removeFromTop (20));
    playThruLabel.setBounds (area.removeFromTop (20));
    playThruTextEditor.setBounds (area.removeFromTop (20));
    slicerQuantSizeLabel.setBounds (area.removeFromTop (20));
    slicerQuantSizeTextEditor.setBounds (area.removeFromTop (20));
    slicerSyncLabel.setBounds (area.removeFromTop (20));
    slicerSyncTextEditor.setBounds (area.removeFromTop (20));
    padNoteLabel.setBounds (area.removeFromTop (20));
    padNoteTextEditor.setBounds (area.removeFromTop (20));
    loopFadeAmtLabel.setBounds (area.removeFromTop (20));
    loopFadeAmtTextEditor.setBounds (area.removeFromTop (20));
    lfoWaveLabel.setBounds (area.removeFromTop (20));
    lfoWaveTextEditor.setBounds (area.removeFromTop (20));
    lfoRateLabel.setBounds (area.removeFromTop (20));
    lfoRateTextEditor.setBounds (area.removeFromTop (20));
    lfoAmountLabel.setBounds (area.removeFromTop (20));
    lfoAmountTextEditor.setBounds (area.removeFromTop (20));
    lfoKeyTrigLabel.setBounds (area.removeFromTop (20));
    lfoKeyTrigTextEditor.setBounds (area.removeFromTop (20));
    lfoBeatSyncLabel.setBounds (area.removeFromTop (20));
    lfoBeatSyncTextEditor.setBounds (area.removeFromTop (20));
    lfoRateBeatSyncLabel.setBounds (area.removeFromTop (20));
    lfoRateBeatSyncTextEditor.setBounds (area.removeFromTop (20));
    grainSizePercLabel.setBounds (area.removeFromTop (20));
    grainSizePercTextEditor.setBounds (area.removeFromTop (20));
    grainScatLabel.setBounds (area.removeFromTop (20));
    grainScatTextEditor.setBounds (area.removeFromTop (20));
    grainPanRndLabel.setBounds (area.removeFromTop (20));
    grainPanRndTextEditor.setBounds (area.removeFromTop (20));
    grainDensityLabel.setBounds (area.removeFromTop (20));
    grainDensityTextEditor.setBounds (area.removeFromTop (20));
    sliceModeLabel.setBounds (area.removeFromTop (20));
    sliceModeTextEditor.setBounds (area.removeFromTop (20));
    legatoModeLabel.setBounds (area.removeFromTop (20));
    legatoModeTextEditor.setBounds (area.removeFromTop (20));
    gainSsrcWinLabel.setBounds (area.removeFromTop (20));
    gainSsrcWinTextEditor.setBounds (area.removeFromTop (20));
    grainReadSpeedLabel.setBounds (area.removeFromTop (20));
    grainReadSpeedTextEditor.setBounds (area.removeFromTop (20));
    recPresetLenLabel.setBounds (area.removeFromTop (20));
    recPresetLenTextEditor.setBounds (area.removeFromTop (20));
    recQuantLabel.setBounds (area.removeFromTop (20));
    recQuantTextEditor.setBounds (area.removeFromTop (20));
    recInputLabel.setBounds (area.removeFromTop (20));
    recInputTextEditor.setBounds (area.removeFromTop (20));
    recUseThresLabel.setBounds (area.removeFromTop (20));
    recUseThresTextEditor.setBounds (area.removeFromTop (20));
    recThresLabel.setBounds (area.removeFromTop (20));
    recThresTextEditor.setBounds (area.removeFromTop (20));
    recMonOutBusLabel.setBounds (area.removeFromTop (20));
    recMonOutBusTextEditor.setBounds (area.removeFromTop (20));
}

void SampleEditorComponent::paint (juce::Graphics& g)
{

}

void SampleEditorComponent::paintOverChildren (juce::Graphics& g)
{

}
