#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <inttypes.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include "terminal.h"

#define PROC_CNT  8
#define NAME_SIZE 64
#define RND_MAX   1000000001
#define DATA_FILE "./src.dat"

static inline void handle_error(const char *msg) {
  printf("%6d: %s\n  [%d] %s\n", getpid(), msg, errno, strerror(errno));
  exit(EXIT_FAILURE);
}

void generate(int count) {
  if (count < 1 || count % 8 > 0)
    handle_error("Invalid data size");

  int data;
  int fd = open(DATA_FILE, O_WRONLY | O_CREAT);
  if (fd == -1)
    handle_error("Can't open file for writing");
  if (fchmod(fd, S_IRUSR | S_IWUSR) == -1)
    handle_error("Can't set permissions on file");

  srand(time(NULL));
  while (count-- > 0) {
    data = rand() % RND_MAX;
    if (write(fd, &data, sizeof(data)) == -1)
      handle_error("Data writing error");
  }

  close(fd);
}

void childMain(int rfd, int wfd) {
  int pid = getpid();
  int offset, size;
  int* buff;

  read(rfd, &buff, sizeof(buff));
  read(rfd, &offset, sizeof(offset));
  read(rfd, &size, sizeof(size));
  settermattr(TC_F_GREEN);
  printf("%6d: Config loaded [addr: %p, offset: %8x, size: %8x]\n",
    pid, buff, offset, size);

  int max = 0;
  buff += offset;
  while (size-- > 0) {
    if (*buff > max) max = *buff;
    buff++;
  }

  settermattr(TC_F_GREEN);
  printf("%6d: Found max value: %d\n", pid, max);
  write(wfd, &max, sizeof(max));
  close(wfd);

  settermattr(TC_F_GREEN);
  printf("%6d: Process finished\n", pid);
  exit(EXIT_SUCCESS);
}

int main(int argc, const char **argv) {
  int created, ret, size = 0, offset = 0;
  int pid = getpid();
  int pids[PROC_CNT];
  int fds[PROC_CNT];
  int *src_buff;
  int pfd[2];

  // Reading parameters
  if (argc > 2) {
    if (!strcmp(argv[1], "-g"))
      size = atoi(argv[2]);
  }

  // Creating data set
  if (size) {
    printf("%6d: Generating data set: %d\n", pid, size);
    generate(size);
    printf("%6d: Data set generated: %s\n", pid, DATA_FILE);
  }

  // Loading input file
  int fd = open(DATA_FILE, O_RDONLY);
  if (fd == -1)
    handle_error("Can`t open input file");
  struct stat fs;
  if (fstat(fd, &fs) == -1)
    handle_error("Can't get data size");
  size = fs.st_size;
  src_buff = (int*) mmap(NULL, size,
    PROT_READ, MAP_SHARED, fd, 0);
  if (src_buff == MAP_FAILED)
    handle_error("Can`t map file to memory");
  
  // Creating child processes
  created = -1;
  int segsize = size / PROC_CNT / sizeof(int);
  while (++created < PROC_CNT) {
    if (pipe(pfd) == -1)
      handle_error("Can't open pipe");
    ret = fork();

    if (ret == -1)
      handle_error("Can't create child process");
    else if (ret == 0)
      break;
    else {
      settermattr(TC_RESET);
      printf("%6d: Created child process: %d\n", pid, ret);
      offset = created * segsize;
      write(pfd[1], &src_buff, sizeof(src_buff));
      write(pfd[1], &offset, sizeof(segsize));
      write(pfd[1], &segsize, sizeof(segsize));
      fds[created] = pfd[0];
      pids[created] = ret;
    }
  }

  // Switch to child process code
  if (!ret) childMain(pfd[0], pfd[1]);

  // Waiting for child process finish
  int max = 0;
  created = PROC_CNT;
  while (created-- > 0) {
    ret = wait(NULL);
    settermattr(TC_RESET);
    printf("%6d: Child process %d finished\n", pid, ret);
    for (int i = 0; i < PROC_CNT; i++) {
      if (pids[i] == ret) {
        read(fds[i], &ret, sizeof(ret));
        if (ret > max) max = ret;
        close(fds[i]);
      }
    }
  }

  munmap(src_buff, size);
  close(fd);

  settermattr(TC_RESET);
  printf("%6d: Max value: %d\n", pid, max);
  printf("%6d: Process finished\n", pid);
  exit(EXIT_SUCCESS);
}
