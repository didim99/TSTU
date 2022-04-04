#pragma once

class Dlg : public CDialogEx
{
public:
	Dlg(CWnd* pParent = nullptr);

#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_OOPLAB9_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);
	HICON m_hIcon;
	CListBox LbRes;

	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	afx_msg void OnBnClickedBtnOc();
	afx_msg void OnBnClickedBtnYnc();
	afx_msg void OnBnClickedBtnRc();
	afx_msg void OnBnClickedBtnYn();
	void doDialog(ULONG flags);
};
