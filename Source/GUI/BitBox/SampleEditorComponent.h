#pragma once

#include <JuceHeader.h>
#include "../../BitBox/SampleProperties.h"
#include "../../Utility/CustomComboBox.h"
#include "../../Utility/CustomTextEditor.h"
#include "../../Utility/FileSelectLabel.h"
#include "../../Utility/NoArrowComboBoxLnF.h"
#include "../../Utility/RoundedSlideSwitch.h"

class SampleEditorComponent : public juce::Component,
                              public juce::FileDragAndDropTarget
{
public:
    SampleEditorComponent ();
    ~SampleEditorComponent () override;

    void init (juce::ValueTree samplePropertiesVT);
    bool loadFile (juce::String sampleFileName);

    juce::ValueTree getSamplePropertiesVT ();

private:
    SampleProperties sampleProperties;
    bool draggingFiles { false };
    bool supportedFile { false };
    juce::String dropMsg;
    juce::String dropDetails;

    juce::TextButton toolsButton;
    juce::Label sampleLengthLabel;

    // Edit fields
    juce::Label fileNameLabel;
    FileSelectLabel fileNameSelectLabel;
    juce::Label gainLabel;
    CustomTextEditorInt gainTextEditor; // -96 to +12db (mod)
    juce::Label pitchLabel;
    CustomTextEditorInt pitchTextEditor; // -24.0 to +24.0 (mod)
    juce::Label panPosLabel;
    CustomTextEditorInt panPosTextEditor; // -100% to 100% (mod)
    juce::Label samTrigTypeLabel;
    CustomComboBox samTrigTypeComboBox; // (launch mode?) Trigger, Gate, Toggle
    juce::Label loopModeLabel;
    CustomComboBox loopModeComboBox; // on/off
    juce::Label loopModesLabel; // ?
    CustomTextEditorInt loopModesTextEditor; // ?
    juce::Label midiModeLabel; // ?
    CustomTextEditorInt midiModeTextEditor; // ?
    juce::Label reverseLabel;
    CustomComboBox reverseComboBox; // on/off
    juce::Label cellModeLabel;
    CustomComboBox cellModeComboBox; // sample, clip, slicer, granular
    juce::Label envAttackLabel;
    CustomTextEditorInt envAttackTextEditor; // 0% to 100 % (mod)
    juce::Label envDecayLabel;
    CustomTextEditorInt envDecayTextEditor; // 0% to 100 % (mod)
    juce::Label envSusLabel;
    CustomTextEditorInt envSusTextEditor; // 0% to 100 %
    juce::Label envRelLabel;
    CustomTextEditorInt envRelTextEditor; // 0% to 100 % (mod)
    juce::Label samStartLabel;
    CustomTextEditorInt samStartTextEditor;
    juce::Label samLenLabel;
    CustomTextEditorInt samLenTextEditor;
    juce::Label loopStartLabel;
    CustomTextEditorInt loopStartTextEditor;
    juce::Label loopEndLabel;
    CustomTextEditorInt loopEndTextEditor;
    juce::Label quantSizeLabel;
    CustomTextEditorInt quantSizeTextEditor;
    juce::Label syncTypeLabel;
    CustomTextEditorInt syncTypeTextEditor;
    juce::Label actSliceLabel;
    CustomTextEditorInt actSliceTextEditor;
    juce::Label outputBusLabel;
    CustomComboBox outputBusComboBox;
    juce::Label polyModeLabel;
    CustomComboBox polyModeComboBox;
    juce::Label polyModeSliceLabel;
    CustomTextEditorInt polyModeSliceTextEditor;
    juce::Label sliceStepModeLabel;
    CustomComboBox sliceStepModeComboBox;

    juce::Label chokeGrpLabel;
    CustomTextEditorInt chokeGrpTextEditor;
    juce::Label dualFilCutoffLabel;
    CustomTextEditorInt dualFilCutoffTextEditor; // -100% to +100%, negative low pass, positive high pass (mod)
    juce::Label resLabel;
    CustomTextEditorInt resTextEditor; // 0% to 100 (mod)
    juce::Label rootNoteLabel;
    CustomTextEditorInt rootNoteTextEditor;
    juce::Label beatCountLabel;
    CustomTextEditorInt beatCountTextEditor;
    juce::Label fx1SendLabel;
    CustomTextEditorInt fx1SendTextEditor;
    juce::Label fx2SendLabel;
    CustomTextEditorInt fx2SendTextEditor;
    juce::Label multiSamModeLabel;
    CustomTextEditorInt multiSamModeTextEditor;
    juce::Label interpQualLabel;
    CustomTextEditorInt interpQualTextEditor;
    juce::Label playThruLabel;
    CustomTextEditorInt playThruTextEditor;
    juce::Label slicerQuantSizeLabel;
    CustomTextEditorInt slicerQuantSizeTextEditor;
    juce::Label slicerSyncLabel;
    CustomTextEditorInt slicerSyncTextEditor;
    juce::Label padNoteLabel;
    CustomTextEditorInt padNoteTextEditor;
    juce::Label loopFadeAmtLabel;
    CustomTextEditorInt loopFadeAmtTextEditor;
    juce::Label lfoWaveLabel;
    CustomComboBox lfoWaveComboBox;  // saw, rev saw, triangle, pos triangle, sine, pos sine, square, pos square, random
    juce::Label lfoRateLabel;
    CustomTextEditorInt lfoRateTextEditor;  // 0 to 100% [LFO BeatSyn off] (mod)
                                            // 8,4,2,1,1/2,1/2t,1/4,1/4t,1/8,1/8t1/16,1/16t,1/32,1/32t,1/64 [LFO BeatSyn on] (mod)
    juce::Label lfoAmountLabel;
    CustomTextEditorInt lfoAmountTextEditor; // 0 to 100% (mod)
    juce::Label lfoKeyTrigLabel;
                                                // TODO lfoKeyTrigTextEditor should be a switch
    CustomComboBox lfoKeyTrigComboBox;   // ON/OFF
    juce::Label lfoBeatSyncLabel;
                                                // TODO lfoBeatSyncTextEditor should be a switch
    CustomComboBox lfoBeatSyncComboBox;  // ON/OFF
    juce::Label lfoRateBeatSyncLabel;
    CustomTextEditorInt lfoRateBeatSyncTextEditor;
    juce::Label grainSizePercLabel;
    CustomTextEditorInt grainSizePercTextEditor;
    juce::Label grainScatLabel;
    CustomTextEditorInt grainScatTextEditor;
    juce::Label grainPanRndLabel;
    CustomTextEditorInt grainPanRndTextEditor;
    juce::Label grainDensityLabel;
    CustomTextEditorInt grainDensityTextEditor;
    juce::Label sliceModeLabel;
    CustomTextEditorInt sliceModeTextEditor;
    juce::Label legatoModeLabel;
    CustomTextEditorInt legatoModeTextEditor;
    juce::Label gainSsrcWinLabel;
    CustomTextEditorInt gainSsrcWinTextEditor;
    juce::Label grainReadSpeedLabel;
    CustomTextEditorInt grainReadSpeedTextEditor;
    juce::Label recPresetLenLabel;
    CustomTextEditorInt recPresetLenTextEditor;
    juce::Label recQuantLabel;
    CustomTextEditorInt recQuantTextEditor;
    juce::Label recInputLabel;
    CustomTextEditorInt recInputTextEditor;
    juce::Label recUseThresLabel;
    CustomTextEditorInt recUseThresTextEditor;
    juce::Label recThresLabel;
    CustomTextEditorInt recThresTextEditor;
    juce::Label recMonOutBusLabel;
    CustomTextEditorInt recMonOutBusTextEditor;

    NoArrowComboBoxLnF noArrowComboBoxLnF;

    void gainDataChanged (int gain);
    void pitchDataChanged (int pitch);
    void panPosDataChanged (int panPos);
    void samTrigTypeDataChanged (int samTrigType);
    void loopModeDataChanged (int loopMode);
    void loopModesDataChanged (int loopModes);
    void midiModeDataChanged (int midiMode);
    void reverseDataChanged (int reverse);
    void cellModeDataChanged (int cellMode);
    void envAttackDataChanged (int envAttack);
    void envDecayDataChanged (int envDecay);
    void envSusDataChanged (int envSus);
    void envRelDataChanged (int envRel);
    void samStartDataChanged (int samStart);
    void samLenDataChanged (int samLen);
    void loopStartDataChanged (int loopStart);
    void loopEndDataChanged (int loopEnd);
    void quantSizeDataChanged (int quantSize);
    void syncTypeDataChanged (int syncType);
    void actSliceDataChanged (int actSlice);
    void outputBusDataChanged (int outputBus);
    void polyModeDataChanged (int polyMode);
    void polyModeSliceDataChanged (int polyModeSlice);
    void sliceStepModeDataChanged (int sliceStepMode);
    void chokeGrpDataChanged (int chokeGrp);
    void dualFilCutoffDataChanged (int dualFilCutoff);
    void resDataChanged (int res);
    void rootNoteDataChanged (int rootNote);
    void beatCountDataChanged (int beatCount);
    void fx1SendDataChanged (int fx1Send);
    void fx2SendDataChanged (int fx2Send);
    void multiSamModeDataChanged (int multiSamMode);
    void interpQualDataChanged (int interpQual);
    void playThruDataChanged (int playThru);
    void slicerQuantSizeDataChanged (int slicerQuantSize);
    void slicerSyncDataChanged (int slicerSync);
    void padNoteDataChanged (int padNote);
    void loopFadeAmtDataChanged (int loopFadeAmt);
    void lfoWaveDataChanged (int lfoWave);
    void lfoRateDataChanged (int lfoRate);
    void lfoAmountDataChanged (int lfoAmount);
    void lfoKeyTrigDataChanged (int lfoKeyTrig);
    void lfoBeatSyncDataChanged (int lfoBeatSync);
    void lfoRateBeatSyncDataChanged (int lfoRateBeatSync);
    void grainSizePercDataChanged (int grainSizePerc);
    void grainScatDataChanged (int grainScat);
    void grainPanRndDataChanged (int grainPanRnd);
    void grainDensityDataChanged (int grainDensity);
    void sliceModeDataChanged (int sliceMode);
    void legatoModeDataChanged (int legatoMode);
    void gainSsrcWinDataChanged (int gainSsrcWin);
    void grainReadSpeedDataChanged (int grainReadSpeed);
    void recPresetLenDataChanged (int recPresetLen);
    void recQuantDataChanged (int recQuant);
    void recInputDataChanged (int recInput);
    void recUseThresDataChanged (int recUseThres);
    void recThresDataChanged (int recThres);
    void recMonOutBusDataChanged (int recMonOutBus);

    void gainUiChanged (int gain);
    void pitchUiChanged (int pitch);
    void panPosUiChanged (int panPos);
    void samTrigTypeUiChanged (int samTrigType);
    void loopModeUiChanged (int loopMode);
    void loopModesUiChanged (int loopModes);
    void midiModeUiChanged (int midiMode);
    void reverseUiChanged (int reverse);
    void cellModeUiChanged (int cellMode);
    void envAttackUiChanged (int envAttack);
    void envDecayUiChanged (int envDecay);
    void envSusUiChanged (int envSus);
    void envRelUiChanged (int envRel);
    void samStartUiChanged (int samStart);
    void samLenUiChanged (int samLen);
    void loopStartUiChanged (int loopStart);
    void loopEndUiChanged (int loopEnd);
    void quantSizeUiChanged (int quantSize);
    void syncTypeUiChanged (int syncType);
    void actSliceUiChanged (int actSlice);
    void outputBusUiChanged (int outputBus);
    void polyModeUiChanged (int polyMode);
    void polyModeSliceUiChanged (int polyModeSlice);
    void sliceStepModeUiChanged (int sliceStepMode);
    void chokeGrpUiChanged (int chokeGrp);
    void dualFilCutoffUiChanged (int dualFilCutoff);
    void resUiChanged (int res);
    void rootNoteUiChanged (int rootNote);
    void beatCountUiChanged (int beatCount);
    void fx1SendUiChanged (int fx1Send);
    void fx2SendUiChanged (int fx2Send);
    void multiSamModeUiChanged (int multiSamMode);
    void interpQualUiChanged (int interpQual);
    void playThruUiChanged (int playThru);
    void slicerQuantSizeUiChanged (int slicerQuantSize);
    void slicerSyncUiChanged (int slicerSync);
    void padNoteUiChanged (int padNote);
    void loopFadeAmtUiChanged (int loopFadeAmt);
    void lfoWaveUiChanged (int lfoWave);
    void lfoRateUiChanged (int lfoRate);
    void lfoAmountUiChanged (int lfoAmount);
    void lfoKeyTrigUiChanged (int lfoKeyTrig);
    void lfoBeatSyncUiChanged (int lfoBeatSync);
    void lfoRateBeatSyncUiChanged (int lfoRateBeatSync);
    void grainSizePercUiChanged (int grainSizePerc);
    void grainScatUiChanged (int grainScat);
    void grainPanRndUiChanged (int grainPanRnd);
    void grainDensityUiChanged (int grainDensity);
    void sliceModeUiChanged (int sliceMode);
    void legatoModeUiChanged (int legatoMode);
    void gainSsrcWinUiChanged (int gainSsrcWin);
    void grainReadSpeedUiChanged (int grainReadSpeed);
    void recPresetLenUiChanged (int recPresetLen);
    void recQuantUiChanged (int recQuant);
    void recInputUiChanged (int recInput);
    void recUseThresUiChanged (int recUseThres);
    void recThresUiChanged (int recThres);
    void recMonOutBusUiChanged (int recMonOutBus);

    bool isInterestedInFileDrag (const juce::StringArray& files) override;
    void filesDropped (const juce::StringArray& files, int, int) override;
    void fileDragEnter (const juce::StringArray& files, int, int) override;
    void fileDragExit (const juce::StringArray& files) override;

    void resized () override;
    void paint (juce::Graphics& g) override;
    void paintOverChildren (juce::Graphics& g) override;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SampleEditorComponent)
};