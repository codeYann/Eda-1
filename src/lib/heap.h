#ifndef HEAP
#define HEAP

typedef struct {
  int *list;
  int capacity;
  int length;
} Heap;

Heap *CreateHeap(int capacity);
void maxHeapifyUp(Heap *heap, int index);
void maxHeapifyDown(Heap *heap, int index);
void Insert(Heap* heap, int element);
int Remove(Heap* heap);

#endif
