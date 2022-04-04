package ru.didim99.tstu.mathmodeling.core.integrator;

import ru.didim99.tstu.mathmodeling.core.util.Function;
import ru.didim99.tstu.mathmodeling.core.util.FunctionRN;
import ru.didim99.tstu.mathmodeling.core.util.PointD;
import ru.didim99.tstu.mathmodeling.core.util.Variable;
import java.util.ArrayList;

public class LayerIntegrator extends IntegratorRN {
  private static final int RES = 200;
  private static final int IP = 0;
  private static final int IS = 1;
  private static final int IV = 2;

  private final Direction pDir, sDir;
  private final FunctionRN mainMapper;

  public LayerIntegrator(Direction primary, Direction secondary,
                         FunctionRN mainMapper) {
    this.pDir = primary;
    this.sDir = secondary;
    this.mainMapper = mainMapper;
  }

  @Override
  public void integrate() {
    PointD point = new PointD(pDir.var.getMinValue(),
      sDir.var.getMinValue(), 0);

    ArrayList<PointD> startLayer = calcBound(
      point, IP, pDir, Direction.Bound.START);
    ArrayList<PointD> leftBound = calcBound(
      point, IS, sDir, Direction.Bound.START);
    point.set(IP, pDir.var.getMaxValue());
    ArrayList<PointD> rightBound = calcBound(
      point, IS, sDir, Direction.Bound.END);

    cacheLayer(startLayer);
    double factor = sDir.var.getStep()
      / Math.pow(pDir.var.getStep(), 2);
    ArrayList<PointD> prevLayer = startLayer;
    int layerSize = startLayer.size();

    int interval = 1;
    if (leftBound.size() > RES)
      interval = leftBound.size() / RES;

    for (int i = 1; i < leftBound.size(); i++) {
      ArrayList<PointD> layer = new ArrayList<>(layerSize);
      layer.add(leftBound.get(i));

      point.add(IS, sDir.var.getStep());
      point.set(IP, pDir.var.getMinValue());
      for (int j = 1; j < layerSize - 1; j++) {
        point.add(IP, pDir.var.getStep());
        double part = prevLayer.get(j - 1).get(IV) -
          2 * prevLayer.get(j).get(IV) + prevLayer.get(j + 1).get(IV);
        point.set(IV, mainMapper.f(point) * factor
          * part + prevLayer.get(j).get(IV));
        layer.add(new PointD(point));
      }

      layer.add(rightBound.get(i));
      if (i % interval == 0)
        cacheLayer(layer);
      prevLayer = layer;
    }
  }

  private void cacheLayer(ArrayList<PointD> layer) {
    for (PointD point : layer)
      listener.onIntegrationStep(point);
  }

  private ArrayList<PointD> calcBound(PointD point, int varIndex,
                                      Direction dir, Direction.Bound bound) {
    ArrayList<PointD> result = new ArrayList<>();
    Function fun = dir.getBound(bound);
    while (point.get(varIndex) <= dir.var.getMaxValue()) {
      point.set(IV, fun.f(point.get(varIndex)));
      result.add(new PointD(point));
      point.add(varIndex, dir.var.getStep());
    }

    point.set(varIndex, dir.var.getMinValue());
    return result;
  }

  public static class Direction {
    private enum Bound { START, END }

    private final Variable var;
    private final Function start;
    private final Function end;

    public Direction(Variable var, Function start, Function end) {
      this.var = var;
      this.start = start;
      this.end = end;
    }

    public Function getBound(Bound bound) {
      switch (bound) {
        case START: return start;
        case END: return end;
        default: return null;
      }
    }
  }
}
