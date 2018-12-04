// SampleImportGeometryDialog.cpp : implementation file
//

#include "stdafx.h"
#include "SampleImportGeometryDialog.h"
#include "SampleFlowPlugIn.h"
//#include "afxdialogex.h"
#include "Resource.h"


// SampleImportGeometryDialog dialog

//IMPLEMENT_DYNAMIC(CSampleImportGeometryDialog, CRhinoDialog)
IMPLEMENT_SERIAL(CSampleImportGeometryDialog, CRhinoUiDockBarDialog, 1)

CSampleImportGeometryDialog::CSampleImportGeometryDialog(CWnd* pParent /*=nullptr*/)
	: CRhinoUiDockBarDialog(CSampleImportGeometryDialog::IDD, pParent)
{

}

CSampleImportGeometryDialog::~CSampleImportGeometryDialog()
{
}

void CSampleImportGeometryDialog::DoDataExchange(CDataExchange* pDX)
{
	CRhinoUiDockBarDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSampleImportGeometryDialog, CRhinoUiDockBarDialog)
    ON_BN_CLICKED(IDCANCEL, &CSampleImportGeometryDialog::OnBnClickedCancel)
    ON_BN_CLICKED(IDOK, &CSampleImportGeometryDialog::OnBnClickedOk)
END_MESSAGE_MAP()


// SampleImportGeometryDialog message handlers

BOOL CSampleImportGeometryDialog::OnInitDialog()
{
    CRhinoUiDockBarDialog::OnInitDialog();
    
    // TODO...
    return TRUE;
}

void CSampleImportGeometryDialog::OnBnClickedCancel()
{
    // TODO: Add your control notification handler code here
    CRhinoUiDockBarDialog::OnCancel();
}


void CSampleImportGeometryDialog::OnBnClickedOk()
{
    // TODO: Add your control notification handler code here
    CRhinoUiDockBarDialog::OnOK();
}
