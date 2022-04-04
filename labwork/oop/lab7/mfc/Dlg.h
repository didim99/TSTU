#pragma once

// Диалоговое окно Dlg
class Dlg : public CDialogEx
{
public:
	Dlg(CWnd* pParent = nullptr);
	afx_msg void OnBnClickedBtnExit();
	afx_msg void OnBnClickedBtnAdd();
	afx_msg void OnBnClickedBtnDel();
	afx_msg void OnBnClickedBtnAbout();

#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_OOPLAB7_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV
	HICON m_hIcon;
	CComboBox Spinner;
	CListBox List;
	CEdit Edit;

	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
};
