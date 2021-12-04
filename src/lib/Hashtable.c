#include "./Hashtable.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

unsigned int ModMethod(int key, int m) {
  return key % m;
}

unsigned int MultiplicationMethod(int key, int m) {
  const float A = 0.61231;
  return (m * fmodf(key * A, 1));
}

Node *CreateNode(int key, char *value) {
  Node* node = (Node*) malloc(sizeof(Node));
  node->value = value;
  node->key = key;
  node->next = NULL;
  return node;
}

HashTable* CreateHashTable(int capacity) {
  HashTable* hashTable = (HashTable*) malloc(sizeof(HashTable));
  hashTable->capacity = capacity;
  hashTable->list = (Node**) malloc(sizeof(Node) * capacity);
  return hashTable;
}

void Append(HashTable *hashTable, int key, char *value, unsigned int (*HashMethod)(int key, int capacity)) {
  unsigned int index = (*HashMethod)(key, hashTable->capacity);
  Node* node = hashTable->list[index];

  if (node == NULL) {
    hashTable->list[index] = CreateNode(key, value);
  } else {
    while (node != NULL) {
      if (node->next == NULL) {
        node->next = CreateNode(key, value);
        break;
      }
      node = node->next;
    }
  }
}

char *Search(HashTable *hashTable, int key, unsigned int (*HashMethod)(int key, int capacity)) {
  unsigned int index = (*HashMethod)(key, hashTable->capacity);
  Node* node = hashTable->list[index];
  while (node != NULL) {
    if (node->key == key) {
      return node->value;
    }
    node = node->next;
  }
  return "";
}
