#pragma once
#include "stdafx.h"
#include "SampleFlowViewColorsConduit.h"

class CSampleFlowViewReceiver
{
public:
    CSampleFlowViewReceiver() = default;

    static CRhinoCommand::result action( const CRhinoCommandContext& context,
        CSampleFlowViewColorsConduit& conduit);

private:
    static CRhinoCommand::result createSampleFlowView( const CRhinoCommandContext& context, 
        CSampleFlowViewColorsConduit& conduit );
    //static void setConduit(CSampleFlowViewColorsConduit& conduit);

    //CSampleFlowViewColorsConduit m_conduit;

};
