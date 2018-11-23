#include "stdafx.h"
#include "SampleFlowViewColorsConduit.h"

CSampleFlowViewColorsConduit::CSampleFlowViewColorsConduit() :
    CRhinoDisplayConduit(CSupportChannels::SC_INITFRAMEBUFFER | CSupportChannels::SC_DRAWBACKGROUND)
{
    m_background_color = ON_UNSET_COLOR;
    m_thick_line_color = ON_UNSET_COLOR;
    m_thin_line_color = ON_UNSET_COLOR;
    m_grid_x_axis_color = ON_UNSET_COLOR;
    m_grid_y_axis_color = ON_UNSET_COLOR;
    m_grid_z_axis_color = ON_UNSET_COLOR;
}

bool CSampleFlowViewColorsConduit::ExecConduit(CRhinoDisplayPipeline& dp, UINT nChannel, bool& bTerminate)
{
    if (dp.IsPrinting())
    {
        return true;
    }

    if (CSupportChannels::SC_INITFRAMEBUFFER == nChannel)
    {
        return OnInitFrameBuffer(dp, bTerminate);
    }
    else if (CSupportChannels::SC_DRAWBACKGROUND == nChannel)
    {
        return OnDrawBackground(dp, bTerminate);
    }

    return true;
}

bool CSampleFlowViewColorsConduit::OnInitFrameBuffer(CRhinoDisplayPipeline& dp, bool& bTerminate) const
{
    UNREFERENCED_PARAMETER(bTerminate);

    // This should only be called once in the initial frame buffer init,
    // but just to be safe make sure it doesn't do anything in a nested call.
    {
        if (dp.NestLevel() > 0)
            return true;
    }

    const CRhinoViewport* viewport = dp.GetRhinoVP();
    if (viewport && viewport->VP().Projection() == ON::perspective_view)
    {
        m_pChannelAttrs->m_eFrameBufferFillMode = FBFM_SOLID_COLOR;
        m_pChannelAttrs->m_SolidColor = m_background_color;
    }

    return true;
    
}

bool CSampleFlowViewColorsConduit::OnDrawBackground(CRhinoDisplayPipeline& dp, bool& bTerminate)
{
    UNREFERENCED_PARAMETER(bTerminate);

    const CRhinoViewport* viewport = dp.GetRhinoVP();
    if (viewport && viewport->VP().Projection() == ON::perspective_view)
    {
        dp.DrawConstructionPlane(
            viewport->ConstructionPlane(),
            true, true, true,
            m_thick_line_color,
            m_thin_line_color,
            m_grid_x_axis_color,
            m_grid_y_axis_color,
            m_grid_z_axis_color
        );

        m_pChannelAttrs->m_bGridDrawn = true;
        m_pChannelAttrs->m_bAxesDrawn = true;
    }

    return true;
}