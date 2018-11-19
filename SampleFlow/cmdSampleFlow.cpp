// cmdSampleFlow.cpp : command file
//

#include "stdafx.h"
#include "SampleFlowPlugIn.h"

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
//
// BEGIN SampleFlow command
//

#pragma region SampleFlow command

// Do NOT put the definition of class CCommandSampleFlow in a header
// file. There is only ONE instance of a CCommandSampleFlow class
// and that instance is the static theSampleFlowCommand that appears
// immediately below the class definition.

class CCommandSampleFlow : public CRhinoCommand
{
public:
    // The one and only instance of CCommandSampleFlow is created below.
    // No copy constructor or operator= is required.
    // Values of member variables persist for the duration of the application.

    // CCommandSampleFlow::CCommandSampleFlow()
    // is called exactly once when static theSampleFlowCommand is created.
    CCommandSampleFlow() = default;

    // CCommandSampleFlow::~CCommandSampleFlow()
    // is called exactly once when static theSampleFlowCommand is destroyed.
    // The destructor should not make any calls to the Rhino SDK. 
    // If your command has persistent settings, then override 
    // CRhinoCommand::SaveProfile and CRhinoCommand::LoadProfile.
    ~CCommandSampleFlow() = default;

    // Returns a unique UUID for this command.
    // If you try to use an id that is already being used, then
    // your command will not work. Use GUIDGEN.EXE to make unique UUID.
    UUID CommandUUID() override
    {
        // {BA8F7106-3730-4B3B-BFFD-0A688734CC1F}
        static const GUID SampleFlowCommand_UUID =
            {0xBA8F7106, 0x3730, 0x4B3B, {0xBF, 0xFD, 0xA, 0x68, 0x87, 0x34, 0xCC, 0x1F}};
        return SampleFlowCommand_UUID;
    }

    // Returns the English command name.
    // If you want to provide a localized command name, then override 
    // CRhinoCommand::LocalCommandName.
    const wchar_t* EnglishCommandName() override
    {
        return L"SampleFlow";
    }

    // Rhino calls RunCommand to run the command.
    result RunCommand( const CRhinoCommandContext& context ) override;
};

// The one and only CCommandSampleFlow object
// Do NOT create any other instance of a CCommandSampleFlow class.
static class CCommandSampleFlow the_sample_flow_command;

CRhinoCommand::result CCommandSampleFlow::RunCommand( const CRhinoCommandContext& context )
{
    // CCommandSampleFlow::RunCommand() is called when the user
    // runs the "SampleFlow".

    // TODO: Add command code here.

    // Rhino command that display a dialog box interface should also support
    // a command-line, or scriptable interface.

    ON_wString str;
    str.Format(L"The \"%s\" command is under construction.\n", EnglishCommandName());
    const auto* pszStr = static_cast< const wchar_t* >(str);
    if ( context.IsInteractive() )
        RhinoMessageBox(pszStr, SampleFlowPlugIn().PlugInName(), MB_OK);
    else
        RhinoApp().Print(pszStr);

    // TODO: Return one of the following values:
    //   CRhinoCommand::success:  The command worked.
    //   CRhinoCommand::failure:  The command failed because of invalid input, inability
    //                            to compute the desired result, or some other reason
    //                            computation reason.
    //   CRhinoCommand::cancel:   The user interactively canceled the command 
    //                            (by pressing ESCAPE, clicking a CANCEL button, etc.)
    //                            in a Get operation, dialog, time consuming computation, etc.

    return success;
}

#pragma endregion

//
// END SampleFlow command
//
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
