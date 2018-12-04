////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
//
// BEGIN ImportGeometry command
//
#include "stdafx.h"
#include "SampleImportGeometry.h"

#pragma region ImportGeometry command

class CCommandImportGeometry : public CRhinoCommand
{
public:
    CCommandImportGeometry() = default;
    UUID CommandUUID() override
    {
        // {84373977-94F5-4647-816E-DDB12489BD30}
        static const GUID ImportGeometryCommand_UUID =
        { 0x84373977, 0x94F5, 0x4647, { 0x81, 0x6E, 0xDD, 0xB1, 0x24, 0x89, 0xBD, 0x30 } };
        return ImportGeometryCommand_UUID;
    }
    const wchar_t* EnglishCommandName() override { return L"ImportGeometry"; }
    CRhinoCommand::result RunCommand(const CRhinoCommandContext& context) override;
};

// The one and only CCommandImportGeometry object
static class CCommandImportGeometry theImportGeometryCommand;

CRhinoCommand::result CCommandImportGeometry::RunCommand(const CRhinoCommandContext& context)
{
    ON_wString str;
    str.Format(L"The \"%s\" command is under construction.\n", EnglishCommandName());
    if (context.IsInteractive())
    {
        //RhinoMessageBox(str, EnglishCommandName(), MB_OK);
        // Create the dialog box
        RhinoUiDockBarManager().ShowDockBar(CSampleImportGeometry().DockBarID(), true, false);
    }
    else
        RhinoApp().Print(str);
    return CRhinoCommand::success;
}

#pragma endregion

//
// END ImportGeometry command
//
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
