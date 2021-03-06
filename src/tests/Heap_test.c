#include "../lib/heap.h"
#include <stdio.h>

#define INSERT_LENGTH 6
#define HEAPIFY_LENGTH 9

void test_insert() {
  Heap *h = create_heap(10);
  unsigned long array[] = {4, 2, 5, 1, 3, 6};

  printf("List: ");
  for (unsigned long i = 0; i < INSERT_LENGTH; i++) {
    printf(" %lu ", array[i]);
    Insert(h, array[i]);
  }

  printf("\nHeap: ");
  for (unsigned long i = 1; i <= h->length; i++) {
    printf(" %lu ", h->list[i]);
  }
}

void test_remove() {
  Heap *h = create_heap(15);
  unsigned long array[] = {33, 39, 78, 60, 95, 66, 28, 70, 11, 35, 14};

  for (int i = 0; i < 11; i++)
    Insert(h, array[i]);

  printf("Heap: ");
  for (unsigned long i = 1; i <= h->length; i++) {
    printf(" %lu ", h->list[i]);
  }

  printf("\n");
  Remove(h);

  printf("Heap: ");
  for (unsigned long i = 1; i < h->length; i++) {
    printf(" %lu ", h->list[i]);
  }
}

void test_heapify() {
  unsigned long array[] = {4, 7, 3, 10, 2, 15, 1, 9, 6};

  printf("List: ");
  for (unsigned long i = 0; i < HEAPIFY_LENGTH; i++) {
    printf(" %lu ", array[i]);
  }

  Heap *a = Heapify(array, HEAPIFY_LENGTH);

  printf("\nHeap: ");
  for (unsigned long i = 1; i <= HEAPIFY_LENGTH; i++) {
    printf(" %lu ", a->list[i]);
  }
}

int main(int argc, char *argv[]) {
  printf("Test Insert: \n");
  test_insert();
  printf("\n");

  printf("\nTest Remove: \n");
  test_remove();
  printf("\n");

  printf("\nTest Heapify: \n");
  test_heapify();
  printf("\n");

  return 0;
}
