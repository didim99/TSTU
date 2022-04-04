
#pragma once

class Dlg : public CDialogEx
{
public:
	Dlg(CWnd* pParent = nullptr);
	afx_msg void OnBnClickedBtnExit();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);

#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_OOPLAB3_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);
	HICON m_hIcon;
	CSliderCtrl sbWidth;
	CPoint *prevPos;
	CClientDC *dc;
	CPen *pen;

	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
};
