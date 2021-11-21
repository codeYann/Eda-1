#include "../lib/heapSort.h"
#include <stdio.h>

#define SIZE 14


int main(int argc, char** argv) {
  int vec[] = {200, 182, 54, 56, 28, 10, 11, 3, 2, 1, 9, 0, -28, 14};
  int* A = HeapSort(vec, SIZE);

  for(int i = 0; i < SIZE; i++) {
    printf(" %d ", A[i]);
  }
  return 0;
}
