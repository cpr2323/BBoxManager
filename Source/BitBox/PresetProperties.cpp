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

juce::ValueTree getCellProperties (juce::ValueTree vt, int row, int column, int layer)
{
    juce::ValueTree cellPropertiesVT;
    ValueTreeHelpers::forEachChildOfType (vt, CellProperties::CellTypeId, [&cellPropertiesVT, row, column, layer] (juce::ValueTree cellChild)
    {
        CellProperties cellProperties { cellChild, CellProperties::WrapperType::client, CellProperties::EnableCallbacks::no };
        if (cellProperties.getRow () == row && cellProperties.getColumn () == column && cellProperties.getLayer () == layer)
        {
            cellPropertiesVT = cellChild;
            return false;
        }
        return true;
    });
    return cellPropertiesVT;
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
            if (srcCellType == "sample")
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
                ValueTreeHelpers::forEachChildOfType (srcCellProperties.getValueTree (), ModSourceProperties::ModSourceTypeId, [this, &destCellPropertiesVT] (juce::ValueTree child)
                {
                    if (child.getType () == ModSourceProperties::ModSourceTypeId)
                        destCellPropertiesVT.addChild (child.createCopy (), -1, nullptr);
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
