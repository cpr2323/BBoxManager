#include "SampleProperties.h"

void SampleProperties::setFileName (juce::String fileName, bool includeSelfCallback) { setValue (fileName, FileNamePropertyId, includeSelfCallback); }
juce::String SampleProperties::getFileName () { return getValue<juce::String> (FileNamePropertyId); }

void SampleProperties::setGainDb (int gainDb, bool includeSelfCallback) { setValue (gainDb, GainDbPropertyId, includeSelfCallback); }
int SampleProperties::getGainDb () { return getValue<int> (GainDbPropertyId); }

void SampleProperties::setPitch (int pitch, bool includeSelfCallback) { setValue (pitch, PitchPropertyId, includeSelfCallback); }
int SampleProperties::getPitch () { return getValue<int> (PitchPropertyId); }

void SampleProperties::setPanPos (int panPos, bool includeSelfCallback) { setValue (panPos, PanPosPropertyId, includeSelfCallback); }
int SampleProperties::getPanPos () { return getValue<int> (PanPosPropertyId); }

void SampleProperties::setSamTrigType (int samTrigType, bool includeSelfCallback) { setValue (samTrigType, SamTrigTypePropertyId, includeSelfCallback); }
int SampleProperties::getSamTrigType () { return getValue<int> (SamTrigTypePropertyId); }

void SampleProperties::setLoopMode (int loopMode, bool includeSelfCallback) { setValue (loopMode, LoopModePropertyId, includeSelfCallback); }
int SampleProperties::getLoopMode () { return getValue<int> (LoopModePropertyId); }

void SampleProperties::setLoopModes (int loopModes, bool includeSelfCallback) { setValue (loopModes, LoopModesPropertyId, includeSelfCallback); }
int SampleProperties::getLoopModes () { return getValue<int> (LoopModesPropertyId); }

void SampleProperties::setMidiMode (int midiMode, bool includeSelfCallback) { setValue (midiMode, MidiModePropertyId, includeSelfCallback); }
int SampleProperties::getMidiMode () { return getValue<int> (MidiModePropertyId); }

void SampleProperties::setReverse (int reverse, bool includeSelfCallback) { setValue (reverse, ReversePropertyId, includeSelfCallback); }
int SampleProperties::getReverse () { return getValue<int> (ReversePropertyId); }

void SampleProperties::setCellMode (int cellMode, bool includeSelfCallback) { setValue (cellMode, CellModePropertyId, includeSelfCallback); }
int SampleProperties::getCellMode () { return getValue<int> (CellModePropertyId); }

void SampleProperties::setEnvAttack (int envAttack, bool includeSelfCallback) { setValue (envAttack, EnvAttackPropertyId, includeSelfCallback); }
int SampleProperties::getEnvAttack () { return getValue<int> (EnvAttackPropertyId); }

void SampleProperties::setEnvDecay (int envDecay, bool includeSelfCallback) { setValue (envDecay, EnvDecayPropertyId, includeSelfCallback); }
int SampleProperties::getEnvDecay () { return getValue<int> (EnvDecayPropertyId); }

void SampleProperties::setEnvSus (int envSus, bool includeSelfCallback) { setValue (envSus, EnvSusPropertyId, includeSelfCallback); }
int SampleProperties::getEnvSus () { return getValue<int> (EnvSusPropertyId); }

void SampleProperties::setEnvRel (int envRel, bool includeSelfCallback) { setValue (envRel, EnvRelPropertyId, includeSelfCallback); }
int SampleProperties::getEnvRel () { return getValue<int> (EnvRelPropertyId); }

void SampleProperties::setSamStart (int samStart, bool includeSelfCallback) { setValue (samStart, SamStartPropertyId, includeSelfCallback); }
int SampleProperties::getSamStart () { return getValue<int> (SamStartPropertyId); }

void SampleProperties::setSamLen (int samLen, bool includeSelfCallback) { setValue (samLen, SamLenPropertyId, includeSelfCallback); }
int SampleProperties::getSamLen () { return getValue<int> (SamLenPropertyId); }

void SampleProperties::setLoopStart (int loopStart, bool includeSelfCallback) { setValue (loopStart, LoopStartPropertyId, includeSelfCallback); }
int SampleProperties::getLoopStart () { return getValue<int> (LoopStartPropertyId); }

