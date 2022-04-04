#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <inttypes.h>
#include <sys/types.h>
#include <unistd.h>
#include "terminal.h"

#define MEMINFOFILE "/proc/meminfo"
#define PROCMAPSFILE "/proc/%d/maps"

#define retError(err) do { errno = err; return -1; } while(0)
#define strStartsWith(s, match) (strncmp((s),(match),strlen(match)) == 0)
#define tryRead(label, variable) do { if (strStartsWith(buffer, label) \
  && sscanf(buffer + strlen(label), " %32lu kB", variable)) { break; } } while(0)

#define BYTE_NAMES      "kMGT"
#define CLR_MEM_SHARED  TC_F_RED
#define CLR_MEM_USED    TC_F_GREEN
#define CLR_MEM_BUFFER  TC_F_BLUE
#define CLR_MEM_CACHE   TC_F_YELLOW
#define CLR_MEM_FREE    TC_F_BLACK
#define CLR_SWP_USED    TC_F_GREEN
#define IDX_MEM_SHARED  0
#define IDX_MEM_USED    1
#define IDX_MEM_BUFFER  2
#define IDX_MEM_CACHE   3
#define IDX_SWP_USED    0

typedef struct meminfo {
  uint64_t totalMem;
  uint64_t usedMem;
  uint64_t availMem;
  uint64_t freeMem;
  uint64_t sharedMem;
  uint64_t buffersMem;
  uint64_t cachedMem;
  uint64_t totalSwap;
  uint64_t usedSwap;
  uint64_t freeSwap;
} meminfo_t;

void handle_error(const char *msg);
int getMemoryInfo(meminfo_t *info);
int showMemoryDetails(uint32_t pid);

void printPercent(double val);
void printBytes(uint64_t bytes);
void printBytesPart(uint64_t part, uint64_t total);
void printField(const char* name, uint64_t bytes,
                double percent, int color);
