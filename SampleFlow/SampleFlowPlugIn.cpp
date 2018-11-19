// SampleFlowPlugIn.cpp : defines the initialization routines for the plug-in.
//

#include "stdafx.h"
#include "rhinoSdkPlugInDeclare.h"
#include "SampleFlowPlugIn.h"
#include "Resource.h"

// The plug-in object must be constructed before any plug-in classes derived
// from CRhinoCommand. The #pragma init_seg(lib) ensures that this happens.
#pragma warning(push)
#pragma warning(disable : 4073)
#pragma init_seg(lib)
#pragma warning(pop)

// Rhino plug-in declaration
RHINO_PLUG_IN_DECLARE

// Rhino plug-in name
// Provide a short, friendly name for this plug-in.
RHINO_PLUG_IN_NAME(L"SampleFlow");

// Rhino plug-in id
// Provide a unique uuid for this plug-in.
RHINO_PLUG_IN_ID(L"F8BF6D30-0645-4787-8803-1404F1314948");

// Rhino plug-in version
// Provide a version number string for this plug-in.
RHINO_PLUG_IN_VERSION(__DATE__ "  " __TIME__)

// Rhino plug-in description
// Provide a description of this plug-in.
RHINO_PLUG_IN_DESCRIPTION(L"SampleFlow plug-in for Rhinoceros®");

// Rhino plug-in icon resource id
// Provide an icon resource this plug-in.
// Icon resource should contain 16, 24, 32, 48, and 256-pixel image sizes.
RHINO_PLUG_IN_ICON_RESOURCE_ID(IDI_ICON);

// Rhino plug-in developer declarations
// TODO: fill in the following developer declarations with
// your company information. Note, all of these declarations
// must be present or your plug-in will not load.
//
// When completed, delete the following #error directive.
//#error Developer declarations block is incomplete!
RHINO_PLUG_IN_DEVELOPER_ORGANIZATION(L"My Company Name");
RHINO_PLUG_IN_DEVELOPER_ADDRESS(L"123 Developer Street\r\nCity State 12345-6789");
RHINO_PLUG_IN_DEVELOPER_COUNTRY(L"My Country");
RHINO_PLUG_IN_DEVELOPER_PHONE(L"123.456.7890");
RHINO_PLUG_IN_DEVELOPER_FAX(L"123.456.7891");
RHINO_PLUG_IN_DEVELOPER_EMAIL(L"support@mycompany.com");
RHINO_PLUG_IN_DEVELOPER_WEBSITE(L"http://www.mycompany.com");
RHINO_PLUG_IN_UPDATE_URL(L"http://www.mycompany.com/support");

// The one and only CSampleFlowPlugIn object
static class CSampleFlowPlugIn thePlugIn;

/////////////////////////////////////////////////////////////////////////////
// CSampleFlowPlugIn definition

CSampleFlowPlugIn& SampleFlowPlugIn()
{
    // Return a reference to the one and only CSampleFlowPlugIn object
    return thePlugIn;
}

CSampleFlowPlugIn::CSampleFlowPlugIn()
{
    // Description:
    //   CSampleFlowPlugIn constructor. The constructor is called when the
    //   plug-in is loaded and "thePlugIn" is constructed. Once the plug-in
    //   is loaded, CSampleFlowPlugIn::OnLoadPlugIn() is called. The
    //   constructor should be simple and solid. Do anything that might fail in
    //   CSampleFlowPlugIn::OnLoadPlugIn().

    // TODO: Add construction code here
    m_plugin_version = RhinoPlugInVersion();
}

/////////////////////////////////////////////////////////////////////////////
// Required overrides

const wchar_t* CSampleFlowPlugIn::PlugInName() const
{
    // Description:
    //   Plug-in name display string.  This name is displayed by Rhino when
    //   loading the plug-in, in the plug-in help menu, and in the Rhino
    //   interface for managing plug-ins.

    // TODO: Return a short, friendly name for the plug-in.
    return RhinoPlugInName();
}