void SampleProperties::setLoopEnd (int loopEnd, bool includeSelfCallback) { setValue (loopEnd, LoopEndPropertyId, includeSelfCallback); }
int SampleProperties::getLoopEnd () { return getValue<int> (LoopEndPropertyId); }

void SampleProperties::setQuantSize (int quantSize, bool includeSelfCallback) { setValue (quantSize, QuantSizePropertyId, includeSelfCallback); }
int SampleProperties::getQuantSize () { return getValue<int> (QuantSizePropertyId); }

void SampleProperties::setSyncType (int syncType, bool includeSelfCallback) { setValue (syncType, SyncTypePropertyId, includeSelfCallback); }
int SampleProperties::getSyncType () { return getValue<int> (SyncTypePropertyId); }

void SampleProperties::setActSlice (int actSlice, bool includeSelfCallback) { setValue (actSlice, ActSlicePropertyId, includeSelfCallback); }
int SampleProperties::getActSlice () { return getValue<int> (ActSlicePropertyId); }

void SampleProperties::setOutputBus (int outputBus, bool includeSelfCallback) { setValue (outputBus, OutputBusPropertyId, includeSelfCallback); }
int SampleProperties::getOutputBus () { return getValue<int> (OutputBusPropertyId); }

void SampleProperties::setPolyMode (int polyMode, bool includeSelfCallback) { setValue (polyMode, PolyModePropertyId, includeSelfCallback); }
int SampleProperties::getPolyMode () { return getValue<int> (PolyModePropertyId); }

void SampleProperties::setPolyModeSlice (int polyModeSlice, bool includeSelfCallback) { setValue (polyModeSlice, PolyModeSlicePropertyId, includeSelfCallback); }
int SampleProperties::getPolyModeSlice () { return getValue<int> (PolyModeSlicePropertyId); }

void SampleProperties::setSliceStepMode (int sliceStepMode, bool includeSelfCallback) { setValue (sliceStepMode, SliceStepModePropertyId, includeSelfCallback); }
int SampleProperties::getSliceStepMode () { return getValue<int> (SliceStepModePropertyId); }

void SampleProperties::setChokeGrp (int chokeGrp, bool includeSelfCallback) { setValue (chokeGrp, ChokeGrpPropertyId, includeSelfCallback); }
int SampleProperties::getChokeGrp () { return getValue<int> (ChokeGrpPropertyId); }

void SampleProperties::setDualFilCutoff (int dualFilCutoff, bool includeSelfCallback) { setValue (dualFilCutoff, DualFilCutoffPropertyId, includeSelfCallback); }
int SampleProperties::getDualFilCutoff () { return getValue<int> (DualFilCutoffPropertyId); }

void SampleProperties::setRes (int res, bool includeSelfCallback) { setValue (res, ResPropertyId, includeSelfCallback); }
int SampleProperties::getRes () { return getValue<int> (ResPropertyId); }

void SampleProperties::setRootNote (int rootNote, bool includeSelfCallback) { setValue (rootNote, RootNotePropertyId, includeSelfCallback); }
int SampleProperties::getRootNote () { return getValue<int> (RootNotePropertyId); }

void SampleProperties::setBeatCount (int beatCount, bool includeSelfCallback) { setValue (beatCount, BeatCountPropertyId, includeSelfCallback); }
int SampleProperties::getBeatCount () { return getValue<int> (BeatCountPropertyId); }

void SampleProperties::setFx1Send (int fx1Send, bool includeSelfCallback) { setValue (fx1Send, Fx1SendPropertyId, includeSelfCallback); }
int SampleProperties::getFx1Send () { return getValue<int> (Fx1SendPropertyId); }

void SampleProperties::setFx2Send (int fx2Send, bool includeSelfCallback) { setValue (fx2Send, Fx2SendPropertyId, includeSelfCallback); }
int SampleProperties::getFx2Send () { return getValue<int> (Fx2SendPropertyId); }

void SampleProperties::setMultiSamMode (int multiSamMode, bool includeSelfCallback) { setValue (multiSamMode, MultiSamModePropertyId, includeSelfCallback); }
int SampleProperties::getMultiSamMode () { return getValue<int> (MultiSamModePropertyId); }

