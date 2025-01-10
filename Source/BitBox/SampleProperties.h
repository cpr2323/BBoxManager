#pragma once
#include <JuceHeader.h>
#include "../Utility/ValueTreeWrapper.h"

#pragma once
#include <JuceHeader.h>
#include "../Utility/ValueTreeWrapper.h"

class SampleProperties : public ValueTreeWrapper<SampleProperties>
{
public:
    SampleProperties () noexcept : ValueTreeWrapper<SampleProperties> (SampleTypeId) {}
    SampleProperties (juce::ValueTree vt, WrapperType wrapperType, EnableCallbacks shouldEnableCallbacks)
        : ValueTreeWrapper<SampleProperties> (SampleTypeId, vt, wrapperType, shouldEnableCallbacks) {}

    void setFileName (juce::String fileName, bool includeSelfCallback);
    juce::String getFileName ();

    void setGainDb (int gainDb, bool includeSelfCallback);
    int getGainDb ();

    void setPitch (int pitch, bool includeSelfCallback);
    int getPitch ();

    void setPanPos (int panPos, bool includeSelfCallback);
    int getPanPos ();

    void setSamTrigType (int samTrigType, bool includeSelfCallback);
    int getSamTrigType ();

    void setLoopMode (int loopMode, bool includeSelfCallback);
    int getLoopMode ();

    void setLoopModes (int loopModes, bool includeSelfCallback);
    int getLoopModes ();

    void setMidiMode (int midiMode, bool includeSelfCallback);
    int getMidiMode ();

    void setReverse (int reverse, bool includeSelfCallback);
    int getReverse ();

    void setCellMode (int cellMode, bool includeSelfCallback);
    int getCellMode ();

    void setEnvAttack (int envAttack, bool includeSelfCallback);
    int getEnvAttack ();

    void setEnvDecay (int envDecay, bool includeSelfCallback);
    int getEnvDecay ();

    void setEnvSus (int envSus, bool includeSelfCallback);
    int getEnvSus ();

    void setEnvRel (int envRel, bool includeSelfCallback);
    int getEnvRel ();

    void setSamStart (int samStart, bool includeSelfCallback);
    int getSamStart ();

    void setSamLen (int samLen, bool includeSelfCallback);
    int getSamLen ();

    void setLoopStart (int loopStart, bool includeSelfCallback);
    int getLoopStart ();

    void setLoopEnd (int loopEnd, bool includeSelfCallback);
    int getLoopEnd ();

    void setQuantSize (int quantSize, bool includeSelfCallback);
    int getQuantSize ();

    void setSyncType (int syncType, bool includeSelfCallback);
    int getSyncType ();

    void setActSlice (int actSlice, bool includeSelfCallback);
    int getActSlice ();

    void setOutputBus (int outputBus, bool includeSelfCallback);
    int getOutputBus ();

    void setPolyMode (int polyMode, bool includeSelfCallback);
    int getPolyMode ();

    void setPolyModeSlice (int polyModeSlice, bool includeSelfCallback);
    int getPolyModeSlice ();

    void setSliceStepMode (int sliceStepMode, bool includeSelfCallback);
    int getSliceStepMode ();

    void setChokeGrp (int chokeGrp, bool includeSelfCallback);
    int getChokeGrp ();

    void setDualFilCutoff (int dualFilCutoff, bool includeSelfCallback);
    int getDualFilCutoff ();

    void setRes (int res, bool includeSelfCallback);
    int getRes ();

    void setRootNote (int rootNote, bool includeSelfCallback);
    int getRootNote ();

    void setBeatCount (int beatCount, bool includeSelfCallback);
    int getBeatCount ();

    void setFx1Send (int fx1Send, bool includeSelfCallback);
    int getFx1Send ();

    void setFx2Send (int fx2Send, bool includeSelfCallback);
    int getFx2Send ();

    void setMultiSamMode (int multiSamMode, bool includeSelfCallback);
    int getMultiSamMode ();

