#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <inttypes.h>
#include <sys/wait.h>
#include "terminal.h"

static inline void handle_error(const char *msg) {
  printf("%s\n  %3d: %s\n", msg, errno, strerror(errno));
  exit(EXIT_FAILURE);
}

void childMain(void) {
  int pid = getpid();
  int rv = 2 + pid % 7;
  settermattr(TC_F_GREEN);
  printf("CHILD: Started child process: %d\n", pid);
  printf("CHILD: Sleeping: %d seconds\n", rv);
  settermattr(TC_RESET);
  sleep(rv);
  exit(rv);
}

int main(int argc, const char **argv) {
  int num, created, ret, rv;
  if (argc < 2) num = 3;
  else num = atoi(argv[1]);

  printf("PARENT: Started parent process: %d\n", getpid());
  printf("PARENT: Creating %d child processes...\n", num);

  created = num;
  while (created-- > 0) {
    ret = fork();
    if (ret == -1)
      handle_error("PARENT: Can't create child process");
    else if (ret == 0)
      break;
    else {
      settermattr(TC_RESET);
      printf("PARENT: Created child process: %d\n", ret);
      sleep(1);
    }
  }

  if (!ret)
    childMain();

  created = num;
  settermattr(TC_RESET);
  printf("PARENT: Waiting for child processes...\n");
  while (created-- > 0) {
    ret = wait(&rv);
    printf("PARENT: Child process %d finished. Return code: %d\n", ret, WEXITSTATUS(rv));
  }

  printf("PARENT: Parent process finished\n");
  exit(EXIT_SUCCESS);
}