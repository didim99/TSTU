#include "terminal.h"

static inline void drawBarPart(char filler, int len) {
  for (int i = 0; i < len; i++) putchar(filler);
}

void drawBar(graph_t *data, size_t count) {
  int width = GRAPH_WIDTH, part = 0;
  settermattr(TC_BRIGHT);
  putchar(GRAPH_START);
  resetterm();

  for (int i = 0; i < count; i++, data++) {
    part = (int) round(data->value / 100 * GRAPH_WIDTH);
    if (part == 0) part = 1;
    if (part > width) part = width;
    settermattr(data->color);
    drawBarPart(GRAPH_ITEM, part);
    width -= part;
  }

  resetterm();
  drawBarPart(GRAPH_EMPTY, width);
  settermattr(TC_BRIGHT);
  putchar(GRAPH_END);
  resetterm();
}
