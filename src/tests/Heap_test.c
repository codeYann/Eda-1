#include "../lib/heap.h"
#include <stdio.h>

void TestInsert() {
  Heap* h = CreateHeap(10);

  Insert(h, 4); 
  Insert(h, 2);
  Insert(h, 5);
  Insert(h, 1);
  Insert(h, 3);
  Insert(h, 6);

  for(int i = 0; i < h->length; i++){
    printf(" %d ", h->list[i]);
  }
}

void TestRemove() {
  Heap* h = CreateHeap(10);
  Insert(h, 33); 
  Insert(h, 39);
  Insert(h, 78);
  Insert(h, 60);
  Insert(h, 95);
  Insert(h, 66);
  Insert(h, 28);
  Insert(h, 70);

  for(int i = 0; i < h->length; i++) {
    printf(" %d ", h->list[i]);
  }

  printf("\n");
  Remove(h);

  for(int i = 0; i < h->length; i++) {
    printf(" %d ", h->list[i]);
  }
}

void TestHeapify() {
  int array[] = {4, 7, 3, 10, 2, 15, 1, 9, 6};
  Heap* a = Heapify(array, 9);

  for(int i = 0; i < a->length; i++) {
    printf(" %d ", a->list[i]);
  }

}

int main(int argc, char* argv[]) {
  TestHeapify();
  return 0;
}

