#ifndef HASHTABLE
#define HASHTABLE

typedef struct node
{
  unsigned long key;
  char *value;
  struct node *next;
} Node;

typedef struct
{
  unsigned long capacity;
  unsigned long collision;
  Node **list;
} HashTable;

HashTable *CreateHashTable(unsigned long capacity);

void Append(
    HashTable *hashTable,
    unsigned long key,
    char *value,
    unsigned long (*HashMethod)(unsigned long key, unsigned long capacity)
);

char *Search(
    HashTable *hashTable, 
    unsigned long key, 
    unsigned long (*HashMethod)(unsigned long key, unsigned long capacity)
);

unsigned long ModMethod(unsigned long key, unsigned long m);
unsigned long MultiplicationMethod(unsigned long key, unsigned long m);
unsigned long FoldMethod(unsigned long key, unsigned long m);

#endif
