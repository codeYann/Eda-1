#include "insertion.h"

void InsertionSort(int list[], int n) {
  for(int j = 1; j < n; j++) {
    int key = list[j];
    int i = j - 1;
    while(i >= 0 && list[i] > key) {
      list[i+1] = list[i];
      i -= 1;
    }
    list[i+1] = key;
  }
}
