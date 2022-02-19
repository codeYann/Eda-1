#include "../../lib/heapSort.h"
#include "../../lib/insertion.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LENGTH 0                          // Passe o length correto
#define NAME "src/tests/Sorting/file.txt" // Passe o arquivo certo

unsigned long *generate_list(char *name, unsigned long size) {
  unsigned long *list = (unsigned long *)malloc(sizeof(unsigned long) * size);
  FILE *file;

  if (!(file = fopen(name, "r"))) {
    fprintf(stdout, "%s", "Couldn't read file");
    exit(1);
  }

  for (unsigned long j = 0; j < size; j++) {
    fscanf(file, "%lu", &list[j]);
  };

  fclose(file);
  return list;
}

void exec(int option, unsigned long *list, unsigned long n) {
  if (option == 1) {
    clock_t start, end;
    start = clock();
    insertion_sort(list, n);
    end = clock();
    printf("%.2f\n", (float)(end - start) / CLOCKS_PER_SEC);
  } else {
    clock_t start, end;
    start = clock();
    unsigned long *h = heap_sort(list, n);
    end = clock();
    printf("%.2f\n", (float)(end - start) / CLOCKS_PER_SEC);
  }
}

int main(int argc, char **argv) {
  int option;
  printf("1 -> InsertionSort\n");
  printf("2 -> heap_sort\n");
  scanf("%d", &option);

  if (option == 1) {
    unsigned long *list = generate_list(NAME, LENGTH);
    exec(option, list, LENGTH);
  } else {
    unsigned long *list = generate_list(NAME, LENGTH);
    exec(option, list, LENGTH);
  }

  return 0;
}
