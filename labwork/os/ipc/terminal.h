#ifndef _TERMINAL_H_
#define _TERMINAL_H_

#include <stdio.h>
#include <inttypes.h>
#include <math.h>

#define ESC "\033"
//Format text
#define TC_RESET      0
#define TC_BRIGHT     1
#define TC_DIM        2
#define TC_UNDERSCORE 3
#define TC_BLINK      4
#define TC_REVERSE    5
#define TC_HIDDEN     6
//Foreground Colours (text)
#define TC_F_BLACK    30
#define TC_F_RED      31
#define TC_F_GREEN    32
#define TC_F_YELLOW   33
#define TC_F_BLUE     34
#define TC_F_MAGENTA  35
#define TC_F_CYAN     36
#define TC_F_WHITE    37
//Background Colours
#define TC_B_BLACK    40
#define TC_B_RED      41
#define TC_B_GREEN    42
#define TC_B_YELLOW   44
#define TC_B_BLUE     44
#define TC_B_MAGENTA  45
#define TC_B_CYAN     46
#define TC_B_WHITE    47

#define home()            printf(ESC "[H")  //Move cursor to the (1, 1)
#define clrscr()          printf(ESC "[2J") //clear the screen, move to (1,1)
#define gotoxy(x, y)      printf(ESC "[%d;%dH", y, x)
#define visiblecursor()   printf(ESC "[?251")
//Set Display Attribute Mode  <ESC>[{attr1};...;{attrn}m
#define settermattr(attr) printf(ESC "[%dm", attr)
#define resetterm()       settermattr(TC_RESET)

#define GRAPH_WIDTH   50
#define GRAPH_START   '['
#define GRAPH_ITEM    '|'
#define GRAPH_EMPTY   ' '
#define GRAPH_END     ']'

typedef struct graph {
  double value;
  int color;
} graph_t;

void drawBar(graph_t *data, size_t count);

#endif /* _TERMINAL_H_ */
