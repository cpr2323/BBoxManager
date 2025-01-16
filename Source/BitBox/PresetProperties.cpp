#include "PresetProperties.h"
#include "CellProperties.h"
#include "DelayProperties.h"
#include "IoConnectInProperties.h"
#include "IoConnectOutProperties.h"
#include "ModSourceProperties.h"
#include "ReverbProperties.h"
#include "SampleProperties.h"
#include "SliceListProperties.h"
#include "SliceProperties.h"
#include "SongProperties.h"
#include "Preset/BitBoxPresetReader.h"

void PresetProperties::initValueTree ()
{
    setName ("", false);
    // Cell (samtempl) 0, 0, 0
    // Cell (samtempl) 1, 0, 0
    // Cell (samtempl) 2, 0, 0
    // Cell (samtempl) 3, 0, 0
    // Cell (samtempl) 0, 1, 0
    // Cell (samtempl) 1, 1, 0
    // Cell (samtempl) 2, 1, 0
    // Cell (samtempl) 3, 1, 0
    // Cell (samtempl) 0, 2, 0
    // Cell (samtempl) 1, 2, 0
    // Cell (samtempl) 2, 2, 0
    // Cell (samtempl) 3, 2, 0
    // Cell (samtempl) 0, 3, 0
    // Cell (samtempl) 1, 3, 0
    // Cell (samtempl) 2, 3, 0
    // Cell (samtempl) 3, 3, 0
    // Cell (samtempl) 0, 4, 0
    // Cell (samtempl) 1, 4, 0
    // Cell (samtempl) 2, 4, 0
    // Cell (samtempl) 3, 4, 0
    constexpr auto kPadLayer { 0 };
    SampleProperties templateSampleProperties { {},SampleProperties::WrapperType::owner, SampleProperties::EnableCallbacks::no };
    templateSampleProperties.getValueTree ().setProperty ("deftemplate", 1, nullptr);
    for (auto col { 0 }; col < 5; ++col)
    {
        for (auto row { 0 }; row < 4; ++row)
        {
            // prepare Cell Properties
            CellProperties cell { {}, CellProperties::WrapperType::owner, CellProperties::EnableCallbacks::no };
            cell.setRow (row, false);
            cell.setColumn (col, false);
            cell.setLayer (kPadLayer, false);
            cell.setType ("samtempl", false);
            // add a samtempl properties to the cell
            cell.getValueTree ().addChild (templateSampleProperties.getValueTree ().createCopy (), -1, nullptr);
            // add empty slice list to the cell
            SliceListProperties sliceListProperties { {}, SliceListProperties::WrapperType::owner, SliceListProperties::EnableCallbacks::no };
            cell.getValueTree ().addChild (sliceListProperties.getValueTree ().createCopy (), -1, nullptr);
            // add cell to preset
            data.addChild (cell.getValueTree (), -1, nullptr);
        }
    }

    constexpr auto kEffectsLayer { 3 };
    // Cell (delay) 0, -1, 3
    // prepare Cell Properties
    CellProperties delayCell { {}, CellProperties::WrapperType::owner, CellProperties::EnableCallbacks::no };
    delayCell.setRow (0, false);
    delayCell.setLayer (kEffectsLayer, false);
    delayCell.setType ("delay", false);
    // add DelayProperties to the cell
    DelayProperties delayProperties { {}, DelayProperties::WrapperType::owner, DelayProperties::EnableCallbacks::no };
    // <params delay="400" delaymustime="6" feedback="400" cutoff="120" filtquality="1000" dealybeatsync="1" filtenable="1" delaypingpong="1"/>
    delayCell.getValueTree ().addChild (delayProperties.getValueTree ().createCopy (), -1, nullptr);
    // add cell to preset
    data.addChild (delayCell.getValueTree (), -1, nullptr);


    // Cell (reverb) 1, -1, 3
    // prepare Cell Properties
    CellProperties reverbCell { {}, CellProperties::WrapperType::owner, CellProperties::EnableCallbacks::no };
    reverbCell.setRow (1, false);
    reverbCell.setLayer (kEffectsLayer, false);
    reverbCell.setType ("reverb", false);
    // add ReverbProperties to the cell
    ReverbProperties reverbProperties { {}, ReverbProperties::WrapperType::owner, ReverbProperties::EnableCallbacks::no };
    // <params decay = "600" predelay = "40" damping = "500" / >
    reverbCell.getValueTree ().addChild (reverbProperties.getValueTree ().createCopy (), -1, nullptr);
    // add cell to preset
    data.addChild (reverbCell.getValueTree (), -1, nullptr);

    // Cell (eq) 2, -1, 3
    //     	<params eqactband="0" eqgain="0" eqcutoff="200" eqres="400" eqenable="1" eqtype="0" eqgain2="0" eqcutoff2="400" eqres2="400"
    //              eqenable2="1" eqtype2="0" eqgain3="0" eqcutoff3="600" eqres3="400" eqenable3="1" eqtype3="0" eqgain4="0" eqcutoff4="800" eqres4="400" eqenable4="1" eqtype4="0"/>

    // Cell (null) 3, -1, 3
    // Cell (null) 4, -1, 3

    // Cell (ioconnectin) 0, -1, 8
    // Cell (ioconnectin) 1, -1, 8
    // Cell (ioconnectin) 2, -1, 8
    // Cell (ioconnectin) 3, -1, 8
    // Cell (ioconnectin) 4, -1, 8
    // Cell (ioconnectin) 5, -1, 8
    // Cell (ioconnectin) 6, -1, 8
    // Cell (ioconnectin) 7, -1, 8
    constexpr auto kIoConnectInLayer { 8 };
    for (auto ioConnectInIndex { 0 }; ioConnectInIndex < 8; ++ioConnectInIndex)
    {
        // prepare Cell Properties
        CellProperties ioConnectInCell { {}, CellProperties::WrapperType::owner, CellProperties::EnableCallbacks::no };
        ioConnectInCell.setRow (ioConnectInIndex, false);
        ioConnectInCell.setLayer (kIoConnectInLayer, false);
        ioConnectInCell.setType ("ioconnectin", false);
        // add IoConnectInProperties to the cell
        IoConnectInProperties ioConnectInProperties { {}, IoConnectInProperties::WrapperType::owner, IoConnectInProperties::EnableCallbacks::no };
        // <params inputiocon="gatein"/>
        ioConnectInProperties.setInputIoCon ("gatein", false);
        ioConnectInCell.getValueTree ().addChild (ioConnectInProperties.getValueTree ().createCopy (), -1, nullptr);
        // add cell to preset
        data.addChild (ioConnectInCell.getValueTree (), -1, nullptr);
    }

    // Cell (ioconnectout) 0, -1, 9
    // Cell (ioconnectout) 1, -1, 9
    // Cell (ioconnectout) 2, -1, 9
    // Cell (ioconnectout) 3, -1, 9
    // Cell (ioconnectout) 4, -1, 9
    // Cell (ioconnectout) 5, -1, 9
    // Cell (ioconnectout) 6, -1, 9
    // Cell (ioconnectout) 7, -1, 9
    auto addIoConnectOut = [this] (int row, juce::String ioConnectOutString)
    {
        constexpr auto kIoConnectOutLayer { 9 };
        // prepare Cell Properties
        CellProperties ioConnectOutCell { {}, CellProperties::WrapperType::owner, CellProperties::EnableCallbacks::no };
        ioConnectOutCell.setRow (row, false);
        ioConnectOutCell.setLayer (kIoConnectOutLayer, false);
        ioConnectOutCell.setType ("ioconnectout", false);
        // add IoConnectOutProperties to the cell
        IoConnectOutProperties ioConnectOutProperties { {}, IoConnectOutProperties::WrapperType::owner, IoConnectOutProperties::EnableCallbacks::no };
        // <params outputiocon="chanout1"/>
        ioConnectOutProperties.setOutputIoCon (ioConnectOutString, false);
        ioConnectOutCell.getValueTree ().addChild (ioConnectOutProperties.getValueTree ().createCopy (), -1, nullptr);
        // add cell to preset
        data.addChild (ioConnectOutCell.getValueTree (), -1, nullptr);
    };
    constexpr auto kIoConnectOutLayer { 9 };
    for (auto ioConnectOutIndex { 0 }; ioConnectOutIndex < 8; ++ioConnectOutIndex)
        addIoConnectOut (ioConnectOutIndex, "chanout" + juce::String (ioConnectOutIndex + 1));
    addIoConnectOut (6, "masterout1");
    addIoConnectOut (7, "masterout2");

    // Cell (song) -1, -1, -1
    // prepare Cell Properties
    CellProperties songCell { {}, CellProperties::WrapperType::owner, CellProperties::EnableCallbacks::no };
    songCell.setType ("song", false);
    // add Song Properties to the cell
    SongProperties songProperties { {}, SongProperties::WrapperType::owner, SongProperties::EnableCallbacks::no };
    // <params globtempo="120" songmode="0" sectcount="1" sectloop="1" swing="50" keymode="1" keyroot="3"/>
    songCell.getValueTree ().addChild (songProperties.getValueTree ().createCopy (), -1, nullptr);
    // add cell to preset
    data.addChild (songCell.getValueTree (), -1, nullptr);
}

