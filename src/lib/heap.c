#include "heap.h"
#include <stdlib.h>
#include <stdio.h>

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
  Heap *heap = (Heap*) malloc(sizeof(Heap));
  heap->length = 0;
  heap->capacity = capacity;
  heap->list = (int*) malloc(capacity * sizeof(int));
  return heap;
}

void maxHeapifyUp(Heap *heap, int index) {
  int parent = GetParent(index);
  if (heap->list[index] > heap->list[parent]) {
    int temp = heap->list[index];
    heap->list[index] = heap->list[parent];
    heap->list[parent] = temp;
    maxHeapifyUp(heap, parent);
  }
}

void maxHeapifyDown(Heap *heap, int index) {
  int left = LeftChildren(index);
  int right = RightChildren(index);
  int  j = index;

  if(left <= heap->length && heap->list[right] < heap->list[left]) {
    j = left;
  } 

  if(right <= heap->length && heap->list[left] < heap->list[right]) {
    j = right;
  }

  if(j == index) return;
    
  if(heap->list[index] < heap->list[j]) {
    int temp = heap->list[index];
    heap->list[index] = heap->list[j];
    heap->list[j] = temp;
    maxHeapifyDown(heap, j);
  }
}


void Insert(Heap* heap, int element) {
  if(heap->length < heap->capacity) { 
    heap->list[heap->length] = element;
    maxHeapifyUp(heap, heap->length);
    heap->length += 1;
  }
}

int Remove(Heap* heap) {
  if(heap->length > 0) {
    int n = heap->length;
    int max = heap->list[0];
    heap->list[0] = heap->list[n];
    heap->length--;
    maxHeapifyDown(heap, 0);
    return max;
  } else {
    return -1;
  }
}

Heap* Heapify(int* array, int n) {
  Heap* heap = malloc(sizeof(Heap));
  heap->capacity = 3*n;
  heap->length = n - 1;
  heap->list = array;

  for(int i = n/2; i >= 0; i--) {
    maxHeapifyDown(heap, i);
  }

  return heap;
}
