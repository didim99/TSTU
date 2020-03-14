<%@ page contentType="text/html; charset=UTF-8" %>
<%@ page import="ru.didim99.tstu.jsp.rsa.WebUI" %>
<%@ page import="ru.didim99.tstu.jsp.rsa.encryption.rsa.RSAKey" %>
<%@ page import="ru.didim99.tstu.jsp.rsa.encryption.CryptoManager" %>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
<jsp:useBean id="manager" scope="session"
             type="ru.didim99.tstu.jsp.rsa.encryption.CryptoManager"/>
<%

  manager = (CryptoManager)
    request.getSession().getAttribute(WebUI.ATTR_MANAGER);
  boolean hasKey = manager.getKey() != null;

%>
<%--
  User: didim
  Date: 13.03.2020
--%>
<html lang="ru">
  <head>
    <title>Система шифрования RSA</title>
    <link rel="stylesheet" href="./main.css">
  </head>
  <body>
    <h1>Система шифрования RSA</h1>
    <c:if test="${error != null}">
      <div class="error">${error}</div>
    </c:if>
    <hr/>
    <form action="${pageContext.request.contextPath}/rsa" method="POST">
      <input type="hidden" name="${WebUI.ATTR_ACTION}" value="${WebUI.ACTION_GEN_KEY}" />
      Сгенерировать ключ длиной
      <select name="${WebUI.ATTR_KEY_LEN}">
        <c:forEach items="${RSAKey.getPossibleLength()}" var="len">
          <option value="${len}">${len} бит</option>
        </c:forEach>
      </select>
      <input type="submit" value="Сгенерировать">
    </form>
    <div class="header">Параметры ключа</div>
    <form action="${pageContext.request.contextPath}/rsa" method="POST">
      <input type="hidden" name="${WebUI.ATTR_ACTION}" value="${WebUI.ACTION_SET_KEY}" />
      E: <input type="text" name="${WebUI.ATTR_KEY_E}" class="keyField" value="<%
        if (hasKey) out.print(manager.getKey().getE().toString()); %>"/>
      D: <input type="text" name="${WebUI.ATTR_KEY_D}" class="keyField" value="<%
        if (hasKey) out.print(manager.getKey().getD().toString()); %>"/>
      N: <input type="text" name="${WebUI.ATTR_KEY_N}" class="keyField" value="<%
        if (hasKey) out.print(manager.getKey().getN().toString()); %>"/>
      &nbsp;<input type="submit" value="Установить">
    </form>
    <hr/>
    <div class="wrapper">
      <div class="header">Исходное сообщение</div>
      <form action="${pageContext.request.contextPath}/rsa"
            method="POST" enctype="multipart/form-data">
        <input type="hidden" name="${WebUI.ATTR_ACTION}" value="${WebUI.ACTION_GO}" />
        <textarea name="${WebUI.ATTR_MESSAGE}" wrap="hard" cols="90" rows="6"
                  placeholder="Введите сообщение">${manager.getMessage()}</textarea>
        <div class="go-wrapper">
          Или загрузите текстовый файл:
          <input type="file" name="${WebUI.ATTR_IN_FILE}" />
          <div class="go"><input type="submit" value="Зашифровать"/></div>
        </div>
      </form>
    </div>
    <c:if test="${encoded != null}">
      <hr/>
      <div class="wrapper">
        <div class="header">Зашифрованное сообщение</div>
        <div class="pre-wrapper"><pre>${encoded}</pre></div>
      </div>
    </c:if>
    <c:if test="${decoded != null}">
      <hr/>
      <div class="wrapper">
        <div class="header">Результат дешифровки</div>
        <div class="pre-wrapper"><pre>${decoded}</pre></div>
      </div>
    </c:if>
  </body>
</html>
