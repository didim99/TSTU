package ru.didim99.tstu.mathmodeling.core;

import ru.didim99.tstu.mathmodeling.core.integrator.LayerIntegrator;
import ru.didim99.tstu.mathmodeling.core.integrator.SequenceIntegrator;
import ru.didim99.tstu.mathmodeling.core.util.Function;
import ru.didim99.tstu.mathmodeling.core.util.FunctionRN;
import ru.didim99.tstu.mathmodeling.core.util.Variable;

public class Functions {
  // Constants (liquid)
  public static final double kt     = 6500;   // W/m^2*degC
  public static final double ct     = 4190;   // J/kg*degC
  public static final double ro     = 1000;   // kg/m^3
  public static final double TT     = 80;     // degC
  public static final double L      = 1;      // m
  public static final double D      = 0.05;   // m
  public static final double u      = 0.2;    // m/s
  public static final double tauMax = 10;     // s
  public static final double dAlpha = 0.3;
  public static final double dBeta  = 0.2;
  // Pre-calculated constants
  public static final double tauS   = L / u;  // s
  // Parameter indexes
  public static final int IBETA     = 0;
  public static final int IALPHA    = 1;
  public static final int IT        = 2;

  // variant 2
  public static Function tIn = tau -> 22 + 6 * Math.cos(tau);
  public static Function T0 = l -> 25 + 3 * Math.pow(l + 1, 2);
  // variant 14
  //public static Function tIn = tau -> 15 + 10 * Math.exp(-tau);
  //public static Function T0 = l -> -3 * l * l - 6 * l + 25;

  public static Function dT = tPrev -> (TT - tPrev) * 4 * kt / (ct * ro * D);

  // Variables mapper: tau, l, T
  public static FunctionRN[] liquidMapper = {
    vars -> vars.get(IALPHA) + vars.get(IBETA),
    vars -> u * (vars.get(IALPHA) - vars.get(IBETA)),
    vars -> vars.get(IT)
  };

  // Integration ranges
  public static final SequenceIntegrator.Step[] sequence = {
    new SequenceIntegrator.Step(new SequenceIntegrator.Range[] {
      new SequenceIntegrator.Range(p -> -tauS/2, p -> p.get(IBETA) <= 0, dBeta),
      new SequenceIntegrator.Range(p -> -p.get(IBETA), p -> p.get(IALPHA) <= p.get(IBETA) + tauS, dAlpha)},
      p -> T0.f(-2 * u * p.get(IBETA))
    ),
    new SequenceIntegrator.Step(new SequenceIntegrator.Range[] {
      new SequenceIntegrator.Range(p -> p.get(IBETA), p -> p.get(IBETA) <= (tauMax - tauS) / 2, dBeta),
      new SequenceIntegrator.Range(p -> p.get(IBETA), p -> p.get(IALPHA) <= p.get(IBETA) + tauS, dAlpha)},
      p -> tIn.f(2 * p.get(IBETA))
    ),
    new SequenceIntegrator.Step(new SequenceIntegrator.Range[] {
      new SequenceIntegrator.Range(p -> p.get(IBETA), p -> p.get(IBETA) <= tauMax / 2, dBeta),
      new SequenceIntegrator.Range(p -> p.get(IBETA), p -> p.get(IALPHA) <= tauMax - p.get(IBETA), dAlpha)},
      p -> tIn.f(2 * p.get(IBETA))
    ),
  };

  // Constants (thermal)
  public static final double alpha  = 1.3E-2; // m^2/s
  // Parameter indexes
  public static final int IX        = 0;
  public static final int ITAU      = 1;

  // variant 2
  public static Function phi = x -> 25 + 3 * Math.pow(x + 1, 2);
  public static Function f1 = tau -> 22 + 6 * Math.cos(tau);
  public static Function f2 = tau -> 37 - 0.1 * tau;

  // Variables mapper: x, tau, T
  public static FunctionRN[] thermalMapper = {
    vars -> vars.get(ITAU),
    vars -> vars.get(IX),
    vars -> vars.get(IT)
  };

  public static FunctionRN mm = point -> alpha;

  public static Variable vX = new Variable("vX", 0, 1, 0.1);
  public static Variable vTau = new Variable("vTau", 0, 100, 0.005);

  public static LayerIntegrator.Direction dirX =
    new LayerIntegrator.Direction(vX, phi, null);
  public static LayerIntegrator.Direction dirTau =
    new LayerIntegrator.Direction(vTau, f1, f2);
}
