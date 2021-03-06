#pragma once

#include "Resource.h"
// SampleImportGeometryDialog dialog

class CSampleImportGeometryDialog : public CRhinoUiDockBarDialog
{
	//DECLARE_DYNAMIC(CSampleImportGeometryDialog)
    DECLARE_SERIAL(CSampleImportGeometryDialog)

public:
	CSampleImportGeometryDialog(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CSampleImportGeometryDialog();

// Dialog Data
//#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_RHINO_DOCKBAR_DIALOG };
//#endif

protected:
    virtual BOOL OnInitDialog() override;
	virtual void DoDataExchange(CDataExchange* pDX) override;    // DDX/DDV support
    afx_msg void OnBnClickedCancel();
    afx_msg void OnBnClickedOk();
	DECLARE_MESSAGE_MAP()

};
