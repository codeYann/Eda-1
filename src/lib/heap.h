#ifndef HEAP
#define HEAP

typedef struct
{
  unsigned long *list;
  unsigned long capacity;
  unsigned long length;
} Heap;

Heap *CreateHeap(unsigned long capacity);
void maxHeapifyUp(Heap *heap, unsigned long index);
void maxHeapifyDown(Heap *heap, unsigned long index);
void Insert(Heap *heap, unsigned long element);
unsigned long Remove(Heap *heap);
Heap *Heapify(unsigned long *array, unsigned long n);

#endif
