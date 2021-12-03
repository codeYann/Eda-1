#ifndef HASHTABLE
#define HASHTABLE

typedef struct node {
  int key;
  char *value;
  struct node *next;
} Node;

typedef struct {
  int capacity;
  Node** list;
} HashTable;

HashTable* CreateHashTable(int capacity);
void Append(HashTable* hashTable, int key, char *value, unsigned int(*HashMethod)(int key, int capacity));
char* Search(HashTable* hashTable, int key, unsigned int(*HashMethod)(int key, int capacity));

unsigned int ModMethod(int key, int m);
unsigned int MultiplicationMethod(int key, int m);

#endif
