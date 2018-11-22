// SampleFlowPlugIn.h : main header file for the SampleFlow plug-in.
//

#pragma once
#include "FlowsRuiOnUpdateMenuItems.h"

// CSampleFlowPlugIn
// See SampleFlowPlugIn.cpp for the implementation of this class
//

class CSampleFlowPlugIn : public CRhinoUtilityPlugIn
{
public:
    // CSampleFlowPlugIn constructor. The constructor is called when the
    // plug-in is loaded and "thePlugIn" is constructed. Once the plug-in
    // is loaded, CSampleFlowPlugIn::OnLoadPlugIn() is called. The
    // constructor should be simple and solid. Do anything that might fail in
    // CSampleFlowPlugIn::OnLoadPlugIn().
    CSampleFlowPlugIn();

    // CSampleFlowPlugIn destructor. The destructor is called to destroy
    // "thePlugIn" when the plug-in is unloaded. Immediately before the
    // DLL is unloaded, CSampleFlowPlugIn::OnUnloadPlugin() is called. Do
    // not do too much here. Be sure to clean up any memory you have allocated
    // with onmalloc(), onrealloc(), oncalloc(), or onstrdup().
    ~CSampleFlowPlugIn() = default;

    // Required overrides

    // Plug-in name display string. This name is displayed by Rhino when
    // loading the plug-in, in the plug-in help menu, and in the Rhino
    // interface for managing plug-ins. 
    const wchar_t* PlugInName() const override;

    // Plug-in version display string. This name is displayed by Rhino
    // when loading the plug-in and in the Rhino interface for 
    // managing plug-ins.
    const wchar_t* PlugInVersion() const override;

    // Plug-in unique identifier. The identifier is used by Rhino for
    // managing plug-ins.
    GUID PlugInID() const override;

    // Additional overrides

    // Called after the plug-in is loaded and the constructor has been
    // run. This is a good place to perform any significant initialization,
    // license checking, and so on.  This function must return TRUE for
    // the plug-in to continue to load.  
    BOOL OnLoadPlugIn() override;

    // Called one time when plug-in is about to be unloaded. By this time,
    // Rhino's mainframe window has been destroyed, and some of the SDK
    // managers have been deleted. There is also no active document or active
    // view at this time. Thus, you should only be manipulating your own objects.
    // or tools here.  
    void OnUnloadPlugIn() override;

    void LoadProfile( LPCTSTR lpszSection, CRhinoProfileContext& pc ) override;
    void SaveProfile( LPCTSTR lpszSection, CRhinoProfileContext& pc ) override;

    //Add these members to your derived CRhinoPlugIn class
    // 6fbd18ca-bdce-44ae-ba8f-3c2c463e52f9
    static const UUID m_idFile;
    // 130a9a5b-5620-4588-9641-13d67d4a1907
    static const UUID m_idMenuFlows;
    // 7648b550-b008-42ab-b2b3-f1b8f4ace597
    static const UUID m_idMenuItemSampleFlow;

    CFlowsRuiOnUpdateMenuItems m_MyUpdateMenuItems;

private:
    ON_wString m_plugin_version;
    ON_wString m_last_version;

    // TODO: Add additional class information here
};

// Return a reference to the one and only CSampleFlowPlugIn object
CSampleFlowPlugIn& SampleFlowPlugIn();
