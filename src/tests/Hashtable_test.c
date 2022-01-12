#include <stdio.h>
#include "../lib/Hashtable.h"

int main(int argc, char** argv) 
{
  HashTable *hash = CreateHashTable(100);
  Append(hash, 1, "Yanzinho", &MultiplicationMethod);
  Append(hash, 2, "Rodrigues", &MultiplicationMethod);

  printf("%s\n", Search(hash, 2, &MultiplicationMethod));
  printf("%s\n", Search(hash, 1, &MultiplicationMethod));

  return 0;
}

