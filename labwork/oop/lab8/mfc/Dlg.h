#pragma once

class Dlg : public CDialogEx
{
public:
	Dlg(CWnd* pParent = nullptr);
	afx_msg void OnActAbout();
	afx_msg void OnActExit();
	afx_msg void OnActGo();

#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_OOPLAB8_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);
	HICON m_hIcon;
	CEdit EtInput;
	CStatic TvRes;

	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
};