void SampleProperties::setInterpQual (int interpQual, bool includeSelfCallback) { setValue (interpQual, InterpQualPropertyId, includeSelfCallback); }
int SampleProperties::getInterpQual () { return getValue<int> (InterpQualPropertyId); }

void SampleProperties::setPlayThru (int playThru, bool includeSelfCallback) { setValue (playThru, PlayThruPropertyId, includeSelfCallback); }
int SampleProperties::getPlayThru () { return getValue<int> (PlayThruPropertyId); }

void SampleProperties::setSlicerQuantSize (int slicerQuantSize, bool includeSelfCallback) { setValue (slicerQuantSize, SlicerQuantSizePropertyId, includeSelfCallback); }
int SampleProperties::getSlicerQuantSize () { return getValue<int> (SlicerQuantSizePropertyId); }

void SampleProperties::setSlicerSync (int slicerSync, bool includeSelfCallback) { setValue (slicerSync, SlicerSyncPropertyId, includeSelfCallback); }
int SampleProperties::getSlicerSync () { return getValue<int> (SlicerSyncPropertyId); }

void SampleProperties::setPadNote (int padNote, bool includeSelfCallback) { setValue (padNote, PadNotePropertyId, includeSelfCallback); }
int SampleProperties::getPadNote () { return getValue<int> (PadNotePropertyId); }

void SampleProperties::setLoopFadeAmt (int loopFadeAmt, bool includeSelfCallback) { setValue (loopFadeAmt, LoopFadeAmtPropertyId, includeSelfCallback); }
int SampleProperties::getLoopFadeAmt () { return getValue<int> (LoopFadeAmtPropertyId); }

void SampleProperties::setLfoWave (int lfoWave, bool includeSelfCallback) { setValue (lfoWave, LfoWavePropertyId, includeSelfCallback); }
int SampleProperties::getLfoWave () { return getValue<int> (LfoWavePropertyId); }

void SampleProperties::setLfoRate (int lfoRate, bool includeSelfCallback) { setValue (lfoRate, LfoRatePropertyId, includeSelfCallback); }
int SampleProperties::getLfoRate () { return getValue<int> (LfoRatePropertyId); }

void SampleProperties::setLfoAmount (int lfoAmount, bool includeSelfCallback) { setValue (lfoAmount, LfoAmountPropertyId, includeSelfCallback); }
int SampleProperties::getLfoAmount () { return getValue<int> (LfoAmountPropertyId); }

void SampleProperties::setLfoKeyTrig (int lfoKeyTrig, bool includeSelfCallback) { setValue (lfoKeyTrig, LfoKeyTrigPropertyId, includeSelfCallback); }
int SampleProperties::getLfoKeyTrig () { return getValue<int> (LfoKeyTrigPropertyId); }

void SampleProperties::setLfoBeatSync (int lfoBeatSync, bool includeSelfCallback) { setValue (lfoBeatSync, LfoBeatSyncPropertyId, includeSelfCallback); }
int SampleProperties::getLfoBeatSync () { return getValue<int> (LfoBeatSyncPropertyId); }

void SampleProperties::setLfoRateBeatSync (int lfoRateBeatSync, bool includeSelfCallback) { setValue (lfoRateBeatSync, LfoRateBeatSyncPropertyId, includeSelfCallback); }
int SampleProperties::getLfoRateBeatSync () { return getValue<int> (LfoRateBeatSyncPropertyId); }

void SampleProperties::setGrainSizePerc (int grainSizePerc, bool includeSelfCallback) { setValue (grainSizePerc, GrainSizePercPropertyId, includeSelfCallback); }
int SampleProperties::getGrainSizePerc () { return getValue<int> (GrainSizePercPropertyId); }

void SampleProperties::setGrainScat (int grainScat, bool includeSelfCallback) { setValue (grainScat, GrainScatPropertyId, includeSelfCallback); }
int SampleProperties::getGrainScat () { return getValue<int> (GrainScatPropertyId); }

void SampleProperties::setGrainPanRnd (int grainPanRnd, bool includeSelfCallback) { setValue (grainPanRnd, GrainPanRndPropertyId, includeSelfCallback); }
int SampleProperties::getGrainPanRnd () { return getValue<int> (GrainPanRndPropertyId); }

