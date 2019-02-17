#include "Processor.h"
#pragma once

// Диалоговое окно Dlg
class Dlg : public CDialogEx
{
public:
	Dlg(CWnd* pParent = nullptr);

#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_OOPLAB1_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);
	HICON m_hIcon;

	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	
	CEdit editSrc;
public:
	afx_msg void OnBnClickedBtnAdd();
	afx_msg void OnBnClickedBtnSub();
	afx_msg void OnBnClickedBtnMult();
	afx_msg void OnBnClickedBtnDiv();
	void OnEvent(Processor::action action);
};