void PresetProperties::forEachPad (std::function<bool (juce::ValueTree padVT, int padIndex)> padVTCallback)
{
    jassert (padVTCallback != nullptr);
    auto callCellCallback = [this, &padVTCallback] (int padIndex, int row, int col, int lyr)
    {
        auto padVT { getCellProperties (data, row, col, lyr) };
        if (padVT.isValid ())
            padVTCallback (padVT, 0);
    };
    callCellCallback (0, 1, 0, 0);
    callCellCallback (1, 0, 0, 0);
    callCellCallback (2, 1, 1, 0);
    callCellCallback (3, 0, 1, 0);
    callCellCallback (4, 1, 2, 0);
    callCellCallback (5, 0, 2, 0);
    callCellCallback (6, 1, 3, 0);
    callCellCallback (7, 0, 3, 0);
}

juce::ValueTree PresetProperties::getCellProperties (juce::ValueTree vt, int row, int column, int layer)
{
    juce::ValueTree cellPropertiesVT;
    ValueTreeHelpers::forEachChildOfType (vt, CellProperties::CellTypeId, [&cellPropertiesVT, row, column, layer] (juce::ValueTree cellChild)
    {
        CellProperties cellProperties { cellChild, CellProperties::WrapperType::client, CellProperties::EnableCallbacks::no };
        const auto cellRow { cellChild.hasProperty (CellProperties::RowPropertyId) ? cellProperties.getRow () : -1 };
        const auto cellColumn { cellChild.hasProperty (CellProperties::ColumnPropertyId) ? cellProperties.getColumn () : -1 };
        const auto cellLayer { cellChild.hasProperty (CellProperties::LayerPropertyId) ? cellProperties.getLayer () : -1 };
        if (cellRow == row && cellColumn == column && cellLayer == layer)
        {
            cellPropertiesVT = cellChild;
            return false;
        }
        return true;
    });
    return cellPropertiesVT;
}

