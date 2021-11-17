#include "../lib/heap.h"
#include <stdio.h>

void TestInsert() {
  Heap* h = CreateHeap(10);
  Insert(h, 33); 
  Insert(h, 39);
  Insert(h, 78);
  Insert(h, 60);
  Insert(h, 95);
  Insert(h, 66);
  Insert(h, 28);
  Insert(h, 70);

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

int main(int argc, char* argv[]) {
  return 0;
}

