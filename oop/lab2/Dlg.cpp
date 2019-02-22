
#include "stdafx.h"
#include "OOP-lab2.h"
#include "Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

Dlg::Dlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_OOPLAB2_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_ED_CMD, EdCmd);
	DDX_Control(pDX, IDC_CB_ENABLED, CbEnabled);
	DDX_Control(pDX, IDC_CB_VISIBLE, CbVisible);
	CbEnabled.SetCheck(BST_CHECKED);
	CbVisible.SetCheck(BST_CHECKED);
}

BEGIN_MESSAGE_MAP(Dlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CB_ENABLED, &Dlg::OnClickedEnabled)
	ON_BN_CLICKED(IDC_CB_VISIBLE, &Dlg::OnClickedVisible)
	ON_BN_CLICKED(IDC_BTN_TEST, &Dlg::OnClickedBtnTest)
	ON_BN_CLICKED(IDC_BTN_CLEAR, &Dlg::OnClickedBtnClear)
END_MESSAGE_MAP()


// Обработчики сообщений Dlg

BOOL Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	SetIcon(m_hIcon, TRUE);
	return TRUE;
}

void Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this);
		SendMessage(WM_ICONERASEBKGND,
			reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

HCURSOR Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void Dlg::OnClickedEnabled()
{
	int state = (CbEnabled.GetCheck() == BST_CHECKED) ? SW_SHOW : SW_HIDE;
	EdCmd.EnableWindow(state);
}

void Dlg::OnClickedVisible()
{
	int state = (CbVisible.GetCheck() == BST_CHECKED) ? SW_SHOW : SW_HIDE;
	EdCmd.ShowWindow(state);
}

void Dlg::OnClickedBtnTest()
{
	CString str;
	EdCmd.GetWindowTextW(str);
	str.MakeLower();
	
	if (str.IsEmpty()) return;
	if (str.Compare(L"exit") == 0)
		OnOK();
	else if (str.Compare(L"paint") == 0)
		system("mspaint");
	else if (str.Compare(L"calculator") == 0)
		system("calc");
	else
	{
		USES_CONVERSION;
		char *p = new char[str.GetLength() + 1];
		strcpy(p, T2A(LPCTSTR(str)));
		system(p);
	}
}

void Dlg::OnClickedBtnClear() { EdCmd.SetWindowTextW(nullptr); }