void PresetProperties::copyPropertiesFrom (juce::ValueTree sourceVT)
{
    // copy local data
    // copy pads
    // iterate over <cell> tags
    //  create CellProperties
    //  based on cellType tag, copy
    //      create SampleProperties, MultiSampleProperties, ClipProperties, SliceProperties, GranualProperties, IoConnectInProperties, and IoConnectOutProperties
    PresetProperties sourcePresetProperties {sourceVT, PresetProperties::WrapperType::client, PresetProperties::EnableCallbacks::no };
    setName (sourcePresetProperties.getName (), false);
    // iterate over Cells
    ValueTreeHelpers::forEachChildOfType (sourceVT, CellProperties::CellTypeId, [this] (juce::ValueTree srcCellVT)
    {
        // <Cell row="0" column="0" layer="0" type="samtempl">
        //     <SampleProperties>
        //          ...
        //     <DelayProperties>
        //     <ReverbProperties>
        //     <IoConnectInProperties>
        //          ...
        //     <IoConnectOutProperties>
        //          ...
        //     <SongProperties>
        //     <AssetProperties>
        //          ...
        // </Cell>
        CellProperties srcCellProperties { srcCellVT, CellProperties::WrapperType::client, CellProperties::EnableCallbacks::no };
        auto destCellPropertiesVT { getCellProperties (data, srcCellProperties.getRow (), srcCellProperties.getColumn (), srcCellProperties.getLayer ()) };
        if (! destCellPropertiesVT.isValid ())
        {
            auto newCellProperties { srcCellProperties.getValueTree ().createCopy () };
            destCellPropertiesVT = newCellProperties;
            data.addChild (newCellProperties, -1, nullptr);
        }
        // iterate over children of Cell
        ValueTreeHelpers::forEachChild (srcCellVT, [this, &srcCellProperties, &destCellPropertiesVT] (juce::ValueTree srcCellChild)
        {
            const auto srcCellType { srcCellProperties.getType () };
            if (srcCellType == "samtempl")
            {
                jassertfalse;
            }
            else if (srcCellType == "sample")
            {
                SampleProperties srcSampleProperties { srcCellProperties.getValueTree().getChildWithName (SampleProperties::SampleTypeId), SampleProperties::WrapperType::client, SampleProperties::EnableCallbacks::no};
                const auto srcCellMode { srcSampleProperties.getCellMode () };
                jassert (srcCellMode == kSampleType || srcCellMode == kClipType || srcCellMode == kSlicedType || srcCellMode == kGranularType);
                SampleProperties destSampleProperties { destCellPropertiesVT.getChildWithName (SampleProperties::SampleTypeId), SampleProperties::WrapperType::client, SampleProperties::EnableCallbacks::no };
                if (destSampleProperties.isValid ())
                    destSampleProperties.copyPropertiesFrom (srcSampleProperties.getValueTree ());
                else
                    destCellPropertiesVT.addChild (srcSampleProperties.getValueTree ().createCopy(), -1, nullptr);

                // remove old modsources
                for (auto destChildIndex { destCellPropertiesVT.getNumChildren () }; destChildIndex > -1; --destChildIndex)
                {
                    auto destChild { destCellPropertiesVT.getChild (destChildIndex) };
                    if (destChild.getType () == ModSourceProperties::ModSourceTypeId)
                        destCellPropertiesVT.removeChild (destChild, nullptr);
                }
                // copy modsources
                ValueTreeHelpers::forEachChildOfType (srcCellProperties.getValueTree (), ModSourceProperties::ModSourceTypeId, [this, &destCellPropertiesVT] (juce::ValueTree modSrcChild)
                {
                    destCellPropertiesVT.addChild (modSrcChild.createCopy (), -1, nullptr);
                    return true;
                });
                // remove old slices
                auto destSlices = destCellPropertiesVT.getOrCreateChildWithName (SliceListProperties::SliceListTypeId, nullptr);
                if (destSlices.isValid ())
                {
                    for (auto destSliceIndex { destSlices.getNumChildren () }; destSliceIndex > -1; --destSliceIndex)
                    {
                        auto destChild { destSlices.getChild (destSliceIndex) };
                        if (destChild.getType () == SliceProperties::SliceTypeId)
                            destSlices.removeChild (destChild, nullptr);
                    }
                }
                // copy slices
                auto srcSlices = srcCellProperties.getValueTree ().getChildWithName (SliceListProperties::SliceListTypeId);
                if (srcSlices.isValid ())
                {
                    for (auto srcSlice : srcSlices)
                        destSlices.addChild (srcSlices.createCopy (), -1, nullptr);
                }
            }
            else if (srcCellType == "delay")
            {
                DelayProperties srcDelayProperties { srcCellProperties.getValueTree ().getChildWithName (DelayProperties::DelayTypeId), DelayProperties::WrapperType::client, DelayProperties::EnableCallbacks::no };
                DelayProperties destDelayProperties { getCellProperties (data, srcCellProperties.getRow(), srcCellProperties.getColumn(), srcCellProperties.getLayer()), DelayProperties::WrapperType::client, DelayProperties::EnableCallbacks::no};
                if (destDelayProperties.isValid ())
                {
                    destDelayProperties.copyPropertiesFrom (srcDelayProperties.getValueTree ());
                }
                else
                {
                    data.addChild (srcCellProperties.getValueTree ().createCopy (), -1, nullptr);
                }
            }
            else if (srcCellType == "reverb")
            {
                ReverbProperties srcReverbProperties { srcCellProperties.getValueTree ().getChildWithName (ReverbProperties::ReverbTypeId), ReverbProperties::WrapperType::client, ReverbProperties::EnableCallbacks::no };
                ReverbProperties destReverbProperties { getCellProperties (data, srcCellProperties.getRow (), srcCellProperties.getColumn (), srcCellProperties.getLayer ()), ReverbProperties::WrapperType::client, ReverbProperties::EnableCallbacks::no };
                if (destReverbProperties.isValid ())
                {
                    destReverbProperties.copyPropertiesFrom (srcReverbProperties.getValueTree ());
                }
                else
                {
                    data.addChild (srcCellProperties.getValueTree ().createCopy (), -1, nullptr);
                }
            }
            else if (srcCellType == "ioconnectin")
            {
                IoConnectInProperties srcIoConnectInProperties { srcCellProperties.getValueTree ().getChildWithName (IoConnectInProperties::IoConnectInTypeId), IoConnectInProperties::WrapperType::client, IoConnectInProperties::EnableCallbacks::no };
                IoConnectInProperties destIoConnectInProperties { getCellProperties (data, srcCellProperties.getRow (), srcCellProperties.getColumn (), srcCellProperties.getLayer ()), IoConnectInProperties::WrapperType::client, IoConnectInProperties::EnableCallbacks::no };
                if (destIoConnectInProperties.isValid ())
                {
                    destIoConnectInProperties.copyPropertiesFrom (srcIoConnectInProperties.getValueTree ());
                }
                else
                {
                    data.addChild (srcCellProperties.getValueTree ().createCopy (), -1, nullptr);
                }
            }
            else if (srcCellType == "ioconnectout")
            {
                IoConnectOutProperties srcIoConnectOutProperties { srcCellProperties.getValueTree ().getChildWithName (IoConnectOutProperties::IoConnectOutTypeId), IoConnectOutProperties::WrapperType::client, IoConnectOutProperties::EnableCallbacks::no };
                IoConnectOutProperties destIoConnectOutProperties { getCellProperties (data, srcCellProperties.getRow (), srcCellProperties.getColumn (), srcCellProperties.getLayer ()), IoConnectOutProperties::WrapperType::client, IoConnectOutProperties::EnableCallbacks::no };
                if (destIoConnectOutProperties.isValid ())
                {
                    destIoConnectOutProperties.copyPropertiesFrom (srcIoConnectOutProperties.getValueTree ());
                }
                else
                {
                    data.addChild (srcCellProperties.getValueTree ().createCopy (), -1, nullptr);
                }
            }
            else if (srcCellType == "song")
            {
                auto songPropsVT { srcCellProperties.getValueTree ().getChildWithName (SongProperties::SongTypeId) };
                SongProperties srcSongProperties { songPropsVT, SongProperties::WrapperType::client, SongProperties::EnableCallbacks::no };
                SongProperties destSongProperties { getCellProperties (data, srcCellProperties.getRow (), srcCellProperties.getColumn (), srcCellProperties.getLayer ()), SongProperties::WrapperType::client, SongProperties::EnableCallbacks::no };
                if (destSongProperties.isValid ())
                {
                    destSongProperties.copyPropertiesFrom (srcSongProperties.getValueTree ());
                }
                else
                {
                    data.addChild (srcCellProperties.getValueTree ().createCopy (), -1, nullptr);
                }
            }
            else
            {
                // unhandled cell types
                //if (cellType != "null")
                jassertfalse;
            }

            return true;
        });
        return true;
    });
}