#include "heap.h"
#include <stdlib.h>

int GetParent(int index) {
  return (index - 1) / 2;
}

int LeftChildren(int index) {
  return (index * 2) + 1;
}

int RightChildren(int index) {
  return (index * 2) + 2;
}

Heap *CreateHeap(int capacity) {
  Heap *heap = (Heap *)malloc(sizeof(Heap));
  heap->length = 0;
  heap->capacity = capacity;
  heap->list = (int *)malloc(capacity * sizeof(int));
  return heap;
}

void maxHeapifyUp(Heap *heap, int index) {
  int parent = GetParent(index);
  int temp = 0;
  if (heap->list[index] > heap->list[parent]) {
    temp = heap->list[index];
    heap->list[index] = heap->list[parent];
    heap->list[parent] = temp;

    maxHeapifyUp(heap, parent);
  }
}

void Insert(Heap* heap, int element) {
  if(heap->length <= heap->capacity) {
    if(heap->length == 0) {
      heap->list[0] = element;
    } else {
      heap->list[heap->length] = element;
      maxHeapifyUp(heap, heap->length);
    }
  
    heap->length += 1;
  }
}

