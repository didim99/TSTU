#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <inttypes.h>
#include "terminal.h"

#define FLD_SIZE      32
#define BUF_SIZE      1024
#define PRINTVALUE    "%20s : %s\n"
#define PROCCOMMFILE  "/proc/%d/comm"
#define PROCEXEFILE   "/proc/%d/exe"
#define PROCSTATFILE  "/proc/%d/status"

#define retError(err) do { errno = err; return -1; } while(0)
#define strStartsWith(s, match) (strncmp((s),(match),strlen(match)) == 0)
#define tryRead(label, variable) do { if (strStartsWith(buffer, label) \
  && sscanf(buffer + strlen(label), " %s", variable)) { break; } } while(0)

typedef struct procstat {
  char state[FLD_SIZE];
  char ppid[FLD_SIZE];
  char threads[FLD_SIZE];
} procstat_t;

static inline void handle_error(const char *msg);
int getProcStat(const char* path, procstat_t *stat);
int readProc(int pid);
