#include "insertion.h"

void InsertionSort(unsigned long* list, unsigned long n) {
  for(unsigned long j = 1; j < n; j++) {
    unsigned long key = list[j];
    unsigned long i = j - 1;
    while(i >= 0 && list[i] > key) {
      list[i+1] = list[i];
      i -= 1;
    }
    list[i+1] = key;
  }
}
