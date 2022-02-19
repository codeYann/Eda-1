#include "./Hashtable.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

unsigned long sum_without_carry(unsigned long a, unsigned long b) {
  unsigned long res = a + b;
  if (res >= 10) {
    res %= 10;
  }
  return res;
}

unsigned long digit_occurrence(unsigned long key) {
  unsigned long t = 0;
  while (key != 0) {
    key /= 10;
    t += 1;
  }
  return t;
}

unsigned long mod_method(unsigned long key, unsigned long m) { return key % m; }

unsigned long multiplication_method(unsigned long key, unsigned long m) {
  const float A = 0.2251;
  return (m * fmodf(key * A, 1));
}

unsigned long fold_method(unsigned long key, unsigned long m) {
  int *digits_list;
  unsigned long digits = digit_occurrence(key);

  if (digits % 2 == 1) {
    digits_list = malloc(sizeof(int) * digits + 1);
  } else {
    digits_list = malloc(sizeof(int) * digits);
  }

  unsigned long j = digits;
  unsigned long u = 0;

  while (key != 0) {
    u = key % 10;
    digits_list[j - 1] = u;
    key /= 10;
    j--;
  }

  for (unsigned long i = 2; i < digits; i += 2) {
    j = 0;
    u = digits_list[j + 1];
    digits_list[j + 1] = sum_without_carry(digits_list[j], digits_list[i + 1]);
    j += 1;
    digits_list[j - 1] = sum_without_carry(u, digits_list[i]);
  }

  u = digits_list[0] * 10 + digits_list[1];
  return u;
}

Node *create_node(unsigned long key, char *value) {
  Node *node = (Node *)malloc(sizeof(Node));
  node->value = value;
  node->key = key;
  node->next = NULL;
  return node;
}

HashTable *create_hash_table(unsigned long capacity) {
  HashTable *hash_table = (HashTable *)malloc(sizeof(HashTable));
  hash_table->capacity = capacity;
  hash_table->list = (Node **)malloc(sizeof(Node) * capacity);
  hash_table->collision = 0;
  return hash_table;
}

void Append(HashTable *hash_table, unsigned long key, char *value,
            unsigned long (*hash_method)(unsigned long key,
                                        unsigned long capacity)) {
  unsigned long index = (*hash_method)(key, hash_table->capacity);
  Node *node = hash_table->list[index];

  if (node == NULL) {
    hash_table->list[index] = create_node(key, value);
  } else {
    hash_table->collision += 1;
    while (node != NULL) {
      if (node->next == NULL) {
        node->next = create_node(key, value);
        break;
      }
      node = node->next;
    }
  }
}

char *Search(HashTable *hash_table, unsigned long key,
             unsigned long (*hash_method)(unsigned long key,
                                         unsigned long capacity)) {
  unsigned long index = (*hash_method)(key, hash_table->capacity);
  Node *node = hash_table->list[index];
  while (node != NULL) {
    if (node->key == key) {
      return node->value;
    }
    node = node->next;
  }
  return "";
}