    void setInterpQual (int interpQual, bool includeSelfCallback);
    int getInterpQual ();

    void setPlayThru (int playThru, bool includeSelfCallback);
    int getPlayThru ();

    void setSlicerQuantSize (int slicerQuantSize, bool includeSelfCallback);
    int getSlicerQuantSize ();

    void setSlicerSync (int slicerSync, bool includeSelfCallback);
    int getSlicerSync ();

    void setPadNote (int padNote, bool includeSelfCallback);
    int getPadNote ();

    void setLoopFadeAmt (int loopFadeAmt, bool includeSelfCallback);
    int getLoopFadeAmt ();

    void setLfoWave (int lfoWave, bool includeSelfCallback);
    int getLfoWave ();

    void setLfoRate (int lfoRate, bool includeSelfCallback);
    int getLfoRate ();

    void setLfoAmount (int lfoAmount, bool includeSelfCallback);
    int getLfoAmount ();

    void setLfoKeyTrig (int lfoKeyTrig, bool includeSelfCallback);
    int getLfoKeyTrig ();

    void setLfoBeatSync (int lfoBeatSync, bool includeSelfCallback);
    int getLfoBeatSync ();

    void setLfoRateBeatSync (int lfoRateBeatSync, bool includeSelfCallback);
    int getLfoRateBeatSync ();

    void setGrainSizePerc (int grainSizePerc, bool includeSelfCallback);
    int getGrainSizePerc ();

    void setGrainScat (int grainScat, bool includeSelfCallback);
    int getGrainScat ();

    void setGrainPanRnd (int grainPanRnd, bool includeSelfCallback);
    int getGrainPanRnd ();

    void setGrainDensity (int grainDensity, bool includeSelfCallback);
    int getGrainDensity ();

    void setSliceMode (int sliceMode, bool includeSelfCallback);
    int getSliceMode ();

    void setLegatoMode (int legatoMode, bool includeSelfCallback);
    int getLegatoMode ();

    void setGainSsrcWin (int gainSsrcWin, bool includeSelfCallback);
    int getGainSsrcWin ();

    void setGrainReadSpeed (int grainReadSpeed, bool includeSelfCallback);
    int getGrainReadSpeed ();

    void setRecPresetLen (int recPresetLen, bool includeSelfCallback);
    int getRecPresetLen ();

    void setRecQuant (int recQuant, bool includeSelfCallback);
    int getRecQuant ();

    void setRecInput (int recInput, bool includeSelfCallback);
    int getRecInput ();

    void setRecUseThres (int recUseThres, bool includeSelfCallback);
    int getRecUseThres ();

    void setRecThres (int recThres, bool includeSelfCallback);
    int getRecThres ();

    void setRecMonOutBus (int recMonOutBus, bool includeSelfCallback);
    int getRecMonOutBus ();

