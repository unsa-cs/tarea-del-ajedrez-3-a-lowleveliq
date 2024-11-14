#include "chess.h"
#include "figures.h"
#include "gc.h"
#include <stdio.h>

void registrar(int **dst, void *src) {
  registerPointerToMemory((void **)dst, src);
}

void display(){ 
  int *a;
  memoryAlloc((void **)&a, sizeof(int));
  *a = 45;
  printf("a = %d\n", *a);

  int *b;
  registrar(&b, (void *)a);
  *b = 3;
  
  int* c;
  registrar(&c, (void *)a);
  *c = 6;

  printf("a = %d\n", *a); // debe imprimir a = 6;
  printf("b = %d\n", *b); // debe imprimir b = 6;
  printf("c = %d\n", *c); // debe imprimir c = 6;
  
  countMemoryEntries();
  unregisterPointer((void **)&a);
  unregisterPointer((void **)&b);
  unregisterPointer((void **)&c);
  garbageCollector();
  countMemoryEntries();
}
