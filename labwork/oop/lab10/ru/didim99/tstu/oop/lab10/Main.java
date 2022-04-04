package ru.didim99.tstu.oop.lab10;

import com.google.gson.Gson;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Objects;
import java.util.Set;
import java.util.Stack;
import java.util.stream.Collectors;

public class Main {
  private static final String FILENAME = "/res/students.dat";
  private static final Gson parser = new Gson();

  private static ArrayList<String> readResource(String name)
    throws IOException {
    BufferedReader reader = new BufferedReader(
      new InputStreamReader(Main.class
        .getResourceAsStream(name)));
    ArrayList<String> data = new ArrayList<>();
    String line;
    while ((line = reader.readLine()) != null)
      if (!line.isEmpty()) data.add(line);
    return data;
  }

  private static StudentInfo parse(String src) {
    return parser.fromJson(src, StudentInfo.class);
  }

  private static List<StudentInfo> load()
    throws IOException {
    System.out.println("Reading: " + FILENAME);
    return readResource(FILENAME)
      .stream().map(Main::parse)
      .filter(Objects::nonNull)
      .collect(Collectors.toList());
  }

  private static StudentInfo readFromConsole(BufferedReader reader)
    throws IOException, NumberFormatException {
    System.out.print("Full name: ");
    String name = reader.readLine();
    GradeList gradeList = new GradeList();
    System.out.print("Grades lang: ");
    String line = reader.readLine();
    gradeList.setLang(Integer.parseInt(line));
    System.out.print("       math: ");
    line = reader.readLine();
    gradeList.setMath(Integer.parseInt(line));
    System.out.print("    physics: ");
    line = reader.readLine();
    gradeList.setPhysics(Integer.parseInt(line));
    System.out.print("         cs: ");
    line = reader.readLine();
    gradeList.setCS(Integer.parseInt(line));
    return new StudentInfo(name, gradeList);
  }

  public static void main(String[] args) {
    BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    List<StudentInfo> sourceList = new ArrayList<>();
    List<StudentInfo> list = new ArrayList<>();
    Stack<StudentInfo> stack = new Stack<>();

    try {
      System.out.print("Entry count: ");
      String line = reader.readLine();
      int count = Integer.parseInt(line);
      System.out.print("Load from file? (Y/N): ");
      line = reader.readLine();
      if (line.toLowerCase().equals("y")) {
        sourceList = load();
      } else {
        for (int i = 0; i < count; i++)
          sourceList.add(readFromConsole(reader));
      }

      sourceList.stream()
        .limit(count)
        .forEach(stack::add);

      stack.stream()
        .filter(s -> s.getGrades().avg() >= 4)
        .forEach(list::add);

      stack.removeAll(list);
      Set<StudentInfo> set = new HashSet<>(stack);

      System.out.println("\nStudents with good grades:");
      list.forEach(System.out::println);

      System.out.println("\nOther Students:");
      set.forEach(System.out::println);

    } catch (Exception e) {
      e.printStackTrace();
    }
  }
}
