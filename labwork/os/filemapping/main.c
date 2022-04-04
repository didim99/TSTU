#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <inttypes.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>

#define SRC_PATH "./data.txt"
#define TBL_PATH "./translate.dat"
#define BLK_SIZE 8192
#define TBL_SIZE 256

static inline void handle_error(const char *msg) {
  printf("%s\n  %3d: %s\n", msg, errno, strerror(errno));
  exit(EXIT_FAILURE);
}

uint8_t *load_translation_table(const char *path) {
  int fd = open(path, O_RDONLY);
  if (fd == -1) return NULL;
  struct stat fs;
  if (fstat(fd, &fs) == -1) return NULL;
  uint8_t *src = (uint8_t*) calloc(TBL_SIZE, sizeof(uint8_t));
  if (!src) return NULL;
  if (read(fd, src, fs.st_size) == -1) return NULL;
  close(fd);

  uint8_t *table = (uint8_t*) calloc(TBL_SIZE, sizeof(uint8_t));
  if (!table) return NULL;

  int size = (fs.st_size - fs.st_size % 2) >> 1;
  uint8_t *to = src + size + 1;
  uint8_t *from = src;

  int offset = 0;
  while (offset++ < size) {
    table[*from] = *to;
    table[*to++] = *from++;
  }

  free(src);
  return table;
}

int main(void) {
  // Open input file
  int fd = open(SRC_PATH, O_RDWR);
  if (fd == -1)
    handle_error("Can`t open input file");
  printf("Created file descriptor: \t%d\n", fd);

  // Get file size
  struct stat fs;
  if (fstat(fd, &fs) == -1)
    handle_error("Can`t get file size");
  off_t src_size = fs.st_size;
  printf("Input file size: \t\t%ld\n", src_size);

  // Map file to memory
  uint8_t *src_buff;
  src_buff = (uint8_t*) mmap(NULL, src_size,
    PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
  if (src_buff == MAP_FAILED)
    handle_error("Can`t map file to memory");
  printf("File mapped to address: \t%p\n", src_buff);

  // Create temporary buffer and copy data into this
  size_t tmp_size = src_size + (BLK_SIZE - src_size % BLK_SIZE);
  uint8_t *tmp_buff = (uint8_t*) calloc(tmp_size, sizeof(uint8_t));
  if (!tmp_buff)
    handle_error("Can`t create temporary buffer");
  printf("Created temporary buffer: \t%p (%lu)\n", tmp_buff, tmp_size);
  
  // Load translation table
  uint8_t *table = load_translation_table(TBL_PATH);
  if (!table)
    handle_error("Can`t load translation table");
  printf("Translation table loaded: \t%p (%d)\n", table, TBL_SIZE);

  // Copy data to temporary buffer
  memcpy(tmp_buff, src_buff, src_size);
  printf("\nData copied to temporary buffer\n");
  
  // Data processing
  uint8_t *proc = tmp_buff;
  uint8_t *offset = proc + src_size;
  printf("Processing started\n");
  do if (table[*proc]) *proc = table[*proc];
  while (proc++ < offset);
  printf("Processing completed\n");
  memcpy(src_buff, tmp_buff, src_size);
  printf("Data copied from temporary buffer\n");

  // Free resources
  free(table);
  printf("\nTranslation table unloaded\n");
  free(tmp_buff);
  printf("Temporary buffer closed\n");
  if (munmap(src_buff, src_size))
    handle_error("Can`t unmap input file");
  printf("File unmapped\n");
  if (close(fd))
    handle_error("Can`t close input file");
  printf("File descriptor closed\n");
  exit(EXIT_SUCCESS);
}
