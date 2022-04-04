#include "stdafx.h"
#include "OOP-lab7.h"
#include "Dlg.h"
#include "afxdialogex.h"
#include "About.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

Dlg::Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_OOPLAB7_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST, List);
	DDX_Control(pDX, IDC_EDIT, Edit);
	DDX_Control(pDX, IDC_COMBO, Spinner);
}

BEGIN_MESSAGE_MAP(Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_EXIT, &Dlg::OnBnClickedBtnExit)
	ON_BN_CLICKED(IDC_BTN_ADD, &Dlg::OnBnClickedBtnAdd)
	ON_BN_CLICKED(IDC_BTN_DEL, &Dlg::OnBnClickedBtnDel)
	ON_BN_CLICKED(IDC_BTN_ABOUT, &Dlg::OnBnClickedBtnAbout)
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

void Dlg::OnBnClickedBtnAdd()
{
	CString str;
	Edit.GetWindowTextW(str);
	if (str.IsEmpty()) {
		MessageBox(L"Невозможно добавить пустую строку",
			L"Ошибка", MB_ICONERROR | MB_OK);
		return;
	}
	List.AddString(str);
	Spinner.AddString(str);
}

void Dlg::OnBnClickedBtnDel()
{
	int sel = List.GetCurSel();
	if (sel == LB_ERR) return;
	List.DeleteString(sel);
}

void Dlg::OnBnClickedBtnAbout()
{
	About about(this);
	about.DoModal();
}

void Dlg::OnBnClickedBtnExit() { OnOK(); }
