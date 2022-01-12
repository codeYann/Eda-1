#include "../lib/heapSort.h"
#include <stdio.h>

#define SIZE 16


int main(int argc, char **argv) 
{
  unsigned long vec[] = {3,200, 182, 54, 27,56, 28, 10, 11, 3, 2, 1, 9, 0, 28, 14};
  unsigned long *A = HeapSort(vec, SIZE);

  for(int i = 1; i <= SIZE; i++) {
    printf(" %lu ", A[i]);
  }
  return 0;
}
