package ru.didim99.tstu.oop.lab10;

import com.google.gson.annotations.SerializedName;

class StudentInfo {
  @SerializedName("name")
  private String name;
  @SerializedName("grades")
  private GradeList grades;

  StudentInfo(String name, GradeList grades) {
    this.name = name;
    this.grades = grades;
  }

  GradeList getGrades() {
    return grades;
  }

  @Override
  public String toString() {
    return String.format("Student name: %-30s grades: %s", name, grades);
  }
}
