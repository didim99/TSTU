
// OOP-lab1.cpp: определяет поведение классов для приложения.

#include "stdafx.h"
#include "OOP-lab1.h"
#include "Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// App
BEGIN_MESSAGE_MAP(App, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// Создание App
App::App()
{
	// TODO: добавьте код создания,
	// Размещает весь важный код инициализации в InitInstance
}


// Единственный объект App
App theApp;

// Инициализация App
BOOL App::InitInstance()
{
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);
	CWinApp::InitInstance();
	CShellManager *pShellManager = new CShellManager;
	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));
	SetRegistryKey(_T("Локальные приложения, созданные с помощью мастера приложений"));

	Dlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK) {}
	else if (nResponse == IDCANCEL) {}
	else if (nResponse == -1) {}

	if (pShellManager != nullptr)
		delete pShellManager;

#if !defined(_AFXDLL) && !defined(_AFX_NO_MFC_CONTROLS_IN_DIALOGS)
	ControlBarCleanUp();
#endif

	return FALSE;
}
