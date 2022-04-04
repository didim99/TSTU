package ru.didim99.tstu.mathmodeling.core;

import ru.didim99.tstu.mathmodeling.core.util.FunctionRN;
import ru.didim99.tstu.mathmodeling.core.util.PointD;
import ru.didim99.tstu.mathmodeling.core.util.PointRN;
import java.util.ArrayList;

/**
 * Distributed system dynamic mode processor
 *
 * Created by didim99 on 02.05.20.
 */
public class DDProcessor {
  private ArrayList<PointD> result;
  private FunctionRN[] mapper;

  public void process() {
    this.result = new ArrayList<>();
    this.mapper = Functions.mapper;
    IntegratorRN integrator = new IntegratorRN(
      Functions.sequence, Functions.dT, this::cachePoint);
    integrator.integrate();
  }

  public ArrayList<PointD> getResult() {
    return result;
  }

  private void cachePoint(PointRN point) {
    PointD cached = new PointD(mapper.length);
    for (int i = 0; i < mapper.length; i++)
      cached.set(i, mapper[i].f(point));
    result.add(cached);
  }
}
