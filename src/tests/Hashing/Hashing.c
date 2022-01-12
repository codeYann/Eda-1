#include <stdio.h>
#include <stdlib.h>
/* #include <time.h> */
#include "../../lib/Hashtable.h"

#define SIZE 100000
#define LENGTH 0                     // Passe o length correto
#define NAME "src/tests/Hashing/File.txt" // Passe o arquivo certo

unsigned long *GenerateList(char *name, unsigned long size) 
{
  unsigned long *list = (unsigned long *) malloc(sizeof(unsigned long) * size);
  FILE *file;

  if (!(file = fopen(name, "r"))) {
    fprintf(stdout, "%s", "Couldn't read file");
    exit(1);
  }

  for (unsigned long j = 0; j < size; j++) {
    fscanf(file, "%lu", &list[j]);
  };
  fclose(file);
  return list;
}

void Exec(int option) 
{
  HashTable *hash = CreateHashTable(SIZE);
  unsigned long *list = GenerateList(NAME, LENGTH);
  switch (option) {
    case 1: {
      for (unsigned long j = 0; j < LENGTH; j++) {
        Append(hash, list[j], "Yan", &ModMethod);
      }
      printf("Número de colisões %lu\n", hash->collision);
    }
    break;
    case 2: {
      for (unsigned long j = 0; j < LENGTH; j++) {
        Append(hash, list[j], "Yan", &MultiplicationMethod);
      }
      printf("Número de colisões %lu", hash->collision);
    }
    break;
    case 3: {
      for (unsigned long j = 0; j < LENGTH; j++) {
        Append(hash, list[j], "Yan", &FoldMethod);
      }
      printf("Número de colisões %lu", hash->collision);
    }
    break;
  }
  free(hash);
  free(list);
}

int main(int argc, char **argv) 
{
  int i;
  puts("1 -> Método da Divisão");
  puts("2 -> Método da Multiplicação");
  puts("3 -> Método da Dobra");
  puts("4 -> Método da Análise de digito");

  printf("Digite uma opção:");
  scanf("%d", &i);
  
  Exec(i);
  return 0;
}
