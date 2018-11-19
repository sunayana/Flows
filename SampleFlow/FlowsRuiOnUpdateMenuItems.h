#pragma once

class CFlowsRuiOnUpdateMenuItems : public CRuiOnUpdateMenuItems
{
public:
    CFlowsRuiOnUpdateMenuItems();

    void OnUpdateMenuItem( CRuiUpdateUi& cmdui ) override;
};
