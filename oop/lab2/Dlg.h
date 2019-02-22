
#pragma once

class Dlg : public CDialog
{
public:
	Dlg(CWnd* pParent = nullptr);
	afx_msg void OnClickedEnabled();
	afx_msg void OnClickedVisible();
	afx_msg void OnClickedBtnTest();
	afx_msg void OnClickedBtnClear();

#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_OOPLAB2_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);
	HICON m_hIcon;
	CButton CbEnabled;
	CButton CbVisible;
	CEdit EdCmd;

	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
};
