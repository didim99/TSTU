#include "stdafx.h"
#include "Plotter.h"

Plotter::Plotter(CWnd *view)
{
	func = new CPen(PS_SOLID, 2, COLOR_FUNC1);
	grid = new CPen(PS_SOLID, 1, COLOR_GRID);
	bg = new CBrush(PS_SOLID, COLOR_BG);
	dc = new CClientDC(view);

	CFont font;
	LOGFONT lf;
	memset(&lf, 0, sizeof(lf));
	lf.lfHeight = 14;
	font.CreateFontIndirectW(&lf);
	dc->SelectObject(font);
	
	CRect rect;
	view->GetClientRect(&rect);
	vw = rect.Width();
	vh = rect.Height();

	setViewRange(DEF_XMIN, DEF_XMAX, DEF_YMIN, DEF_YMAX);
	setGridScale(DEF_GRID);
}

Plotter::~Plotter()
{
	delete func, bg, dc;
}

void Plotter::setViewRange(double xMin, double xMax, double yMin, double yMax)
{
	this->xMin = xMin;
	this->xMax = xMax;
	this->yMin = yMin;
	this->yMax = yMax;
	xFactor = (double) vw / (xMax - xMin);
	yFactor = (double) vh / (yMax - yMin);
}

void Plotter::setGridScale(double scale)
{
	gridScale = scale;
}

void Plotter::setPlotColor(COLORREF color)
{
	plotColor = color;
}

void Plotter::clearPlot()
{
	CRect rect(0, 0, vw, vh);
	dc->FillRect(rect, bg);
	drawGrid();
}

void Plotter::drawGrid()
{
	dc->SelectObject(grid);
	dc->MoveTo(x(xMin), y(0));
	dc->LineTo(x(xMax), y(0));
	dc->MoveTo(x(0), y(yMin));
	dc->LineTo(x(0), y(yMax));

	CString str;
	dc->SetTextAlign(TA_CENTER);
	int dots = (int) ((xMax - xMin) / gridScale);
	for (int i = 0; i < dots; i++) {
		double tx = xMin + gridScale * i;
		dc->MoveTo(x(tx), y(0) - GRID_DOT_SZ);
		dc->LineTo(x(tx), y(0) + GRID_DOT_SZ);
		if (i > 0 && (int) tx != 0) {
			str.Format(L"%.1lf", tx);
			dc->TextOutW(x(tx), y(0) + 5, str);
		}
	}

	dc->SetTextAlign(TA_RIGHT);
	dots = (int) ((yMax - yMin) / gridScale);
	for (int i = 0; i < dots; i++) {
		double ty = yMin + gridScale * i;
		dc->MoveTo(x(0) - GRID_DOT_SZ, y(ty));
		dc->LineTo(x(0) + GRID_DOT_SZ, y(ty));
		if (i > 0 && (int) ty != 0) {
			str.Format(L"%.1lf", ty);
			dc->TextOutW(x(0) - 5, y(ty), str);
		}
	}
}

void Plotter::drawFunction(void *pf, double xFrom, double xTo)
{
	func = new CPen(PS_SOLID, 2, plotColor);
	double (*f)(double) = (double(*)(double)) pf;
	double xStep = (xTo - xFrom) / PLOT_STEPS;
	double tx = xFrom;

	dc->SelectObject(func);
	dc->MoveTo(x(tx), y(f(tx)));
	for (int i = 0; i < PLOT_STEPS; i++, tx += xStep) {
		for (volatile int i = 0; i < SLEEP; i++);
		dc->LineTo(x(tx), y(f(tx)));
	}
	dc->LineTo(x(xTo), y(f(xTo)));
}

void Plotter::drawFunction(void *f) { drawFunction(f, xMin, xMax); }
int Plotter::x(double x) { return (int) ((x - xMin) * xFactor); }
int Plotter::y(double y) { return vh - (int) ((y - yMin) * yFactor); }
