#include "SampleEditorComponent.h"

SampleEditorComponent::SampleEditorComponent ()
{
    auto setupLabel = [this] (juce::Label& label, juce::String text, juce::Component& editor)
    {
        label.setColour (juce::Label::textColourId, juce::Colours::black);
        label.setText (text, juce::dontSendNotification);
        addAndMakeVisible (label);
        addAndMakeVisible (editor);
    };

    fileNameSelectLabel.setColour (juce::Label::ColourIds::textColourId, juce::Colours::white);
    fileNameSelectLabel.setColour (juce::Label::ColourIds::backgroundColourId, juce::Colours::black);
    fileNameSelectLabel.setOutline (juce::Colours::white);
    setupLabel (fileNameLabel, "File Name", fileNameSelectLabel);

    setupLabel (gainLabel, "Gain (dB)", gainTextEditor);
    setupLabel (pitchLabel, "Pitch", pitchTextEditor);
    setupLabel (panPosLabel, "Pan Position", panPosTextEditor);
    setupLabel (samTrigTypeLabel, "Sample Trigger Type", samTrigTypeTextEditor);
    setupLabel (loopModeLabel, "Loop Mode", loopModeComboBox);
    setupLabel (loopModesLabel, "Loop Modes", loopModesTextEditor);
    setupLabel (midiModeLabel, "MIDI Mode", midiModeTextEditor);
    setupLabel (reverseLabel, "Reverse", reverseButton);
    setupLabel (cellModeLabel, "Cell Mode", cellModeTextEditor);
    setupLabel (envAttackLabel, "Attack", envAttackTextEditor);
    setupLabel (envDecayLabel, "Decay", envDecayTextEditor);
    setupLabel (envSusLabel, "Sustain", envSusTextEditor);
    setupLabel (envRelLabel, "Release", envRelTextEditor);
    setupLabel (samStartLabel, "Sample Start", samStartTextEditor);
    setupLabel (samLenLabel, "Sample Length", samLenTextEditor);
    setupLabel (loopStartLabel, "Loop Start", loopStartTextEditor);
    setupLabel (loopEndLabel, "Loop End", loopEndTextEditor);
    setupLabel (quantSizeLabel, "Quant Size", quantSizeTextEditor);
    setupLabel (syncTypeLabel, "Sync Type", syncTypeTextEditor);
    setupLabel (actSliceLabel, "Active Slice", actSliceTextEditor);
    setupLabel (outputBusLabel, "Output Bus", outputBusTextEditor);
    setupLabel (polyModeLabel, "Poly Mode", polyModeTextEditor);
    setupLabel (polyModeSliceLabel, "Poly Mode Slice", polyModeSliceTextEditor);
    setupLabel (sliceStepModeLabel, "Slice Step Mode", sliceStepModeTextEditor);
    setupLabel (chokeGrpLabel, "Choke Group", chokeGrpTextEditor);
    setupLabel (dualFilCutoffLabel, "Dual Filter Cutoff", dualFilCutoffTextEditor);
    setupLabel (resLabel, "Resonance", resTextEditor);
    setupLabel (rootNoteLabel, "Root Note", rootNoteTextEditor);
    setupLabel (beatCountLabel, "Beat Count", beatCountTextEditor);
    setupLabel (fx1SendLabel, "FX1 Send", fx1SendTextEditor);
    setupLabel (fx2SendLabel, "FX2 Send", fx2SendTextEditor);
    setupLabel (multiSamModeLabel, "Multi Sample Mode", multiSamModeTextEditor);
    setupLabel (interpQualLabel, "Interpolation Quality", interpQualTextEditor);
    setupLabel (playThruLabel, "Play Through", playThruTextEditor);
    setupLabel (slicerQuantSizeLabel, "Slicer Quant Size", slicerQuantSizeTextEditor);
    setupLabel (slicerSyncLabel, "Slicer Sync", slicerSyncTextEditor);
    setupLabel (padNoteLabel, "Pad Note", padNoteTextEditor);
    setupLabel (loopFadeAmtLabel, "Loop Fade Amount", loopFadeAmtTextEditor);
    setupLabel (lfoWaveLabel, "LFO Wave", lfoWaveTextEditor);
    setupLabel (lfoRateLabel, "LFO Rate", lfoRateTextEditor);
    setupLabel (lfoAmountLabel, "LFO Amount", lfoAmountTextEditor);
    setupLabel (lfoKeyTrigLabel, "LFO Key Trigger", lfoKeyTrigTextEditor);
    setupLabel (lfoBeatSyncLabel, "LFO Beat Sync", lfoBeatSyncTextEditor);
    setupLabel (lfoRateBeatSyncLabel, "LFO Rate Beat Sync", lfoRateBeatSyncTextEditor);
    setupLabel (grainSizePercLabel, "Grain Size Percentage", grainSizePercTextEditor);
    setupLabel (grainScatLabel, "Grain Scatter", grainScatTextEditor);
    setupLabel (grainPanRndLabel, "Grain Pan Random", grainPanRndTextEditor);
    setupLabel (grainDensityLabel, "Grain Density", grainDensityTextEditor);
    setupLabel (sliceModeLabel, "Slice Mode", sliceModeTextEditor);
    setupLabel (legatoModeLabel, "Legato Mode", legatoModeTextEditor);
    setupLabel (gainSsrcWinLabel, "Gain SSRC Window", gainSsrcWinTextEditor);
    setupLabel (grainReadSpeedLabel, "Grain Read Speed", grainReadSpeedTextEditor);
    setupLabel (recPresetLenLabel, "Record Preset Length", recPresetLenTextEditor);
    setupLabel (recQuantLabel, "Record Quantization", recQuantTextEditor);
    setupLabel (recInputLabel, "Record Input", recInputTextEditor);
    setupLabel (recUseThresLabel, "Record Use Threshold", recUseThresTextEditor);
    setupLabel (recThresLabel, "Record Threshold", recThresTextEditor);
    setupLabel (recMonOutBusLabel, "Record Monitor Output Bus", recMonOutBusTextEditor);
}

