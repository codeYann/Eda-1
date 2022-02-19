#ifndef HEAP
#define HEAP

typedef struct {
  unsigned long *list;
  unsigned long capacity;
  unsigned long length;
} Heap;

Heap *create_heap(unsigned long capacity);
void max_heapify_up(Heap *heap, unsigned long index);
void max_heapify_down(Heap *heap, unsigned long index);
void Insert(Heap *heap, unsigned long element);
unsigned long Remove(Heap *heap);
Heap *Heapify(unsigned long *array, unsigned long n);

#endif
