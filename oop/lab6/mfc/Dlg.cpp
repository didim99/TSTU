#include "stdafx.h"
#include "OOP-lab6.h"
#include "afxdialogex.h"
#include "Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

Dlg::Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_OOPLAB6_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_GRAPH, VGraph);
	DDX_Control(pDX, IDC_ETXFROM, EtXFrom);
	DDX_Control(pDX, IDC_ETYFROM, EtYFrom);
	DDX_Control(pDX, IDC_ETXTO, EtXTo);
	DDX_Control(pDX, IDC_ETYTO, EtYTo);
	DDX_Control(pDX, IDC_ETGRID, EtGrid);

	CString str;
	str.Format(L"%.1f", DEF_XMIN);
	EtXFrom.SetWindowTextW(str);
	str.Format(L"%.1f", DEF_XMAX);
	EtXTo.SetWindowTextW(str);
	str.Format(L"%.1f", DEF_YMIN);
	EtYFrom.SetWindowTextW(str);
	str.Format(L"%.1f", DEF_YMAX);
	EtYTo.SetWindowTextW(str);
	str.Format(L"%.1f", DEF_GRID);
	EtGrid.SetWindowTextW(str);
	plotter = new Plotter(&VGraph);
}

BEGIN_MESSAGE_MAP(Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_CLR, &Dlg::OnClickedBtnClr)
	ON_BN_CLICKED(IDC_BTN_PLOT, &Dlg::OnClickedBtnPlot)
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

double f1(double x) { return sin(x) * 2; }
double f2(double x) { return cos(x) * 2; }
double f3(double x) { return x * x; }

void Dlg::updateValues()
{
	CString str;
	double xFrom, xTo, yFrom, yTo, grid;
	EtXFrom.GetWindowTextW(str);
	if (str.IsEmpty()) return;
	xFrom = _tstof(str);
	EtXTo.GetWindowTextW(str);
	if (str.IsEmpty()) return;
	xTo = _tstof(str);
	EtYFrom.GetWindowTextW(str);
	if (str.IsEmpty()) return;
	yFrom = _tstof(str);
	EtYTo.GetWindowTextW(str);
	if (str.IsEmpty()) return;
	yTo = _tstof(str);
	EtGrid.GetWindowTextW(str);
	if (str.IsEmpty()) return;
	grid = _tstof(str);

	if (xTo - xFrom < MIN_DX) return;
	if (yTo - yFrom < MIN_DY) return;
	if (grid < MIN_GRID) return;

	plotter->setViewRange(xFrom, xTo, yFrom, yTo);
	plotter->setGridScale(grid);
}

void Dlg::OnClickedBtnClr()
{
	updateValues();
	plotter->clearPlot();
}

void Dlg::OnClickedBtnPlot()
{
	updateValues();
	plotter->setPlotColor(COLOR_FUNC1);
	plotter->drawFunction(f1);
	plotter->setPlotColor(COLOR_FUNC2);
	plotter->drawFunction(f2);
	plotter->setPlotColor(COLOR_FUNC3);
	plotter->drawFunction(f3);
}