const wchar_t* CSampleFlowPlugIn::PlugInVersion() const
{
    // Description:
    //   Plug-in version display string. This name is displayed by Rhino
    //   when loading the plug-in and in the Rhino interface for managing
    //   plug-ins.

    // TODO: Return the version number of the plug-in.
    return m_plugin_version;
}

GUID CSampleFlowPlugIn::PlugInID() const
{
    // Description:
    //   Plug-in unique identifier. The identifier is used by Rhino to
    //   manage the plug-ins.

    // TODO: Return a unique identifier for the plug-in.
    // {F8BF6D30-0645-4787-8803-1404F1314948}
    return ON_UuidFromString(RhinoPlugInId());
}

/////////////////////////////////////////////////////////////////////////////
// Additional overrides

BOOL CSampleFlowPlugIn::OnLoadPlugIn()
{
    // Description:
    //   Called after the plug-in is loaded and the constructor has been
    //   run. This is a good place to perform any significant initialization,
    //   license checking, and so on.  This function must return TRUE for
    //   the plug-in to continue to load.

    // Remarks:
    //    Plug-ins are not loaded until after Rhino is started and a default document
    //    is created.  Because the default document already exists
    //    CRhinoEventWatcher::On????Document() functions are not called for the default
    //    document.  If you need to do any document initialization/synchronization then
    //    override this function and do it here.  It is not necessary to call
    //    CPlugIn::OnLoadPlugIn() from your derived class.

    // TODO: Add plug-in initialization code here.
    // If the version number of the plugin that was last used does not match the 
    // version number of this plugin, proceed.
    if ( !m_last_version.IsEmpty() && 0 != m_last_version.CompareNoCase(m_plugin_version) )
    {
        // Build a path to the user's staged RUI file.

        ON_wString path;
        CRhinoFileUtilities::GetRhinoRoamingProfileDataFolder(path);
        path += L"UI\\Plug-ins\\";

        ON_wString plugin;
        GetPlugInFileName(plugin);

        ON_wString fname;
        ON_wString::SplitPath(plugin, nullptr, nullptr, &fname, nullptr);
        fname += L".rui";

        path += fname;

        // Verify the RUI file exists.
        if ( CRhinoFileUtilities::FileExists(path) )
            // Delete the RUI file.
            CRhinoFileUtilities::DeleteFile(path);
    }

    

    return CRhinoUtilityPlugIn::OnLoadPlugIn();
    //return TRUE;
}

void CSampleFlowPlugIn::OnUnloadPlugIn()
{
    // Description:
    //    Called one time when plug-in is about to be unloaded. By this time,
    //    Rhino's mainframe window has been destroyed, and some of the SDK
    //    managers have been deleted. There is also no active document or active
    //    view at this time. Thus, you should only be manipulating your own objects.
    //    or tools here.

    // TODO: Add plug-in cleanup code here.
    CRhinoUtilityPlugIn::OnUnloadPlugIn();
}

void CSampleFlowPlugIn::LoadProfile( LPCTSTR lpszSection, CRhinoProfileContext& pc )
{
    // Get the version number of our plugin that was last used
    pc.LoadProfileString(lpszSection, L"PlugInVersion", m_last_version);
}

void CSampleFlowPlugIn::SaveProfile( LPCTSTR lpszSection, CRhinoProfileContext& pc )
{
    // Get the version number of our plugin
    pc.SaveProfileString(lpszSection, L"PlugInVersion", m_plugin_version);
}

const UUID CSampleFlowPlugIn::m_idFile = {0x6fbd18ca, 0xbdce, 0x44ae, {0xba, 0x8f, 0x3c, 0x2c, 0x46, 0x3e, 0x52, 0xf9}};
const UUID CSampleFlowPlugIn::m_idMenuFlows = {
    0x130a9a5b, 0x5620, 0x4588, {0x96, 0x41, 0x13, 0xd6, 0x7d, 0x4a, 0x19, 0x07}
};
const UUID CSampleFlowPlugIn::m_idMenuItemSampleFlow = {
    0x7648b550, 0xb008, 0x42ab, {0xb2, 0xb3, 0xf1, 0xb8, 0xf4, 0xac, 0xe5, 0x97}
};
