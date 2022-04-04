package ru.didim99.tstu.jsp.rsa.encryption;

import ru.didim99.tstu.jsp.rsa.Utils;
import ru.didim99.tstu.jsp.rsa.encryption.rsa.RSAKey;
import ru.didim99.tstu.jsp.rsa.encryption.rsa.RSAProcessor;
import java.io.File;
import java.io.IOException;
import java.io.InputStream;

/**
 * Created by didim99 on 05.03.20.
 */
public class CryptoManager {
  private static final String EXT_SEP = ".";
  private static final String EXT_TXT = ".txt";
  private static final String EXT_ENC = ".crypt";
  private static final String EXT_KEY = ".key";
  private static final String DEFAULT_FILE = "message";

  // Config and state
  private String filename;
  private String message;
  private byte[] encryptedData;
  private String decryptedData;
  private RSAKey key;

  public CryptoManager() {}

  public void setMessage(String message) {
    this.message = message;
  }

  void setEncryptedData(byte[] encryptedData) {
    this.encryptedData = encryptedData;
  }

  public void setKey(RSAKey key) {
    this.key = key;
  }

  public String getMessage() {
    return message;
  }

  public String getEncryptedDataStr() {
    if (encryptedData == null) return null;
    StringBuilder sb = new StringBuilder();
    for (byte b : encryptedData)
      sb.append(String.format("%02x ", b));
    return sb.toString().trim();
  }

  public String getDecryptedData() {
    return decryptedData;
  }

  public RSAKey getKey() {
    return key;
  }

  public void loadFile(String name, InputStream in) throws IOException {
    if (name.isEmpty())
      throw new IOException("Input data is empty");
    if (!name.endsWith(EXT_KEY))
      filename = name.substring(0, name.lastIndexOf(EXT_SEP));

    message = null;
    encryptedData = null;
    decryptedData = null;

    if (name.endsWith(CryptoManager.EXT_KEY))
      setKey(new RSAKey(Utils.readFileRaw(in)));
    else if (name.endsWith(CryptoManager.EXT_TXT))
      setMessage(Utils.joinStr("\n",
        Utils.readFile(in, true)));
    else if (name.endsWith(CryptoManager.EXT_ENC))
      setEncryptedData(Utils.readFileRaw(in));
    else throw new IOException("Unsupported file type ("
        + name.substring(name.lastIndexOf(CryptoManager.EXT_SEP)) + ")");
  }

  public void process() throws IOException {
    if (filename == null) filename = DEFAULT_FILE;
    RSAProcessor processor = new RSAProcessor(key);
    File tmpFile = File.createTempFile(filename, EXT_ENC);
    String tmpPath = tmpFile.getAbsolutePath();
    if (message != null && !message.isEmpty()) {
      Utils.writeFile(tmpPath, processor.encrypt(message));
      encryptedData = Utils.readFileRaw(tmpPath);
    }

    if (encryptedData != null)
      decryptedData = processor.decrypt(encryptedData);
    if (!tmpFile.delete())
      throw new IOException("Unable to delete temp file: " + tmpPath);
  }
}
