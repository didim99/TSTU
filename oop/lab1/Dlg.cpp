
// Dlg.cpp: файл реализации
//

#include "stdafx.h"
#include "OOP-lab1.h"
#include "Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// Диалоговое окно Dlg
Dlg::Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_OOPLAB1_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	
}

void Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_INPUT, editSrc);
}

BEGIN_MESSAGE_MAP(Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_ADD, &Dlg::OnBnClickedBtnAdd)
	ON_BN_CLICKED(IDC_BTN_SUB, &Dlg::OnBnClickedBtnSub)
	ON_BN_CLICKED(IDC_BTN_MULT, &Dlg::OnBnClickedBtnMult)
	ON_BN_CLICKED(IDC_BTN_DIV, &Dlg::OnBnClickedBtnDiv)
END_MESSAGE_MAP()


// Обработчики сообщений Dlg
BOOL Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	SetIcon(m_hIcon, TRUE);
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

void Dlg::OnEvent(Processor::action action)
{
	int pos = 0;
	CString str = _T(""), str2;
	editSrc.GetWindowTextW(str);
	if (str.IsEmpty())
	{
		MessageBox(L"Input values not defined", L"Error", MB_ICONERROR);
		return;
	}

	int count = 0;
	bool fp = str.Find(L".", 0) >= 0;
	if (fp)
	{
		double d;
		CArray<double>* doubleArr = new CArray<double>();
		while (pos < str.GetLength())
		{
			str2 = str.Tokenize(_T(" "), pos);
			d = _tstof(str2);
			if (action == Processor::DIV && count > 0 && d == 0.0)
			{
				MessageBox(L"Division by zero", L"Error", MB_ICONWARNING);
				return;
			}
			doubleArr->Add(d);
			count++;
		}

		if (doubleArr->GetSize() < 2)
		{
			MessageBox(L"Too few arguments", L"Warning", MB_ICONWARNING);
			return;
		}

		Processor p;
		p.setAction(action);
		p.setData(doubleArr);
		p.process();
		MessageBox(p.getResult(), L"Result", MB_ICONINFORMATION);
	}
	else
	{
		int i;
		CArray<int>* intArr = new CArray<int>();
		while (pos < str.GetLength())
		{
			str2 = str.Tokenize(_T(" "), pos);
			i = _ttoi(str2);
			if (action == Processor::DIV && count > 0 && i == 0)
			{
				MessageBox(L"Division by zero", L"Error", MB_ICONWARNING);
				return;
			}
			intArr->Add(i);
			count++;
		}

		if (intArr->GetSize() < 2)
		{
			MessageBox(L"Too few arguments", L"Warning", MB_ICONWARNING);
			return;
		}

		Processor* p2 = new Processor();
		p2->setAction(action);
		p2->setData(intArr);
		p2->process();
		MessageBox(p2->getResult(), L"Result", MB_ICONINFORMATION);
	}
}

void Dlg::OnBnClickedBtnAdd() { OnEvent(Processor::ADD); }
void Dlg::OnBnClickedBtnSub() { OnEvent(Processor::SUB); }
void Dlg::OnBnClickedBtnMult() { OnEvent(Processor::MULT); }
void Dlg::OnBnClickedBtnDiv() { OnEvent(Processor::DIV); }
