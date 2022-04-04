
// OOP-lab1.h: главный файл заголовка для приложения PROJECT_NAME
#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"
class App : public CWinApp
{
public:
	App();
	virtual BOOL InitInstance();
	DECLARE_MESSAGE_MAP()
};

extern App theApp;
