#include "SampleEditorComponent.h"

SampleEditorComponent::SampleEditorComponent ()
{
    auto setupEditor = [this] (juce::Label& label, juce::String text, juce::Component& editor)
    {
        label.setColour (juce::Label::textColourId, juce::Colours::black);
        label.setText (text, juce::dontSendNotification);
        addAndMakeVisible (label);
        addAndMakeVisible (editor);
    };

    auto setupComboBox = [this] (juce::Label& label, juce::String text, juce::Component& combobox)
    {
        label.setColour (juce::Label::textColourId, juce::Colours::black);
        label.setText (text, juce::dontSendNotification);
        addAndMakeVisible (label);
        addAndMakeVisible (combobox);
    };

    fileNameSelectLabel.setColour (juce::Label::ColourIds::textColourId, juce::Colours::white);
    fileNameSelectLabel.setColour (juce::Label::ColourIds::backgroundColourId, juce::Colours::black);
    fileNameSelectLabel.setOutline (juce::Colours::white);
    setupEditor (fileNameLabel, "File Name", fileNameSelectLabel);
    fileNameSelectLabel.onFilesSelected = [this] (const juce::StringArray& files)
    {
        // if (!handleSampleAssignment (files [0]))
        // {
        //     // TODO - indicate an error? first thought was a red outline that fades out over a couple of second
        // }
    };
    fileNameSelectLabel.onPopupMenuCallback = [this] ()
    {
        // Clone
        // Revert
    };
    addAndMakeVisible (fileNameSelectLabel);

    // GAIN
    gainTextEditor.setTooltip ("Gain in decibels");
    gainTextEditor.getMinValueCallback = [this] () { return -96; };
    gainTextEditor.getMaxValueCallback = [this] () { return 12; };
    gainTextEditor.toStringCallback = [this] (int value) { return juce::String (value); };
    gainTextEditor.updateDataCallback = [this] (int value) { gainUiChanged (value); };
    gainTextEditor.onDragCallback = [this] (DragSpeed dragSpeed, int direction)
    {
        const auto multiplier = [dragSpeed] ()
            {
                if (dragSpeed == DragSpeed::slow)
                    return 1;
                else if (dragSpeed == DragSpeed::medium)
                    return 10;
                else
                    return 25;
            } ();
        const auto newValue { sampleProperties.getGainDb () + (multiplier * direction) };
        gainTextEditor.setValue (newValue);
    };
    gainTextEditor.onPopupMenuCallback = [this] () {};
    setupEditor (gainLabel, "Gain (dB)", gainTextEditor);

    // PITCH
    pitchTextEditor.setTooltip ("Pitch in semitones");
    pitchTextEditor.getMinValueCallback = [this] () { return -24; };
    pitchTextEditor.getMaxValueCallback = [this] () { return 24; };
    pitchTextEditor.toStringCallback = [this] (int value) { return juce::String (value); };
    pitchTextEditor.updateDataCallback = [this] (int value) { pitchUiChanged (value); };
    pitchTextEditor.onDragCallback = [this] (DragSpeed dragSpeed, int direction)
    {
        const auto multiplier = [dragSpeed] ()
            {
                if (dragSpeed == DragSpeed::slow)
                    return 1;
                else if (dragSpeed == DragSpeed::medium)
                    return 2;
                else
                    return 5;
            }();
        const auto newValue { sampleProperties.getPitch () + (multiplier * direction) };
        pitchTextEditor.setValue (newValue);
    };
    pitchTextEditor.onPopupMenuCallback = [this] () {};
    setupEditor (pitchLabel, "Pitch", pitchTextEditor);

    // PAN
    panPosTextEditor.setTooltip ("Pan Position in percentage");
    panPosTextEditor.getMinValueCallback = [this] () { return -100; };
    panPosTextEditor.getMaxValueCallback = [this] () { return 100; };
    panPosTextEditor.toStringCallback = [this] (int value) { return juce::String (value); };
    panPosTextEditor.updateDataCallback = [this] (int value) { panPosUiChanged (value); };
    panPosTextEditor.onDragCallback = [this] (DragSpeed dragSpeed, int direction)
    {
        const auto multiplier = [dragSpeed] ()
            {
                if (dragSpeed == DragSpeed::slow)
                    return 1;
                else if (dragSpeed == DragSpeed::medium)
                    return 5;
                else
                    return 10;
            }();
        const auto newValue { sampleProperties.getPanPos () + (multiplier * direction) };
        panPosTextEditor.setValue (newValue);
    };
    panPosTextEditor.onPopupMenuCallback = [this] () {};
    setupEditor (panPosLabel, "Pan Position", panPosTextEditor);

    // SAMPLE TRIGGER TYPE (launch mode?)
    samTrigTypeComboBox.setLookAndFeel (&noArrowComboBoxLnF);
    samTrigTypeComboBox.addItem ("Trigger", 1);
    samTrigTypeComboBox.addItem ("Gate", 2);
    samTrigTypeComboBox.addItem ("Toggle", 3);
    setupComboBox (samTrigTypeLabel, "Sample Trigger Type", samTrigTypeComboBox);

    // LOOP MODE
    loopModeComboBox.setLookAndFeel (&noArrowComboBoxLnF);
    setupComboBox (loopModeLabel, "Loop Mode", loopModeComboBox);

    // LOOP MODES
    loopModesTextEditor.setTooltip ("Loop modes");
    loopModesTextEditor.getMinValueCallback = [this] () { return 0; };
    loopModesTextEditor.getMaxValueCallback = [this] () { return 10; };
    loopModesTextEditor.toStringCallback = [this] (int value) { return juce::String (value); };
    loopModesTextEditor.updateDataCallback = [this] (int value) { loopModesUiChanged (value); };
    loopModesTextEditor.onDragCallback = [this] (DragSpeed dragSpeed, int direction)
    {
        const auto multiplier = [dragSpeed] ()
            {
                if (dragSpeed == DragSpeed::slow)
                    return 1;
                else if (dragSpeed == DragSpeed::medium)
                    return 2;
                else
                    return 5;
            } ();
        const auto newValue { sampleProperties.getLoopModes () + (multiplier * direction) };
        loopModesTextEditor.setValue (newValue);
    };
    loopModesTextEditor.onPopupMenuCallback = [this] () {};
    setupEditor (loopModesLabel, "Loop Modes", loopModesTextEditor);

    // MIDI MODE
    midiModeTextEditor.setTooltip ("MIDI mode");
    midiModeTextEditor.getMinValueCallback = [this] () { return 0; };
    midiModeTextEditor.getMaxValueCallback = [this] () { return 10; };
    midiModeTextEditor.toStringCallback = [this] (int value) { return juce::String (value); };
    midiModeTextEditor.updateDataCallback = [this] (int value) { midiModeUiChanged (value); };
    midiModeTextEditor.onDragCallback = [this] (DragSpeed dragSpeed, int direction)
    {
        const auto multiplier = [dragSpeed] ()
            {
                if (dragSpeed == DragSpeed::slow)
                    return 1;
                else if (dragSpeed == DragSpeed::medium)
                    return 2;
                else
                    return 5;
            } ();
        const auto newValue { sampleProperties.getMidiMode () + (multiplier * direction) };
        midiModeTextEditor.setValue (newValue);
    };
    midiModeTextEditor.onPopupMenuCallback = [this] () {};
    setupEditor (midiModeLabel, "MIDI Mode", midiModeTextEditor);

    // REVERSE
    reverseComboBox.addItem ("Forward", 1);
    reverseComboBox.addItem ("Reverse", 2);
    setupComboBox (reverseLabel, "Reverse", reverseComboBox);

    // CELL MODE
    cellModeComboBox.addItem ("Sample", 1);
    cellModeComboBox.addItem ("Clip", 2);
    cellModeComboBox.addItem ("Slicer", 3);
    cellModeComboBox.addItem ("Granular", 4);
    setupComboBox (cellModeLabel, "Cell Mode", cellModeComboBox);

    // ENVELOPE ATTACK
    envAttackTextEditor.setTooltip ("Envelope attack");
    envAttackTextEditor.getMinValueCallback = [this] () { return 0; };
    envAttackTextEditor.getMaxValueCallback = [this] () { return 100; };
    envAttackTextEditor.toStringCallback = [this] (int value) { return juce::String (value); };
    envAttackTextEditor.updateDataCallback = [this] (int value) { envAttackUiChanged (value); };
    envAttackTextEditor.onDragCallback = [this] (DragSpeed dragSpeed, int direction)
    {
        const auto multiplier = [dragSpeed] ()
            {
                if (dragSpeed == DragSpeed::slow)
                    return 1;
                else if (dragSpeed == DragSpeed::medium)
                    return 5;
                else
                    return 10;
            } ();
        const auto newValue { sampleProperties.getEnvAttack () + (multiplier * direction) };
        envAttackTextEditor.setValue (newValue);
    };
    envAttackTextEditor.onPopupMenuCallback = [this] () {};
    setupEditor (envAttackLabel, "Attack", envAttackTextEditor);

    // ENVELOPE DECAY
    envDecayTextEditor.setTooltip ("Envelope decay");
    envDecayTextEditor.getMinValueCallback = [this] () { return 0; };
    envDecayTextEditor.getMaxValueCallback = [this] () { return 100; };
    envDecayTextEditor.toStringCallback = [this] (int value) { return juce::String (value); };
    envDecayTextEditor.updateDataCallback = [this] (int value) { envDecayUiChanged (value); };
    envDecayTextEditor.onDragCallback = [this] (DragSpeed dragSpeed, int direction)
    {
        const auto multiplier = [dragSpeed] ()
            {
                if (dragSpeed == DragSpeed::slow)
                    return 1;
                else if (dragSpeed == DragSpeed::medium)
                    return 5;
                else
                    return 10;
            } ();
        const auto newValue { sampleProperties.getEnvDecay () + (multiplier * direction) };
        envDecayTextEditor.setValue (newValue);
    };
    envDecayTextEditor.onPopupMenuCallback = [this] () {};
    setupEditor (envDecayLabel, "Decay", envDecayTextEditor);

    // ENVELOPE SUSTAIN
    envSusTextEditor.setTooltip ("Envelope sustain");
    envSusTextEditor.getMinValueCallback = [this] () { return 0; };
    envSusTextEditor.getMaxValueCallback = [this] () { return 100; };
    envSusTextEditor.toStringCallback = [this] (int value) { return juce::String (value); };
    envSusTextEditor.updateDataCallback = [this] (int value) { envSusUiChanged (value); };
    envSusTextEditor.onDragCallback = [this] (DragSpeed dragSpeed, int direction)
    {
        const auto multiplier = [dragSpeed] ()
            {
                if (dragSpeed == DragSpeed::slow)
                    return 1;
                else if (dragSpeed == DragSpeed::medium)
                    return 5;
                else
                    return 10;
            } ();
        const auto newValue { sampleProperties.getEnvSus () + (multiplier * direction) };
        envSusTextEditor.setValue (newValue);
    };
    envSusTextEditor.onPopupMenuCallback = [this] () {};
    setupEditor (envSusLabel, "Sustain", envSusTextEditor);

    // ENVELOPE RELEASE
    envRelTextEditor.setTooltip ("Envelope release");
    envRelTextEditor.getMinValueCallback = [this] () { return 0; };
    envRelTextEditor.getMaxValueCallback = [this] () { return 100; };
    envRelTextEditor.toStringCallback = [this] (int value) { return juce::String (value); };
    envRelTextEditor.updateDataCallback = [this] (int value) { envRelUiChanged (value); };
    envRelTextEditor.onDragCallback = [this] (DragSpeed dragSpeed, int direction)
    {
        const auto multiplier = [dragSpeed] ()
            {
                if (dragSpeed == DragSpeed::slow)
                    return 1;
                else if (dragSpeed == DragSpeed::medium)
                    return 5;
                else
                    return 10;
            } ();
        const auto newValue { sampleProperties.getEnvRel () + (multiplier * direction) };
        envRelTextEditor.setValue (newValue);
    };
    envRelTextEditor.onPopupMenuCallback = [this] () {};
    setupEditor (envRelLabel, "Release", envRelTextEditor);

    // SAMPLE START
    samStartTextEditor.setTooltip ("Sample start position");
    samStartTextEditor.getMinValueCallback = [this] () { return 0; };
    samStartTextEditor.getMaxValueCallback = [this] () { return 100; };
    samStartTextEditor.toStringCallback = [this] (int value) { return juce::String (value); };
    samStartTextEditor.updateDataCallback = [this] (int value) { samStartUiChanged (value); };
    samStartTextEditor.onDragCallback = [this] (DragSpeed dragSpeed, int direction)
    {
        const auto multiplier = [dragSpeed] ()
            {
                if (dragSpeed == DragSpeed::slow)
                    return 1;
                else if (dragSpeed == DragSpeed::medium)
                    return 5;
                else
                    return 10;
            } ();
        const auto newValue { sampleProperties.getSamStart () + (multiplier * direction) };
        samStartTextEditor.setValue (newValue);
    };
    samStartTextEditor.onPopupMenuCallback = [this] () {};
    setupEditor (samStartLabel, "Sample Start", samStartTextEditor);

    // SAMPLE LENGTH
    samLenTextEditor.setTooltip ("Sample length");
    samLenTextEditor.getMinValueCallback = [this] () { return 0; };
    samLenTextEditor.getMaxValueCallback = [this] () { return 100; };
    samLenTextEditor.toStringCallback = [this] (int value) { return juce::String (value); };
    samLenTextEditor.updateDataCallback = [this] (int value) { samLenUiChanged (value); };
    samLenTextEditor.onDragCallback = [this] (DragSpeed dragSpeed, int direction)
    {
        const auto multiplier = [dragSpeed] ()
            {
                if (dragSpeed == DragSpeed::slow)
                    return 1;
                else if (dragSpeed == DragSpeed::medium)
                    return 5;
                else
                    return 10;
            } ();
        const auto newValue { sampleProperties.getSamLen () + (multiplier * direction) };
        samLenTextEditor.setValue (newValue);
    };
    samLenTextEditor.onPopupMenuCallback = [this] () {};
    setupEditor (samLenLabel, "Sample Length", samLenTextEditor);

    // LOOP START
    loopStartTextEditor.setTooltip ("Loop start position");
    loopStartTextEditor.getMinValueCallback = [this] () { return 0; };
    loopStartTextEditor.getMaxValueCallback = [this] () { return 100; };
    loopStartTextEditor.toStringCallback = [this] (int value) { return juce::String (value); };
    loopStartTextEditor.updateDataCallback = [this] (int value) { loopStartUiChanged (value); };
    loopStartTextEditor.onDragCallback = [this] (DragSpeed dragSpeed, int direction)
    {
        const auto multiplier = [dragSpeed] ()
            {
                if (dragSpeed == DragSpeed::slow)
                    return 1;
                else if (dragSpeed == DragSpeed::medium)
                    return 5;
                else
                    return 10;
            } ();
        const auto newValue { sampleProperties.getLoopStart () + (multiplier * direction) };
        loopStartTextEditor.setValue (newValue);
    };
    loopStartTextEditor.onPopupMenuCallback = [this] () {};
    setupEditor (loopStartLabel, "Loop Start", loopStartTextEditor);

    // LOOP END
    loopEndTextEditor.setTooltip ("Loop end position");
    loopEndTextEditor.getMinValueCallback = [this] () { return 0; };
    loopEndTextEditor.getMaxValueCallback = [this] () { return 100; };
    loopEndTextEditor.toStringCallback = [this] (int value) { return juce::String (value); };
    loopEndTextEditor.updateDataCallback = [this] (int value) { loopEndUiChanged (value); };
    loopEndTextEditor.onDragCallback = [this] (DragSpeed dragSpeed, int direction)
    {
        const auto multiplier = [dragSpeed] ()
            {
                if (dragSpeed == DragSpeed::slow)
                    return 1;
                else if (dragSpeed == DragSpeed::medium)
                    return 5;
                else
                    return 10;
            } ();
        const auto newValue { sampleProperties.getLoopEnd () + (multiplier * direction) };
        loopEndTextEditor.setValue (newValue);
    };
    loopEndTextEditor.onPopupMenuCallback = [this] () {};
    setupEditor (loopEndLabel, "Loop End", loopEndTextEditor);

    // QUANT SIZE
    quantSizeTextEditor.setTooltip ("Quantization size");
    quantSizeTextEditor.getMinValueCallback = [this] () { return 0; };
    quantSizeTextEditor.getMaxValueCallback = [this] () { return 100; };
    quantSizeTextEditor.toStringCallback = [this] (int value) { return juce::String (value); };
    quantSizeTextEditor.updateDataCallback = [this] (int value) { quantSizeUiChanged (value); };
    quantSizeTextEditor.onDragCallback = [this] (DragSpeed dragSpeed, int direction)
    {
        const auto multiplier = [dragSpeed] ()
            {
                if (dragSpeed == DragSpeed::slow)
                    return 1;
                else if (dragSpeed == DragSpeed::medium)
                    return 5;
                else
                    return 10;
            } ();
        const auto newValue { sampleProperties.getQuantSize () + (multiplier * direction) };
        quantSizeTextEditor.setValue (newValue);
    };
    quantSizeTextEditor.onPopupMenuCallback = [this] () {};
    setupEditor (quantSizeLabel, "Quant Size", quantSizeTextEditor);

    // SYNC TYPE
    syncTypeTextEditor.setTooltip ("Sync type");
    syncTypeTextEditor.getMinValueCallback = [this] () { return 0; };
    syncTypeTextEditor.getMaxValueCallback = [this] () { return 10; };
    syncTypeTextEditor.toStringCallback = [this] (int value) { return juce::String (value); };
    syncTypeTextEditor.updateDataCallback = [this] (int value) { syncTypeUiChanged (value); };
    syncTypeTextEditor.onDragCallback = [this] (DragSpeed dragSpeed, int direction)
    {
        const auto multiplier = [dragSpeed] ()
            {
                if (dragSpeed == DragSpeed::slow)
                    return 1;
                else if (dragSpeed == DragSpeed::medium)
                    return 2;
                else
                    return 5;
            } ();
        const auto newValue { sampleProperties.getSyncType () + (multiplier * direction) };
        syncTypeTextEditor.setValue (newValue);
    };
    syncTypeTextEditor.onPopupMenuCallback = [this] () {};
    setupEditor (syncTypeLabel, "Sync Type", syncTypeTextEditor);

    // ACTIVE SLICE
    actSliceTextEditor.setTooltip ("Active slice");
    actSliceTextEditor.getMinValueCallback = [this] () { return 0; };
    actSliceTextEditor.getMaxValueCallback = [this] () { return 100; };
    actSliceTextEditor.toStringCallback = [this] (int value) { return juce::String (value); };
    actSliceTextEditor.updateDataCallback = [this] (int value) { actSliceUiChanged (value); };
    actSliceTextEditor.onDragCallback = [this] (DragSpeed dragSpeed, int direction)
    {
        const auto multiplier = [dragSpeed] ()
            {
                if (dragSpeed == DragSpeed::slow)
                    return 1;
                else if (dragSpeed == DragSpeed::medium)
                    return 5;
                else
                    return 10;
            } ();
        const auto newValue { sampleProperties.getActSlice () + (multiplier * direction) };
        actSliceTextEditor.setValue (newValue);
    };
    actSliceTextEditor.onPopupMenuCallback = [this] () {};
    setupEditor (actSliceLabel, "Active Slice", actSliceTextEditor);

    // OUTPUT BUS
    outputBusComboBox.addItem ("Out 1/2", 1);
    outputBusComboBox.addItem ("Out 3/4", 2);
    outputBusComboBox.addItem ("Out 5/6", 3);
    outputBusComboBox.addItem ("Out 7/8", 4);
    outputBusComboBox.addItem ("Out 1", 5);
    outputBusComboBox.addItem ("Out 2", 6);
    outputBusComboBox.addItem ("Out 3", 7);
    outputBusComboBox.addItem ("Out 4", 8);
    outputBusComboBox.addItem ("Out 5", 9);
    outputBusComboBox.addItem ("Out 6", 10);
    outputBusComboBox.addItem ("Out 7", 11);
    outputBusComboBox.addItem ("Out 8", 12);
    setupComboBox (outputBusLabel, "Output Bus", outputBusComboBox);

    // POLY MODE
    polyModeComboBox.addItem ("Mono", 1);
    polyModeComboBox.addItem ("Poly 2", 2);
    polyModeComboBox.addItem ("Poly 4", 3);
    polyModeComboBox.addItem ("Poly 6", 4);
    polyModeComboBox.addItem ("Poly 8", 5);
    polyModeComboBox.addItem ("Poly X", 6);
    setupComboBox (polyModeLabel, "Poly Mode", polyModeComboBox);

    // POLY MODE SLICE
    polyModeSliceTextEditor.setTooltip ("Polyphonic mode slice");
    polyModeSliceTextEditor.getMinValueCallback = [this] () { return 0; };
    polyModeSliceTextEditor.getMaxValueCallback = [this] () { return 10; };
    polyModeSliceTextEditor.toStringCallback = [this] (int value) { return juce::String (value); };
    polyModeSliceTextEditor.updateDataCallback = [this] (int value) { polyModeSliceUiChanged (value); };
    polyModeSliceTextEditor.onDragCallback = [this] (DragSpeed dragSpeed, int direction)
    {
        const auto multiplier = [dragSpeed] ()
            {
                if (dragSpeed == DragSpeed::slow)
                    return 1;
                else if (dragSpeed == DragSpeed::medium)
                    return 2;
                else
                    return 5;
            } ();
        const auto newValue { sampleProperties.getPolyModeSlice () + (multiplier * direction) };
        polyModeSliceTextEditor.setValue (newValue);
    };
    polyModeSliceTextEditor.onPopupMenuCallback = [this] () {};
    setupEditor (polyModeSliceLabel, "Poly Mode Slice", polyModeSliceTextEditor);

    // SLICE STEP MODE
    sliceStepModeComboBox.addItem ("None", 1);
    sliceStepModeComboBox.addItem ("Forward", 2);
    sliceStepModeComboBox.addItem ("Backward", 3);
    sliceStepModeComboBox.addItem ("Random", 4);
    sliceStepModeComboBox.addItem ("Stagger", 5);
    setupComboBox (sliceStepModeLabel, "Slice Step Mode", sliceStepModeComboBox);

    // CHOKE GROUP
    chokeGrpTextEditor.setTooltip ("Choke group");
    chokeGrpTextEditor.getMinValueCallback = [this] () { return 0; };
    chokeGrpTextEditor.getMaxValueCallback = [this] () { return 10; };
    chokeGrpTextEditor.toStringCallback = [this] (int value) { return juce::String (value); };
    chokeGrpTextEditor.updateDataCallback = [this] (int value) { chokeGrpUiChanged (value); };
    chokeGrpTextEditor.onDragCallback = [this] (DragSpeed dragSpeed, int direction)
    {
        const auto multiplier = [dragSpeed] ()
            {
                if (dragSpeed == DragSpeed::slow)
                    return 1;
                else if (dragSpeed == DragSpeed::medium)
                    return 2;
                else
                    return 5;
            } ();
        const auto newValue { sampleProperties.getChokeGrp () + (multiplier * direction) };
        chokeGrpTextEditor.setValue (newValue);
    };
    chokeGrpTextEditor.onPopupMenuCallback = [this] () {};
    setupEditor (chokeGrpLabel, "Choke Group", chokeGrpTextEditor);

    // DUAL FILTER CUTOFF
    dualFilCutoffTextEditor.setTooltip ("Dual filter cutoff");
    dualFilCutoffTextEditor.getMinValueCallback = [this] () { return -100; };
    dualFilCutoffTextEditor.getMaxValueCallback = [this] () { return 100; };
    dualFilCutoffTextEditor.toStringCallback = [this] (int value) { return juce::String (value); };
    dualFilCutoffTextEditor.updateDataCallback = [this] (int value) { dualFilCutoffUiChanged (value); };
    dualFilCutoffTextEditor.onDragCallback = [this] (DragSpeed dragSpeed, int direction)
    {
        const auto multiplier = [dragSpeed] ()
            {
                if (dragSpeed == DragSpeed::slow)
                    return 1;
                else if (dragSpeed == DragSpeed::medium)
                    return 5;
                else
                    return 10;
            } ();
        const auto newValue { sampleProperties.getDualFilCutoff () + (multiplier * direction) };
        dualFilCutoffTextEditor.setValue (newValue);
    };
    dualFilCutoffTextEditor.onPopupMenuCallback = [this] () {};
    setupEditor (dualFilCutoffLabel, "Dual Filter Cutoff", dualFilCutoffTextEditor);

    // RESONANCE
    resTextEditor.setTooltip ("Resonance");
    resTextEditor.getMinValueCallback = [this] () { return 0; };
    resTextEditor.getMaxValueCallback = [this] () { return 100; };
    resTextEditor.toStringCallback = [this] (int value) { return juce::String (value); };
    resTextEditor.updateDataCallback = [this] (int value) { resUiChanged (value); };
    resTextEditor.onDragCallback = [this] (DragSpeed dragSpeed, int direction)
    {
        const auto multiplier = [dragSpeed] ()
            {
                if (dragSpeed == DragSpeed::slow)
                    return 1;
                else if (dragSpeed == DragSpeed::medium)
                    return 5;
                else
                    return 10;
            } ();
        const auto newValue { sampleProperties.getRes () + (multiplier * direction) };
        resTextEditor.setValue (newValue);
    };
    resTextEditor.onPopupMenuCallback = [this] () {};
    setupEditor (resLabel, "Resonance", resTextEditor);

    // ROOT NOTE
    rootNoteTextEditor.setTooltip ("Root note");
    rootNoteTextEditor.getMinValueCallback = [this] () { return 0; };
    rootNoteTextEditor.getMaxValueCallback = [this] () { return 100; };
    rootNoteTextEditor.toStringCallback = [this] (int value) { return juce::String (value); };
    rootNoteTextEditor.updateDataCallback = [this] (int value) { rootNoteUiChanged (value); };
    rootNoteTextEditor.onDragCallback = [this] (DragSpeed dragSpeed, int direction)
    {
        const auto multiplier = [dragSpeed] ()
            {
                if (dragSpeed == DragSpeed::slow)
                    return 1;
                else if (dragSpeed == DragSpeed::medium)
                    return 5;
                else
                    return 10;
            } ();
        const auto newValue { sampleProperties.getRootNote () + (multiplier * direction) };
        rootNoteTextEditor.setValue (newValue);
    };
    rootNoteTextEditor.onPopupMenuCallback = [this] () {};
    setupEditor (rootNoteLabel, "Root Note", rootNoteTextEditor);

    // BEAT COUNT
    beatCountTextEditor.setTooltip ("Beat count");
    beatCountTextEditor.getMinValueCallback = [this] () { return 0; };
    beatCountTextEditor.getMaxValueCallback = [this] () { return 100; };
    beatCountTextEditor.toStringCallback = [this] (int value) { return juce::String (value); };
    beatCountTextEditor.updateDataCallback = [this] (int value) { beatCountUiChanged (value); };
    beatCountTextEditor.onDragCallback = [this] (DragSpeed dragSpeed, int direction)
    {
        const auto multiplier = [dragSpeed] ()
            {
                if (dragSpeed == DragSpeed::slow)
                    return 1;
                else if (dragSpeed == DragSpeed::medium)
                    return 5;
                else
                    return 10;
            } ();
        const auto newValue { sampleProperties.getBeatCount () + (multiplier * direction) };
        beatCountTextEditor.setValue (newValue);
    };
    beatCountTextEditor.onPopupMenuCallback = [this] () {};
    setupEditor (beatCountLabel, "Beat Count", beatCountTextEditor);

    // FX1 SEND
    fx1SendTextEditor.setTooltip ("FX1 send level");
    fx1SendTextEditor.getMinValueCallback = [this] () { return 0; };
    fx1SendTextEditor.getMaxValueCallback = [this] () { return 100; };
    fx1SendTextEditor.toStringCallback = [this] (int value) { return juce::String (value); };
    fx1SendTextEditor.updateDataCallback = [this] (int value) { fx1SendUiChanged (value); };
    fx1SendTextEditor.onDragCallback = [this] (DragSpeed dragSpeed, int direction)
    {
        const auto multiplier = [dragSpeed] ()
            {
                if (dragSpeed == DragSpeed::slow)
                    return 1;
                else if (dragSpeed == DragSpeed::medium)
                    return 5;
                else
                    return 10;
            } ();
        const auto newValue { sampleProperties.getFx1Send () + (multiplier * direction) };
        fx1SendTextEditor.setValue (newValue);
    };
    fx1SendTextEditor.onPopupMenuCallback = [this] () {};
    setupEditor (fx1SendLabel, "FX1 Send", fx1SendTextEditor);

    // FX2 SEND
    fx2SendTextEditor.setTooltip ("FX2 send level");
    fx2SendTextEditor.getMinValueCallback = [this] () { return 0; };
    fx2SendTextEditor.getMaxValueCallback = [this] () { return 100; };
    fx2SendTextEditor.toStringCallback = [this] (int value) { return juce::String (value); };
    fx2SendTextEditor.updateDataCallback = [this] (int value) { fx2SendUiChanged (value); };
    fx2SendTextEditor.onDragCallback = [this] (DragSpeed dragSpeed, int direction)
    {
        const auto multiplier = [dragSpeed] ()
            {
                if (dragSpeed == DragSpeed::slow)
                    return 1;
                else if (dragSpeed == DragSpeed::medium)
                    return 5;
                else
                    return 10;
            } ();
        const auto newValue { sampleProperties.getFx2Send () + (multiplier * direction) };
        fx2SendTextEditor.setValue (newValue);
    };
    fx2SendTextEditor.onPopupMenuCallback = [this] () {};
    setupEditor (fx2SendLabel, "FX2 Send", fx2SendTextEditor);

    // MULTI SAMPLE MODE
    multiSamModeTextEditor.setTooltip ("Multi sample mode");
    multiSamModeTextEditor.getMinValueCallback = [this] () { return 0; };
    multiSamModeTextEditor.getMaxValueCallback = [this] () { return 10; };
    multiSamModeTextEditor.toStringCallback = [this] (int value) { return juce::String (value); };
    multiSamModeTextEditor.updateDataCallback = [this] (int value) { multiSamModeUiChanged (value); };
    multiSamModeTextEditor.onDragCallback = [this] (DragSpeed dragSpeed, int direction)
    {
        const auto multiplier = [dragSpeed] ()
            {
                if (dragSpeed == DragSpeed::slow)
                    return 1;
                else if (dragSpeed == DragSpeed::medium)
                    return 2;
                else
                    return 5;
            } ();
        const auto newValue { sampleProperties.getMultiSamMode () + (multiplier * direction) };
        multiSamModeTextEditor.setValue (newValue);
    };
    multiSamModeTextEditor.onPopupMenuCallback = [this] () {};
    setupEditor (multiSamModeLabel, "Multi Sample Mode", multiSamModeTextEditor);

    // INTERPOLATION QUALITY
    interpQualTextEditor.setTooltip ("Interpolation quality");
    interpQualTextEditor.getMinValueCallback = [this] () { return 0; };
    interpQualTextEditor.getMaxValueCallback = [this] () { return 10; };
    interpQualTextEditor.toStringCallback = [this] (int value) { return juce::String (value); };
    interpQualTextEditor.updateDataCallback = [this] (int value) { interpQualUiChanged (value); };
    interpQualTextEditor.onDragCallback = [this] (DragSpeed dragSpeed, int direction)
    {
        const auto multiplier = [dragSpeed] ()
            {
                if (dragSpeed == DragSpeed::slow)
                    return 1;
                else if (dragSpeed == DragSpeed::medium)
                    return 2;
                else
                    return 5;
            } ();
        const auto newValue { sampleProperties.getInterpQual () + (multiplier * direction) };
        interpQualTextEditor.setValue (newValue);
    };
    interpQualTextEditor.onPopupMenuCallback = [this] () {};
    setupEditor (interpQualLabel, "Interpolation Quality", interpQualTextEditor);

// PLAY THROUGH
    playThruTextEditor.setTooltip ("Play through");
    playThruTextEditor.getMinValueCallback = [this] () { return 0; };
    playThruTextEditor.getMaxValueCallback = [this] () { return 1; };
    playThruTextEditor.toStringCallback = [this] (int value) { return juce::String (value); };
    playThruTextEditor.updateDataCallback = [this] (int value) { playThruUiChanged (value); };
    playThruTextEditor.onDragCallback = [this] (DragSpeed dragSpeed, int direction)
    {
        const auto multiplier = [dragSpeed] ()
            {
                if (dragSpeed == DragSpeed::slow)
                    return 1;
                else if (dragSpeed == DragSpeed::medium)
                    return 1;
                else
                    return 1;
            } ();
        const auto newValue { sampleProperties.getPlayThru () + (multiplier * direction) };
        playThruTextEditor.setValue (newValue);
    };
    playThruTextEditor.onPopupMenuCallback = [this] () {};
    setupEditor (playThruLabel, "Play Through", playThruTextEditor);

    // SLICER QUANT SIZE
    slicerQuantSizeTextEditor.setTooltip ("Slicer quantization size");
    slicerQuantSizeTextEditor.getMinValueCallback = [this] () { return 0; };
    slicerQuantSizeTextEditor.getMaxValueCallback = [this] () { return 100; };
    slicerQuantSizeTextEditor.toStringCallback = [this] (int value) { return juce::String (value); };
    slicerQuantSizeTextEditor.updateDataCallback = [this] (int value) { slicerQuantSizeUiChanged (value); };
    slicerQuantSizeTextEditor.onDragCallback = [this] (DragSpeed dragSpeed, int direction)
    {
        const auto multiplier = [dragSpeed] ()
            {
                if (dragSpeed == DragSpeed::slow)
                    return 1;
                else if (dragSpeed == DragSpeed::medium)
                    return 5;
                else
                    return 10;
            } ();
        const auto newValue { sampleProperties.getSlicerQuantSize () + (multiplier * direction) };
        slicerQuantSizeTextEditor.setValue (newValue);
    };
    slicerQuantSizeTextEditor.onPopupMenuCallback = [this] () {};
    setupEditor (slicerQuantSizeLabel, "Slicer Quant Size", slicerQuantSizeTextEditor);

    // SLICER SYNC
    slicerSyncTextEditor.setTooltip ("Slicer sync");
    slicerSyncTextEditor.getMinValueCallback = [this] () { return 0; };
    slicerSyncTextEditor.getMaxValueCallback = [this] () { return 1; };
    slicerSyncTextEditor.toStringCallback = [this] (int value) { return juce::String (value); };
    slicerSyncTextEditor.updateDataCallback = [this] (int value) { slicerSyncUiChanged (value); };
    slicerSyncTextEditor.onDragCallback = [this] (DragSpeed dragSpeed, int direction)
    {
        const auto multiplier = [dragSpeed] ()
            {
                if (dragSpeed == DragSpeed::slow)
                    return 1;
                else if (dragSpeed == DragSpeed::medium)
                    return 1;
                else
                    return 1;
            } ();
        const auto newValue { sampleProperties.getSlicerSync () + (multiplier * direction) };
        slicerSyncTextEditor.setValue (newValue);
    };
    slicerSyncTextEditor.onPopupMenuCallback = [this] () {};
    setupEditor (slicerSyncLabel, "Slicer Sync", slicerSyncTextEditor);

    // PAD NOTE
    padNoteTextEditor.setTooltip ("Pad note");
    padNoteTextEditor.getMinValueCallback = [this] () { return 0; };
    padNoteTextEditor.getMaxValueCallback = [this] () { return 127; };
    padNoteTextEditor.toStringCallback = [this] (int value) { return juce::String (value); };
    padNoteTextEditor.updateDataCallback = [this] (int value) { padNoteUiChanged (value); };
    padNoteTextEditor.onDragCallback = [this] (DragSpeed dragSpeed, int direction)
    {
        const auto multiplier = [dragSpeed] ()
            {
                if (dragSpeed == DragSpeed::slow)
                    return 1;
                else if (dragSpeed == DragSpeed::medium)
                    return 1;
                else
                    return 1;
            } ();
        const auto newValue { sampleProperties.getPadNote () + (multiplier * direction) };
        padNoteTextEditor.setValue (newValue);
    };
    padNoteTextEditor.onPopupMenuCallback = [this] () {};
    setupEditor (padNoteLabel, "Pad Note", padNoteTextEditor);

    // LOOP FADE AMOUNT
    loopFadeAmtTextEditor.setTooltip ("Loop fade amount");
    loopFadeAmtTextEditor.getMinValueCallback = [this] () { return 0; };
    loopFadeAmtTextEditor.getMaxValueCallback = [this] () { return 100; };
    loopFadeAmtTextEditor.toStringCallback = [this] (int value) { return juce::String (value); };
    loopFadeAmtTextEditor.updateDataCallback = [this] (int value) { loopFadeAmtUiChanged (value); };
    loopFadeAmtTextEditor.onDragCallback = [this] (DragSpeed dragSpeed, int direction)
    {
        const auto multiplier = [dragSpeed] ()
            {
                if (dragSpeed == DragSpeed::slow)
                    return 1;
                else if (dragSpeed == DragSpeed::medium)
                    return 5;
                else
                    return 10;
            } ();
        const auto newValue { sampleProperties.getLoopFadeAmt () + (multiplier * direction) };
        loopFadeAmtTextEditor.setValue (newValue);
    };
    loopFadeAmtTextEditor.onPopupMenuCallback = [this] () {};
    setupEditor (loopFadeAmtLabel, "Loop Fade Amount", loopFadeAmtTextEditor);

    // LFO WAVE
    // saw, rev saw, triangle, pos triangle, sine, pos sine, square, pos square, random
    lfoWaveComboBox.setTooltip ("LFO wave");
    lfoWaveComboBox.addItem ("saw", 1);
    lfoWaveComboBox.addItem ("rev saw", 2);
    lfoWaveComboBox.addItem ("triangle", 3);
    lfoWaveComboBox.addItem ("pos triangle", 4);
    lfoWaveComboBox.addItem ("sine", 5);
    lfoWaveComboBox.addItem ("pos sine", 6);
    lfoWaveComboBox.addItem ("square", 7);
    lfoWaveComboBox.addItem ("pos square", 8);
    lfoWaveComboBox.addItem ("random", 9);
    lfoWaveComboBox.setLookAndFeel (&noArrowComboBoxLnF);
    setupComboBox (lfoWaveLabel, "LFO Wave", lfoWaveComboBox);

    // LFO RATE
    lfoRateTextEditor.setTooltip ("LFO rate");
    lfoRateTextEditor.getMinValueCallback = [this] () { return 0; };
    lfoRateTextEditor.getMaxValueCallback = [this] () { return 100; };
    lfoRateTextEditor.toStringCallback = [this] (int value) { return juce::String (value); };
    lfoRateTextEditor.updateDataCallback = [this] (int value) { lfoRateUiChanged (value); };
    lfoRateTextEditor.onDragCallback = [this] (DragSpeed dragSpeed, int direction)
    {
        const auto multiplier = [dragSpeed] ()
            {
                if (dragSpeed == DragSpeed::slow)
                    return 1;
                else if (dragSpeed == DragSpeed::medium)
                    return 5;
                else
                    return 10;
            } ();
        const auto newValue { sampleProperties.getLfoRate () + (multiplier * direction) };
        lfoRateTextEditor.setValue (newValue);
    };
    lfoRateTextEditor.onPopupMenuCallback = [this] () {};
    setupEditor (lfoRateLabel, "LFO Rate", lfoRateTextEditor);

    // LFO AMOUNT
    lfoAmountTextEditor.setTooltip ("LFO amount");
    lfoAmountTextEditor.getMinValueCallback = [this] () { return 0; };
    lfoAmountTextEditor.getMaxValueCallback = [this] () { return 100; };
    lfoAmountTextEditor.toStringCallback = [this] (int value) { return juce::String (value); };
    lfoAmountTextEditor.updateDataCallback = [this] (int value) { lfoAmountUiChanged (value); };
    lfoAmountTextEditor.onDragCallback = [this] (DragSpeed dragSpeed, int direction)
    {
        const auto multiplier = [dragSpeed] ()
            {
                if (dragSpeed == DragSpeed::slow)
                    return 1;
                else if (dragSpeed == DragSpeed::medium)
                    return 5;
                else
                    return 10;
            } ();
        const auto newValue { sampleProperties.getLfoAmount () + (multiplier * direction) };
        lfoAmountTextEditor.setValue (newValue);
    };
    lfoAmountTextEditor.onPopupMenuCallback = [this] () {};
    setupEditor (lfoAmountLabel, "LFO Amount", lfoAmountTextEditor);

    // LFO KEY TRIGGER
    lfoKeyTrigTextEditor.setTooltip ("LFO key trigger");
    lfoKeyTrigTextEditor.getMinValueCallback = [this] () { return 0; };
    lfoKeyTrigTextEditor.getMaxValueCallback = [this] () { return 1; };
    lfoKeyTrigTextEditor.toStringCallback = [this] (int value) { return juce::String (value); };
    lfoKeyTrigTextEditor.updateDataCallback = [this] (int value) { lfoKeyTrigUiChanged (value); };
    lfoKeyTrigTextEditor.onDragCallback = [this] (DragSpeed dragSpeed, int direction)
    {
        const auto multiplier = [dragSpeed] ()
            {
                if (dragSpeed == DragSpeed::slow)
                    return 1;
                else if (dragSpeed == DragSpeed::medium)
                    return 1;
                else
                    return 1;
            } ();
        const auto newValue { sampleProperties.getLfoKeyTrig () + (multiplier * direction) };
        lfoKeyTrigTextEditor.setValue (newValue);
    };
    lfoKeyTrigTextEditor.onPopupMenuCallback = [this] () {};
    setupEditor (lfoKeyTrigLabel, "LFO Key Trigger", lfoKeyTrigTextEditor);

    // LFO BEAT SYNC
    lfoBeatSyncTextEditor.setTooltip ("LFO beat sync");
    lfoBeatSyncTextEditor.getMinValueCallback = [this] () { return 0; };
    lfoBeatSyncTextEditor.getMaxValueCallback = [this] () { return 1; };
    lfoBeatSyncTextEditor.toStringCallback = [this] (int value) { return juce::String (value); };
    lfoBeatSyncTextEditor.updateDataCallback = [this] (int value) { lfoBeatSyncUiChanged (value); };
    lfoBeatSyncTextEditor.onDragCallback = [this] (DragSpeed dragSpeed, int direction)
    {
        const auto multiplier = [dragSpeed] ()
            {
                if (dragSpeed == DragSpeed::slow)
                    return 1;
                else if (dragSpeed == DragSpeed::medium)
                    return 1;
                else
                    return 1;
            } ();
        const auto newValue { sampleProperties.getLfoBeatSync () + (multiplier * direction) };
        lfoBeatSyncTextEditor.setValue (newValue);
    };
    lfoBeatSyncTextEditor.onPopupMenuCallback = [this] () {};
    setupEditor (lfoBeatSyncLabel, "LFO Beat Sync", lfoBeatSyncTextEditor);

    // LFO RATE BEAT SYNC
    lfoRateBeatSyncTextEditor.setTooltip ("LFO rate beat sync");
    lfoRateBeatSyncTextEditor.getMinValueCallback = [this] () { return 0; };
    lfoRateBeatSyncTextEditor.getMaxValueCallback = [this] () { return 100; };
    lfoRateBeatSyncTextEditor.toStringCallback = [this] (int value) { return juce::String (value); };
    lfoRateBeatSyncTextEditor.updateDataCallback = [this] (int value) { lfoRateBeatSyncUiChanged (value); };
    lfoRateBeatSyncTextEditor.onDragCallback = [this] (DragSpeed dragSpeed, int direction)
    {
        const auto multiplier = [dragSpeed] ()
            {
                if (dragSpeed == DragSpeed::slow)
                    return 1;
                else if (dragSpeed == DragSpeed::medium)
                    return 5;
                else
                    return 10;
            } ();
        const auto newValue { sampleProperties.getLfoRateBeatSync () + (multiplier * direction) };
        lfoRateBeatSyncTextEditor.setValue (newValue);
    };
    lfoRateBeatSyncTextEditor.onPopupMenuCallback = [this] () {};
    setupEditor (lfoRateBeatSyncLabel, "LFO Rate Beat Sync", lfoRateBeatSyncTextEditor);

// GRAIN SIZE PERCENTAGE
    grainSizePercTextEditor.setTooltip ("Grain size percentage");
    grainSizePercTextEditor.getMinValueCallback = [this] () { return 0; };
    grainSizePercTextEditor.getMaxValueCallback = [this] () { return 100; };
    grainSizePercTextEditor.toStringCallback = [this] (int value) { return juce::String (value); };
    grainSizePercTextEditor.updateDataCallback = [this] (int value) { grainSizePercUiChanged (value); };
    grainSizePercTextEditor.onDragCallback = [this] (DragSpeed dragSpeed, int direction)
    {
        const auto multiplier = [dragSpeed] ()
            {
                if (dragSpeed == DragSpeed::slow)
                    return 1;
                else if (dragSpeed == DragSpeed::medium)
                    return 5;
                else
                    return 10;
            } ();
        const auto newValue { sampleProperties.getGrainSizePerc () + (multiplier * direction) };
        grainSizePercTextEditor.setValue (newValue);
    };
    grainSizePercTextEditor.onPopupMenuCallback = [this] () {};
    setupEditor (grainSizePercLabel, "Grain Size Percentage", grainSizePercTextEditor);

    // GRAIN SCATTER
    grainScatTextEditor.setTooltip ("Grain scatter");
    grainScatTextEditor.getMinValueCallback = [this] () { return 0; };
    grainScatTextEditor.getMaxValueCallback = [this] () { return 100; };
    grainScatTextEditor.toStringCallback = [this] (int value) { return juce::String (value); };
    grainScatTextEditor.updateDataCallback = [this] (int value) { grainScatUiChanged (value); };
    grainScatTextEditor.onDragCallback = [this] (DragSpeed dragSpeed, int direction)
    {
        const auto multiplier = [dragSpeed] ()
            {
                if (dragSpeed == DragSpeed::slow)
                    return 1;
                else if (dragSpeed == DragSpeed::medium)
                    return 5;
                else
                    return 10;
            } ();
        const auto newValue { sampleProperties.getGrainScat () + (multiplier * direction) };
        grainScatTextEditor.setValue (newValue);
    };
    grainScatTextEditor.onPopupMenuCallback = [this] () {};
    setupEditor (grainScatLabel, "Grain Scatter", grainScatTextEditor);

    // GRAIN PAN RANDOM
    grainPanRndTextEditor.setTooltip ("Grain pan random");
    grainPanRndTextEditor.getMinValueCallback = [this] () { return 0; };
    grainPanRndTextEditor.getMaxValueCallback = [this] () { return 100; };
    grainPanRndTextEditor.toStringCallback = [this] (int value) { return juce::String (value); };
    grainPanRndTextEditor.updateDataCallback = [this] (int value) { grainPanRndUiChanged (value); };
    grainPanRndTextEditor.onDragCallback = [this] (DragSpeed dragSpeed, int direction)
    {
        const auto multiplier = [dragSpeed] ()
            {
                if (dragSpeed == DragSpeed::slow)
                    return 1;
                else if (dragSpeed == DragSpeed::medium)
                    return 5;
                else
                    return 10;
            } ();
        const auto newValue { sampleProperties.getGrainPanRnd () + (multiplier * direction) };
        grainPanRndTextEditor.setValue (newValue);
    };
    grainPanRndTextEditor.onPopupMenuCallback = [this] () {};
    setupEditor (grainPanRndLabel, "Grain Pan Random", grainPanRndTextEditor);

    // GRAIN DENSITY
    grainDensityTextEditor.setTooltip ("Grain density");
    grainDensityTextEditor.getMinValueCallback = [this] () { return 0; };
    grainDensityTextEditor.getMaxValueCallback = [this] () { return 100; };
    grainDensityTextEditor.toStringCallback = [this] (int value) { return juce::String (value); };
    grainDensityTextEditor.updateDataCallback = [this] (int value) { grainDensityUiChanged (value); };
    grainDensityTextEditor.onDragCallback = [this] (DragSpeed dragSpeed, int direction)
    {
        const auto multiplier = [dragSpeed] ()
            {
                if (dragSpeed == DragSpeed::slow)
                    return 1;
                else if (dragSpeed == DragSpeed::medium)
                    return 5;
                else
                    return 10;
            } ();
        const auto newValue { sampleProperties.getGrainDensity () + (multiplier * direction) };
        grainDensityTextEditor.setValue (newValue);
    };
    grainDensityTextEditor.onPopupMenuCallback = [this] () {};
    setupEditor (grainDensityLabel, "Grain Density", grainDensityTextEditor);

    // SLICE MODE
    sliceModeTextEditor.setTooltip ("Slice mode");
    sliceModeTextEditor.getMinValueCallback = [this] () { return 0; };
    sliceModeTextEditor.getMaxValueCallback = [this] () { return 10; };
    sliceModeTextEditor.toStringCallback = [this] (int value) { return juce::String (value); };
    sliceModeTextEditor.updateDataCallback = [this] (int value) { sliceModeUiChanged (value); };
    sliceModeTextEditor.onDragCallback = [this] (DragSpeed dragSpeed, int direction)
    {
        const auto multiplier = [dragSpeed] ()
            {
                if (dragSpeed == DragSpeed::slow)
                    return 1;
                else if (dragSpeed == DragSpeed::medium)
                    return 2;
                else
                    return 5;
            } ();
        const auto newValue { sampleProperties.getSliceMode () + (multiplier * direction) };
        sliceModeTextEditor.setValue (newValue);
    };
    sliceModeTextEditor.onPopupMenuCallback = [this] () {};
    setupEditor (sliceModeLabel, "Slice Mode", sliceModeTextEditor);

    // LEGATO MODE
    legatoModeTextEditor.setTooltip ("Legato mode");
    legatoModeTextEditor.getMinValueCallback = [this] () { return 0; };
    legatoModeTextEditor.getMaxValueCallback = [this] () { return 10; };
    legatoModeTextEditor.toStringCallback = [this] (int value) { return juce::String (value); };
    legatoModeTextEditor.updateDataCallback = [this] (int value) { legatoModeUiChanged (value); };
    legatoModeTextEditor.onDragCallback = [this] (DragSpeed dragSpeed, int direction)
    {
        const auto multiplier = [dragSpeed] ()
            {
                if (dragSpeed == DragSpeed::slow)
                    return 1;
                else if (dragSpeed == DragSpeed::medium)
                    return 2;
                else
                    return 5;
            } ();
        const auto newValue { sampleProperties.getLegatoMode () + (multiplier * direction) };
        legatoModeTextEditor.setValue (newValue);
    };
    legatoModeTextEditor.onPopupMenuCallback = [this] () {};
    setupEditor (legatoModeLabel, "Legato Mode", legatoModeTextEditor);

    // GAIN SSRC WINDOW
    gainSsrcWinTextEditor.setTooltip ("Gain SSRC window");
    gainSsrcWinTextEditor.getMinValueCallback = [this] () { return 0; };
    gainSsrcWinTextEditor.getMaxValueCallback = [this] () { return 100; };
    gainSsrcWinTextEditor.toStringCallback = [this] (int value) { return juce::String (value); };
    gainSsrcWinTextEditor.updateDataCallback = [this] (int value) { gainSsrcWinUiChanged (value); };
    gainSsrcWinTextEditor.onDragCallback = [this] (DragSpeed dragSpeed, int direction)
    {
        const auto multiplier = [dragSpeed] ()
            {
                if (dragSpeed == DragSpeed::slow)
                    return 1;
                else if (dragSpeed == DragSpeed::medium)
                    return 5;
                else
                    return 10;
            } ();
        const auto newValue { sampleProperties.getGainSsrcWin () + (multiplier * direction) };
        gainSsrcWinTextEditor.setValue (newValue);
    };
    gainSsrcWinTextEditor.onPopupMenuCallback = [this] () {};
    setupEditor (gainSsrcWinLabel, "Gain SSRC Window", gainSsrcWinTextEditor);

    // GRAIN READ SPEED
    grainReadSpeedTextEditor.setTooltip ("Grain read speed");
    grainReadSpeedTextEditor.getMinValueCallback = [this] () { return 0; };
    grainReadSpeedTextEditor.getMaxValueCallback = [this] () { return 100; };
    grainReadSpeedTextEditor.toStringCallback = [this] (int value) { return juce::String (value); };
    grainReadSpeedTextEditor.updateDataCallback = [this] (int value) { grainReadSpeedUiChanged (value); };
    grainReadSpeedTextEditor.onDragCallback = [this] (DragSpeed dragSpeed, int direction)
    {
        const auto multiplier = [dragSpeed] ()
            {
                if (dragSpeed == DragSpeed::slow)
                    return 1;
                else if (dragSpeed == DragSpeed::medium)
                    return 5;
                else
                    return 10;
            } ();
        const auto newValue { sampleProperties.getGrainReadSpeed () + (multiplier * direction) };
        grainReadSpeedTextEditor.setValue (newValue);
    };
    grainReadSpeedTextEditor.onPopupMenuCallback = [this] () {};
    setupEditor (grainReadSpeedLabel, "Grain Read Speed", grainReadSpeedTextEditor);

    // RECORD PRESET LENGTH
    recPresetLenTextEditor.setTooltip ("Record preset length");
    recPresetLenTextEditor.getMinValueCallback = [this] () { return 0; };
    recPresetLenTextEditor.getMaxValueCallback = [this] () { return 100; };
    recPresetLenTextEditor.toStringCallback = [this] (int value) { return juce::String (value); };
    recPresetLenTextEditor.updateDataCallback = [this] (int value) { recPresetLenUiChanged (value); };
    recPresetLenTextEditor.onDragCallback = [this] (DragSpeed dragSpeed, int direction)
    {
        const auto multiplier = [dragSpeed] ()
            {
                if (dragSpeed == DragSpeed::slow)
                    return 1;
                else if (dragSpeed == DragSpeed::medium)
                    return 5;
                else
                    return 10;
            } ();
        const auto newValue { sampleProperties.getRecPresetLen () + (multiplier * direction) };
        recPresetLenTextEditor.setValue (newValue);
    };
    recPresetLenTextEditor.onPopupMenuCallback = [this] () {};
    setupEditor (recPresetLenLabel, "Record Preset Length", recPresetLenTextEditor);

    // RECORD QUANTIZATION
    recQuantTextEditor.setTooltip ("Record quantization");
    recQuantTextEditor.getMinValueCallback = [this] () { return 0; };
    recQuantTextEditor.getMaxValueCallback = [this] () { return 100; };
    recQuantTextEditor.toStringCallback = [this] (int value) { return juce::String (value); };
    recQuantTextEditor.updateDataCallback = [this] (int value) { recQuantUiChanged (value); };
    recQuantTextEditor.onDragCallback = [this] (DragSpeed dragSpeed, int direction)
    {
        const auto multiplier = [dragSpeed] ()
            {
                if (dragSpeed == DragSpeed::slow)
                    return 1;
                else if (dragSpeed == DragSpeed::medium)
                    return 5;
                else
                    return 10;
            } ();
        const auto newValue { sampleProperties.getRecQuant () + (multiplier * direction) };
        recQuantTextEditor.setValue (newValue);
    };
    recQuantTextEditor.onPopupMenuCallback = [this] () {};
    setupEditor (recQuantLabel, "Record Quantization", recQuantTextEditor);

    // RECORD INPUT
    recInputTextEditor.setTooltip ("Record input");
    recInputTextEditor.getMinValueCallback = [this] () { return 0; };
    recInputTextEditor.getMaxValueCallback = [this] () { return 100; };
    recInputTextEditor.toStringCallback = [this] (int value) { return juce::String (value); };
    recInputTextEditor.updateDataCallback = [this] (int value) { recInputUiChanged (value); };
    recInputTextEditor.onDragCallback = [this] (DragSpeed dragSpeed, int direction)
    {
        const auto multiplier = [dragSpeed] ()
            {
                if (dragSpeed == DragSpeed::slow)
                    return 1;
                else if (dragSpeed == DragSpeed::medium)
                    return 5;
                else
                    return 10;
            } ();
        const auto newValue { sampleProperties.getRecInput () + (multiplier * direction) };
        recInputTextEditor.setValue (newValue);
    };
    recInputTextEditor.onPopupMenuCallback = [this] () {};
    setupEditor (recInputLabel, "Record Input", recInputTextEditor);

    // RECORD USE THRESHOLD
    recUseThresTextEditor.setTooltip ("Record use threshold");
    recUseThresTextEditor.getMinValueCallback = [this] () { return 0; };
    recUseThresTextEditor.getMaxValueCallback = [this] () { return 1; };
    recUseThresTextEditor.toStringCallback = [this] (int value) { return juce::String (value); };
    recUseThresTextEditor.updateDataCallback = [this] (int value) { recUseThresUiChanged (value); };
    recUseThresTextEditor.onDragCallback = [this] (DragSpeed dragSpeed, int direction)
    {
        const auto multiplier = [dragSpeed] ()
            {
                if (dragSpeed == DragSpeed::slow)
                    return 1;
                else if (dragSpeed == DragSpeed::medium)
                    return 1;
                else
                    return 1;
            } ();
        const auto newValue { sampleProperties.getRecUseThres () + (multiplier * direction) };
        recUseThresTextEditor.setValue (newValue);
    };
    recUseThresTextEditor.onPopupMenuCallback = [this] () {};
    setupEditor (recUseThresLabel, "Record Use Threshold", recUseThresTextEditor);

    // RECORD THRESHOLD
    recThresTextEditor.setTooltip ("Record threshold");
    recThresTextEditor.getMinValueCallback = [this] () { return 0; };
    recThresTextEditor.getMaxValueCallback = [this] () { return 100; };
    recThresTextEditor.toStringCallback = [this] (int value) { return juce::String (value); };
    recThresTextEditor.updateDataCallback = [this] (int value) { recThresUiChanged (value); };
    recThresTextEditor.onDragCallback = [this] (DragSpeed dragSpeed, int direction)
    {
        const auto multiplier = [dragSpeed] ()
            {
                if (dragSpeed == DragSpeed::slow)
                    return 1;
                else if (dragSpeed == DragSpeed::medium)
                    return 5;
                else
                    return 10;
            } ();
        const auto newValue { sampleProperties.getRecThres () + (multiplier * direction) };
        recThresTextEditor.setValue (newValue);
    };
    recThresTextEditor.onPopupMenuCallback = [this] () {};
    setupEditor (recThresLabel, "Record Threshold", recThresTextEditor);

    // RECORD MONITOR OUTPUT BUS
    recMonOutBusTextEditor.setTooltip ("Record monitor output bus");
    recMonOutBusTextEditor.getMinValueCallback = [this] () { return 0; };
    recMonOutBusTextEditor.getMaxValueCallback = [this] () { return 10; };
    recMonOutBusTextEditor.toStringCallback = [this] (int value) { return juce::String (value); };
    recMonOutBusTextEditor.updateDataCallback = [this] (int value) { recMonOutBusUiChanged (value); };
    recMonOutBusTextEditor.onDragCallback = [this] (DragSpeed dragSpeed, int direction)
    {
        const auto multiplier = [dragSpeed] ()
            {
                if (dragSpeed == DragSpeed::slow)
                    return 1;
                else if (dragSpeed == DragSpeed::medium)
                    return 2;
                else
                    return 5;
            } ();
        const auto newValue { sampleProperties.getRecMonOutBus () + (multiplier * direction) };
        recMonOutBusTextEditor.setValue (newValue);
    };
    recMonOutBusTextEditor.onPopupMenuCallback = [this] () {};
    setupEditor (recMonOutBusLabel, "Record Monitor Output Bus", recMonOutBusTextEditor);
}

