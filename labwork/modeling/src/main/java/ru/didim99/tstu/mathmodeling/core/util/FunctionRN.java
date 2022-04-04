package ru.didim99.tstu.mathmodeling.core.util;

/**
 * Multi-argument mathematical function
 * Created by didim99 on 02.10.19.
 */
@FunctionalInterface
public interface FunctionRN {
  double f(PointRN p);
}
