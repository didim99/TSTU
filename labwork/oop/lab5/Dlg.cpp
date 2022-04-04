#include "stdafx.h"
#include "OOP-lab5.h"
#include "Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

Dlg::Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_OOPLAB5_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_ET_X0, EtX0);
	DDX_Control(pDX, IDC_ET_XK, EtXk);
	DDX_Control(pDX, IDC_ET_DX, EtDx);
	DDX_Control(pDX, IDC_ET_A, EtA);
	DDX_Control(pDX, IDC_ET_B, EtB);
	DDX_Control(pDX, IDC_LIST, LbRes);
	CString str;
	str.Format(L"%.2f", DEFAULT_X0);
	EtX0.SetWindowTextW(str);
	str.Format(L"%.2f", DEFAULT_XK);
	EtXk.SetWindowTextW(str);
	str.Format(L"%.2f", DEFAULT_DX);
	EtDx.SetWindowTextW(str);
	str.Format(L"%.2f", DEFAULT_A);
	EtA.SetWindowTextW(str);
	str.Format(L"%.2f", DEFAULT_B);
	EtB.SetWindowTextW(str);
}

BEGIN_MESSAGE_MAP(Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_CALC, &Dlg::OnBnClickedBtnCalc)
	ON_BN_CLICKED(IDC_BTN_CLEAR, &Dlg::OnBnClickedBtnClear)
	ON_BN_CLICKED(IDC_BTN_EXIT, &Dlg::OnBnClickedBtnExit)
END_MESSAGE_MAP()


// Обработчики сообщений Dlg

BOOL Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	SetIcon(m_hIcon, TRUE);
	SetIcon(m_hIcon, FALSE);

	// TODO: добавьте дополнительную инициализацию

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

void Dlg::OnBnClickedBtnCalc()
{
	CString str;
	EtX0.GetWindowTextW(str);
	if (str.IsEmpty()) return;
	x0 = _tstof(str);
	EtXk.GetWindowTextW(str);
	if (str.IsEmpty()) return;
	xk = _tstof(str);
	EtDx.GetWindowTextW(str);
	if (str.IsEmpty()) return;
	dx = _tstof(str);
	EtA.GetWindowTextW(str);
	if (str.IsEmpty()) return;
	a = _tstof(str);
	EtB.GetWindowTextW(str);
	if (str.IsEmpty()) return;
	b = _tstof(str);
	calculate();
}

void Dlg::calculate()
{
	CString str;
	double x = x0;
	int steps = (int) abs(abs(xk - x0) / dx);
	for (int i = 0; i < steps; i++, x+=dx)
	{
		double y = f(x);
		str.Format(L"X: %.2f -> Y: %.6f", x, y);
		LbRes.AddString(str);
	}
}

void Dlg::OnBnClickedBtnClear()
{
	int count = LbRes.GetCount() - 1;
	for (int i = count; i >= 0; i--)
		LbRes.DeleteString(i);
}

void Dlg::OnBnClickedBtnExit() { OnOK(); }
double Dlg::f(double x) { return 1.2 * pow(a - b, 3) * exp(pow(x, 2)) + x; }