#pragma once

#define MIN_DX		1.0
#define MIN_DY		1.0
#define MIN_GRID	0.1
#define DEF_XMIN	-10.0
#define DEF_XMIN	-10.0
#define DEF_XMAX	10.0
#define DEF_YMIN	-10.0
#define DEF_YMAX	10.0
#define DEF_GRID	2.0
#define COLOR_GRID	0x00202020
#define COLOR_BG	0x00eeeeee
#define COLOR_GRID	0x00202020
#define COLOR_FUNC1	0x00950000
#define COLOR_FUNC2	0x00009500
#define COLOR_FUNC3	0x00000095
#define SLEEP		1500000
#define PLOT_STEPS	1000
#define GRID_DOT_SZ	3

class Plotter
{
public:
	Plotter(CWnd *view);
	~Plotter();

	void clearPlot();
	void drawFunction(void *f);
	void drawFunction(void *f, double xFrom, double xTo);
	void setViewRange(double xMin, double xMax, double yMin, double yMax);
	void setGridScale(double scale);
	void setPlotColor(COLORREF color);
private:
	CClientDC *dc;
	COLORREF plotColor;
	CPen *func, *grid;
	CBrush *bg;

	int vw, vh;
	double xMin, xMax, yMin, yMax;
	double xFactor, yFactor;
	double gridScale;

	void drawGrid();
	int x(double x);
	int y(double y);
};

