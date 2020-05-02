package ru.didim99.tstu.mathmodeling.core;

import ru.didim99.tstu.mathmodeling.core.util.*;

public class IntegratorRN {
  private final IntegrationListener listener;
  private final Step[] sequence;
  private final Function df;

  public IntegratorRN(Step[] sequence, Function df, IntegrationListener listener) {
    this.listener = listener;
    this.sequence = sequence;
    this.df = df;
  }

  public void integrate() {
    PointD point = new PointD(sequence[0].vars.length + 1);
    for (Step step : sequence) integrate(step, point, 0);
  }

  private void integrate(Step step, PointD point, int i) {
    int primary = step.vars.length;
    int last = primary - 1;
    Range range = step.vars[i];
    point.set(i, range.start.f(point));

    if (i == last)
      point.set(primary, step.primaryStart.f(point));
    while (range.stop.check(point)) {
      if (i == last) {
        double v = point.get(primary);
        listener.onIntegrationStep(point);
        point.set(primary, v + df.f(v) * range.step);
      } else
        integrate(step, point, i+1);
      point.add(i, range.step);
    }
  }

  public static class Step {
    private final FunctionRN primaryStart;
    private final Range[] vars;

    public Step(Range[] vars, FunctionRN primaryStart) {
      this.primaryStart = primaryStart;
      this.vars = vars;
    }
  }

  public static class Range {
    private final FunctionRN start;
    private final ConditionRN stop;
    private final double step;

    public Range(FunctionRN start, ConditionRN stop, double step) {
      this.start = start;
      this.stop = stop;
      this.step = step;
    }
  }

  public interface IntegrationListener {
    void onIntegrationStep(PointRN point);
  }
}
