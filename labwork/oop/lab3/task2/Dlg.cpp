
#include "stdafx.h"
#include "OOP-lab3.h"
#include "Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

Dlg::Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_OOPLAB3_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SBWIDTH, sbWidth);
}

BEGIN_MESSAGE_MAP(Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_EXIT, &Dlg::OnBnClickedBtnExit)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_HSCROLL()
END_MESSAGE_MAP()

BOOL Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	SetIcon(m_hIcon, TRUE);
	sbWidth.SetRange(1, 20, TRUE);
	sbWidth.SetPos(10);
	prevPos = new CPoint();
	pen = new CPen(PS_SOLID, 10, 0x000000ff);
	dc = new CClientDC(this);
	dc->SelectObject(pen);
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

HCURSOR Dlg::OnQueryDragIcon() { return static_cast<HCURSOR>(m_hIcon); }
void Dlg::OnBnClickedBtnExit() { OnCancel(); }


void Dlg::OnMouseMove(UINT nFlags, CPoint point)
{
	CDialogEx::OnMouseMove(nFlags, point);
	if ((nFlags & MK_LBUTTON) > 0)
	{
		dc->MoveTo(prevPos->x, prevPos->y);
		dc->LineTo(point.x, point.y);
		dc->MoveTo(point.x, point.y);
		prevPos->SetPoint(point.x, point.y);
	}
}

void Dlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	CDialogEx::OnMButtonDown(nFlags, point);
	prevPos->SetPoint(point.x, point.y);
}


void Dlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
	if (pScrollBar == (CScrollBar*)&sbWidth)
	{
		pen = new CPen(PS_SOLID, sbWidth.GetPos(), 0x000000ff);
		dc->SelectObject(pen);
	}
}
