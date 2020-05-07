package ru.didim99.tstu.mathmodeling.core.integrator;

import ru.didim99.tstu.mathmodeling.core.util.PointRN;

public abstract class IntegratorRN {
  protected IntegrationListener listener;

  public abstract void integrate();

  public void setListener(IntegrationListener listener) {
    this.listener = listener;
  }

  public interface IntegrationListener {
    void onIntegrationStep(PointRN point);
  }
}