void SampleProperties::setGrainDensity (int grainDensity, bool includeSelfCallback) { setValue (grainDensity, GrainDensityPropertyId, includeSelfCallback); }
int SampleProperties::getGrainDensity () { return getValue<int> (GrainDensityPropertyId); }

void SampleProperties::setSliceMode (int sliceMode, bool includeSelfCallback) { setValue (sliceMode, SliceModePropertyId, includeSelfCallback); }
int SampleProperties::getSliceMode () { return getValue<int> (SliceModePropertyId); }

void SampleProperties::setLegatoMode (int legatoMode, bool includeSelfCallback) { setValue (legatoMode, LegatoModePropertyId, includeSelfCallback); }
int SampleProperties::getLegatoMode () { return getValue<int> (LegatoModePropertyId); }

void SampleProperties::setGrainsSrcWin (int grainsSrcWin, bool includeSelfCallback) { setValue (grainsSrcWin, GrainsSrcWinPropertyId, includeSelfCallback); }
int SampleProperties::getGrainsSrcWin () { return getValue<int> (GrainsSrcWinPropertyId); }

void SampleProperties::setGrainReadSpeed (int grainReadSpeed, bool includeSelfCallback) { setValue (grainReadSpeed, GrainReadSpeedPropertyId, includeSelfCallback); }
int SampleProperties::getGrainReadSpeed () { return getValue<int> (GrainReadSpeedPropertyId); }

void SampleProperties::setRecPresetLen (int recPresetLen, bool includeSelfCallback) { setValue (recPresetLen, RecPresetLenPropertyId, includeSelfCallback); }
int SampleProperties::getRecPresetLen () { return getValue<int> (RecPresetLenPropertyId); }

void SampleProperties::setRecQuant (int recQuant, bool includeSelfCallback) { setValue (recQuant, RecQuantPropertyId, includeSelfCallback); }
int SampleProperties::getRecQuant () { return getValue<int> (RecQuantPropertyId); }

void SampleProperties::setRecInput (int recInput, bool includeSelfCallback) { setValue (recInput, RecInputPropertyId, includeSelfCallback); }
int SampleProperties::getRecInput () { return getValue<int> (RecInputPropertyId); }

void SampleProperties::setRecUseThres (int recUseThres, bool includeSelfCallback) { setValue (recUseThres, RecUseThresPropertyId, includeSelfCallback); }
int SampleProperties::getRecUseThres () { return getValue<int> (RecUseThresPropertyId); }

void SampleProperties::setRecThres (int recThres, bool includeSelfCallback) { setValue (recThres, RecThresPropertyId, includeSelfCallback); }
int SampleProperties::getRecThres () { return getValue<int> (RecThresPropertyId); }

void SampleProperties::setRecMonOutBus (int recMonOutBus, bool includeSelfCallback) { setValue (recMonOutBus, RecMonOutBusPropertyId, includeSelfCallback); }
int SampleProperties::getRecMonOutBus () { return getValue<int> (RecMonOutBusPropertyId); }

