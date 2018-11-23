////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
//
// BEGIN StartFlow command
//


#include "stdafx.h"
#include <rhinoSdkCommand.h>

#include "SampleFlowViewReceiver.h"
#include "SampleFlowViewColorsConduit.h"

//This is the command name that is used in the rui toolbar button.
#pragma region StartFlow command

class CCommandStartFlow : public CRhinoCommand
{
public:
    CCommandStartFlow();
    ~CCommandStartFlow() = default;

    UUID CommandUUID() override
    {
        // {BEE6CFDE-E0A2-41CD-BADC-8E6831CF26E2}
        static const GUID StartFlowCommand_UUID =
            {0xBEE6CFDE, 0xE0A2, 0x41CD, {0xBA, 0xDC, 0x8E, 0x68, 0x31, 0xCF, 0x26, 0xE2}};
        return StartFlowCommand_UUID;
    }

    const wchar_t* EnglishCommandName() override
    {
        return L"StartFlow";
    }

    result RunCommand( const CRhinoCommandContext& context ) override;

private:
    CSampleFlowViewColorsConduit m_conduit;
};

// The one and only CCommandStartFlow object
static class CCommandStartFlow the_start_flow_command;

CCommandStartFlow::CCommandStartFlow()
{
    m_conduit.m_background_color = RGB(255, 255, 255);
    m_conduit.m_thick_line_color = RGB(255, 255, 255);
    m_conduit.m_thin_line_color = RGB(255, 255, 255);
    m_conduit.m_grid_x_axis_color = RGB(255, 0, 0);
    m_conduit.m_grid_y_axis_color = RGB(0, 255, 0);
    m_conduit.m_grid_z_axis_color = RGB(0, 0, 255);
}

// Command to create a new view that has the properties of an existing view.
CRhinoCommand::result CCommandStartFlow::RunCommand( const CRhinoCommandContext& context )
{
    if (m_conduit.IsEnabled())
    {
        m_conduit.Disable();
    }
    else
    {
        m_conduit.Enable(context.m_doc.RuntimeSerialNumber());
    }
    context.m_doc.Regen();

    return CSampleFlowViewReceiver::action(context);
}
