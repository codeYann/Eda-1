#ifndef HEAP
#define HEAP

typedef struct {
  int *list;
  int capacity;
  int length;
} Heap;

int GetParent(int index);
int LeftChildren(int index);
int RightChildren(int index);
Heap *CreateHeap(int capacity);
void maxHeapifyUp(Heap *heap, int index);
void Insert(Heap* heap, int element);
#endif