    static inline const juce::Identifier SampleTypeId { "Sample" };
    static inline const juce::Identifier FileNamePropertyId { "fileName" };
    static inline const juce::Identifier GainDbPropertyId { "gainDb" };
    static inline const juce::Identifier PitchPropertyId { "pitch" };
    static inline const juce::Identifier PanPosPropertyId { "panPos" };
    static inline const juce::Identifier SamTrigTypePropertyId { "samTrigType" };
    static inline const juce::Identifier LoopModePropertyId { "loopMode" };
    static inline const juce::Identifier LoopModesPropertyId { "loopModes" };
    static inline const juce::Identifier MidiModePropertyId { "midiMode" };
    static inline const juce::Identifier ReversePropertyId { "reverse" };
    static inline const juce::Identifier CellModePropertyId { "cellMode" };
    static inline const juce::Identifier EnvAttackPropertyId { "envAttack" };
    static inline const juce::Identifier EnvDecayPropertyId { "envDecay" };
    static inline const juce::Identifier EnvSusPropertyId { "envSus" };
    static inline const juce::Identifier EnvRelPropertyId { "envRel" };
    static inline const juce::Identifier SamStartPropertyId { "samStart" };
    static inline const juce::Identifier SamLenPropertyId { "samLen" };
    static inline const juce::Identifier LoopStartPropertyId { "loopStart" };
    static inline const juce::Identifier LoopEndPropertyId { "loopEnd" };
    static inline const juce::Identifier QuantSizePropertyId { "quantSize" };
    static inline const juce::Identifier SyncTypePropertyId { "syncType" };
    static inline const juce::Identifier ActSlicePropertyId { "actSlice" };
    static inline const juce::Identifier OutputBusPropertyId { "outputBus" };
    static inline const juce::Identifier PolyModePropertyId { "polyMode" };
    static inline const juce::Identifier PolyModeSlicePropertyId { "polyModeSlice" };
    static inline const juce::Identifier SliceStepModePropertyId { "sliceStepMode" };
    static inline const juce::Identifier ChokeGrpPropertyId { "chokeGrp" };
    static inline const juce::Identifier DualFilCutoffPropertyId { "dualFilCutoff" };
    static inline const juce::Identifier ResPropertyId { "res" };
    static inline const juce::Identifier RootNotePropertyId { "rootNote" };
    static inline const juce::Identifier BeatCountPropertyId { "beatCount" };
    static inline const juce::Identifier Fx1SendPropertyId { "fx1Send" };
    static inline const juce::Identifier Fx2SendPropertyId { "fx2Send" };
    static inline const juce::Identifier MultiSamModePropertyId { "multiSamMode" };
    static inline const juce::Identifier InterpQualPropertyId { "interpQual" };
    static inline const juce::Identifier PlayThruPropertyId { "playThru" };
    static inline const juce::Identifier SlicerQuantSizePropertyId { "slicerQuantSize" };
    static inline const juce::Identifier SlicerSyncPropertyId { "slicerSync" };
    static inline const juce::Identifier PadNotePropertyId { "padNote" };
    static inline const juce::Identifier LoopFadeAmtPropertyId { "loopFadeAmt" };
    static inline const juce::Identifier LfoWavePropertyId { "lfoWave" };
    static inline const juce::Identifier LfoRatePropertyId { "lfoRate" };
    static inline const juce::Identifier LfoAmountPropertyId { "lfoAmount" };
    static inline const juce::Identifier LfoKeyTrigPropertyId { "lfoKeyTrig" };
    static inline const juce::Identifier LfoBeatSyncPropertyId { "lfoBeatSync" };
    static inline const juce::Identifier LfoRateBeatSyncPropertyId { "lfoRateBeatSync" };
    static inline const juce::Identifier GrainSizePercPropertyId { "grainSizePerc" };
    static inline const juce::Identifier GrainScatPropertyId { "grainScat" };
    static inline const juce::Identifier GrainPanRndPropertyId { "grainPanRnd" };
    static inline const juce::Identifier GrainDensityPropertyId { "grainDensity" };
    static inline const juce::Identifier SliceModePropertyId { "sliceMode" };
    static inline const juce::Identifier LegatoModePropertyId { "legatoMode" };
    static inline const juce::Identifier GainSsrcWinPropertyId { "gainSsrcWin" };
    static inline const juce::Identifier GrainReadSpeedPropertyId { "grainReadSpeed" };
    static inline const juce::Identifier RecPresetLenPropertyId { "recPresetLen" };
    static inline const juce::Identifier RecQuantPropertyId { "recQuant" };
    static inline const juce::Identifier RecInputPropertyId { "recInput" };
    static inline const juce::Identifier RecUseThresPropertyId { "recUseThres" };
    static inline const juce::Identifier RecThresPropertyId { "recThres" };
    static inline const juce::Identifier RecMonOutBusPropertyId { "recMonOutBus" };

