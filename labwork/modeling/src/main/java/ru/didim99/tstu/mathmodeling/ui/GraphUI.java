package ru.didim99.tstu.mathmodeling.ui;

import org.jzy3d.analysis.AbstractAnalysis;
import org.jzy3d.chart.factories.AWTChartComponentFactory;
import org.jzy3d.colors.Color;
import org.jzy3d.colors.ColorMapper;
import org.jzy3d.colors.colormaps.ColorMapRainbow;
import org.jzy3d.maths.Coord3d;
import org.jzy3d.plot3d.builder.Builder;
import org.jzy3d.plot3d.primitives.AbstractDrawable;
import org.jzy3d.plot3d.primitives.Scatter;
import org.jzy3d.plot3d.primitives.Shape;
import org.jzy3d.plot3d.primitives.axes.layout.renderers.FixedDecimalTickRenderer;
import org.jzy3d.plot3d.rendering.canvas.Quality;
import ru.didim99.tstu.mathmodeling.core.Processor;
import ru.didim99.tstu.mathmodeling.core.util.PointD;
import java.util.ArrayList;
import java.util.List;

public class GraphUI extends AbstractAnalysis {
  // UI settings
  private static final Color CLR_BG = new Color(16, 16, 16);
  private static final Color CLR_GRID = new Color(240, 240, 240);
  private static final Color CLR_EDGE = new Color(255, 255, 255, 32);
  private static final Color CLR_BASE = new Color(1, 1, 1, .65f);
  private static final float WIDTH_WIRE = 0.5f;
  private static final int TICK_PRECISION = 1;

  private final boolean viewSurface;
  private final boolean viewWireFrame;
  private final Processor processor;

  public GraphUI(boolean surface, boolean wireFrame, Processor processor) {
    this.viewSurface = surface;
    this.viewWireFrame = wireFrame;
    this.processor = processor;
  }

  @Override
  public String getName() {
    return R.GRAPH_TITLE;
  }

  @Override
  public void init() {
    processor.process();
    ArrayList<PointD> points = processor.getResult();
    List<Coord3d> data = Coord3d.list(points.size());
    for (PointD point : points)
      data.add(new Coord3d(point.get(0), point.get(1), point.get(2)));

    AbstractDrawable drawable;
    // Create the object to represent the surface
    if (viewSurface) {
      final Shape surface = Builder.buildDelaunay(data);
      surface.setColorMapper(new ColorMapper(new ColorMapRainbow(),
        surface.getBounds().getZmin(), surface.getBounds().getZmax(), CLR_BASE));
      surface.setWireframeDisplayed(viewWireFrame);
      surface.setWireframeWidth(WIDTH_WIRE);
      surface.setWireframeColor(CLR_EDGE);
      surface.setFaceDisplayed(true);
      drawable = surface;
    } else {
      Scatter scatter = new Scatter(data.toArray(new Coord3d[0]));
      scatter.setColor(Color.WHITE);
      scatter.setWidth(1.5f);
      drawable = scatter;
    }

    // Create a chart
    chart = AWTChartComponentFactory.chart(Quality.Advanced, getCanvasType());
    chart.getAxeLayout().setXTickRenderer(new FixedDecimalTickRenderer(TICK_PRECISION));
    chart.getAxeLayout().setYTickRenderer(new FixedDecimalTickRenderer(TICK_PRECISION));
    chart.getAxeLayout().setZTickRenderer(new FixedDecimalTickRenderer(TICK_PRECISION));
    chart.getAxeLayout().setFaceDisplayed(false);
    chart.getAxeLayout().setMainColor(CLR_GRID);
    chart.getView().setBackgroundColor(CLR_BG);
    chart.getScene().getGraph().add(drawable);

    chart.getAxeLayout().setXAxeLabel(R.LABEL_TAU);
    chart.getAxeLayout().setYAxeLabel(R.LABEL_L);
    chart.getAxeLayout().setZAxeLabel(R.LABEL_T);
  }
}