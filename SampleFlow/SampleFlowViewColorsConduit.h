#pragma once

class CSampleFlowViewColorsConduit : public CRhinoDisplayConduit
{
public:
    CSampleFlowViewColorsConduit();
    
    bool ExecConduit(CRhinoDisplayPipeline& dp, UINT nChannel, bool& bTerminate) override;

    

public:
    ON_Color m_background_color;
    ON_Color m_thick_line_color;
    ON_Color m_thin_line_color;
    ON_Color m_grid_x_axis_color;
    ON_Color m_grid_y_axis_color;
    ON_Color m_grid_z_axis_color;

private:
    bool OnInitFrameBuffer(CRhinoDisplayPipeline& dp, bool& bTerminate) const;
    bool OnDrawBackground(CRhinoDisplayPipeline& dp, bool& bTerminate) const;
};
