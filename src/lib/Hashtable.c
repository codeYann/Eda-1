#include "./Hashtable.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

unsigned long ModMethod(unsigned long key, unsigned long m) {
  return key % m;
}

unsigned long MultiplicationMethod(unsigned long key, unsigned long m) {
  const float A = 0.61231;
  return (m * fmodf(key * A, 1));
}

unsigned long FoldMethod(unsigned long key, unsigned long m) {
  return 1;
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
