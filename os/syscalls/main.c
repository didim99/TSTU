#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <pwd.h>
#include <sys/utsname.h>
#include <X11/cursorfont.h>
#include <X11/Xlib.h>
#include <time.h>
#include <locale.h>
#include <gtk/gtk.h>

#define NAME_SIZE 64

void printorerr(int status, const char* name, const char* value) {
  if (!status) printf("%19s: %s\n", name, value);
  else printf("Can't get %s: error %s\n", name, strerror(status));
}

void rgbToStr(GdkRGBA* src, char* target) {
  int r = (int) (src->red * 256);
  int g = (int) (src->green * 256);
  int b = (int) (src->blue * 256);
  sprintf(target, "#%02X%02X%02X", r, g, b);
}

int main(int argc, char** argv) {
  int status = 0;
  char* strbuff = (char*) malloc(sizeof(char) * NAME_SIZE);
  Display *display;

  // try to open X11 main display
  if ((display = XOpenDisplay(NULL)) == NULL) {
    printf("Error: can't open main display\n");
    exit(EXIT_FAILURE);
  }
  Window rootwindow = XDefaultRootWindow(display);

  // Get hostname and username
  status = gethostname(strbuff, NAME_SIZE);
  printorerr(status, "hostname", strbuff);
  struct passwd *pwd = getpwuid(getuid());
  printorerr(pwd ? 0 : 1, "username", pwd ? pwd->pw_name : NULL);

  // Get kernel and OS version
  struct utsname sysname;
  status = uname(&sysname);
  printorerr(status, "kernel version", sysname.release);
  printorerr(status, "OS version", sysname.version);

  // Get binary directories using PATH
  char *path = getenv("PATH");
  path = strtok(path, ":");
  printorerr(0, "binary directories", path);
  while (path = strtok(NULL, ":"))
    if (path) printf("%21s%s\n", "", path);

  // Get screen count from X11
  sprintf(strbuff, "%d", ScreenCount(display));
  printorerr(status, "number of screens", strbuff);
  // Get main screen resolution from X11
  XWindowAttributes xw_attrs;
  XGetWindowAttributes(display, rootwindow, &xw_attrs);
  sprintf(strbuff, "%dx%d", xw_attrs.width, xw_attrs.height);
  printorerr(status, "screen resolution", strbuff);

  // Get system colors from GTK
  GtkWidget *window;
  GtkStyleContext *context;
  GdkRGBA fg, bg, border;
  gtk_init(&argc, &argv);
  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  context = gtk_widget_get_style_context(window);
  gtk_style_context_get_color(context, GTK_STATE_FLAG_NORMAL, &fg);
  gtk_style_context_get_background_color(context, GTK_STATE_FLAG_NORMAL, &bg);
  gtk_style_context_get_border_color(context, GTK_STATE_FLAG_NORMAL, &border);
  rgbToStr(&bg, strbuff);
  printorerr(status, "background color", strbuff);
  rgbToStr(&fg, strbuff);
  printorerr(status, "foreground color", strbuff);
  rgbToStr(&border, strbuff);
  printorerr(status, "border color", strbuff);

  // Get time and time zone info
  struct tm tmp;
  time_t t = time(NULL);
  localtime_r(&t, &tmp);
  status = strftime(strbuff, NAME_SIZE, "%a, %d %b %Y %T", &tmp);
  printorerr(status == 0 ? 1 : 0, "local time", strbuff);
  status = strftime(strbuff, NAME_SIZE, "%z", &tmp);
  printorerr(status == 0 ? 1 : 0, "time zone", strbuff);

  // Get current mouse position on next click
  XEvent evt;
  XGrabPointer(display, rootwindow, False,
    ButtonPressMask, GrabModeAsync, GrabModeAsync,
    None, XCreateFontCursor(display, XC_cross), CurrentTime);
  XNextEvent(display, &evt);
  sprintf(strbuff, "x: %d, y: %d", evt.xbutton.x_root, evt.xbutton.y_root);
  printorerr(0, "mouse position", strbuff);

  // Get some environment information
  printorerr(0, "current terminal", getenv("TERM"));
  printorerr(0, "current shell", getenv("SHELL"));
  printorerr(0, "current locale", setlocale(LC_ALL, NULL));
  
  XCloseDisplay(display); // free X11 main display
  free(strbuff);
  return 0;
}
