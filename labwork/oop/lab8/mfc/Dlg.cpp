#include "stdafx.h"
#include "OOP-lab8.h"
#include "Dlg.h"
#include "afxdialogex.h"
#include "About.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

Dlg::Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_OOPLAB8_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT, EtInput);
	DDX_Control(pDX, IDC_RES, TvRes);
}

BEGIN_MESSAGE_MAP(Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_ACT_ABOUT, &Dlg::OnActAbout)
	ON_COMMAND(ID_ACT_EXIT, &Dlg::OnActExit)
	ON_COMMAND(ID_ACT_GO, &Dlg::OnActGo)
END_MESSAGE_MAP()

BOOL Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	SetIcon(m_hIcon, TRUE);
	SetIcon(m_hIcon, FALSE);
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
		CDialogEx::OnPaint();
	}
}

HCURSOR Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void Dlg::OnActGo()
{
	CString str;
	EtInput.GetWindowTextW(str);
	int a = 0, o = 0, e = 0;
	
	str.MakeLower();
	for (int pos = 0; pos < str.GetLength(); pos++)
	{
		switch (str.GetAt(pos)) {
			case 'a':
			case 'а': a++; break;
			case 'o':
			case 'о': o++; break;
			case 'e':
			case 'е': e++; break;
		}
	}

	str.Format(L"Букв А: %d, Букв О: %d, Букв Е: %d\nСумма: %d",
		a, o, e, a + e + o);
	TvRes.SetWindowTextW(str);
}

void Dlg::OnActAbout()
{
	About about(this);
	about.DoModal();
}

void Dlg::OnActExit() { OnOK(); }