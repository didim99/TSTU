#include "main.h"

void handle_error(const char *msg) {
  printf(" %s\n  %3d: %s\n\n", msg, errno, strerror(errno));
  exit(EXIT_FAILURE);
}

void printPercent(double val) {
  int prec = val < 100 ? (val < 10 ? 2 : 1) : 0;
  printf(" (%4.*f%%) ", prec, val);
}

void printBytes(uint64_t bytes) {
  int idx = 0;
  double size = (double) bytes;
  while (size > 1024) 
    { size /= 1024; idx++; }

  int prec = 0;
  if (size < 10) prec = 2;
  else if (size < 100) prec = 1;
  printf("%4.*f%c", prec, size, BYTE_NAMES[idx]);
}

void printBytesPart(uint64_t part, uint64_t total) {
  printBytes(part);
  printf("/");
  printBytes(total);
}

void printField(const char* name, uint64_t bytes,
                double percent, int color) {
  settermattr(color);
  printf("%-8s ", name);
  printBytes(bytes);
  printPercent(percent);
  resetterm();
}

/*
 * Get global memory information from /proc/meminfo, Linux-specific
 * Based on htop source, see https://github.com/hishamhm/htop
 */
int getMemoryInfo(meminfo_t *info) {
  if (!info) retError(EINVAL);
  FILE* file = fopen(MEMINFOFILE, "r");
  if (!file) return -1;
  
  char buffer[128];
  uint64_t shmem = 0;
  uint64_t sreclaimable = 0;
  while (fgets(buffer, 128, file)) {
    switch (buffer[0]) {
      case 'B': tryRead("Buffers:", &info->buffersMem); break;
      case 'C': tryRead("Cached:", &info->cachedMem); break;
      case 'M':
        switch (buffer[3]) {
          case 'T': tryRead("MemTotal:", &info->totalMem); break;
          case 'F': tryRead("MemFree:", &info->freeMem); break;
          case 'S': tryRead("MemShared:", &info->sharedMem); break;
          case 'A': tryRead("MemAvailable:", &info->availMem); break;
        }
        break;
      case 'S':
        switch (buffer[1]) {
          case 'w':
            tryRead("SwapTotal:", &info->totalSwap);
            tryRead("SwapFree:", &info->freeSwap);
            break;
          case 'h':
            tryRead("Shmem:", &shmem);
            break;
          case 'R':
            tryRead("SReclaimable:", &sreclaimable);
            break;
        }
        break;
    }
  }

  if (!info->sharedMem) info->sharedMem = shmem;
  info->usedSwap = info->totalSwap - info->freeSwap;
  info->usedMem = info->totalMem - info->availMem;
  fclose(file);
  return 0;
}

int showMemoryDetails(uint32_t pid) {
  const char *header[] = {"address", "perms", "offset", "dev", "inode", "pathname"};
  const int width[] = {34, 6, 10, 6, 10, 0};
  const int columns = sizeof(width) / sizeof(*width);

  char *buff = (char*) calloc(1, 256);
  sprintf(buff, PROCMAPSFILE, pid);
  FILE* file = fopen(buff, "r");
  if (!file) return -1;

  settermattr(TC_BRIGHT);
  for (int i = 0; i < columns; i++)
    printf(" %-*s", width[i], header[i]);
  settermattr(TC_RESET);
  putchar('\n');

  char *buff2;
  while (fgets(buff, 256, file)) {
    int pos = 0, style = 0;
    buff2 = strtok(buff, " ");
    printf(" %-*s", width[pos], buff2);
    while ((buff2 = strtok(NULL, " "))) {
      if (++pos == columns - 1) {
        buff2 = strtok(buff2, "\n");
        if (!buff2) {
          buff2 = "[anonimous mapping]";
          style = TC_F_YELLOW;
        } else if (*buff2 == '/') {
          style = TC_F_BLUE;
        } else if (*buff2 == '[') {
          style = TC_F_GREEN;
        }
      }

      if (style) settermattr(style);
      printf(" %-*s", width[pos], buff2);
      if (style) settermattr(style = TC_RESET);
    }
    putchar('\n');
  }

  fclose(file);
  free(buff);
  return 0;
}

int main(int argc, const char **argv) {
  uint32_t pid = 0;
  for (int i = 0; i < argc; i++) {
    if (strcmp(argv[i], "-p") == 0) {
      if (argc > i) sscanf(argv[i+1], "%u", &pid);
    }
  }

  // Get global memory info
  meminfo_t *mi = (meminfo_t*) calloc(1, sizeof(meminfo_t));
  if (getMemoryInfo(mi) == -1)
    handle_error("Can`t get system memory info");
  graph_t gmem[] = { {0, CLR_MEM_SHARED}, {0, CLR_MEM_USED}, 
                      {0, CLR_MEM_BUFFER}, {0, CLR_MEM_CACHE} };
  graph_t gswp[] = { {0, CLR_SWP_USED} };

  // Calculate drawing parameters
  double usedMem = (double) mi->usedMem / mi->totalMem * 100;
  double usedSwap = (double) mi->usedSwap / mi->totalSwap * 100;
  double freeMem = (double) mi->freeMem / mi->totalMem * 100;
  gmem[IDX_MEM_SHARED].value = (double) mi->sharedMem / mi->totalMem * 100;
  gmem[IDX_MEM_USED].value = usedMem - gmem[IDX_MEM_SHARED].value;
  gmem[IDX_MEM_BUFFER].value = (double) mi->buffersMem / mi->totalMem * 100;
  gmem[IDX_MEM_CACHE].value = (double) mi->cachedMem / mi->totalMem * 100;
  gswp[IDX_SWP_USED].value = usedSwap;

  clrscr();
  int x = 1, y = 1;
  // Draw memory info
  gotoxy(x+=1, y+=1);
  printf("RAM: ");
  printBytesPart(mi->usedMem, mi->totalMem);
  printPercent(usedMem);
  gotoxy(x+=5, y+=1);
  drawBar(gmem, 4);
  gotoxy(x, y+=1);
  printField("shared", mi->sharedMem, gmem[IDX_MEM_SHARED].value, CLR_MEM_SHARED);
  gotoxy(x+30, y);
  printField("cached", mi->cachedMem, gmem[IDX_MEM_CACHE].value, CLR_MEM_CACHE);
  gotoxy(x, y+=1);
  printField("buffers", mi->buffersMem, gmem[IDX_MEM_BUFFER].value, CLR_MEM_BUFFER);
  gotoxy(x+30, y);
  settermattr(TC_BRIGHT);
  printField("free", mi->freeMem, freeMem, CLR_MEM_FREE);
  
  // Draw swap info
  gotoxy(x=2, y+=2);
  printf("SWP: ");
  printBytesPart(mi->usedSwap, mi->totalSwap);
  printPercent(usedSwap);
  gotoxy(x+=5, y+=1);
  drawBar(gswp, 1);
  
  // Draw memory map
  gotoxy(x=2, y+=2);
  if (!pid) pid = getpid();
  printf("Memory map for process %d", pid);
  gotoxy(x=1, y+=2);
  if (showMemoryDetails(pid))
    handle_error("Can`t get memory details for specified process");
  printf("\n");
  
  free(mi);
  exit(EXIT_SUCCESS);
}
