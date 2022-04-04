#include "stdafx.h"
#include "OOP-lab8.h"
#include "About.h"
#include "afxdialogex.h"

IMPLEMENT_DYNAMIC(About, CDialogEx)

About::About(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ABOUT, pParent) {}

void About::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT, Edit);
	CTime time = CTime::GetCurrentTime();
	CString s = time.Format("%d.%m.%#Y, %A");
	Edit.SetWindowTextW(s);
}

BEGIN_MESSAGE_MAP(About, CDialogEx)
END_MESSAGE_MAP()
