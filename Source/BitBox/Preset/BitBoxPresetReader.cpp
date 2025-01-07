#include "BitBoxPresetReader.h"
#include "../AssetProperties.h"
#include "../SampleProperties.h"
#include "../CellProperties.h"
#include "../DelayProperties.h"
#include "../IoConnectInProperties.h"
#include "../IoConnectOutProperties.h"
#include "../ModSourceProperties.h"
#include "../PresetProperties.h"
#include "../ReverbProperties.h"
#include "../SliceListProperties.h"
#include "../SliceProperties.h"
#include "../SongProperties.h"

juce::ValueTree parse (juce::XmlElement* bitBoxPresetDocumentElement)
{
    jassert (bitBoxPresetDocumentElement != nullptr && bitBoxPresetDocumentElement->getTagName () == "document");
    const auto bitBoxPresetSessionElement { bitBoxPresetDocumentElement->getChildByName ("session") };
    jassert (bitBoxPresetSessionElement != nullptr && bitBoxPresetSessionElement->getTagName () == "session");
    // found document that did not have a version attribute
    jassert (bitBoxPresetSessionElement->getStringAttribute ("version") == "" || bitBoxPresetSessionElement->getStringAttribute ("version") == "2");
    PresetProperties presetProperties { {}, PresetProperties::WrapperType::owner, PresetProperties::EnableCallbacks::no };

    for (auto* bitBoxPresetCellElement : bitBoxPresetSessionElement->getChildIterator ())
    {
        if (bitBoxPresetCellElement->getTagName () == "cell")
        {
            CellProperties cellProperties { {}, CellProperties::WrapperType::owner, CellProperties::EnableCallbacks::no};
            const auto type = bitBoxPresetCellElement->getStringAttribute ("type");
            cellProperties.setType (type, false);
            cellProperties.setRow (bitBoxPresetCellElement->getIntAttribute ("row"), false);
            cellProperties.setColumn (bitBoxPresetCellElement->getIntAttribute ("column"), false);
            cellProperties.setLayer (bitBoxPresetCellElement->getIntAttribute ("layer"), false);

            if (type == "samtempl")
            {
            }
            else if (type == "sample")
            {
                SampleProperties sampleProperties { {}, SampleProperties::WrapperType::owner, SampleProperties::EnableCallbacks::no };
                sampleProperties.setFileName (bitBoxPresetCellElement->getStringAttribute ("filename"), false);

                auto* paramsElement = bitBoxPresetCellElement->getChildByName ("params");
                if (paramsElement == nullptr)
                {
                    jassertfalse;
                    continue;
                }

                sampleProperties.setGainDb (paramsElement->getIntAttribute ("gaindb"), false);
                sampleProperties.setPitch (paramsElement->getIntAttribute ("pitch"), false);
                sampleProperties.setPanPos (paramsElement->getIntAttribute ("panpos"), false);
                sampleProperties.setSamTrigType (paramsElement->getIntAttribute ("samtrigtype"), false);
                sampleProperties.setLoopMode (paramsElement->getIntAttribute ("loopmode"), false);
                sampleProperties.setLoopModes (paramsElement->getIntAttribute ("loopmodes"), false);
                sampleProperties.setMidiMode (paramsElement->getIntAttribute ("midimode"), false);
                sampleProperties.setReverse (paramsElement->getIntAttribute ("reverse"), false);
                sampleProperties.setCellMode (paramsElement->getIntAttribute ("cellmode"), false);
                sampleProperties.setEnvAttack (paramsElement->getIntAttribute ("envattack"), false);
                sampleProperties.setEnvDecay (paramsElement->getIntAttribute ("envdecay"), false);
                sampleProperties.setEnvSus (paramsElement->getIntAttribute ("envsus"), false);
                sampleProperties.setEnvRel (paramsElement->getIntAttribute ("envrel"), false);
                sampleProperties.setSamStart (paramsElement->getIntAttribute ("samstart"), false);
                sampleProperties.setSamLen (paramsElement->getIntAttribute ("samlen"), false);
                sampleProperties.setLoopStart (paramsElement->getIntAttribute ("loopstart"), false);
                sampleProperties.setLoopEnd (paramsElement->getIntAttribute ("loopend"), false);
                sampleProperties.setQuantSize (paramsElement->getIntAttribute ("quantsize"), false);
                sampleProperties.setSyncType (paramsElement->getIntAttribute ("synctype"), false);
                sampleProperties.setActSlice (paramsElement->getIntAttribute ("actslice"), false);
                sampleProperties.setOutputBus (paramsElement->getIntAttribute ("outputbus"), false);
                sampleProperties.setPolyMode (paramsElement->getIntAttribute ("polymode"), false);
                sampleProperties.setPolyModeSlice (paramsElement->getIntAttribute ("polymodeslice"), false);
                sampleProperties.setSliceStepMode (paramsElement->getIntAttribute ("slicestepmode"), false);
                sampleProperties.setChokeGrp (paramsElement->getIntAttribute ("chokegrp"), false);
                sampleProperties.setDualFilCutoff (paramsElement->getIntAttribute ("dualfilcutoff"), false);
                sampleProperties.setRes (paramsElement->getIntAttribute ("res"), false);
                sampleProperties.setRootNote (paramsElement->getIntAttribute ("rootnote"), false);
                sampleProperties.setBeatCount (paramsElement->getIntAttribute ("beatcount"), false);
                sampleProperties.setFx1Send (paramsElement->getIntAttribute ("fx1send"), false);
                sampleProperties.setFx2Send (paramsElement->getIntAttribute ("fx2send"), false);
                sampleProperties.setMultiSamMode (paramsElement->getIntAttribute ("multisammode"), false);
                sampleProperties.setInterpQual (paramsElement->getIntAttribute ("interpqual"), false);
                sampleProperties.setPlayThru (paramsElement->getIntAttribute ("playthru"), false);
                sampleProperties.setSlicerQuantSize (paramsElement->getIntAttribute ("slicerquantsize"), false);
                sampleProperties.setSlicerSync (paramsElement->getIntAttribute ("slicersync"), false);
                sampleProperties.setPadNote (paramsElement->getIntAttribute ("padnote"), false);
                sampleProperties.setLoopFadeAmt (paramsElement->getIntAttribute ("loopfadeamt"), false);
                sampleProperties.setLfoWave (paramsElement->getIntAttribute ("lfowave"), false);
                sampleProperties.setLfoRate (paramsElement->getIntAttribute ("lforate"), false);
                sampleProperties.setLfoAmount (paramsElement->getIntAttribute ("lfoamount"), false);
                sampleProperties.setLfoKeyTrig (paramsElement->getIntAttribute ("lfokeytrig"), false);
                sampleProperties.setLfoBeatSync (paramsElement->getIntAttribute ("lfobeatsync"), false);
                sampleProperties.setLfoRateBeatSync (paramsElement->getIntAttribute ("lforatebeatsync"), false);
                sampleProperties.setGrainSizePerc (paramsElement->getIntAttribute ("grainsizeperc"), false);
                sampleProperties.setGrainScat (paramsElement->getIntAttribute ("grainscat"), false);
                sampleProperties.setGrainPanRnd (paramsElement->getIntAttribute ("grainpanrnd"), false);
                sampleProperties.setGrainDensity (paramsElement->getIntAttribute ("graindensity"), false);
                sampleProperties.setSliceMode (paramsElement->getIntAttribute ("slicemode"), false);
                sampleProperties.setLegatoMode (paramsElement->getIntAttribute ("legatomode"), false);
                sampleProperties.setGainSsrcWin (paramsElement->getIntAttribute ("gainssrcwin"), false);
                sampleProperties.setGrainReadSpeed (paramsElement->getIntAttribute ("grainreadspeed"), false);
                sampleProperties.setRecPresetLen (paramsElement->getIntAttribute ("recpresetlen"), false);
                sampleProperties.setRecQuant (paramsElement->getIntAttribute ("recquant"), false);
                sampleProperties.setRecInput (paramsElement->getIntAttribute ("recinput"), false);
                sampleProperties.setRecUseThres (paramsElement->getIntAttribute ("recusethres"), false);
                sampleProperties.setRecThres (paramsElement->getIntAttribute ("recthresh"), false);
                sampleProperties.setRecMonOutBus (paramsElement->getIntAttribute ("recmonoutbus"), false);

                for (auto* childElement : bitBoxPresetCellElement->getChildIterator ())
                {
                    if (childElement->getTagName () == "modsource")
                    {
                        ModSourceProperties modSourceProperties { {}, ModSourceProperties::WrapperType::owner, ModSourceProperties::EnableCallbacks::no };
                        modSourceProperties.setModDest (childElement->getStringAttribute ("dest"), false);
                        modSourceProperties.setModSrc (childElement->getStringAttribute ("src"), false);
                        modSourceProperties.setModSlot (childElement->getIntAttribute ("slot"), false);
                        modSourceProperties.setModAmount (childElement->getIntAttribute ("amount"), false);
                        cellProperties.getValueTree ().addChild (modSourceProperties.getValueTree (), -1, nullptr);
                    }
                    else if (childElement->getTagName () == "slices")
                    {
                        SliceListProperties sliceListProperties { {}, SliceListProperties::WrapperType::owner, SliceListProperties::EnableCallbacks::no };

                        for (auto* sliceElement : childElement->getChildIterator ())
                        {
                            SliceProperties sliceProperties { {}, SliceProperties::WrapperType::owner, SliceProperties::EnableCallbacks::no };
                            sliceProperties.setSlicePos (sliceElement->getIntAttribute ("pos"), false);
                            sliceListProperties.getValueTree ().addChild (sliceProperties.getValueTree (), -1, nullptr);
                        }

                        cellProperties.getValueTree ().addChild(sliceListProperties.getValueTree (), -1, nullptr);
                    }
                }
                cellProperties.getValueTree ().addChild (sampleProperties.getValueTree (), -1, nullptr);
            }
            else if (type == "multi-sample") // ? I don't know what the type is for multi-sample
            {
                jassertfalse;
            }
            else if (type == "clip") // ? I don't know what the type is for clip
            {
                jassertfalse;
            }
            else if (type == "slice") // ? I don't know what the type is for slice
            {
                jassertfalse;
            }
            else if (type == "gran") // ? I don't know what the type is for granular
            {
                jassertfalse;
            }
            else if (type == "rec") // ? I don't know what the type is for recording
            {
                jassertfalse;
            }
            else if (type == "rec-multi") // ? I don't know what the type is for recording
            {
                jassertfalse;
            }
            else if (type == "delay")
            {
                DelayProperties delayProperties { {}, DelayProperties::WrapperType::owner, DelayProperties::EnableCallbacks::no };

                auto* paramsElement = bitBoxPresetCellElement->getChildByName ("params");
                jassert (paramsElement != nullptr);

                delayProperties.setDelay (paramsElement->getIntAttribute ("delay"), false);
                delayProperties.setDelayMusTime (paramsElement->getIntAttribute ("delaymustime"), false);
                delayProperties.setFeedback (paramsElement->getIntAttribute ("feedback"), false);
                delayProperties.setCutoff (paramsElement->getIntAttribute ("cutoff"), false);
                delayProperties.setFiltQuality (paramsElement->getIntAttribute ("filtquality"), false);
                delayProperties.setDelayBeatSync (paramsElement->getIntAttribute ("dealybeatsync"), false);
                delayProperties.setFiltEnable (paramsElement->getIntAttribute ("filtenable"), false);
                delayProperties.setDelayPingPong (paramsElement->getIntAttribute ("delaypingpong"), false);

                cellProperties.getValueTree ().addChild (delayProperties.getValueTree (), -1, nullptr);
                }
            else if (type == "reverb")
            {
                ReverbProperties reverbProperties { {}, ReverbProperties::WrapperType::owner, ReverbProperties::EnableCallbacks::no };

                auto* paramsElement = bitBoxPresetCellElement->getChildByName ("params");
                jassert (paramsElement != nullptr);

                reverbProperties.setDecay (paramsElement->getIntAttribute ("decay"), false);
                reverbProperties.setPreDelay (paramsElement->getIntAttribute ("predelay"), false);
                reverbProperties.setDamping (paramsElement->getIntAttribute ("damping"), false);

                cellProperties.getValueTree ().addChild (reverbProperties.getValueTree (), -1, nullptr);
            }
            else if (type == "eq")
            {
                //NOTE - NOT PART OF THE MICRO
                //jassertfalse;
                auto* paramsElement = bitBoxPresetCellElement->getChildByName ("params");
                jassert (paramsElement != nullptr);
                const auto eqActBand = paramsElement->getIntAttribute ("eqactband");
                const auto eqGain = paramsElement->getIntAttribute ("eqgain");
                const auto eqCutoff = paramsElement->getIntAttribute ("eqcutoff");
                const auto eqRes = paramsElement->getIntAttribute ("eqres");
                const auto eqEnable = paramsElement->getIntAttribute ("eqenable");
                const auto eqType = paramsElement->getIntAttribute ("eqtype");
                const auto eqGain2 = paramsElement->getIntAttribute ("eqgain2");
                const auto eqCutoff2 = paramsElement->getIntAttribute ("eqcutoff2");
                const auto eqRes2 = paramsElement->getIntAttribute ("eqres2");
                const auto eqEnable2 = paramsElement->getIntAttribute ("eqenable2");
                const auto eqType2 = paramsElement->getIntAttribute ("eqtype2");
                const auto eqGain3 = paramsElement->getIntAttribute ("eqgain3");
                const auto eqCutoff3 = paramsElement->getIntAttribute ("eqcutoff3");
                const auto eqRes3 = paramsElement->getIntAttribute ("eqres3");
                const auto eqEnable3 = paramsElement->getIntAttribute ("eqenable3");
                const auto eqType3 = paramsElement->getIntAttribute ("eqtype3");
                const auto eqGain4 = paramsElement->getIntAttribute ("eqgain4");
                const auto eqCutoff4 = paramsElement->getIntAttribute ("eqcutoff4");
                const auto eqRes4 = paramsElement->getIntAttribute ("eqres4");
                const auto eqEnable4 = paramsElement->getIntAttribute ("eqenable4");
                const auto eqType4 = paramsElement->getIntAttribute ("eqtype4");
            }
            else if (type == "filter")
            {
                //NOTE - NOT PART OF THE bitbox MICRO
                //jassertfalse;
                auto* paramsElement = bitBoxPresetCellElement->getChildByName ("params");
                jassert (paramsElement != nullptr);
                const auto cutoff = paramsElement->getIntAttribute ("cutoff");
                const auto res = paramsElement->getIntAttribute ("res");
                const auto filterType = paramsElement->getIntAttribute ("filtertype");
                const auto fxTrigMode = paramsElement->getIntAttribute ("fxtrigmode");

            }
            else if (type == "bitcrusher")
            {
                //NOTE - NOT PART OF THE bitbox MICRO
                //jassertfalse;
                // no params
            }
            else if (type == "noteseq")
            {
                //NOTE - NOT PART OF THE bitbox MICRO
                //jassertfalse;
                auto* paramsElement = bitBoxPresetCellElement->getChildByName ("params");
                jassert (paramsElement != nullptr);
                const auto noteStepLen = paramsElement->getIntAttribute ("notesteplen");
                const auto noteStepCount = paramsElement->getIntAttribute ("notestepcount");
                const auto dutyCyc = paramsElement->getIntAttribute ("dutycyc");
                const auto midiOutChan = paramsElement->getIntAttribute ("midioutchan");
                const auto quantSize = paramsElement->getIntAttribute ("quantsize");
                const auto padNote = paramsElement->getIntAttribute ("padnote");
                const auto dispMode = paramsElement->getIntAttribute ("dispmode");
                const auto seqPlayEnable = paramsElement->getIntAttribute ("seqplayenable");

                auto* sequenceElement = bitBoxPresetCellElement->getChildByName ("sequence");
                jassert (sequenceElement != nullptr);
                // Process sequence data if needed

            }
            else if (type == "section")
            {
                //NOTE - NOT PART OF THE bitbox MICRO
                //jassertfalse;
                const auto sectionName { bitBoxPresetCellElement->getStringAttribute ("name") };

                auto* paramsElement = bitBoxPresetCellElement->getChildByName ("params");
                jassert (paramsElement != nullptr);
                const auto sectionLenBars { paramsElement->getIntAttribute ("sectionlenbars") };

                auto* sequenceElement = bitBoxPresetCellElement->getChildByName ("sequence");
                jassert (sequenceElement != nullptr);
                // Process sequence data if needed
            }
            else if (type == "null")
            {
                //jassertfalse;
            }
            else if (type == "ioconnectin")
            {
                // TODO - there are a series of "ioconnectin" cells, which contain a field indicating the order, and child
                //        elements of "params" which contain the inputIoCon string
                IoConnectInProperties ioConnectInProperties { {}, IoConnectInProperties::WrapperType::owner, IoConnectInProperties::EnableCallbacks::no };

                auto* paramsElement = bitBoxPresetCellElement->getChildByName ("params");
                jassert (paramsElement != nullptr);

                ioConnectInProperties.setInputIoCon (paramsElement->getStringAttribute ("inputiocon"), false);

                cellProperties.getValueTree ().addChild (ioConnectInProperties.getValueTree (), -1, nullptr);
            }
            else if (type == "ioconnectout")
            {
                // TODO - there are a series of "ioconnectout" cells, which contain a field indicating the order, and child
                //        elements of "params" which contain the inputIoCon string
                IoConnectOutProperties ioConnectOutProperties { {}, IoConnectOutProperties::WrapperType::owner, IoConnectOutProperties::EnableCallbacks::no };

                auto* paramsElement = bitBoxPresetCellElement->getChildByName ("params");
                jassert (paramsElement != nullptr);

                ioConnectOutProperties.setOutputIoCon (paramsElement->getStringAttribute ("outputiocon"), false);

                cellProperties.getValueTree ().addChild (ioConnectOutProperties.getValueTree (), -1, nullptr);
            }
            else if (type == "song")
            {
                SongProperties songProperties { {}, SongProperties::WrapperType::owner, SongProperties::EnableCallbacks::no };

                auto* paramsElement = bitBoxPresetCellElement->getChildByName ("params");
                jassert (paramsElement != nullptr);

                songProperties.setGlobTempo (paramsElement->getIntAttribute ("globtempo"), false);
                songProperties.setSongMode (paramsElement->getIntAttribute ("songmode"), false);
                songProperties.setSectCount (paramsElement->getIntAttribute ("sectcount"), false);
                songProperties.setSectLoop (paramsElement->getIntAttribute ("sectloop"), false);
                songProperties.setSwing (paramsElement->getIntAttribute ("swing"), false);
                songProperties.setKeyMode (paramsElement->getIntAttribute ("keymode"), false);
                songProperties.setKeyRoot (paramsElement->getIntAttribute ("keyroot"), false);

                cellProperties.getValueTree ().addChild (songProperties.getValueTree (), -1, nullptr);
            }
            else if (type == "asset")
            {
                AssetProperties assetProperties { {}, AssetProperties::WrapperType::owner, AssetProperties::EnableCallbacks::no };

                assetProperties.setFileName (bitBoxPresetCellElement->getStringAttribute ("filename"), false);

                auto* paramsElement = bitBoxPresetCellElement->getChildByName ("params");
                jassert (paramsElement != nullptr);

                assetProperties.setRootNote (paramsElement->getIntAttribute ("rootnote"), false);
                assetProperties.setKeyRangeBottom (paramsElement->getIntAttribute ("keyrangebottom"), false);
                assetProperties.setKeyRangeTop (paramsElement->getIntAttribute ("keyrangetop"), false);
                assetProperties.setAssSrcRow (paramsElement->getIntAttribute ("asssrcrow"), false);
                assetProperties.setAssSrcCol (paramsElement->getIntAttribute ("asssrccol"), false);

                cellProperties.getValueTree ().addChild (assetProperties.getValueTree (), -1, nullptr);
            }
            else
            {
                jassertfalse;
                continue;
            }

            presetProperties.getValueTree ().addChild (cellProperties.getValueTree (), -1, nullptr);
        }
        else
        {
            // unknown element type
            jassertfalse;
        }
    }
    return presetProperties.getValueTree ();
}