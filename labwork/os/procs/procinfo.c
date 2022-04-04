#include "procinfo.h"

static inline void handle_error(const char *msg) {
  printf("%s\n  %3d: %s\n", msg, errno, strerror(errno));
  exit(EXIT_FAILURE);
}

int getProcStat(const char* path, procstat_t *stat) {
  if (!stat) retError(EINVAL);
  FILE* file = fopen(path, "r");
  if (!file) return -1;
  
  char buffer[256];
  while (fgets(buffer, 256, file)) {
    switch (buffer[0]) {
      case 'P': tryRead("PPid:", &stat->ppid); break;
      case 'S': tryRead("State:", &stat->state); break;
      case 'T': tryRead("Threads:", &stat->threads); break;
    }
  }

  fclose(file);
  return 0;
}

int readProc(int pid) {
  char buff[BUF_SIZE];
  sprintf(buff, "%d", pid);
  printf(PRINTVALUE, "Process ID", buff);

  // Open comm file
  sprintf(buff, PROCCOMMFILE, pid);
  int fd = open(buff, O_RDONLY);
  if (fd == -1)
    handle_error("Can`t open comm file");
  int readed = read(fd, buff, BUF_SIZE);
  close(fd);

  if (buff[readed - 1] == 10)
    buff[readed - 1] = 0;
  else buff[readed] = 0;
  printf(PRINTVALUE, "Program name", buff);

  // Open exe file
  sprintf(buff, PROCEXEFILE, pid);
  readed = readlink(buff, buff, BUF_SIZE);
  buff[readed] = 0;
  char* tmp = strtok(buff, " ");
  printf(PRINTVALUE, "Executable path", tmp);

  procstat_t stat;
  sprintf(buff, PROCSTATFILE, pid);
  if (getProcStat(buff, &stat))
    handle_error("Can`t open status file");
  printf(PRINTVALUE, "Parent process ID", stat.ppid);
  printf(PRINTVALUE, "Threads count", stat.threads);
  printf(PRINTVALUE, "Process state", stat.state);
  return atoi(stat.ppid);
}

int main(int argc, const char **argv) {
  int pid;
  if (argc < 2) pid = getpid();
  else pid = atoi(argv[1]);
  pid = readProc(pid);
  
  while (pid) {
    settermattr(TC_F_BLUE);
    printf("    ======== Resolving parent ========\n");
    settermattr(TC_RESET);
    pid = readProc(pid);
  }

  exit(EXIT_SUCCESS);
}