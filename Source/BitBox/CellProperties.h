#pragma once

#include <JuceHeader.h>
#include "../Utility/ValueTreeWrapper.h"

class CellProperties : public ValueTreeWrapper<CellProperties>
{
public:
    CellProperties () noexcept : ValueTreeWrapper<CellProperties> (CellTypeId) {}
    CellProperties (juce::ValueTree vt, WrapperType wrapperType, EnableCallbacks shouldEnableCallbacks)
        : ValueTreeWrapper<CellProperties> (CellTypeId, vt, wrapperType, shouldEnableCallbacks) {}

    void setType (juce::String cellType, bool includeSelfCallback) { setValue (cellType, TypePropertyId, includeSelfCallback); }
    juce::String getType () { return getValue<juce::String> (TypePropertyId); }

    void setRow (int row, bool includeSelfCallback) { setValue (row, RowPropertyId, includeSelfCallback); }
    int getRow () { return getValue<int> (RowPropertyId); }

    void setColumn (int column, bool includeSelfCallback) { setValue (column, ColumnPropertyId, includeSelfCallback); }
    int getColumn () { return getValue<int> (ColumnPropertyId); }

    void setLayer (int layer, bool includeSelfCallback) { setValue (layer, LayerPropertyId, includeSelfCallback); }
    int getLayer () { return getValue<int> (LayerPropertyId); }

    std::function<void (juce::String cellType)> onTypeChange;
    std::function<void (int row)> onRowChange;
    std::function<void (int column)> onColumnChange;
    std::function<void (int layer)> onLayerChange;

    static inline const juce::Identifier CellTypeId { "Cell" };
    static inline const juce::Identifier TypePropertyId   { "cellType" };
    static inline const juce::Identifier RowPropertyId    { "row" };
    static inline const juce::Identifier ColumnPropertyId { "column" };
    static inline const juce::Identifier LayerPropertyId  { "layer" };

    void initValueTree () {}
    void processValueTree () {}

private:
    void valueTreePropertyChanged (juce::ValueTree& treeWhosePropertyHasChanged, const juce::Identifier& property) override
    {
        if (treeWhosePropertyHasChanged == data)
        {
            if (property == TypePropertyId)
            {
                if (onTypeChange != nullptr)
                    onTypeChange (getType ());
            }
            else if (property == RowPropertyId)
            {
                if (onRowChange != nullptr)
                    onRowChange (getRow ());
            }
            else if (property == ColumnPropertyId)
            {
                if (onColumnChange != nullptr)
                    onColumnChange (getColumn ());
            }
            else if (property == LayerPropertyId)
            {
                if (onLayerChange != nullptr)
                    onLayerChange (getLayer ());
            }
        }
    }
};