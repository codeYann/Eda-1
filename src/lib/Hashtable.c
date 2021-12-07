#include "./Hashtable.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

unsigned long sumWithOutCarry(unsigned long a, unsigned long b) {
  unsigned long res = a + b;
  if (res >= 10) {
    res %=  10;
  } 
  return res;
}

unsigned long digitOccurrence(unsigned long key) {
  unsigned long T = 0; 
  while (key != 0) {
    key /= 10;
    T += 1;
  } 
  return T;
}

unsigned long ModMethod(unsigned long key, unsigned long m) {
  return key % m;
}

unsigned long MultiplicationMethod(unsigned long key, unsigned long m) {
  const float A = 0.2251;
  return (m * fmodf(key * A, 1));
}

unsigned long FoldMethod(unsigned long key, unsigned long m) {
  int* digitsList;
  unsigned long digits = digitOccurrence(key);

  if (digits % 2 == 1) {
    digitsList = malloc(sizeof(int) * digits + 1);
  } else {
    digitsList = malloc(sizeof(int) * digits);
  }

  unsigned long j = digits; 
  unsigned long u = 0;

  while (key != 0) {
    u = key % 10;
    digitsList[j - 1] = u;
    key /= 10;
    j--;
  }
 
  for (unsigned long i = 2; i < digits; i += 2) {
    j = 0;
    u = digitsList[j + 1];
    digitsList[j + 1] = sumWithOutCarry(digitsList[j], digitsList[i + 1]);
    j += 1;
    digitsList[j - 1] = sumWithOutCarry(u, digitsList[i]);
  }

  u = digitsList[0] * 10 + digitsList[1];
  return u;
}

Node *CreateNode(unsigned long key, char *value) {
  Node* node = (Node*) malloc(sizeof(Node));
  node->value = value;
  node->key = key;
  node->next = NULL;
  return node;
}

HashTable* CreateHashTable(unsigned long capacity) {
  HashTable* hashTable = (HashTable*) malloc(sizeof(HashTable));
  hashTable->capacity = capacity;
  hashTable->list = (Node**) malloc(sizeof(Node) * capacity);
  hashTable->collision = 0;
  return hashTable;
}

void Append(HashTable *hashTable, unsigned long key, char *value, unsigned long (*HashMethod)(unsigned long key, unsigned long capacity)) {
  unsigned long index = (*HashMethod)(key, hashTable->capacity);
  Node* node = hashTable->list[index];

  if (node == NULL) {
    hashTable->list[index] = CreateNode(key, value);
  } else {
    hashTable->collision += 1;
    while (node != NULL) {
      if (node->next == NULL) {
        node->next = CreateNode(key, value);
        break;
      }
      node = node->next;
    }
  }
}

char *Search(HashTable *hashTable, unsigned long key, unsigned long (*HashMethod)(unsigned long key, unsigned long capacity)) {
  unsigned long index = (*HashMethod)(key, hashTable->capacity);
  Node* node = hashTable->list[index];
  while (node != NULL) {
    if (node->key == key) {
      return node->value;
    }
    node = node->next;
  }
  return "";
}
