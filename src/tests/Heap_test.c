#include "../lib/heap.h"
#include <stdio.h>

int main(int argc, char* argv[]) {
  Heap* h = CreateHeap(10);

  Insert(h, 33); 
  Insert(h, 39);
  Insert(h, 78);
  Insert(h, 60);
  Insert(h, 95);
  Insert(h, 66);
  Insert(h, 28);
  Insert(h, 70);

  printf("%d\n", h->list[0]);

  for(int i = 0; i < h->length; i++){
    printf(" %d ", h->list[i]);
  }

  return 0;
}

