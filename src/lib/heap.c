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

void maxHeapifyDown(Heap *heap, int index) {
  int l = heap->length;
  int j;
  int left = LeftChildren(index), right = RightChildren(index);

  while(left <= l) {
    if(left == l) {
      j = left;
    } else if(heap->list[left] > heap->list[index]) {
      j = left;
    } else {
      j = right;
    }

    if(heap->list[index] < heap->list[j]) {
      int temp = heap->list[index];
      heap->list[index] = heap->list[j];
      heap->list[j] = temp;
      index = j;
      left = LeftChildren(index); 
      right = LeftChildren(index);
    } else {
      return;
    }
  }
}


void Insert(Heap* heap, int element) {
  if(heap->length < heap->capacity) {
    if(heap->length == 0) {
      heap->list[0] = element;
    } else {
      heap->list[heap->length] = element;
      maxHeapifyUp(heap, heap->length);
    } 
    heap->length += 1;
  }
}

int Remove(Heap* heap) {
  if(heap->length >= 1) { 
    int aux = heap->list[0];
    heap->list[0] = heap->list[heap->length - 1];
    heap->length -= 1;
    maxHeapifyDown(heap, 0);
    return aux;
  } else {
    return 0;
  } 
}
