#include "heapSort.h"
#include "heap.h"
#include <stdio.h>

unsigned long *heap_sort(unsigned long *list, unsigned long n) {
  Heap *A = Heapify(list, n);

  for (unsigned long i = A->length; i >= 1; i--) {
    unsigned long temp = A->list[1];
    A->list[1] = A->list[i];
    A->list[i] = temp;
    A->length -= 1;
    max_heapify_down(A, 1);
  }
  return A->list;
}