void SampleProperties::copyPropertiesFrom (juce::ValueTree source)
{
    SampleProperties srcSampleProperties { source, SampleProperties::WrapperType::client, SampleProperties::EnableCallbacks::no };
    // set properties
    setGainDb (srcSampleProperties.getGainDb (), false);
    setPitch (srcSampleProperties.getPitch (), false);
    setPanPos (srcSampleProperties.getPanPos (), false);
    setSamTrigType (srcSampleProperties.getSamTrigType (), false);
    setLoopMode (srcSampleProperties.getLoopMode (), false);
    setLoopModes (srcSampleProperties.getLoopModes (), false);
    setMidiMode (srcSampleProperties.getMidiMode (), false);
    setReverse (srcSampleProperties.getReverse (), false);
    setCellMode (srcSampleProperties.getCellMode (), false);
    setEnvAttack (srcSampleProperties.getEnvAttack (), false);
    setEnvDecay (srcSampleProperties.getEnvDecay (), false);
    setEnvSus (srcSampleProperties.getEnvSus (), false);
    setEnvRel (srcSampleProperties.getEnvRel (), false);
    setSamStart (srcSampleProperties.getSamStart (), false);
    setSamLen (srcSampleProperties.getSamLen (), false);
    setLoopStart (srcSampleProperties.getLoopStart (), false);
    setLoopEnd (srcSampleProperties.getLoopEnd (), false);
    setQuantSize (srcSampleProperties.getQuantSize (), false);
    setSyncType (srcSampleProperties.getSyncType (), false);
    setActSlice (srcSampleProperties.getActSlice (), false);
    setOutputBus (srcSampleProperties.getOutputBus (), false);
    setPolyMode (srcSampleProperties.getPolyMode (), false);
    setPolyModeSlice (srcSampleProperties.getPolyModeSlice (), false);
    setSliceStepMode (srcSampleProperties.getSliceStepMode (), false);
    setChokeGrp (srcSampleProperties.getChokeGrp (), false);
    setDualFilCutoff (srcSampleProperties.getDualFilCutoff (), false);
    setRes (srcSampleProperties.getRes (), false);
    setRootNote (srcSampleProperties.getRootNote (), false);
    setBeatCount (srcSampleProperties.getBeatCount (), false);
    setFx1Send (srcSampleProperties.getFx1Send (), false);
    setFx2Send (srcSampleProperties.getFx2Send (), false);
    setMultiSamMode (srcSampleProperties.getMultiSamMode (), false);
    setInterpQual (srcSampleProperties.getInterpQual (), false);
    setPlayThru (srcSampleProperties.getPlayThru (), false);
    setSlicerQuantSize (srcSampleProperties.getSlicerQuantSize (), false);
    setSlicerSync (srcSampleProperties.getSlicerSync (), false);
    setPadNote (srcSampleProperties.getPadNote (), false);
    setLoopFadeAmt (srcSampleProperties.getLoopFadeAmt (), false);
    setLfoWave (srcSampleProperties.getLfoWave (), false);
    setLfoRate (srcSampleProperties.getLfoRate (), false);
    setLfoAmount (srcSampleProperties.getLfoAmount (), false);
    setLfoKeyTrig (srcSampleProperties.getLfoKeyTrig (), false);
    setLfoBeatSync (srcSampleProperties.getLfoBeatSync (), false);
    setLfoRateBeatSync (srcSampleProperties.getLfoRateBeatSync (), false);
    setGrainSizePerc (srcSampleProperties.getGrainSizePerc (), false);
    setGrainScat (srcSampleProperties.getGrainScat (), false);
    setGrainPanRnd (srcSampleProperties.getGrainPanRnd (), false);
    setGrainDensity (srcSampleProperties.getGrainDensity (), false);
    setSliceMode (srcSampleProperties.getSliceMode (), false);
    setLegatoMode (srcSampleProperties.getLegatoMode (), false);
    setGrainsSrcWin (srcSampleProperties.getGrainsSrcWin (), false);
    setGrainReadSpeed (srcSampleProperties.getGrainReadSpeed (), false);
    setRecPresetLen (srcSampleProperties.getRecPresetLen (), false);
    setRecQuant (srcSampleProperties.getRecQuant (), false);
    setRecInput (srcSampleProperties.getRecInput (), false);
    setRecUseThres (srcSampleProperties.getRecUseThres (), false);
    setRecThres (srcSampleProperties.getRecThres (), false);
    setRecMonOutBus (srcSampleProperties.getRecMonOutBus (), false);
}

