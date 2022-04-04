#pragma once

class Dlg : public CDialogEx
{
public:
	Dlg(CWnd* pParent = nullptr);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnBnClickedBtnExit();
	afx_msg void OnBnClickedBtnAngle();
	afx_msg void OnBnClickedBtnSqe();
	afx_msg void OnBnClickedBtnNot();
	afx_msg void OnBnClickedBtnAnd();
	afx_msg void OnBnClickedBtnOr();
	afx_msg void OnBnClickedBtnXor();
	static double deg2rad(double deg);

#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_OOPLAB4_DIALOG };
#endif

protected:
	enum Bitwise { NOT, AND, OR, XOR };
	virtual void DoDataExchange(CDataExchange* pDX);
	HICON m_hIcon;

	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	void processBitwise(Bitwise action);
	void Activate();
private:
	const UINT keypass[4] = { 16, 16, 17, 16 };
	int passed = 0;

	CButton RbSq;
	CButton RbBSq;
	CButton BtnAngle;
	CButton BtnSqe;
	CButton BtnNot;
	CButton BtnAnd;
	CButton BtnOr;
	CButton BtnXor;
	CButton BtnExit;
	CButton CbFile;
	CStatic TvAngle;
	CStatic TvSQE;
	CStatic TvKb;
	CStatic TvBits;
	CStatic TvBitsR;
	CEdit EdInt1;
	CEdit EdInt2;
	CEdit EdAngle;
	CEdit EdA;
	CEdit EdB;
	CEdit EdC;
};
