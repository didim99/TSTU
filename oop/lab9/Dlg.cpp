#include "stdafx.h"
#include "OOP-lab9.h"
#include "Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

Dlg::Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_OOPLAB9_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST, LbRes);
}

BEGIN_MESSAGE_MAP(Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_OC, &Dlg::OnBnClickedBtnOc)
	ON_BN_CLICKED(IDC_BTN_YNC, &Dlg::OnBnClickedBtnYnc)
	ON_BN_CLICKED(IDC_BTN_RC, &Dlg::OnBnClickedBtnRc)
	ON_BN_CLICKED(IDC_BTN_YN, &Dlg::OnBnClickedBtnYn)
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
		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);
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

void Dlg::OnBnClickedBtnOc() { doDialog(MB_OKCANCEL); }
void Dlg::OnBnClickedBtnYnc() { doDialog(MB_YESNOCANCEL); }
void Dlg::OnBnClickedBtnRc() { doDialog(MB_RETRYCANCEL); }
void Dlg::OnBnClickedBtnYn() { doDialog(MB_YESNO); }

void Dlg::doDialog(ULONG flags)
{
	int result = MessageBox(L"Выберите действие",
		L"Тест диалогового окна", flags | MB_ICONINFORMATION);
	CString str;
	switch (result)
	{
		case IDOK:		str = L"Ok"; break;
		case IDCANCEL:	str = L"Cancel"; break;
		case IDRETRY:	str = L"Retry"; break;
		case IDYES:		str = L"Yes"; break;
		case IDNO:		str = L"No"; break;
	}

	str.Format(L"Нажата кнопка: %s", str);
	LbRes.AddString(str);
}
