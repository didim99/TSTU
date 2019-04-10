#pragma once

class About : public CDialogEx
{
	DECLARE_DYNAMIC(About)
public:
	About(CWnd* pParent = nullptr);
	
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);
	DECLARE_MESSAGE_MAP()
	CEdit Edit;
};