void SampleProperties::valueTreePropertyChanged (juce::ValueTree& treeWhosePropertyHasChanged, const juce::Identifier& property)
{
    if (treeWhosePropertyHasChanged == data)
    {
        if (property == FileNamePropertyId)
        {
            if (onFileNameChange != nullptr)
                onFileNameChange (getFileName ());
        }
        else if (property == GainDbPropertyId)
        {
            if (onGainDbChange != nullptr)
                onGainDbChange (getGainDb ());
        }
        else if (property == PitchPropertyId)
        {
            if (onPitchChange != nullptr)
                onPitchChange (getPitch ());
        }
        else if (property == PanPosPropertyId)
        {
            if (onPanPosChange != nullptr)
                onPanPosChange (getPanPos ());
        }
        else if (property == SamTrigTypePropertyId)
        {
            if (onSamTrigTypeChange != nullptr)
                onSamTrigTypeChange (getSamTrigType ());
        }
        else if (property == LoopModePropertyId)
        {
            if (onLoopModeChange != nullptr)
                onLoopModeChange (getLoopMode ());
        }
        else if (property == LoopModesPropertyId)
        {
            if (onLoopModesChange != nullptr)
                onLoopModesChange (getLoopModes ());
        }
        else if (property == MidiModePropertyId)
        {
            if (onMidiModeChange != nullptr)
                onMidiModeChange (getMidiMode ());
        }
        else if (property == ReversePropertyId)
        {
            if (onReverseChange != nullptr)
                onReverseChange (getReverse ());
        }
        else if (property == CellModePropertyId)
        {
            if (onCellModeChange != nullptr)
                onCellModeChange (getCellMode ());
        }
        else if (property == EnvAttackPropertyId)
        {
            if (onEnvAttackChange != nullptr)
                onEnvAttackChange (getEnvAttack ());
        }
        else if (property == EnvDecayPropertyId)
        {
            if (onEnvDecayChange != nullptr)
                onEnvDecayChange (getEnvDecay ());
        }
        else if (property == EnvSusPropertyId)
        {
            if (onEnvSusChange != nullptr)
                onEnvSusChange (getEnvSus ());
        }
        else if (property == EnvRelPropertyId)
        {
            if (onEnvRelChange != nullptr)
                onEnvRelChange (getEnvRel ());
        }
        else if (property == SamStartPropertyId)
        {
            if (onSamStartChange != nullptr)
                onSamStartChange (getSamStart ());
        }
        else if (property == SamLenPropertyId)
        {
            if (onSamLenChange != nullptr)
                onSamLenChange (getSamLen ());
        }
        else if (property == LoopStartPropertyId)
        {
            if (onLoopStartChange != nullptr)
                onLoopStartChange (getLoopStart ());
        }
        else if (property == LoopEndPropertyId)
        {
            if (onLoopEndChange != nullptr)
                onLoopEndChange (getLoopEnd ());
        }
        else if (property == QuantSizePropertyId)
        {
            if (onQuantSizeChange != nullptr)
                onQuantSizeChange (getQuantSize ());
        }
        else if (property == SyncTypePropertyId)
        {
            if (onSyncTypeChange != nullptr)
                onSyncTypeChange (getSyncType ());
        }
        else if (property == ActSlicePropertyId)
        {
            if (onActSliceChange != nullptr)
                onActSliceChange (getActSlice ());
        }
        else if (property == OutputBusPropertyId)
        {
            if (onOutputBusChange != nullptr)
                onOutputBusChange (getOutputBus ());
        }
        else if (property == PolyModePropertyId)
        {
            if (onPolyModeChange != nullptr)
                onPolyModeChange (getPolyMode ());
        }
        else if (property == PolyModeSlicePropertyId)
        {
            if (onPolyModeSliceChange != nullptr)
                onPolyModeSliceChange (getPolyModeSlice ());
        }
        else if (property == SliceStepModePropertyId)
        {
            if (onSliceStepModeChange != nullptr)
                onSliceStepModeChange (getSliceStepMode ());
        }
        else if (property == ChokeGrpPropertyId)
        {
            if (onChokeGrpChange != nullptr)
                onChokeGrpChange (getChokeGrp ());
        }
        else if (property == DualFilCutoffPropertyId)
        {
            if (onDualFilCutoffChange != nullptr)
                onDualFilCutoffChange (getDualFilCutoff ());
        }
        else if (property == ResPropertyId)
        {
            if (onResChange != nullptr)
                onResChange (getRes ());
        }
        else if (property == RootNotePropertyId)
        {
            if (onRootNoteChange != nullptr)
                onRootNoteChange (getRootNote ());
        }
        else if (property == BeatCountPropertyId)
        {
            if (onBeatCountChange != nullptr)
                onBeatCountChange (getBeatCount ());
        }
        else if (property == Fx1SendPropertyId)
        {
            if (onFx1SendChange != nullptr)
                onFx1SendChange (getFx1Send ());
        }
        else if (property == Fx2SendPropertyId)
        {
            if (onFx2SendChange != nullptr)
                onFx2SendChange (getFx2Send ());
        }
        else if (property == MultiSamModePropertyId)
        {
            if (onMultiSamModeChange != nullptr)
                onMultiSamModeChange (getMultiSamMode ());
        }
        else if (property == InterpQualPropertyId)
        {
            if (onInterpQualChange != nullptr)
                onInterpQualChange (getInterpQual ());
        }
        else if (property == PlayThruPropertyId)
        {
            if (onPlayThruChange != nullptr)
                onPlayThruChange (getPlayThru ());
        }
        else if (property == SlicerQuantSizePropertyId)
        {
            if (onSlicerQuantSizeChange != nullptr)
                onSlicerQuantSizeChange (getSlicerQuantSize ());
        }
        else if (property == SlicerSyncPropertyId)
        {
            if (onSlicerSyncChange != nullptr)
                onSlicerSyncChange (getSlicerSync ());
        }
        else if (property == PadNotePropertyId)
        {
            if (onPadNoteChange != nullptr)
                onPadNoteChange (getPadNote ());
        }
        else if (property == LoopFadeAmtPropertyId)
        {
            if (onLoopFadeAmtChange != nullptr)
                onLoopFadeAmtChange (getLoopFadeAmt ());
        }
        else if (property == LfoWavePropertyId)
        {
            if (onLfoWaveChange != nullptr)
                onLfoWaveChange (getLfoWave ());
        }
        else if (property == LfoRatePropertyId)
        {
            if (onLfoRateChange != nullptr)
                onLfoRateChange (getLfoRate ());
        }
        else if (property == LfoAmountPropertyId)
        {
            if (onLfoAmountChange != nullptr)
                onLfoAmountChange (getLfoAmount ());
        }
        else if (property == LfoKeyTrigPropertyId)
        {
            if (onLfoKeyTrigChange != nullptr)
                onLfoKeyTrigChange (getLfoKeyTrig ());
        }
        else if (property == LfoBeatSyncPropertyId)
        {
            if (onLfoBeatSyncChange != nullptr)
                onLfoBeatSyncChange (getLfoBeatSync ());
        }
        else if (property == LfoRateBeatSyncPropertyId)
        {
            if (onLfoRateBeatSyncChange != nullptr)
                onLfoRateBeatSyncChange (getLfoRateBeatSync ());
        }
        else if (property == GrainSizePercPropertyId)
        {
            if (onGrainSizePercChange != nullptr)
                onGrainSizePercChange (getGrainSizePerc ());
        }
        else if (property == GrainScatPropertyId)
        {
            if (onGrainScatChange != nullptr)
                onGrainScatChange (getGrainScat ());
        }
        else if (property == GrainPanRndPropertyId)
        {
            if (onGrainPanRndChange != nullptr)
                onGrainPanRndChange (getGrainPanRnd ());
        }
        else if (property == GrainDensityPropertyId)
        {
            if (onGrainDensityChange != nullptr)
                onGrainDensityChange (getGrainDensity ());
        }
        else if (property == SliceModePropertyId)
        {
            if (onSliceModeChange != nullptr)
                onSliceModeChange (getSliceMode ());
        }
        else if (property == LegatoModePropertyId)
        {
            if (onLegatoModeChange != nullptr)
                onLegatoModeChange (getLegatoMode ());
        }
        else if (property == GrainsSrcWinPropertyId)
        {
            if (onGrainsSrcWinChange != nullptr)
                onGrainsSrcWinChange (getGrainsSrcWin ());
        }
        else if (property == GrainReadSpeedPropertyId)
        {
            if (onGrainReadSpeedChange != nullptr)
                onGrainReadSpeedChange (getGrainReadSpeed ());
        }
        else if (property == RecPresetLenPropertyId)
        {
            if (onRecPresetLenChange != nullptr)
                onRecPresetLenChange (getRecPresetLen ());
        }
        else if (property == RecQuantPropertyId)
        {
            if (onRecQuantChange != nullptr)
                onRecQuantChange (getRecQuant ());
        }
        else if (property == RecInputPropertyId)
        {
            if (onRecInputChange != nullptr)
                onRecInputChange (getRecInput ());
        }
        else if (property == RecUseThresPropertyId)
        {
            if (onRecUseThresChange != nullptr)
                onRecUseThresChange (getRecUseThres ());
        }
        else if (property == RecThresPropertyId)
        {
            if (onRecThresChange != nullptr)
                onRecThresChange (getRecThres ());
        }
        else if (property == RecMonOutBusPropertyId)
        {
            if (onRecMonOutBusChange != nullptr)
                onRecMonOutBusChange (getRecMonOutBus ());
        }
    }
}