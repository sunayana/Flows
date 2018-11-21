#pragma once
#include "stdafx.h"

class CSampleFlowViewReceiver
{
public:
    CSampleFlowViewReceiver() = default;

    static CRhinoCommand::result action( const CRhinoCommandContext& context );

private:
    static CRhinoCommand::result createSampleFlowView( const CRhinoCommandContext& context );
};
