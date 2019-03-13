#pragma once

#define DEFAULT_X0 -0.75
#define DEFAULT_XK -1.5
#define DEFAULT_DX -0.05
#define DEFAULT_A 1.5
#define DEFAULT_B 1.2

class Dlg : public CDialogEx
{
public:
	Dlg(CWnd* pParent = nullptr);
	afx_msg void OnBnClickedBtnCalc();
	afx_msg void OnBnClickedBtnClear();
	afx_msg void OnBnClickedBtnExit();

#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_OOPLAB5_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);
	HICON m_hIcon;

	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	double f(double x);
	void calculate();
private:
	CListBox LbRes;
	CEdit EtX0;
	CEdit EtXk;
	CEdit EtDx;
	CEdit EtA;
	CEdit EtB;

	double x0, xk, dx;
	double a, b;
};
