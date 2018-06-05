#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

#define ITERATIONS 10000
#define BLK_START 48 // 24 kiB
#define BLK_END 1025 // 512 kiB
#define BLK_SIZE 64 // 512 bytes
#define EMPTY_FLAG -1

uint64_t rdtsc (void) {
  uint64_t lo, hi;
  asm volatile ("rdtsc\n" : "=a" (lo), "=d" (hi));
  return (hi << 32) | lo;
}

uint64_t arrayWalk (const uint64_t* array, const uint64_t size) {
  uint64_t steps, index, time, avgTime = 0;
  
  for (int iter = 0; iter < ITERATIONS; iter++) {
    steps = index = 0;
    time = rdtsc();
    while (steps++ < size)
      index = array[index];
    avgTime += rdtsc() - time;
  }

  return avgTime / ITERATIONS;
}

int main(void) {
  srand(time(0));
  uint64_t timeStd, timeRev, timeRand;

  for (int size = BLK_START; size < BLK_END; size++) {
    const uint64_t currSize = size * BLK_SIZE;
    uint64_t *data = (uint64_t *) malloc(currSize * sizeof(uint64_t));
    
    data[currSize - 1] = 0;
    for (int i = 0; i < currSize - 1; i++)
      data[i] = i + 1;
    timeStd = arrayWalk(data, currSize);

    data[0] = currSize - 1;
    for (int i = 1; i < currSize; i++)
      data[i] = i - 1;
    timeRev = arrayWalk(data, currSize);

    for (int i = 0; i < currSize; i++)
      data[i] = EMPTY_FLAG;

    int done, index;
    for (int next = 0; next < currSize; next++) {
      done = 0;
      while (!done) {
        index = rand() % currSize;
        if (index != next && data[index] == EMPTY_FLAG) {
          data[index] = next;
          done = 1;
        }
      }
    }

    timeRand = arrayWalk(data, currSize);

    double timeStdSingle = (double) timeStd / (double) currSize;
    double timeRevSingle = (double) timeRev / (double) currSize;
    double timeRandSingle = (double) timeRand / (double) currSize;

    printf("%5d | %-8ld | %-8ld | %-8ld | %-6.3f | %-6.3f | %-6.3f\n",
      size, timeStd, timeRev, timeRand,
      timeStdSingle, timeRevSingle, timeRandSingle);

    //free(data);
  }

  return 0;
}