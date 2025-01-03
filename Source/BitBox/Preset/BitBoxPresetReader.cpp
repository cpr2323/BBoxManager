#include "BitBoxPresetReader.h"

//auto presetXmlDocument { juce::XmlDocument (presetFile).getDocumentElement () };
//dumpXml (presetXmlDocument.get (), 0);

juce::ValueTree parse (juce::XmlElement* bitBoxPresetDocumentElement)
{
    jassert (bitBoxPresetDocumentElement != nullptr && bitBoxPresetDocumentElement->getTagName () == "document");
    const auto bitBoxPresetSessionElement { bitBoxPresetDocumentElement->getChildByName ("session") };
    jassert (bitBoxPresetSessionElement != nullptr && bitBoxPresetSessionElement->getTagName () == "session");
    jassert (bitBoxPresetSessionElement->getStringAttribute ("version") == "2");
    juce::ValueTree presetPropertiesVT { "PresetProperties" };

    for (auto* bitBoxPresetCellElement : bitBoxPresetSessionElement->getChildIterator())
    {
        jassert (bitBoxPresetCellElement->getTagName () == "cell");
        const auto row { bitBoxPresetCellElement->getIntAttribute ("row") };
        const auto col { bitBoxPresetCellElement->getIntAttribute ("column") };
        const auto layer { bitBoxPresetCellElement->getIntAttribute ("layer") };
        const auto type { bitBoxPresetCellElement->getStringAttribute ("type") };

        if (type == "samtempl")
        {
        }
        else if (type == "sample")
        {
            const auto fileName = bitBoxPresetCellElement->getStringAttribute ("filename");
            auto* paramsElement = bitBoxPresetCellElement->getChildByName ("params");
            jassert (paramsElement != nullptr);
            const auto gainDb = paramsElement->getIntAttribute ("gaindb");
            const auto pitch = paramsElement->getIntAttribute ("pitch");
            const auto panPos = paramsElement->getIntAttribute ("panpos");
            const auto samTrigType = paramsElement->getIntAttribute ("samtrigtype");
            const auto loopMode = paramsElement->getIntAttribute ("loopmode");
            const auto loopModes = paramsElement->getIntAttribute ("loopmodes");
            const auto midiMode = paramsElement->getIntAttribute ("midimode");
            const auto reverse = paramsElement->getIntAttribute ("reverse");
            const auto cellMode = paramsElement->getIntAttribute ("cellmode");
            const auto envAttack = paramsElement->getIntAttribute ("envattack");
            const auto envDecay = paramsElement->getIntAttribute ("envdecay");
            const auto envSus = paramsElement->getIntAttribute ("envsus");
            const auto envRel = paramsElement->getIntAttribute ("envrel");
            const auto samStart = paramsElement->getIntAttribute ("samstart");
            const auto samLen = paramsElement->getIntAttribute ("samlen");
            const auto loopStart = paramsElement->getIntAttribute ("loopstart");
            const auto loopEnd = paramsElement->getIntAttribute ("loopend");
            const auto quantSize = paramsElement->getIntAttribute ("quantsize");
            const auto syncType = paramsElement->getIntAttribute ("synctype");
            const auto actSlice = paramsElement->getIntAttribute ("actslice");
            const auto outputBus = paramsElement->getIntAttribute ("outputbus");
            const auto polyMode = paramsElement->getIntAttribute ("polymode");
            const auto polyModeSlice = paramsElement->getIntAttribute ("polymodeslice");
            const auto sliceStepMode = paramsElement->getIntAttribute ("slicestepmode");
            const auto chokeGrp = paramsElement->getIntAttribute ("chokegrp");
            const auto dualFilCutoff = paramsElement->getIntAttribute ("dualfilcutoff");
            const auto res = paramsElement->getIntAttribute ("res");
            const auto rootNote = paramsElement->getIntAttribute ("rootnote");
            const auto beatCount = paramsElement->getIntAttribute ("beatcount");
            const auto fx1Send = paramsElement->getIntAttribute ("fx1send");
            const auto fx2Send = paramsElement->getIntAttribute ("fx2send");
            const auto multiSamMode = paramsElement->getIntAttribute ("multisammode");
            const auto interpQual = paramsElement->getIntAttribute ("interpqual");
            const auto playThru = paramsElement->getIntAttribute ("playthru");
            const auto slicerQuantSize = paramsElement->getIntAttribute ("slicerquantsize");
            const auto slicerSync = paramsElement->getIntAttribute ("slicersync");
            const auto padNote = paramsElement->getIntAttribute ("padnote");
            const auto loopFadeAmt = paramsElement->getIntAttribute ("loopfadeamt");
            const auto lfoWave = paramsElement->getIntAttribute ("lfowave");
            const auto lfoRate = paramsElement->getIntAttribute ("lforate");
            const auto lfoAmount = paramsElement->getIntAttribute ("lfoamount");
            const auto lfoKeyTrig = paramsElement->getIntAttribute ("lfokeytrig");
            const auto lfoBeatSync = paramsElement->getIntAttribute ("lfobeatsync");
            const auto lfoRateBeatSync = paramsElement->getIntAttribute ("lforatebeatsync");
            const auto grainSizePerc = paramsElement->getIntAttribute ("grainsizeperc");
            const auto grainScat = paramsElement->getIntAttribute ("grainscat");
            const auto grainPanRnd = paramsElement->getIntAttribute ("grainpanrnd");
            const auto grainDensity = paramsElement->getIntAttribute ("graindensity");
            const auto sliceMode = paramsElement->getIntAttribute ("slicemode");
            const auto legatoMode = paramsElement->getIntAttribute ("legatomode");
            const auto gainSsrcWin = paramsElement->getIntAttribute ("gainssrcwin");
            const auto grainReadSpeed = paramsElement->getIntAttribute ("grainreadspeed");
            const auto recPresetLen = paramsElement->getIntAttribute ("recpresetlen");
            const auto recQuant = paramsElement->getIntAttribute ("recquant");
            const auto recInput = paramsElement->getIntAttribute ("recinput");
            const auto recUseThres = paramsElement->getIntAttribute ("recusethres");
            const auto recThres = paramsElement->getIntAttribute ("recthresh");
            const auto recMonOutBus = paramsElement->getIntAttribute ("recmonoutbus");

            for (auto* childElement : bitBoxPresetCellElement->getChildIterator ())
            {
                if (childElement->getTagName () == "modsource")
                {
                    const auto modDest = childElement->getStringAttribute ("dest");
                    const auto modSrc = childElement->getStringAttribute ("src");
                    const auto modSlot = childElement->getIntAttribute ("slot");
                    const auto modAmount = childElement->getIntAttribute ("amount");
                }
                else if (childElement->getTagName () == "slices")
                {
                    for (auto* sliceElement : childElement->getChildIterator ())
                    {
                        const auto slicePos = sliceElement->getIntAttribute ("pos");
                    }
                }
            }
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
            auto* paramsElement = bitBoxPresetCellElement->getChildByName ("params");
            jassert (paramsElement != nullptr);
            const auto delay = paramsElement->getIntAttribute ("delay");
            const auto delaymusTime = paramsElement->getIntAttribute ("delaymustime");
            const auto feedback = paramsElement->getIntAttribute ("feedback");
            const auto cutoff = paramsElement->getIntAttribute ("cutoff");
            const auto filtQuality = paramsElement->getIntAttribute ("filtquality");
            const auto delayBeatSync = paramsElement->getIntAttribute ("dealybeatsync");
            const auto filtEnable = paramsElement->getIntAttribute ("filtenable");
            const auto delayPingPong = paramsElement->getIntAttribute ("delaypingpong");
        }
        else if (type == "reverb")
        {
            auto* paramsElement = bitBoxPresetCellElement->getChildByName ("params");
            jassert (paramsElement != nullptr);
            const auto decay = paramsElement->getIntAttribute ("decay");
            const auto preDelay = paramsElement->getIntAttribute ("predelay");
            const auto damping = paramsElement->getIntAttribute ("damping");
        }
        else if (type == "eq")
        {
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
        else if (type == "null")
        {
        }
        else if (type == "ioconnectin")
        {
            auto* paramsElement = bitBoxPresetCellElement->getChildByName ("params");
            jassert (paramsElement != nullptr);
            const auto inputIoCon = paramsElement->getStringAttribute ("inputiocon");
        }
        else if (type == "ioconnectout")
        {
            auto* paramsElement = bitBoxPresetCellElement->getChildByName ("params");
            jassert (paramsElement != nullptr);
            const auto outputIoCon= paramsElement->getStringAttribute ("outputiocon");
        }
        else if (type == "song")
        {
            auto* paramsElement = bitBoxPresetCellElement->getChildByName ("params");
            jassert (paramsElement != nullptr);
            const auto globTempo = paramsElement->getIntAttribute ("globtempo");
            const auto songMode = paramsElement->getIntAttribute ("songmode");
            const auto sectCount = paramsElement->getIntAttribute ("sectcount");
            const auto sectLoop = paramsElement->getIntAttribute ("sectloop");
            const auto swing = paramsElement->getIntAttribute ("swing");
            const auto keyMode = paramsElement->getIntAttribute ("keymode");
            const auto keyRoot = paramsElement->getIntAttribute ("keyroot");
        }
        else
        {
            jassertfalse;
        }
    }
    return presetPropertiesVT;
}