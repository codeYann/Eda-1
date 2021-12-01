#include "heap.h"
#include <stdlib.h>
#include <stdio.h>

unsigned long GetParent(unsigned long index) {
  return (index / 2);
}

unsigned long LeftChildren(unsigned long index) {
  return (2 * index);
}

unsigned long RightChildren(unsigned long index) {
  return (2 * index) + 1;
}

Heap *CreateHeap(unsigned long capacity) {
  Heap *heap = (Heap*) malloc(sizeof(Heap));
  heap->length = 0;
  heap->capacity = capacity;
  heap->list = (unsigned long*) malloc(capacity * sizeof(unsigned long));
  return heap;
}

void maxHeapifyUp(Heap *heap, unsigned long index) {
  unsigned long parent = GetParent(index);
  if (parent > 0) {
    if (heap->list[index] > heap->list[parent]) {
      unsigned long temp = heap->list[index];
      heap->list[index] = heap->list[parent];
      heap->list[parent] = temp;
      maxHeapifyUp(heap, parent);
    }
  }
}

void maxHeapifyDown(Heap *heap, unsigned long index) { 
  unsigned long lastIndex = heap->length;
  unsigned long left = LeftChildren(index), right = RightChildren(index);
  unsigned long choice = 0;

  while (left <= lastIndex) {
    if (left == lastIndex) {
      choice = left;
    } else if (heap->list[left] > heap->list[right]) {
      choice = left;
    } else {
      choice = right;
    }

    if (heap->list[index] < heap->list[choice]) {
      unsigned long temp = heap->list[index];
      heap->list[index] = heap->list[choice];
      heap->list[choice] = temp;

      index = choice;
      left = LeftChildren(index); 
      right = RightChildren(index);
    } else {
      return;
    }
  }
}

void Insert(Heap *heap, unsigned long element) {
  if (heap->length < heap->capacity) {
    heap->length += 1;
    heap->list[heap->length] = element;
    maxHeapifyUp(heap, heap->length);
  }
}

unsigned long Remove(Heap* heap) {
  if(heap->length > 0) {
    unsigned long n = heap->length;
    unsigned long max = heap->list[1];
    heap->list[1] = heap->list[n - 1];
    heap->length -= 1;
    maxHeapifyDown(heap, 1);
    return max;
  } else {
    return -1;
  }
}

Heap* Heapify(unsigned long* array, unsigned long n) {
  Heap* heap = malloc(sizeof(Heap));
  heap->capacity = n * 2;
  heap->length = n;
  (heap->list) += 1;
  heap->list = array;
  (heap->list) -= 1;
  
  for(unsigned long i = (heap->length/2); i >= 1; i--) {
    maxHeapifyDown(heap, i);
  }

  return heap;
}
