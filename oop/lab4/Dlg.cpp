#include "stdafx.h"
#include "OOP-lab4.h"
#include "Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

Dlg::Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_OOPLAB4_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_ANGLE, EdAngle);
	DDX_Control(pDX, IDC_EDIT_A, EdA);
	DDX_Control(pDX, IDC_EDIT_B, EdB);
	DDX_Control(pDX, IDC_EDIT_C, EdC);
	DDX_Control(pDX, IDC_CB_FILE, CbFile);
	DDX_Control(pDX, IDC_TV_ANGLE, TvAngle);
	DDX_Control(pDX, IDC_TV_SQE, TvSQE);
	DDX_Control(pDX, IDC_TV_KB, TvKb);
	DDX_Control(pDX, IDC_BTN_ANGLE, BtnAngle);
	DDX_Control(pDX, IDC_BTN_SQE, BtnSqe);
	DDX_Control(pDX, IDC_BTN_EXIT, BtnExit);
	DDX_Control(pDX, IDC_RB_SQ, RbSq);
	DDX_Control(pDX, IDC_RB_BSQ, RbBSq);
	DDX_Control(pDX, IDC_EDIT_INT1, EdInt1);
	DDX_Control(pDX, IDC_EDIT_INT2, EdInt2);
	DDX_Control(pDX, IDC_BTN_AND, BtnAnd);
	DDX_Control(pDX, IDC_BTN_OR, BtnOr);
	DDX_Control(pDX, IDC_BTN_XOR, BtnXor);
	DDX_Control(pDX, IDC_TV_BITS, TvBits);
	DDX_Control(pDX, IDC_TV_BITSN, TvBitsR);
	DDX_Control(pDX, IDC_BTN_NOT, BtnNot);
}

BEGIN_MESSAGE_MAP(Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_KEYDOWN()
	ON_BN_CLICKED(IDC_BTN_EXIT, &Dlg::OnBnClickedBtnExit)
	ON_BN_CLICKED(IDC_BTN_ANGLE, &Dlg::OnBnClickedBtnAngle)
	ON_BN_CLICKED(IDC_BTN_SQE, &Dlg::OnBnClickedBtnSqe)
	ON_BN_CLICKED(IDC_BTN_AND, &Dlg::OnBnClickedBtnAnd)
	ON_BN_CLICKED(IDC_BTN_OR, &Dlg::OnBnClickedBtnOr)
	ON_BN_CLICKED(IDC_BTN_XOR, &Dlg::OnBnClickedBtnXor)
	ON_BN_CLICKED(IDC_BTN_NOT, &Dlg::OnBnClickedBtnNot)
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

void Dlg::Activate()
{
	TvKb.SetWindowTextW(L"ACCESS GRANTED");
	BtnAngle.EnableWindow(SW_SHOW);
	BtnSqe.EnableWindow(SW_SHOW);
	BtnNot.EnableWindow(SW_SHOW);
	BtnAnd.EnableWindow(SW_SHOW);
	BtnOr.EnableWindow(SW_SHOW);
	BtnXor.EnableWindow(SW_SHOW);
	BtnExit.EnableWindow(SW_SHOW);
	CbFile.EnableWindow(SW_SHOW);
	EdAngle.EnableWindow(SW_SHOW);
	EdInt1.EnableWindow(SW_SHOW);
	EdInt2.EnableWindow(SW_SHOW);
	EdA.EnableWindow(SW_SHOW);
	EdB.EnableWindow(SW_SHOW);
	EdC.EnableWindow(SW_SHOW);
	RbBSq.EnableWindow(SW_SHOW);
	RbSq.EnableWindow(SW_SHOW);
	RbSq.SetCheck(BST_CHECKED);
	BtnExit.SetFocus();
}

void Dlg::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	CString str = _T("");
	str.Format(L"nChar: %u\nnRepCnt: %u\nnFlags: %u", nChar, nRepCnt, nFlags);
	TvKb.SetWindowTextW(str);
	if (nChar == keypass[passed]) {
		if (passed++ == 3) Activate();
	} else passed = 0;
	CDialogEx::OnKeyDown(nChar, nRepCnt, nFlags);
}

