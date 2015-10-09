// SetSpeakerTestDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SetSpeakerTest.h"
#include "SetSpeakerTestDlg.h"

#define USE_V2

#ifdef USE_V2
	#include "../SetSpeakerMode2/SetSpeakerMode2.h"
	#pragma comment (lib, "../SetSpeakerMode2/Windows Mobile 6.5.3 Professional DTK (ARMV4I)/Debug/SetSpeakerMode2.lib")
//#else
	#include "../SetSpeakerMode/SetSpeakerMode1.h"
	#pragma comment (lib, "../SetSpeakerMode/Windows Mobile 6.5.3 Professional DTK (ARMV4I)/Debug/SetSpeakerMode.lib")
#endif //USE_V2

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CSetSpeakerTestDlg dialog

CSetSpeakerTestDlg::CSetSpeakerTestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSetSpeakerTestDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSetSpeakerTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CSetSpeakerTestDlg, CDialog)
#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
	ON_WM_SIZE()
#endif
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, &CSetSpeakerTestDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CSetSpeakerTestDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CSetSpeakerTestDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CSetSpeakerTestDlg::OnBnClickedButton4)
END_MESSAGE_MAP()


// CSetSpeakerTestDlg message handlers

BOOL CSetSpeakerTestDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	return TRUE;  // return TRUE  unless you set the focus to a control
}

#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
void CSetSpeakerTestDlg::OnSize(UINT /*nType*/, int /*cx*/, int /*cy*/)
{
	if (AfxIsDRAEnabled())
	{
		DRA::RelayoutDialog(
			AfxGetResourceHandle(), 
			this->m_hWnd, 
			DRA::GetDisplayMode() != DRA::Portrait ? 
			MAKEINTRESOURCE(IDD_SETSPEAKERTEST_DIALOG_WIDE) : 
			MAKEINTRESOURCE(IDD_SETSPEAKERTEST_DIALOG));
	}
}
#endif


void CSetSpeakerTestDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	ToggleSpeakerPhone(TRUE);
}

void CSetSpeakerTestDlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	ToggleSpeakerPhone(FALSE);
}

void CSetSpeakerTestDlg::OnBnClickedButton3()
{
	// TODO: Add your control notification handler code here
	setSpeaker(SPK_SPEAKER);
}

void CSetSpeakerTestDlg::OnBnClickedButton4()
{
	// TODO: Add your control notification handler code here
	setSpeaker(SPK_NORMAL);
}
