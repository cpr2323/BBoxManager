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
        ValueTreeHelpers::forEachChild (srcCellVT, [this, &srcCellProperties] (juce::ValueTree srcCellChild)
        {
            const auto srcCellType { srcCellProperties.getType () };
            if (srcCellType == "sample")
            {
                SampleProperties srcSampleProperties { srcCellProperties.getValueTree().getChildWithName (SampleProperties::SampleTypeId), SampleProperties::WrapperType::client, SampleProperties::EnableCallbacks::no};
                const auto srcCellMode { srcSampleProperties.getCellMode () };
                jassert (srcCellMode == kSampleType || srcCellMode == kClipType || srcCellMode == kSlicedType || srcCellMode == kGranularType);
                auto destCellPropertiesVT { getCellProperties (data, srcCellProperties.getRow (), srcCellProperties.getColumn (), srcCellProperties.getLayer ()) };
                if (destCellPropertiesVT.isValid ())
                {
                    SampleProperties destSampleProperties { destCellPropertiesVT.getChildWithName (SampleProperties::SampleTypeId), SampleProperties::WrapperType::client, SampleProperties::EnableCallbacks::no };
                    destSampleProperties.copyPropertiesFrom (srcSampleProperties.getValueTree ());

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
                else
                {
                    data.addChild (srcCellProperties.getValueTree ().createCopy(), -1, nullptr);
                }
            }
            else if (srcCellType == "delay")
            {
                DelayProperties delayProperties { srcCellProperties.getValueTree ().getChildWithName (DelayProperties::DelayTypeId), DelayProperties::WrapperType::client, DelayProperties::EnableCallbacks::no };
            }
            else if (srcCellType == "reverb")
            {
                ReverbProperties reverbProperties { srcCellProperties.getValueTree ().getChildWithName (ReverbProperties::ReverbTypeId), ReverbProperties::WrapperType::client, ReverbProperties::EnableCallbacks::no };
            }
            else if (srcCellType == "ioconnectin")
            {
                IoConnectInProperties ioConnectInProperties { srcCellProperties.getValueTree ().getChildWithName (IoConnectInProperties::IoConnectInTypeId), IoConnectInProperties::WrapperType::client, IoConnectInProperties::EnableCallbacks::no };
            }
            else if (srcCellType == "ioconnectout")
            {
                IoConnectOutProperties ioConnectOutProperties { srcCellProperties.getValueTree ().getChildWithName (IoConnectOutProperties::IoConnectOutTypeId), IoConnectOutProperties::WrapperType::client, IoConnectOutProperties::EnableCallbacks::no };
            }
            else if (srcCellType == "song")
            {
                SongProperties songProperties { srcCellProperties.getValueTree ().getChildWithName (SongProperties::SongTypeId), SongProperties::WrapperType::client, SongProperties::EnableCallbacks::no };
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
