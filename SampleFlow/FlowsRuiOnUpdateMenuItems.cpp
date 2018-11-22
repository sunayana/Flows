#include "stdafx.h"
#include "FlowsRuiOnUpdateMenuItems.h"
#include "SampleFlowPlugIn.h"

CFlowsRuiOnUpdateMenuItems::CFlowsRuiOnUpdateMenuItems()
{
    // Register OnUpdateMenuItem callback for this item
    RegisterMenuItem(CSampleFlowPlugIn::m_idFile, CSampleFlowPlugIn::m_idMenuFlows,
                     CSampleFlowPlugIn::m_idMenuItemSampleFlow);
}

void CFlowsRuiOnUpdateMenuItems::OnUpdateMenuItem( CRuiUpdateUi& cmdui )
{
    // Enable menu item
    if ( CSampleFlowPlugIn::m_idMenuItemSampleFlow == cmdui.MenuItemUUID() )
    {
        cmdui.Enable(true);
    }
}