void Dlg::OnBnClickedBtnAngle()
{
	CString str;
	EdAngle.GetWindowTextW(str);
	if (str.IsEmpty()) return;
	double d = _tstof(str);
	double r = deg2rad(d);
	str.Format(L"%.2f° -> %.4f радиан", d, r);
	TvAngle.SetWindowTextW(str);
}

void Dlg::OnBnClickedBtnSqe()
{
	bool toFile = CbFile.GetCheck() == BST_CHECKED;
	bool sq = RbSq.GetCheck();

	CString str;
	double a, b, c;
	double x1, x2;
	EdA.GetWindowTextW(str);
	if (str.IsEmpty()) return;
	else a = _tstof(str);
	EdB.GetWindowTextW(str);
	if (str.IsEmpty()) return;
	else b = _tstof(str);
	EdC.GetWindowTextW(str);
	if (str.IsEmpty()) return;
	else c = _tstof(str);

	double d = pow(b, 2) - 4 * a * c;
	if (!(d < 0)) d = sqrt(d);
	a *= 2;
	b = -b;

	if (d < 0)
		str = "Действительных корней нет";
	else
	{
		x1 = (b - d) / a;
		x2 = (b + d) / a;

		if (sq)
			str.Format(L"x1 = %.4f\nx2 = %.4f", x1, x2);
		else
		{
			if (x1 > 0) x1 = sqrt(x1);
			if (x2 > 0) x2 = sqrt(x2);

			if (x1 < 0 && x2 < 0)
				str = "Действительных корней нет";
			else if (!(x1 < 0 || x2 < 0))
				str.Format(L"x1 = %.4f\nx2 = %.4f\nx3 = %.4f\nx4 = %.4f",
					-x1, x1, -x2, x2);
			else if (!(x1 < 0))
				str.Format(L"x1 = %.4f\nx2 = %.4f", -x1, x1);
			else if (!(x2 < 0))
				str.Format(L"x1 = %.4f\nx2 = %.4f", -x2, x2);
		}

	}
	
	if (toFile)
	{
		FILE *fp = nullptr;
		fopen_s(&fp, "result.txt", "w");
		if (!fp) return;
		CT2CA outStr(str, CP_UTF8);
		fwrite(outStr, strlen(outStr), 1, fp);
		fclose(fp);
		str = L"Записано в result.txt";
	}
	TvSQE.SetWindowTextW(str);
}

void Dlg::processBitwise(Bitwise action)
{
	int a, b, r;
	CString str, act;
	EdInt1.GetWindowTextW(str);
	if (str.IsEmpty()) return;
	else a = _tstoi(str);
	if (action != Dlg::NOT)
	{
		EdInt2.GetWindowTextW(str);
		if (str.IsEmpty()) return;
		else b = _tstoi(str);
	}

	switch (action)
	{
	case NOT: r = ~a; act = L"~A:"; break;
	case AND: r = a & b; act = L"A && B:"; break;
	case OR: r = a | b; act = L"A | B:"; break;
	case XOR: r = a ^ b; act = L"A ^ B:"; break;
	}

	if (action == Dlg::NOT) str.Format(L"0x%08X\n\n0x%08X", a, r);
	else str.Format(L"0x%08X\n0x%08X\n0x%08X", a, b, r);
	TvBitsR.SetWindowTextW(act);
	TvBits.SetWindowTextW(str);
}

void Dlg::OnBnClickedBtnNot() { processBitwise(Dlg::NOT); }
void Dlg::OnBnClickedBtnAnd() { processBitwise(Dlg::AND); }
void Dlg::OnBnClickedBtnOr() { processBitwise(Dlg::OR); }
void Dlg::OnBnClickedBtnXor() { processBitwise(Dlg::XOR); }
void Dlg::OnBnClickedBtnExit() { OnOK(); }

double Dlg::deg2rad(double deg) {
	return deg * M_PI / 180.0;
}
