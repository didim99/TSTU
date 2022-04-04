package ru.didim99.tstu.oop.lab10;

import com.google.gson.annotations.SerializedName;
import java.util.Locale;

class GradeList {
  @SerializedName("lang")
  private int lang;
  @SerializedName("math")
  private int math;
  @SerializedName("physics")
  private int physics;
  @SerializedName("cs")
  private int cs;

  void setLang(int lang) {
    this.lang = lang;
  }

  void setMath(int math) {
    this.math = math;
  }

  void setPhysics(int physics) {
    this.physics = physics;
  }

  void setCS(int cs) {
    this.cs = cs;
  }

  double avg() {
    return (lang + math + physics + cs) / 4f;
  }

  @Override
  public String toString() {
    return String.format(Locale.US,
      "[l:%d, m:%d, p:%d, c:%d, avg:%.1f]",
      lang, math, physics, cs, avg());
  }
}
