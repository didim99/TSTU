package ru.didim99.tstu.mathmodeling.core.util;

/**
 * Multi-argument mathematical condition
 * Created by didim99 on 02.10.19.
 */
@FunctionalInterface
public interface ConditionRN {
  boolean check(PointRN p);
}
