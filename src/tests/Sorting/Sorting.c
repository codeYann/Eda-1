#include "../../lib/heapSort.h"
#include "../../lib/insertion.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define A 100000
#define NAME "src/tests/Sorting/A.txt"

unsigned long* GenerateList(char* name, unsigned long size) {
  unsigned long* list = (unsigned long*) malloc(sizeof(unsigned long) * size);
  FILE* file;

  if(!(file = fopen(name,"r"))) {
    fprintf(stdout, "%s", "Couldn't read file");
    exit(1);
  }

  for(unsigned long j = 0; j  < size; j++) {
    fscanf(file, "%lu", &list[j]);
  };

  fclose(file);
  return list;
}

void show(unsigned long* list, unsigned long n) {
  for(unsigned long i = 0; i < n; i++) {
    printf("%lu\n", list[i]);
  }
}


void Exec(int option, unsigned long* list, unsigned long n) {
  if(option == 1) {
    clock_t start, end;
    start = clock();
    InsertionSort(list, n);
    end = clock();
    printf("%.2f\n", (float)(end - start)/ CLOCKS_PER_SEC); 
  } else {
    clock_t start, end;
    start = clock();
    unsigned long* h = HeapSort(list, n);
    end = clock();
    printf("%.2f\n", (float)(end - start)/ CLOCKS_PER_SEC); 
    show(h, n);
  }
}

int main(int argc, char** argv) {
  int option;
  printf("1 -> InsertionSort\n");
  printf("2 -> HeapSort\n");
  scanf("%d", &option);

  if(option == 1) {
    unsigned long* list = GenerateList(NAME, A);
    Exec(option, list, A);
  } else {
    unsigned long* list = GenerateList(NAME, A);
    Exec(option, list, A);
  }

  return 0;
}
