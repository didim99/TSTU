package ru.didim99.tstu.jsp.rsa;

import java.io.*;
import java.util.ArrayList;

/**
 * Created by didim99 on 10.09.18.
 */
public class Utils {

  /* ======== STRING UTILS ========== */

  public static String joinStr(String delimiter, ArrayList<String> args) {
    if (args == null || args.isEmpty())
      return null;
    StringBuilder builder = new StringBuilder();
    int size = args.size() - 1;
    for (int i = 0; i < size; i++)
      builder.append(args.get(i)).append(delimiter);
    builder.append(args.get(size));
    return builder.toString();
  }

  /* ======== FILE UTILS =========== */

  public static ArrayList<String> readFile(InputStream in, boolean raw)
    throws IOException {
    BufferedReader reader = new BufferedReader(new InputStreamReader(in));
    ArrayList<String> data = new ArrayList<>();
    String line;
    while ((line = reader.readLine()) != null)
      if (!line.isEmpty() || raw) data.add(line);
    return data;
  }

  public static byte[] readFileRaw(String path) throws IOException {
    return readFileRaw(new FileInputStream(path));
  }

  public static byte[] readFileRaw(InputStream in) throws IOException {
    byte[] buff = new byte[in.available()];
    DataInputStream src = new DataInputStream(in);
    src.readFully(buff);
    src.close();
    return buff;
  }

  public static void writeFile(String fileName, byte[] data) throws IOException {
    File file = new File(fileName);
    DataOutputStream src = new DataOutputStream(new FileOutputStream(file));
    src.write(data);
    src.flush();
    src.close();
  }
}