SampleEditorComponent::~SampleEditorComponent ()
{
    lfoWaveComboBox.setLookAndFeel (nullptr);
    loopModeComboBox.setLookAndFeel (nullptr);
    samTrigTypeComboBox.setLookAndFeel (nullptr);
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

void SampleEditorComponent::gainDataChanged (int gain) { gainTextEditor.setText (juce::String (gain)); }
void SampleEditorComponent::pitchDataChanged (int pitch) { pitchTextEditor.setText (juce::String (pitch)); }
void SampleEditorComponent::panPosDataChanged (int panPos) { panPosTextEditor.setText (juce::String (panPos)); }
void SampleEditorComponent::samTrigTypeDataChanged (int samTrigType) { samTrigTypeComboBox.setText (juce::String (samTrigType)); }
void SampleEditorComponent::loopModeDataChanged (int loopMode) { loopModeComboBox.setSelectedId (loopMode); }
void SampleEditorComponent::loopModesDataChanged (int loopModes) { loopModesTextEditor.setText (juce::String (loopModes)); }
void SampleEditorComponent::midiModeDataChanged (int midiMode) { midiModeTextEditor.setText (juce::String (midiMode)); }
void SampleEditorComponent::reverseDataChanged (int reverse) { reverseButton.setToggleState (reverse, juce::dontSendNotification); }
void SampleEditorComponent::cellModeDataChanged (int cellMode) { cellModeComboBox.setText (juce::String (cellMode)); }
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
void SampleEditorComponent::lfoWaveDataChanged (int lfoWave) { /*lfoWaveComboBox.setText (juce::String (lfoWave));*/ }
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
    setupBounds (samTrigTypeLabel, samTrigTypeComboBox, leftColumn);
    setupBounds (loopModeLabel, loopModeComboBox, leftColumn);
    setupBounds (loopModesLabel, loopModesTextEditor, leftColumn);
    setupBounds (midiModeLabel, midiModeTextEditor, leftColumn);
    setupBounds (reverseLabel, reverseButton, leftColumn);
    setupBounds (cellModeLabel, cellModeComboBox, leftColumn);
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
    setupBounds (lfoWaveLabel, lfoWaveComboBox, rightColumn);
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
