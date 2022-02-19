#ifndef HASHTABLE
#define HASHTABLE

typedef struct node {
  unsigned long key;
  char *value;
  struct node *next;
} Node;

typedef struct {
  unsigned long capacity;
  unsigned long collision;
  Node **list;
} HashTable;

HashTable *create_hash_table(unsigned long capacity);

void Append(HashTable *hash_table, unsigned long key, char *value,
            unsigned long (*hash_method)(unsigned long key,
                                         unsigned long capacity));

char *Search(HashTable *hash_table, unsigned long key,
             unsigned long (*hash_method)(unsigned long key,
                                          unsigned long capacity));

unsigned long mod_method(unsigned long key, unsigned long m);
unsigned long multiplication_method(unsigned long key, unsigned long m);
unsigned long fold_method(unsigned long key, unsigned long m);

#endif
