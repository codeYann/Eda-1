#include "../lib/insertion.h"
#include <stdio.h>

#define LENGTH 14

void test_insertion_sort() {
  unsigned long vec[] = {15, 45, 18, 80, 182, 84, 32,
                         23, 12, 3,  7,  8,   19, 1999};

  printf("Vetor pré Ordenação: ");
  for (int i = 0; i < LENGTH; i++) {
    printf(" %lu ", vec[i]);
  }

  printf("\nVetor pós Ordenção: ");

  insertion_sort(vec, LENGTH);
  for (int i = 0; i < LENGTH; i++) {
    printf(" %lu ", vec[i]);
  }
}

int main(int argc, char **argv) {
  test_insertion_sort();
  return 0;
}
