package ru.didim99.tstu.mathmodeling.ui;

import org.jzy3d.analysis.AbstractAnalysis;
import org.jzy3d.analysis.AnalysisLauncher;
import org.jzy3d.chart.factories.AWTChartComponentFactory;
import org.jzy3d.colors.Color;
import org.jzy3d.colors.ColorMapper;
import org.jzy3d.colors.colormaps.ColorMapRainbow;
import org.jzy3d.maths.Coord3d;
import org.jzy3d.maths.Rectangle;
import org.jzy3d.plot3d.builder.Builder;
import org.jzy3d.plot3d.primitives.Shape;
import org.jzy3d.plot3d.primitives.axes.layout.renderers.DefaultDecimalTickRenderer;
import org.jzy3d.plot3d.rendering.canvas.Quality;
import ru.didim99.tstu.mathmodeling.core.DDProcessor;
import ru.didim99.tstu.mathmodeling.core.Functions;
import ru.didim99.tstu.mathmodeling.core.util.PointD;
import java.util.ArrayList;
import java.util.List;

public class GraphUI extends AbstractAnalysis {

  // UI settings
  private static final Rectangle WINDOW_BOUNDS =
    new Rectangle(500, 100, 800, 800);
  private static final Color CLR_BG = new Color(16, 16, 16);
  private static final Color CLR_GRID = new Color(240, 240, 240);
  private static final Color CLR_EDGE = new Color(255, 255, 255, 32);
  private static final Color CLR_BASE = new Color(1, 1, 1, .65f);
  private static final float WIDTH_WIRE = 0.5f;
  private static final int TICK_PRECISION = 2;

  @Override
  public String getName() {
    return Functions.LABEL_DDP;
  }

  @Override
  public void init() {
    DDProcessor processor = new DDProcessor();
    processor.process();
    ArrayList<PointD> points = processor.getResult();
    List<Coord3d> data = Coord3d.list(points.size());
    for (PointD point : points)
      data.add(new Coord3d(point.get(0), point.get(1), point.get(2)));

    // Create the object to represent the surface
    final Shape surface = Builder.buildDelaunay(data);
    surface.setColorMapper(new ColorMapper(new ColorMapRainbow(),
      surface.getBounds().getZmin(), surface.getBounds().getZmax(), CLR_BASE));
    surface.setWireframeDisplayed(true);
    surface.setWireframeColor(CLR_EDGE);
    surface.setWireframeWidth(WIDTH_WIRE);
    surface.setFaceDisplayed(true);

    // Create a chart
    chart = AWTChartComponentFactory.chart(Quality.Advanced, getCanvasType());
    chart.getAxeLayout().setXTickRenderer(new DefaultDecimalTickRenderer(TICK_PRECISION));
    chart.getAxeLayout().setYTickRenderer(new DefaultDecimalTickRenderer(TICK_PRECISION));
    chart.getAxeLayout().setZTickRenderer(new DefaultDecimalTickRenderer(TICK_PRECISION));
    chart.getAxeLayout().setFaceDisplayed(false);
    chart.getAxeLayout().setMainColor(CLR_GRID);
    chart.getView().setBackgroundColor(CLR_BG);
    chart.getScene().getGraph().add(surface);

    chart.getAxeLayout().setXAxeLabel(Functions.LABEL_TAU);
    chart.getAxeLayout().setYAxeLabel(Functions.LABEL_L);
    chart.getAxeLayout().setZAxeLabel(Functions.LABEL_T);
  }

  public static void main(String[] args) throws Exception {
    AnalysisLauncher.open(new GraphUI(), WINDOW_BOUNDS);
  }
}