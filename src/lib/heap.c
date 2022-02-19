#include "heap.h"
#include <stdio.h>
#include <stdlib.h>

unsigned long get_parent(unsigned long index) { return (index / 2); }

unsigned long left_children(unsigned long index) { return (2 * index); }

unsigned long right_children(unsigned long index) { return (2 * index) + 1; }

Heap *create_heap(unsigned long capacity) {
  Heap *heap = (Heap *)malloc(sizeof(Heap));
  heap->length = 0;
  heap->capacity = capacity;
  heap->list = (unsigned long *)malloc(capacity * sizeof(unsigned long));
  return heap;
}

void max_heapify_up(Heap *heap, unsigned long index) {
  unsigned long parent = get_parent(index);
  if (parent > 0) {
    if (heap->list[index] > heap->list[parent]) {
      unsigned long temp = heap->list[index];
      heap->list[index] = heap->list[parent];
      heap->list[parent] = temp;
      max_heapify_up(heap, parent);
    }
  }
}

void max_heapify_down(Heap *heap, unsigned long index) {
  unsigned long last_index = heap->length;
  unsigned long left = left_children(index), right = right_children(index);
  unsigned long choice = 0;

  while (left <= last_index) {
    if (left == last_index) {
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
      left = left_children(index);
      right = right_children(index);
    } else {
      return;
    }
  }
}

void Insert(Heap *heap, unsigned long element) {
  if (heap->length < heap->capacity) {
    heap->length += 1;
    heap->list[heap->length] = element;
    max_heapify_up(heap, heap->length);
  }
}

unsigned long Remove(Heap *heap) {
  if (heap->length > 0) {
    unsigned long n = heap->length;
    unsigned long max = heap->list[1];
    heap->list[1] = heap->list[n - 1];
    heap->length -= 1;
    max_heapify_down(heap, 1);
    return max;
  } else {
    return -1;
  }
}

Heap *Heapify(unsigned long *array, unsigned long n) {
  Heap *heap = (Heap *)malloc(sizeof(Heap));
  heap->capacity = n * 2;
  heap->length = n;
  (heap->list) += 1;
  heap->list = array;
  (heap->list) -= 1;

  for (unsigned long i = (heap->length / 2); i >= 1; i--) {
    max_heapify_down(heap, i);
  }

  return heap;
}
