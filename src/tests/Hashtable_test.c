#include "../lib/Hashtable.h"
#include <stdio.h>

int main(int argc, char **argv) {
  HashTable *hash = create_hash_table(100);
  Append(hash, 1, "Yanzinho", &multiplication_method);
  Append(hash, 2, "Rodrigues", &multiplication_method);

  printf("%s\n", Search(hash, 2, &multiplication_method));
  printf("%s\n", Search(hash, 1, &multiplication_method));

  return 0;
}
