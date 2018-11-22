// SampleFlow.h : main header file for the SampleFlow DLL.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "Resource.h" // main symbols

// CSampleFlowApp
// See SampleFlowApp.cpp for the implementation of this class
//

class CSampleFlowApp : public CWinApp
{
public:
    // CRITICAL: DO NOT CALL RHINO SDK FUNCTIONS HERE!
    // Only standard MFC DLL instance construction belongs here. 
    // All other significant initialization should take place in
    // CSampleFlowPlugIn::OnLoadPlugIn().
    CSampleFlowApp() = default;

    // CRITICAL: DO NOT CALL RHINO SDK FUNCTIONS HERE!
    // Only standard MFC DLL instance initialization belongs here. 
    // All other significant initialization should take place in
    // CSampleFlowPlugIn::OnLoadPlugIn().
    BOOL InitInstance() override;

    // CRITICAL: DO NOT CALL RHINO SDK FUNCTIONS HERE!
    // Only standard MFC DLL instance clean up belongs here. 
    // All other significant cleanup should take place in either
    // CSampleFlowPlugIn::OnSaveAllSettings() or
    // CSampleFlowPlugIn::OnUnloadPlugIn().  
    int ExitInstance() override;

DECLARE_MESSAGE_MAP()
};
