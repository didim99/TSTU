package ru.didim99.tstu.jsp.rsa;

import ru.didim99.tstu.jsp.rsa.encryption.CryptoManager;
import ru.didim99.tstu.jsp.rsa.encryption.rsa.RSAKey;
import javax.servlet.ServletException;
import javax.servlet.annotation.MultipartConfig;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.*;
import java.io.IOException;
import java.math.BigInteger;

@MultipartConfig
@WebServlet("/rsa")
public class WebUI extends HttpServlet {
  private static final String URL = "index.jsp";
  // Request/response attributes
  public static final String ATTR_KEY_E = "keyE";
  public static final String ATTR_KEY_D = "keyD";
  public static final String ATTR_KEY_N = "keyN";
  public static final String ATTR_ACTION = "action";
  public static final String ATTR_KEY_LEN = "keyLength";
  public static final String ATTR_MESSAGE = "message";
  public static final String ATTR_IN_FILE = "inFile";
  public static final String ATTR_ERROR = "error";
  public static final String ATTR_ENCODED = "encoded";
  public static final String ATTR_DECODED = "decoded";
  // Session attributes
  public static final String ATTR_MANAGER = "manager";
  // Request actions
  public static final String ACTION_GEN_KEY = "genKey";
  public static final String ACTION_SET_KEY = "setKey";
  public static final String ACTION_GO = "go";


  protected void doPost(HttpServletRequest req, HttpServletResponse resp)
    throws ServletException, IOException {
    req.setCharacterEncoding("UTF-8");
    CryptoManager manager = initSession(req);

    switch (req.getParameter(ATTR_ACTION)) {
      case ACTION_GEN_KEY:
        try {
          int length = Integer.parseInt(req.getParameter(ATTR_KEY_LEN));
          manager.setKey(RSAKey.generate(length));
        } catch (NumberFormatException e) {
          req.setAttribute(ATTR_ERROR, "Invalid key length");
        }
        break;
      case ACTION_SET_KEY:
        try {
          manager.setKey(new RSAKey(
            new BigInteger(req.getParameter(ATTR_KEY_E)),
            new BigInteger(req.getParameter(ATTR_KEY_D)),
            new BigInteger(req.getParameter(ATTR_KEY_N))));
        } catch (NumberFormatException e) {
          req.setAttribute(ATTR_ERROR, "Invalid key parameter");
        }
        break;
      case ACTION_GO:
        String message = req.getParameter(ATTR_MESSAGE);
        Part filePart = req.getPart(ATTR_IN_FILE);
        String filename = filePart.getSubmittedFileName();

        if (manager.getKey() == null) {
          req.setAttribute(ATTR_ERROR, "Key not defined");
        } else if ((message == null || message.isEmpty())
          && filename.isEmpty()) {
          req.setAttribute(ATTR_ERROR, "Empty message");
        } else {
          try {
            if (filename.isEmpty())
              manager.setMessage(message);
            else {
              manager.loadFile(filename,
                filePart.getInputStream());
            }

            manager.process();
            req.setAttribute(ATTR_ENCODED, manager.getEncryptedDataStr());
            req.setAttribute(ATTR_DECODED, manager.getDecryptedData());
          } catch (IOException e) {
            req.setAttribute(ATTR_ERROR, e.getMessage());
          }
        }
        break;
    }

    req.getRequestDispatcher(URL).forward(req, resp);
  }

  protected void doGet(HttpServletRequest req, HttpServletResponse resp)
    throws ServletException, IOException {
    initSession(req);
    req.getRequestDispatcher(URL).forward(req, resp);
  }

  private CryptoManager initSession(HttpServletRequest req) {
    HttpSession session = req.getSession();
    CryptoManager manager = (CryptoManager)
      session.getAttribute(ATTR_MANAGER);
    if (manager == null) manager = new CryptoManager();
    session.setAttribute(ATTR_MANAGER, manager);
    return manager;
  }
}