    std::function<void (juce::String fileName)> onFileNameChange;
    std::function<void (int gainDb)> onGainDbChange;
    std::function<void (int pitch)> onPitchChange;
    std::function<void (int panPos)> onPanPosChange;
    std::function<void (int samTrigType)> onSamTrigTypeChange;
    std::function<void (int loopMode)> onLoopModeChange;
    std::function<void (int loopModes)> onLoopModesChange;
    std::function<void (int midiMode)> onMidiModeChange;
    std::function<void (int reverse)> onReverseChange;
    std::function<void (int cellMode)> onCellModeChange;
    std::function<void (int envAttack)> onEnvAttackChange;
    std::function<void (int envDecay)> onEnvDecayChange;
    std::function<void (int envSus)> onEnvSusChange;
    std::function<void (int envRel)> onEnvRelChange;
    std::function<void (int samStart)> onSamStartChange;
    std::function<void (int samLen)> onSamLenChange;
    std::function<void (int loopStart)> onLoopStartChange;
    std::function<void (int loopEnd)> onLoopEndChange;
    std::function<void (int quantSize)> onQuantSizeChange;
    std::function<void (int syncType)> onSyncTypeChange;
    std::function<void (int actSlice)> onActSliceChange;
    std::function<void (int outputBus)> onOutputBusChange;
    std::function<void (int polyMode)> onPolyModeChange;
    std::function<void (int polyModeSlice)> onPolyModeSliceChange;
    std::function<void (int sliceStepMode)> onSliceStepModeChange;
    std::function<void (int chokeGrp)> onChokeGrpChange;
    std::function<void (int dualFilCutoff)> onDualFilCutoffChange;
    std::function<void (int res)> onResChange;
    std::function<void (int rootNote)> onRootNoteChange;
    std::function<void (int beatCount)> onBeatCountChange;
    std::function<void (int fx1Send)> onFx1SendChange;
    std::function<void (int fx2Send)> onFx2SendChange;
    std::function<void (int multiSamMode)> onMultiSamModeChange;
    std::function<void (int interpQual)> onInterpQualChange;
    std::function<void (int playThru)> onPlayThruChange;
    std::function<void (int slicerQuantSize)> onSlicerQuantSizeChange;
    std::function<void (int slicerSync)> onSlicerSyncChange;
    std::function<void (int padNote)> onPadNoteChange;
    std::function<void (int loopFadeAmt)> onLoopFadeAmtChange;
    std::function<void (int lfoWave)> onLfoWaveChange;
    std::function<void (int lfoRate)> onLfoRateChange;
    std::function<void (int lfoAmount)> onLfoAmountChange;
    std::function<void (int lfoKeyTrig)> onLfoKeyTrigChange;
    std::function<void (int lfoBeatSync)> onLfoBeatSyncChange;
    std::function<void (int lfoRateBeatSync)> onLfoRateBeatSyncChange;
    std::function<void (int grainSizePerc)> onGrainSizePercChange;
    std::function<void (int grainScat)> onGrainScatChange;
    std::function<void (int grainPanRnd)> onGrainPanRndChange;
    std::function<void (int grainDensity)> onGrainDensityChange;
    std::function<void (int sliceMode)> onSliceModeChange;
    std::function<void (int legatoMode)> onLegatoModeChange;
    std::function<void (int gainSsrcWin)> onGainSsrcWinChange;
    std::function<void (int grainReadSpeed)> onGrainReadSpeedChange;
    std::function<void (int recPresetLen)> onRecPresetLenChange;
    std::function<void (int recQuant)> onRecQuantChange;
    std::function<void (int recInput)> onRecInputChange;
    std::function<void (int recUseThres)> onRecUseThresChange;
    std::function<void (int recThres)> onRecThresChange;
    std::function<void (int recMonOutBus)> onRecMonOutBusChange;

    void copyPropertiesFrom (juce::ValueTree source);

    void initValueTree () {}
    void processValueTree () {}

private:
    void valueTreePropertyChanged (juce::ValueTree& treeWhosePropertyHasChanged, const juce::Identifier& property) override;
};