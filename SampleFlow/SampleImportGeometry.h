#pragma once

#include "SampleImportGeometryDialog.h"

class CSampleImportGeometry : public CRhinoUiDockBar
{
    DECLARE_SERIAL(CSampleImportGeometry)

public:
    CSampleImportGeometry();
    virtual ~CSampleImportGeometry();

    //Required overrides
    UUID DockBarID() const override;
    const wchar_t* DockBarName(int language_id = 1033) const override;

protected:
    bool CreateDockBarControls() override;

    DECLARE_MESSAGE_MAP()
};
