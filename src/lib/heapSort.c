#include "heapSort.h"
#include "heap.h"
#include <stdio.h>


int* HeapSort(int *list, int n) {
  Heap* A = Heapify(list, n);

  for(int i = A->length; i >= 1; i--) {
    int temp = A->list[0];
    A->list[0] = A->list[i];
    A->list[i] = temp;
    A->length -= 1;
    maxHeapifyDown(A, 0);
  }
  return A->list;
}
