package ru.didim99.tstu.mathmodeling.core;

import ru.didim99.tstu.mathmodeling.core.util.Function;
import ru.didim99.tstu.mathmodeling.core.util.FunctionRN;

public class Functions {
  // Dynamic constants (Distributed)
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
  public static final int IBETA   = 0;
  public static final int IALPHA  = 1;
  public static final int IT      = 2;
  // Window/Axis names
  public static final String LABEL_DDP = "Distributed Dynamic Processor";
  public static final String LABEL_TAU = "tau, s";
  public static final String LABEL_L = "L, m";
  public static final String LABEL_T = "T, degC";

  public static Function tIn = tau -> 22 + 6 * Math.cos(tau);
  public static Function T0 = l -> 25 + 3 * Math.pow(l + 1, 2);

  public static Function dT = tPrev -> (TT - tPrev) * 4 * kt / (ct * ro * D);

  // Variables mapper: tau, l, T
  public static FunctionRN[] mapper = {
    vars -> vars.get(IALPHA) + vars.get(IBETA),
    vars -> u * (vars.get(IALPHA) - vars.get(IBETA)),
    vars -> vars.get(IT)
  };

  // Integration ranges
  public static final IntegratorRN.Step[] sequence = {
    new IntegratorRN.Step(new IntegratorRN.Range[] {
      new IntegratorRN.Range(p -> -tauS/2, p -> p.get(IBETA) <= 0, dBeta),
      new IntegratorRN.Range(p -> -p.get(IBETA), p -> p.get(IALPHA) <= p.get(IBETA) + tauS, dAlpha)},
      p -> T0.f(-2 * u * p.get(IBETA))
    ),
    new IntegratorRN.Step(new IntegratorRN.Range[] {
      new IntegratorRN.Range(p -> p.get(IBETA), p -> p.get(IBETA) <= (tauMax - tauS) / 2, dBeta),
      new IntegratorRN.Range(p -> p.get(IBETA), p -> p.get(IALPHA) <= p.get(IBETA) + tauS, dAlpha)},
      p -> tIn.f(2 * p.get(IBETA))
    ),
    new IntegratorRN.Step(new IntegratorRN.Range[] {
      new IntegratorRN.Range(p -> p.get(IBETA), p -> p.get(IBETA) <= tauMax / 2, dBeta),
      new IntegratorRN.Range(p -> p.get(IBETA), p -> p.get(IALPHA) <= tauMax - p.get(IBETA), dAlpha)},
      p -> tIn.f(2 * p.get(IBETA))
    ),
  };
}
