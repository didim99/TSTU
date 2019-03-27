#include "Plotter.h"
#pragma once

class Dlg : public CDialogEx
{
public:
	Dlg(CWnd* pParent = nullptr);
	afx_msg void OnClickedBtnClr();
	afx_msg void OnClickedBtnPlot();

#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_OOPLAB6_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	void updateValues();

	HICON m_hIcon;
	CStatic VGraph;
	Plotter *plotter;
	CEdit EtXFrom;
	CEdit EtYFrom;
	CEdit EtXTo;
	CEdit EtYTo;
	CEdit EtGrid;
};
