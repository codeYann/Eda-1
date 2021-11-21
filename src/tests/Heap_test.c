#include "../lib/heap.h"
#include <stdio.h>

#define INSERT_LENGTH 6
#define HEAPIFY_LENGTH 9

void TestInsert() {
  Heap* h = CreateHeap(10);
  int list[] = {4, 2, 5, 1, 3, 6};

  printf("List: ");
  for(int i = 0; i < INSERT_LENGTH; i++) {
    printf(" %d ", list[i]);
    Insert(h, list[i]);
  }
  
  printf("\nHeap: ");
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
  
  printf("Heap: ");
  for(int i = 0; i < h->length; i++) {
    printf(" %d ", h->list[i]);
  }

  printf("\n");
  Remove(h);
  
  printf("Heap: ");
  for(int i = 0; i < h->length; i++) {
    printf(" %d ", h->list[i]);
  }
}

void TestHeapify() {
  int array[] = {4, 7, 3, 10, 2, 15, 1, 9, 6};

  printf("List: ");
  for(int i = 0; i < HEAPIFY_LENGTH; i++) {
    printf(" %d ", array[i]);
  }

  Heap* a = Heapify(array, HEAPIFY_LENGTH);
  
  printf("\nHeap: ");
  for(int i = 0; i <= a->length; i++) {
    printf(" %d ", a->list[i]);
  }

}

int main(int argc, char* argv[]) {
  printf("Test Insert: \n");
  TestInsert();
  printf("\n");

  printf("\nTest Remove: \n");
  TestRemove();
  printf("\n");

  printf("\nTest Heapify: \n");
  TestHeapify();
  printf("\n");

  return 0;
}