SampleEditorComponent::~SampleEditorComponent ()
{
}

void SampleEditorComponent::init (juce::ValueTree samplePropertiesVT)
{
    sampleProperties.wrap (samplePropertiesVT, SampleProperties::WrapperType::client, SampleProperties::EnableCallbacks::yes);

    sampleProperties.onGainDbChange = [this] (int gain) { gainDataChanged (gain); };
    sampleProperties.onPitchChange = [this] (int pitch) { pitchDataChanged (pitch); };
    sampleProperties.onPanPosChange = [this] (int panPos) { panPosDataChanged (panPos); };
    sampleProperties.onSamTrigTypeChange = [this] (int samTrigType) { samTrigTypeDataChanged (samTrigType); };
    sampleProperties.onLoopModeChange = [this] (int loopMode) { loopModeDataChanged (loopMode); };
    sampleProperties.onLoopModesChange = [this] (int loopModes) { loopModesDataChanged (loopModes); };
    sampleProperties.onMidiModeChange = [this] (int midiMode) { midiModeDataChanged (midiMode); };
    sampleProperties.onReverseChange = [this] (int reverse) { reverseDataChanged (reverse); };
    sampleProperties.onCellModeChange = [this] (int cellMode) { cellModeDataChanged (cellMode); };
    sampleProperties.onEnvAttackChange = [this] (int envAttack) { envAttackDataChanged (envAttack); };
    sampleProperties.onEnvDecayChange = [this] (int envDecay) { envDecayDataChanged (envDecay); };
    sampleProperties.onEnvSusChange = [this] (int envSus) { envSusDataChanged (envSus); };
    sampleProperties.onEnvRelChange = [this] (int envRel) { envRelDataChanged (envRel); };
    sampleProperties.onSamStartChange = [this] (int samStart) { samStartDataChanged (samStart); };
    sampleProperties.onSamLenChange = [this] (int samLen) { samLenDataChanged (samLen); };
    sampleProperties.onLoopStartChange = [this] (int loopStart) { loopStartDataChanged (loopStart); };
    sampleProperties.onLoopEndChange = [this] (int loopEnd) { loopEndDataChanged (loopEnd); };
    sampleProperties.onQuantSizeChange = [this] (int quantSize) { quantSizeDataChanged (quantSize); };
    sampleProperties.onSyncTypeChange = [this] (int syncType) { syncTypeDataChanged (syncType); };
    sampleProperties.onActSliceChange = [this] (int actSlice) { actSliceDataChanged (actSlice); };
    sampleProperties.onOutputBusChange = [this] (int outputBus) { outputBusDataChanged (outputBus); };
    sampleProperties.onPolyModeChange = [this] (int polyMode) { polyModeDataChanged (polyMode); };
    sampleProperties.onPolyModeSliceChange = [this] (int polyModeSlice) { polyModeSliceDataChanged (polyModeSlice); };
    sampleProperties.onSliceStepModeChange = [this] (int sliceStepMode) { sliceStepModeDataChanged (sliceStepMode); };
    sampleProperties.onChokeGrpChange = [this] (int chokeGrp) { chokeGrpDataChanged (chokeGrp); };
    sampleProperties.onDualFilCutoffChange = [this] (int dualFilCutoff) { dualFilCutoffDataChanged (dualFilCutoff); };
    sampleProperties.onResChange = [this] (int res) { resDataChanged (res); };
    sampleProperties.onRootNoteChange = [this] (int rootNote) { rootNoteDataChanged (rootNote); };
    sampleProperties.onBeatCountChange = [this] (int beatCount) { beatCountDataChanged (beatCount); };
    sampleProperties.onFx1SendChange = [this] (int fx1Send) { fx1SendDataChanged (fx1Send); };
    sampleProperties.onFx2SendChange = [this] (int fx2Send) { fx2SendDataChanged (fx2Send); };
    sampleProperties.onMultiSamModeChange = [this] (int multiSamMode) { multiSamModeDataChanged (multiSamMode); };
    sampleProperties.onInterpQualChange = [this] (int interpQual) { interpQualDataChanged (interpQual); };
    sampleProperties.onPlayThruChange = [this] (int playThru) { playThruDataChanged (playThru); };
    sampleProperties.onSlicerQuantSizeChange = [this] (int slicerQuantSize) { slicerQuantSizeDataChanged (slicerQuantSize); };
    sampleProperties.onSlicerSyncChange = [this] (int slicerSync) { slicerSyncDataChanged (slicerSync); };
    sampleProperties.onPadNoteChange = [this] (int padNote) { padNoteDataChanged (padNote); };
    sampleProperties.onLoopFadeAmtChange = [this] (int loopFadeAmt) { loopFadeAmtDataChanged (loopFadeAmt); };
    sampleProperties.onLfoWaveChange = [this] (int lfoWave) { lfoWaveDataChanged (lfoWave); };
    sampleProperties.onLfoRateChange = [this] (int lfoRate) { lfoRateDataChanged (lfoRate); };
    sampleProperties.onLfoAmountChange = [this] (int lfoAmount) { lfoAmountDataChanged (lfoAmount); };
    sampleProperties.onLfoKeyTrigChange = [this] (int lfoKeyTrig) { lfoKeyTrigDataChanged (lfoKeyTrig); };
    sampleProperties.onLfoBeatSyncChange = [this] (int lfoBeatSync) { lfoBeatSyncDataChanged (lfoBeatSync); };
    sampleProperties.onLfoRateBeatSyncChange = [this] (int lfoRateBeatSync) { lfoRateBeatSyncDataChanged (lfoRateBeatSync); };
    sampleProperties.onGrainSizePercChange = [this] (int grainSizePerc) { grainSizePercDataChanged (grainSizePerc); };
    sampleProperties.onGrainScatChange = [this] (int grainScat) { grainScatDataChanged (grainScat); };
    sampleProperties.onGrainPanRndChange = [this] (int grainPanRnd) { grainPanRndDataChanged (grainPanRnd); };
    sampleProperties.onGrainDensityChange = [this] (int grainDensity) { grainDensityDataChanged (grainDensity); };
    sampleProperties.onSliceModeChange = [this] (int sliceMode) { sliceModeDataChanged (sliceMode); };
    sampleProperties.onLegatoModeChange = [this] (int legatoMode) { legatoModeDataChanged (legatoMode); };
    sampleProperties.onGainSsrcWinChange = [this] (int gainSsrcWin) { gainSsrcWinDataChanged (gainSsrcWin); };
    sampleProperties.onGrainReadSpeedChange = [this] (int grainReadSpeed) { grainReadSpeedDataChanged (grainReadSpeed); };
    sampleProperties.onRecPresetLenChange = [this] (int recPresetLen) { recPresetLenDataChanged (recPresetLen); };
    sampleProperties.onRecQuantChange = [this] (int recQuant) { recQuantDataChanged (recQuant); };
    sampleProperties.onRecInputChange = [this] (int recInput) { recInputDataChanged (recInput); };
    sampleProperties.onRecUseThresChange = [this] (int recUseThres) { recUseThresDataChanged (recUseThres); };
    sampleProperties.onRecThresChange = [this] (int recThres) { recThresDataChanged (recThres); };
    sampleProperties.onRecMonOutBusChange = [this] (int recMonOutBus) { recMonOutBusDataChanged (recMonOutBus); };

    gainDataChanged (sampleProperties.getGainDb ());
    pitchDataChanged (sampleProperties.getPitch ());
    panPosDataChanged (sampleProperties.getPanPos ());
    samTrigTypeDataChanged (sampleProperties.getSamTrigType ());
    loopModeDataChanged (sampleProperties.getLoopMode ());
    loopModesDataChanged (sampleProperties.getLoopModes ());
    midiModeDataChanged (sampleProperties.getMidiMode ());
    reverseDataChanged (sampleProperties.getReverse ());
    cellModeDataChanged (sampleProperties.getCellMode ());
    envAttackDataChanged (sampleProperties.getEnvAttack ());
    envDecayDataChanged (sampleProperties.getEnvDecay ());
    envSusDataChanged (sampleProperties.getEnvSus ());
    envRelDataChanged (sampleProperties.getEnvRel ());
    samStartDataChanged (sampleProperties.getSamStart ());
    samLenDataChanged (sampleProperties.getSamLen ());
    loopStartDataChanged (sampleProperties.getLoopStart ());
    loopEndDataChanged (sampleProperties.getLoopEnd ());
    quantSizeDataChanged (sampleProperties.getQuantSize ());
    syncTypeDataChanged (sampleProperties.getSyncType ());
    actSliceDataChanged (sampleProperties.getActSlice ());
    outputBusDataChanged (sampleProperties.getOutputBus ());
    polyModeDataChanged (sampleProperties.getPolyMode ());
    polyModeSliceDataChanged (sampleProperties.getPolyModeSlice ());
    sliceStepModeDataChanged (sampleProperties.getSliceStepMode ());
    chokeGrpDataChanged (sampleProperties.getChokeGrp ());
    dualFilCutoffDataChanged (sampleProperties.getDualFilCutoff ());
    resDataChanged (sampleProperties.getRes ());
    rootNoteDataChanged (sampleProperties.getRootNote ());
    beatCountDataChanged (sampleProperties.getBeatCount ());
    fx1SendDataChanged (sampleProperties.getFx1Send ());
    fx2SendDataChanged (sampleProperties.getFx2Send ());
    multiSamModeDataChanged (sampleProperties.getMultiSamMode ());
    interpQualDataChanged (sampleProperties.getInterpQual ());
    playThruDataChanged (sampleProperties.getPlayThru ());
    slicerQuantSizeDataChanged (sampleProperties.getSlicerQuantSize ());
    slicerSyncDataChanged (sampleProperties.getSlicerSync ());
    padNoteDataChanged (sampleProperties.getPadNote ());
    loopFadeAmtDataChanged (sampleProperties.getLoopFadeAmt ());
    lfoWaveDataChanged (sampleProperties.getLfoWave ());
    lfoRateDataChanged (sampleProperties.getLfoRate ());
    lfoAmountDataChanged (sampleProperties.getLfoAmount ());
    lfoKeyTrigDataChanged (sampleProperties.getLfoKeyTrig ());
    lfoBeatSyncDataChanged (sampleProperties.getLfoBeatSync ());
    lfoRateBeatSyncDataChanged (sampleProperties.getLfoRateBeatSync ());
    grainSizePercDataChanged (sampleProperties.getGrainSizePerc ());
    grainScatDataChanged (sampleProperties.getGrainScat ());
    grainPanRndDataChanged (sampleProperties.getGrainPanRnd ());
    grainDensityDataChanged (sampleProperties.getGrainDensity ());
    sliceModeDataChanged (sampleProperties.getSliceMode ());
    legatoModeDataChanged (sampleProperties.getLegatoMode ());
    gainSsrcWinDataChanged (sampleProperties.getGainSsrcWin ());
    grainReadSpeedDataChanged (sampleProperties.getGrainReadSpeed ());
    recPresetLenDataChanged (sampleProperties.getRecPresetLen ());
    recQuantDataChanged (sampleProperties.getRecQuant ());
    recInputDataChanged (sampleProperties.getRecInput ());
    recUseThresDataChanged (sampleProperties.getRecUseThres ());
    recThresDataChanged (sampleProperties.getRecThres ());
    recMonOutBusDataChanged (sampleProperties.getRecMonOutBus ());
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

void SampleEditorComponent::gainDataChanged (int gain) {
    gainTextEditor.setText (juce::String (gain)); }
void SampleEditorComponent::pitchDataChanged (int pitch) { pitchTextEditor.setText (juce::String (pitch)); }
void SampleEditorComponent::panPosDataChanged (int panPos) { panPosTextEditor.setText (juce::String (panPos)); }
void SampleEditorComponent::samTrigTypeDataChanged (int samTrigType) { samTrigTypeTextEditor.setText (juce::String (samTrigType)); }
void SampleEditorComponent::loopModeDataChanged (int loopMode) { loopModeComboBox.setSelectedId (loopMode); }
void SampleEditorComponent::loopModesDataChanged (int loopModes) { loopModesTextEditor.setText (juce::String (loopModes)); }
void SampleEditorComponent::midiModeDataChanged (int midiMode) { midiModeTextEditor.setText (juce::String (midiMode)); }
void SampleEditorComponent::reverseDataChanged (int reverse) { reverseButton.setToggleState (reverse, juce::dontSendNotification); }
void SampleEditorComponent::cellModeDataChanged (int cellMode) { cellModeTextEditor.setText (juce::String (cellMode)); }
void SampleEditorComponent::envAttackDataChanged (int envAttack) { envAttackTextEditor.setText (juce::String (envAttack)); }
void SampleEditorComponent::envDecayDataChanged (int envDecay) { envDecayTextEditor.setText (juce::String (envDecay)); }
void SampleEditorComponent::envSusDataChanged (int envSus) { envSusTextEditor.setText (juce::String (envSus)); }
void SampleEditorComponent::envRelDataChanged (int envRel) { envRelTextEditor.setText (juce::String (envRel)); }
void SampleEditorComponent::samStartDataChanged (int samStart) { samStartTextEditor.setText (juce::String (samStart)); }
void SampleEditorComponent::samLenDataChanged (int samLen) { samLenTextEditor.setText (juce::String (samLen)); }
void SampleEditorComponent::loopStartDataChanged (int loopStart) { loopStartTextEditor.setText (juce::String (loopStart)); }
void SampleEditorComponent::loopEndDataChanged (int loopEnd) { loopEndTextEditor.setText (juce::String (loopEnd)); }
void SampleEditorComponent::quantSizeDataChanged (int quantSize) { quantSizeTextEditor.setText (juce::String (quantSize)); }
void SampleEditorComponent::syncTypeDataChanged (int syncType) { syncTypeTextEditor.setText (juce::String (syncType)); }
void SampleEditorComponent::actSliceDataChanged (int actSlice) { actSliceTextEditor.setText (juce::String (actSlice)); }
void SampleEditorComponent::outputBusDataChanged (int outputBus) { outputBusTextEditor.setText (juce::String (outputBus)); }
void SampleEditorComponent::polyModeDataChanged (int polyMode) { polyModeTextEditor.setText (juce::String (polyMode)); }
void SampleEditorComponent::polyModeSliceDataChanged (int polyModeSlice) { polyModeSliceTextEditor.setText (juce::String (polyModeSlice)); }
void SampleEditorComponent::sliceStepModeDataChanged (int sliceStepMode) { sliceStepModeTextEditor.setText (juce::String (sliceStepMode)); }
void SampleEditorComponent::chokeGrpDataChanged (int chokeGrp) { chokeGrpTextEditor.setText (juce::String (chokeGrp)); }
void SampleEditorComponent::dualFilCutoffDataChanged (int dualFilCutoff) { dualFilCutoffTextEditor.setText (juce::String (dualFilCutoff)); }
void SampleEditorComponent::resDataChanged (int res) { resTextEditor.setText (juce::String (res)); }
void SampleEditorComponent::rootNoteDataChanged (int rootNote) { rootNoteTextEditor.setText (juce::String (rootNote)); }
void SampleEditorComponent::beatCountDataChanged (int beatCount) { beatCountTextEditor.setText (juce::String (beatCount)); }
void SampleEditorComponent::fx1SendDataChanged (int fx1Send) { fx1SendTextEditor.setText (juce::String (fx1Send)); }
void SampleEditorComponent::fx2SendDataChanged (int fx2Send) { fx2SendTextEditor.setText (juce::String (fx2Send)); }
void SampleEditorComponent::multiSamModeDataChanged (int multiSamMode) { multiSamModeTextEditor.setText (juce::String (multiSamMode)); }
void SampleEditorComponent::interpQualDataChanged (int interpQual) { interpQualTextEditor.setText (juce::String (interpQual)); }
void SampleEditorComponent::playThruDataChanged (int playThru) { playThruTextEditor.setText (juce::String (playThru)); }
void SampleEditorComponent::slicerQuantSizeDataChanged (int slicerQuantSize) { slicerQuantSizeTextEditor.setText (juce::String (slicerQuantSize)); }
void SampleEditorComponent::slicerSyncDataChanged (int slicerSync) { slicerSyncTextEditor.setText (juce::String (slicerSync)); }
void SampleEditorComponent::padNoteDataChanged (int padNote) { padNoteTextEditor.setText (juce::String (padNote)); }
void SampleEditorComponent::loopFadeAmtDataChanged (int loopFadeAmt) { loopFadeAmtTextEditor.setText (juce::String (loopFadeAmt)); }
void SampleEditorComponent::lfoWaveDataChanged (int lfoWave) { lfoWaveTextEditor.setText (juce::String (lfoWave)); }
void SampleEditorComponent::lfoRateDataChanged (int lfoRate) { lfoRateTextEditor.setText (juce::String (lfoRate)); }
void SampleEditorComponent::lfoAmountDataChanged (int lfoAmount) { lfoAmountTextEditor.setText (juce::String (lfoAmount)); }
void SampleEditorComponent::lfoKeyTrigDataChanged (int lfoKeyTrig) { lfoKeyTrigTextEditor.setText (juce::String (lfoKeyTrig)); }
void SampleEditorComponent::lfoBeatSyncDataChanged (int lfoBeatSync) { lfoBeatSyncTextEditor.setText (juce::String (lfoBeatSync)); }
void SampleEditorComponent::lfoRateBeatSyncDataChanged (int lfoRateBeatSync) { lfoRateBeatSyncTextEditor.setText (juce::String (lfoRateBeatSync)); }
void SampleEditorComponent::grainSizePercDataChanged (int grainSizePerc) { grainSizePercTextEditor.setText (juce::String (grainSizePerc)); }
void SampleEditorComponent::grainScatDataChanged (int grainScat) { grainScatTextEditor.setText (juce::String (grainScat)); }
void SampleEditorComponent::grainPanRndDataChanged (int grainPanRnd) { grainPanRndTextEditor.setText (juce::String (grainPanRnd)); }
void SampleEditorComponent::grainDensityDataChanged (int grainDensity) { grainDensityTextEditor.setText (juce::String (grainDensity)); }
void SampleEditorComponent::sliceModeDataChanged (int sliceMode) { sliceModeTextEditor.setText (juce::String (sliceMode)); }
void SampleEditorComponent::legatoModeDataChanged (int legatoMode) { legatoModeTextEditor.setText (juce::String (legatoMode)); }
void SampleEditorComponent::gainSsrcWinDataChanged (int gainSsrcWin) { gainSsrcWinTextEditor.setText (juce::String (gainSsrcWin)); }
void SampleEditorComponent::grainReadSpeedDataChanged (int grainReadSpeed) { grainReadSpeedTextEditor.setText (juce::String (grainReadSpeed)); }
void SampleEditorComponent::recPresetLenDataChanged (int recPresetLen) { recPresetLenTextEditor.setText (juce::String (recPresetLen)); }
void SampleEditorComponent::recQuantDataChanged (int recQuant) { recQuantTextEditor.setText (juce::String (recQuant)); }
void SampleEditorComponent::recInputDataChanged (int recInput) { recInputTextEditor.setText (juce::String (recInput)); }
void SampleEditorComponent::recUseThresDataChanged (int recUseThres) { recUseThresTextEditor.setText (juce::String (recUseThres)); }
void SampleEditorComponent::recThresDataChanged (int recThres) { recThresTextEditor.setText (juce::String (recThres)); }
void SampleEditorComponent::recMonOutBusDataChanged (int recMonOutBus) { recMonOutBusTextEditor.setText (juce::String (recMonOutBus)); }

void SampleEditorComponent::gainUiChanged (int gain) { sampleProperties.setGainDb (gain, false); }
void SampleEditorComponent::pitchUiChanged (int pitch) { sampleProperties.setPitch (pitch, false); }
void SampleEditorComponent::panPosUiChanged (int panPos) { sampleProperties.setPanPos (panPos, false); }
void SampleEditorComponent::samTrigTypeUiChanged (int samTrigType) { sampleProperties.setSamTrigType (samTrigType, false); }
void SampleEditorComponent::loopModeUiChanged (int loopMode) { sampleProperties.setLoopMode (loopMode, false); }
void SampleEditorComponent::loopModesUiChanged (int loopModes) { sampleProperties.setLoopModes (loopModes, false); }
void SampleEditorComponent::midiModeUiChanged (int midiMode) { sampleProperties.setMidiMode (midiMode, false); }
void SampleEditorComponent::reverseUiChanged (int reverse) { sampleProperties.setReverse (reverse, false); }
void SampleEditorComponent::cellModeUiChanged (int cellMode) { sampleProperties.setCellMode (cellMode, false); }
void SampleEditorComponent::envAttackUiChanged (int envAttack) { sampleProperties.setEnvAttack (envAttack, false); }
void SampleEditorComponent::envDecayUiChanged (int envDecay) { sampleProperties.setEnvDecay (envDecay, false); }
void SampleEditorComponent::envSusUiChanged (int envSus) { sampleProperties.setEnvSus (envSus, false); }
void SampleEditorComponent::envRelUiChanged (int envRel) { sampleProperties.setEnvRel (envRel, false); }
void SampleEditorComponent::samStartUiChanged (int samStart) { sampleProperties.setSamStart (samStart, false); }
void SampleEditorComponent::samLenUiChanged (int samLen) { sampleProperties.setSamLen (samLen, false); }
void SampleEditorComponent::loopStartUiChanged (int loopStart) { sampleProperties.setLoopStart (loopStart, false); }
void SampleEditorComponent::loopEndUiChanged (int loopEnd) { sampleProperties.setLoopEnd (loopEnd, false); }
void SampleEditorComponent::quantSizeUiChanged (int quantSize) { sampleProperties.setQuantSize (quantSize, false); }
void SampleEditorComponent::syncTypeUiChanged (int syncType) { sampleProperties.setSyncType (syncType, false); }
void SampleEditorComponent::actSliceUiChanged (int actSlice) { sampleProperties.setActSlice (actSlice, false); }
void SampleEditorComponent::outputBusUiChanged (int outputBus) { sampleProperties.setOutputBus (outputBus, false); }
void SampleEditorComponent::polyModeUiChanged (int polyMode) { sampleProperties.setPolyMode (polyMode, false); }
void SampleEditorComponent::polyModeSliceUiChanged (int polyModeSlice) { sampleProperties.setPolyModeSlice (polyModeSlice, false); }
void SampleEditorComponent::sliceStepModeUiChanged (int sliceStepMode) { sampleProperties.setSliceStepMode (sliceStepMode, false); }
void SampleEditorComponent::chokeGrpUiChanged (int chokeGrp) { sampleProperties.setChokeGrp (chokeGrp, false); }
void SampleEditorComponent::dualFilCutoffUiChanged (int dualFilCutoff) { sampleProperties.setDualFilCutoff (dualFilCutoff, false); }
void SampleEditorComponent::resUiChanged (int res) { sampleProperties.setRes (res, false); }
void SampleEditorComponent::rootNoteUiChanged (int rootNote) { sampleProperties.setRootNote (rootNote, false); }
void SampleEditorComponent::beatCountUiChanged (int beatCount) { sampleProperties.setBeatCount (beatCount, false); }
void SampleEditorComponent::fx1SendUiChanged (int fx1Send) { sampleProperties.setFx1Send (fx1Send, false); }
void SampleEditorComponent::fx2SendUiChanged (int fx2Send) { sampleProperties.setFx2Send (fx2Send, false); }
void SampleEditorComponent::multiSamModeUiChanged (int multiSamMode) { sampleProperties.setMultiSamMode (multiSamMode, false); }
void SampleEditorComponent::interpQualUiChanged (int interpQual) { sampleProperties.setInterpQual (interpQual, false); }
void SampleEditorComponent::playThruUiChanged (int playThru) { sampleProperties.setPlayThru (playThru, false); }
void SampleEditorComponent::slicerQuantSizeUiChanged (int slicerQuantSize) { sampleProperties.setSlicerQuantSize (slicerQuantSize, false); }
void SampleEditorComponent::slicerSyncUiChanged (int slicerSync) { sampleProperties.setSlicerSync (slicerSync, false); }
void SampleEditorComponent::padNoteUiChanged (int padNote) { sampleProperties.setPadNote (padNote, false); }
void SampleEditorComponent::loopFadeAmtUiChanged (int loopFadeAmt) { sampleProperties.setLoopFadeAmt (loopFadeAmt, false); }
void SampleEditorComponent::lfoWaveUiChanged (int lfoWave) { sampleProperties.setLfoWave (lfoWave, false); }
void SampleEditorComponent::lfoRateUiChanged (int lfoRate) { sampleProperties.setLfoRate (lfoRate, false); }
void SampleEditorComponent::lfoAmountUiChanged (int lfoAmount) { sampleProperties.setLfoAmount (lfoAmount, false); }
void SampleEditorComponent::lfoKeyTrigUiChanged (int lfoKeyTrig) { sampleProperties.setLfoKeyTrig (lfoKeyTrig, false); }
void SampleEditorComponent::lfoBeatSyncUiChanged (int lfoBeatSync) { sampleProperties.setLfoBeatSync (lfoBeatSync, false); }
void SampleEditorComponent::lfoRateBeatSyncUiChanged (int lfoRateBeatSync) { sampleProperties.setLfoRateBeatSync (lfoRateBeatSync, false); }
void SampleEditorComponent::grainSizePercUiChanged (int grainSizePerc) { sampleProperties.setGrainSizePerc (grainSizePerc, false); }
void SampleEditorComponent::grainScatUiChanged (int grainScat) { sampleProperties.setGrainScat (grainScat, false); }
void SampleEditorComponent::grainPanRndUiChanged (int grainPanRnd) { sampleProperties.setGrainPanRnd (grainPanRnd, false); }
void SampleEditorComponent::grainDensityUiChanged (int grainDensity) { sampleProperties.setGrainDensity (grainDensity, false); }
void SampleEditorComponent::sliceModeUiChanged (int sliceMode) { sampleProperties.setSliceMode (sliceMode, false); }
void SampleEditorComponent::legatoModeUiChanged (int legatoMode) { sampleProperties.setLegatoMode (legatoMode, false); }
void SampleEditorComponent::gainSsrcWinUiChanged (int gainSsrcWin) { sampleProperties.setGainSsrcWin (gainSsrcWin, false); }
void SampleEditorComponent::grainReadSpeedUiChanged (int grainReadSpeed) { sampleProperties.setGrainReadSpeed (grainReadSpeed, false); }
void SampleEditorComponent::recPresetLenUiChanged (int recPresetLen) { sampleProperties.setRecPresetLen (recPresetLen, false); }
void SampleEditorComponent::recQuantUiChanged (int recQuant) { sampleProperties.setRecQuant (recQuant, false); }
void SampleEditorComponent::recInputUiChanged (int recInput) { sampleProperties.setRecInput (recInput, false); }
void SampleEditorComponent::recUseThresUiChanged (int recUseThres) { sampleProperties.setRecUseThres (recUseThres, false); }
void SampleEditorComponent::recThresUiChanged (int recThres) { sampleProperties.setRecThres (recThres, false); }
void SampleEditorComponent::recMonOutBusUiChanged (int recMonOutBus) { sampleProperties.setRecMonOutBus (recMonOutBus, false); }

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
    auto columnWidth = area.getWidth () / 3;
    auto leftColumn = area.removeFromLeft (columnWidth).reduced (5);
    auto middleColumn = area.removeFromLeft (columnWidth).reduced (5);
    auto rightColumn = area.reduced (5);

    auto setupBounds = [] (juce::Label& label, juce::Component& editor, juce::Rectangle<int>& columnArea)
        {
            auto row = columnArea.removeFromTop (20);
            label.setBounds (row.removeFromLeft (row.getWidth () * 0.6666));
            editor.setBounds (row);
        };

        // Left column items
    setupBounds (fileNameLabel, fileNameSelectLabel, leftColumn);
    setupBounds (gainLabel, gainTextEditor, leftColumn);
    setupBounds (pitchLabel, pitchTextEditor, leftColumn);
    setupBounds (panPosLabel, panPosTextEditor, leftColumn);
    setupBounds (samTrigTypeLabel, samTrigTypeTextEditor, leftColumn);
    setupBounds (loopModeLabel, loopModeComboBox, leftColumn);
    setupBounds (loopModesLabel, loopModesTextEditor, leftColumn);
    setupBounds (midiModeLabel, midiModeTextEditor, leftColumn);
    setupBounds (reverseLabel, reverseButton, leftColumn);
    setupBounds (cellModeLabel, cellModeTextEditor, leftColumn);
    setupBounds (envAttackLabel, envAttackTextEditor, leftColumn);
    setupBounds (envDecayLabel, envDecayTextEditor, leftColumn);
    setupBounds (envSusLabel, envSusTextEditor, leftColumn);
    setupBounds (envRelLabel, envRelTextEditor, leftColumn);
    setupBounds (samStartLabel, samStartTextEditor, leftColumn);
    setupBounds (samLenLabel, samLenTextEditor, leftColumn);
    setupBounds (loopStartLabel, loopStartTextEditor, leftColumn);
    setupBounds (loopEndLabel, loopEndTextEditor, leftColumn);
    setupBounds (quantSizeLabel, quantSizeTextEditor, leftColumn);

    // Middle column items
    setupBounds (syncTypeLabel, syncTypeTextEditor, middleColumn);
    setupBounds (actSliceLabel, actSliceTextEditor, middleColumn);
    setupBounds (outputBusLabel, outputBusTextEditor, middleColumn);
    setupBounds (polyModeLabel, polyModeTextEditor, middleColumn);
    setupBounds (polyModeSliceLabel, polyModeSliceTextEditor, middleColumn);
    setupBounds (sliceStepModeLabel, sliceStepModeTextEditor, middleColumn);
    setupBounds (chokeGrpLabel, chokeGrpTextEditor, middleColumn);
    setupBounds (dualFilCutoffLabel, dualFilCutoffTextEditor, middleColumn);
    setupBounds (resLabel, resTextEditor, middleColumn);
    setupBounds (rootNoteLabel, rootNoteTextEditor, middleColumn);
    setupBounds (beatCountLabel, beatCountTextEditor, middleColumn);
    setupBounds (fx1SendLabel, fx1SendTextEditor, middleColumn);
    setupBounds (fx2SendLabel, fx2SendTextEditor, middleColumn);
    setupBounds (multiSamModeLabel, multiSamModeTextEditor, middleColumn);
    setupBounds (interpQualLabel, interpQualTextEditor, middleColumn);
    setupBounds (playThruLabel, playThruTextEditor, middleColumn);
    setupBounds (slicerQuantSizeLabel, slicerQuantSizeTextEditor, middleColumn);
    setupBounds (slicerSyncLabel, slicerSyncTextEditor, middleColumn);
    setupBounds (padNoteLabel, padNoteTextEditor, middleColumn);
    setupBounds (loopFadeAmtLabel, loopFadeAmtTextEditor, middleColumn);

    // Right column items
    setupBounds (lfoWaveLabel, lfoWaveTextEditor, rightColumn);
    setupBounds (lfoRateLabel, lfoRateTextEditor, rightColumn);
    setupBounds (lfoAmountLabel, lfoAmountTextEditor, rightColumn);
    setupBounds (lfoKeyTrigLabel, lfoKeyTrigTextEditor, rightColumn);
    setupBounds (lfoBeatSyncLabel, lfoBeatSyncTextEditor, rightColumn);
    setupBounds (lfoRateBeatSyncLabel, lfoRateBeatSyncTextEditor, rightColumn);
    setupBounds (grainSizePercLabel, grainSizePercTextEditor, rightColumn);
    setupBounds (grainScatLabel, grainScatTextEditor, rightColumn);
    setupBounds (grainPanRndLabel, grainPanRndTextEditor, rightColumn);
    setupBounds (grainDensityLabel, grainDensityTextEditor, rightColumn);
    setupBounds (sliceModeLabel, sliceModeTextEditor, rightColumn);
    setupBounds (legatoModeLabel, legatoModeTextEditor, rightColumn);
    setupBounds (gainSsrcWinLabel, gainSsrcWinTextEditor, rightColumn);
    setupBounds (grainReadSpeedLabel, grainReadSpeedTextEditor, rightColumn);
    setupBounds (recPresetLenLabel, recPresetLenTextEditor, rightColumn);
    setupBounds (recQuantLabel, recQuantTextEditor, rightColumn);
    setupBounds (recInputLabel, recInputTextEditor, rightColumn);
    setupBounds (recUseThresLabel, recUseThresTextEditor, rightColumn);
    setupBounds (recThresLabel, recThresTextEditor, rightColumn);
    setupBounds (recMonOutBusLabel, recMonOutBusTextEditor, rightColumn);
}


void SampleEditorComponent::paint (juce::Graphics& g)
{

}

void SampleEditorComponent::paintOverChildren (juce::Graphics& g)
{

}
