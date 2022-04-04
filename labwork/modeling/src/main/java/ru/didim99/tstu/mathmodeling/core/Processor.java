package ru.didim99.tstu.mathmodeling.core;

import java.util.ArrayList;
import ru.didim99.tstu.mathmodeling.core.integrator.IntegratorRN;
import ru.didim99.tstu.mathmodeling.core.util.FunctionRN;
import ru.didim99.tstu.mathmodeling.core.util.PointD;
import ru.didim99.tstu.mathmodeling.core.util.PointRN;

public class Processor {
  private static final FunctionRN[] defaultMapper =
    { vars -> vars.get(0), vars -> vars.get(1), vars -> vars.get(2) };

  private final ArrayList<PointD> result;
  private final IntegratorRN integrator;
  private final FunctionRN[] mapper;

  public Processor(IntegratorRN integrator, FunctionRN[] mapper) {
    this.mapper = mapper == null ? defaultMapper : mapper;
    this.integrator = integrator;
    this.result = new ArrayList<>();
  }

  public void process() {
    integrator.setListener(this::cachePoint);
    integrator.integrate();
  }

  protected void cachePoint(PointRN point) {
    PointD cached = new PointD(mapper.length);
    for (int i = 0; i < mapper.length; i++)
      cached.set(i, mapper[i].f(point));
    result.add(cached);
  }

  public ArrayList<PointD> getResult() {
    return result;
  }
}
