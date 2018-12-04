#include "stdafx.h"
#include "SampleImportGeometry.h"

IMPLEMENT_SERIAL(CSampleImportGeometry, CRhinoUiDockBar, 1)

CSampleImportGeometry::CSampleImportGeometry()
{}

CSampleImportGeometry::~CSampleImportGeometry()
{}

BEGIN_MESSAGE_MAP(CSampleImportGeometry, CRhinoUiDockBar)
END_MESSAGE_MAP()

UUID CSampleImportGeometry::DockBarID() const
{
    // {56A9539C-5AAC-494A-84C5-B550AB4F5C47}
    static const GUID SampleImportGeometry_UUID =
    { 0x56a9539c, 0x5aac, 0x494a, { 0x84, 0xc5, 0xb5, 0x50, 0xab, 0x4f, 0x5c, 0x47 } };
    return SampleImportGeometry_UUID;
}

const wchar_t* CSampleImportGeometry::DockBarName(int language_id)  const
{
    UNREFERENCED_PARAMETER(language_id);
    return L"Import Geometry";
}

bool CSampleImportGeometry::CreateDockBarControls()
{
    // Create the dialog to display in our dockbar
    bool rc = CreateDockBarClientDialog(
        CSampleImportGeometryDialog::IDD,
        RUNTIME_CLASS(CSampleImportGeometryDialog),
        AfxGetStaticModuleState()
    );

    return rc;
}